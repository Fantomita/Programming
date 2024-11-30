<?php
session_start();

// Ensure user is an admin
if (!isset($_SESSION['user']) || $_SESSION['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect if not logged in as admin
    exit;
}

$discord_webhook_url = 'https://discord.com/api/webhooks/1311415874284163154/NYQDv4xSIn5peqL3aaZWvISOLH4GQNpzkk2EFFzRr_9bwIlfgqmrRsm3-ct7Pc9HRq-f'; // Replace with your Discord channel webhook URL

// Handle video upload
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_FILES['video'])) {
    $file = $_FILES['video'];

    // Handle file upload errors
    if ($file['error'] === UPLOAD_ERR_OK) {
        $tmp_name = $file['tmp_name'];
        $extension = pathinfo($file['name'], PATHINFO_EXTENSION);
        $hash_name = bin2hex(random_bytes(16)) . '.' . $extension;

        // Prepare cURL request for file upload to Discord
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $discord_webhook_url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_POST, 1);

        // Prepare the file to upload
        $mime_types = [
    		'mp4' => 'video/mp4',
    		'avi' => 'video/x-msvideo',
    		'mov' => 'video/quicktime',
   		 'mkv' => 'video/x-matroska',
    		// Add more as needed
	];

	$mime_type = $mime_types[$extension] ?? mime_content_type($tmp_name); // Fallback to auto-detection

	$post_fields = [
    	'file' => new CURLFile($tmp_name, $mime_type, $hash_name),
	];

        curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields);

        // Execute the cURL request to upload the video to Discord
        $response = curl_exec($ch);

        // Check for errors
        if (curl_errno($ch)) {
            echo 'Error: ' . curl_error($ch);
        } else {
            // Parse the response and get the video URL
            $response_data = json_decode($response, true);
            if (isset($response_data['attachments'][0]['url'])) {
                $video_url = $response_data['attachments'][0]['url'];
                $message_id = $response_data['id']; // Get the message ID from the response

                // Save the video URL and message ID in the database
                try {
                    $pdo = new PDO('sqlite:/var/www/db/videos.db');
                    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                    // Insert video details into the database (with the Discord URL and message_id)
                    $stmt = $pdo->prepare("INSERT INTO videos (hash_name, original_name, file_url, message_id) VALUES (?, ?, ?, ?)");
                    $stmt->execute([$hash_name, $file['name'], $video_url, $message_id]);

                    // Reload the page to show the new video
                    header('Location: videos.php'); // Redirect to the video list page
                    exit;
                } catch (PDOException $e) {
                    echo "Database error: " . $e->getMessage();
                }
            } else {
                echo "Failed to upload the video to Discord.";
            }

        }

        curl_close($ch);
    } else {
        echo "Error uploading file. Details: ";
	if ($file['error'] != UPLOAD_ERR_OK) {
    		echo "File upload error code: " . $file['error'];
	}

    }
}

// Fetch videos from the database
try {
    $pdo = new PDO('sqlite:/var/www/db/videos.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Query to fetch all videos
    $stmt = $pdo->query("SELECT * FROM videos ORDER BY upload_date DESC");
    $videos = $stmt->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    $error_message = "Error fetching videos: " . $e->getMessage();
}

// Handle delete request
if (isset($_GET['delete'])) {
    $video_id = $_GET['delete'];

    // Fetch the video from the database
    try {
        $pdo = new PDO('sqlite:/var/www/db/videos.db');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $stmt = $pdo->prepare("SELECT * FROM videos WHERE id = ?");
        $stmt->execute([$video_id]);
        $video = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($video) {
            $message_id = $video['message_id']; // Get the message ID
            $discord_channel_id = '1311415762480529491'; // Replace with your channzel ID
            $bot_token = 'MTMxMTMyMzQ1NTExNDcxMTA1MA.Gcrh60.QGlnT3vCRbbUb_-GjDxDUUyiUdvw31Nh_D7rRY'; // Replace with your bot token

            // Prepare cURL request to delete the message from Discord
            $ch = curl_init();
            curl_setopt($ch, CURLOPT_URL, "https://discord.com/api/v9/channels/{$discord_channel_id}/messages/{$message_id}");
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
            curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "DELETE");

            $headers = [
                'Authorization: Bot ' . $bot_token,
            ];

            curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

            $response = curl_exec($ch);
            if (curl_errno($ch)) {
                echo 'Error:' . curl_error($ch);
            } else {
                echo "File deleted from Discord.";
            }

            curl_close($ch);

            // Delete video from the database
            $stmt = $pdo->prepare("DELETE FROM videos WHERE id = ?");
            $stmt->execute([$video_id]);
        }

        header('Location: videos.php'); // Redirect back to video list
        exit;
    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }
}


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Video List</title>
    <link rel="stylesheet" href="../styles/main.css">
    <style>
        /* General Styles */
        .video-item {
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 10px;
            border-bottom: 1px solid #ccc;
            margin-bottom: 10px;
            border-radius: 5px;
        }

        .video-info {
            flex-grow: 1;
            white-space: nowrap;  /* Prevent text from wrapping */
            overflow: hidden;     /* Hide the overflowing text */
            text-overflow: ellipsis; /* Show ellipsis when text is too long */
            max-width: 80%; /* Ensure it doesn't stretch too wide */
        }

        .download-btn {
            background-color: #4CAF50;
            color: white;
            padding: 8px 16px;
            text-decoration: none;
            border-radius: 5px;
            display: inline-block;
            font-size: 16px;
        }

        .download-btn:hover {
            background-color: #45a049;
        }

        /* Modal styles */
        .modal {
            display: none;
            position: fixed;
            z-index: 1;
            left: 0;
            top: 0;
            width: 100%;
            height: 100%;
            overflow: auto;
            background-color: rgba(0, 0, 0, 0.4); /* Semi-transparent dark background */
        }

        /* Modal content (video player container) */
        .modal-content {
            margin: 10% auto;
            padding: 20px;
            width: 80%;
            max-width: 900px;
            background-color: rgba(0, 0, 0, 0.7); /* Dark, slightly transparent background */
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.5);
        }

        /* Video player */
        .modal video {
            width: 100%;
            height: auto;
        }

        /* Close button for the modal */
        .close {
            color: #aaa;
            float: right;
            font-size: 28px;
            font-weight: bold;
        }

        .close:hover,
        .close:focus {
            color: black;
            text-decoration: none;
            cursor: pointer;
        }

        /* Delete button */
        .delete-btn {
            background-color: #ff4d4d;
            color: white;
            padding: 5px 10px;
            text-decoration: none;
            border-radius: 5px;
        }

        .delete-btn:hover {
            background-color: #e60000;
        }

        /* Mobile Styles */
        @media (max-width: 768px) {
            .video-item {
                flex-direction: column;
                align-items: flex-start;
                padding: 15px;
            }

            .video-info {
                margin-bottom: 10px;
                white-space: nowrap;  /* Prevent text from wrapping */
                overflow: hidden;     /* Hide the overflowing text */
                text-overflow: ellipsis; /* Show ellipsis when text is too long */
                max-width: 100%;  /* Allow full width on mobile but keep truncation */
            }

            .download-btn {
                font-size: 14px;
                padding: 6px 12px;
            }

            .modal-content {
                width: 90%;
                padding: 15px;
            }

            /* Video player size on mobile */
            .modal video {
                width: 100%;
                height: auto;
            }

            .delete-btn {
                font-size: 14px;
                padding: 4px 8px;
            }
        }

    </style>
</head>
<body>
    <header>
        <h1>Video List</h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../videos.php">Videos</a>
        <a href="../about.php">About</a>

        <?php
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                $pdo = new PDO('sqlite:db/users.db');
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    echo '<a href="/login/admin.php">Admin Panel</a>';
                }
            } catch (PDOException $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>

        <?php if (!isset($_SESSION['user'])): ?>
            <a href="../login/login.php">Login</a>
        <?php else: ?>
            <a href="../login/logout.php">Logout</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>Upload Video</h2>
        <form method="POST" enctype="multipart/form-data">
    		<label for="video">Choose video:</label>
    		<input type="file" name="video" id="video" accept="video/*,.avi,.mov,.mkv" required>
    		<button type="submit">Upload</button>
	</form>

        <h2>List of Videos</h2>
        <!-- Video List -->
        <?php if (isset($error_message)): ?>
            <p><?php echo $error_message; ?></p>
        <?php else: ?>
            <ul>
                <?php foreach ($videos as $index => $video): ?>
                    <li class="video-item">
                        <div class="video-info">
                            <span class="video-number"><?php echo $index + 1; ?>.</span>
                            <a href="javascript:void(0);" class="video-name" data-video-url="<?php echo htmlspecialchars($video['file_url']); ?>">
                                <?php echo htmlspecialchars($video['original_name']); ?>
                            </a>
                        </div>
                        <div class="video-actions">
                            <a href="?delete=<?php echo $video['id']; ?>" class="button delete">Delete</a>
                        </div>
                    </li>
                <?php endforeach; ?>
            </ul>
        <?php endif; ?>
    </div>

    <!-- Modal for video player -->
    <div id="videoModal" class="modal">
        <div class="modal-content">
            <span class="close">&times;</span>
            <video id="modalVideo" controls>
                <source id="videoSource" src="" type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>
    </div>

    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>

    <script>
        // JavaScript for handling the video name click and opening the modal
        document.querySelectorAll('.video-name').forEach(function(videoName) {
            videoName.addEventListener('click', function() {
                var videoUrl = this.getAttribute('data-video-url');
                var modal = document.getElementById('videoModal');
                var modalVideo = document.getElementById('modalVideo');
                var videoSource = document.getElementById('videoSource');

                // Set the source of the video player
                videoSource.setAttribute('src', videoUrl);
                modalVideo.load(); // Load the video

                // Show the modal
                modal.style.display = "block";
            });
        });

        // Close the modal when the user clicks on the close button
        document.querySelector('.close').addEventListener('click', function() {
            var modal = document.getElementById('videoModal');
            var modalVideo = document.getElementById('modalVideo');
            
            // Pause the video and reset it to the beginning
            modalVideo.pause();
            modalVideo.currentTime = 0;

            // Hide the modal
            modal.style.display = "none";
        });

        // Close the modal if the user clicks outside of the modal content
        window.onclick = function(event) {
            var modal = document.getElementById('videoModal');
            var modalVideo = document.getElementById('modalVideo');
            
            if (event.target === modal) {
                // Pause the video and reset it to the beginning
                modalVideo.pause();
                modalVideo.currentTime = 0;

                // Hide the modal
                modal.style.display = "none";
            }
        };
    </script>
</body>
</html>
