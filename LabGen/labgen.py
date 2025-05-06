import random
from PIL import Image, ImageDraw

def generate_maze(width, height):
    # Initialize the maze with walls (1)
    maze = [[1 for _ in range(width)] for _ in range(height)]
    stack = [(1, 1)]  # Start position
    maze[1][1] = 0  # Mark start as path

    # Directions for carving
    directions = [(0, 2), (0, -2), (2, 0), (-2, 0)]

    while stack:
        x, y = stack[-1]
        random.shuffle(directions)  # Shuffle directions for randomness
        moved = False

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            wall_x, wall_y = x + dx // 2, y + dy // 2
            if 1 <= nx < height - 1 and 1 <= ny < width - 1 and maze[nx][ny] == 1:
                maze[wall_x][wall_y] = 0  # Remove wall
                maze[nx][ny] = 0  # Mark cell as path
                stack.append((nx, ny))
                moved = True
                break

        if not moved:
            stack.pop()  # Backtrack if no moves are possible

    return maze

def find_shortest_path(maze):
    height, width = len(maze), len(maze[0])
    start = (1, 1)
    end = (height - 2, width - 2)
    queue = [(start, [start])]  # (current position, path taken)
    visited = set()

    while queue:
        (x, y), path = queue.pop(0)
        if (x, y) == end:
            return path  # Return the shortest path
        if (x, y) in visited:
            continue
        visited.add((x, y))

        # Add neighbors (up, down, left, right)
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < height and 0 <= ny < width and maze[nx][ny] == 0:
                queue.append(((nx, ny), path + [(nx, ny)]))

    return []  # No path found

def draw_maze_with_path(maze, path, cell_size=20):
    height, width = len(maze), len(maze[0])
    img_width = width * cell_size
    img_height = height * cell_size

    # Create a new image
    img = Image.new("RGB", (img_width, img_height), "white")
    draw = ImageDraw.Draw(img)

    # Draw the maze
    for y, row in enumerate(maze):
        for x, cell in enumerate(row):
            color = "black" if cell == 1 else "white"
            top_left = (x * cell_size, y * cell_size)
            bottom_right = ((x + 1) * cell_size, (y + 1) * cell_size)
            draw.rectangle([top_left, bottom_right], fill=color)

    # Draw the path with red arrows
    for (x1, y1), (x2, y2) in zip(path, path[1:]):
        start = (y1 * cell_size + cell_size // 2, x1 * cell_size + cell_size // 2)
        end = (y2 * cell_size + cell_size // 2, x2 * cell_size + cell_size // 2)
        draw.line([start, end], fill="red", width=3)

    return img

# Parameters
width, height = 33, 17  # Must be odd numbers

# Generate the maze and find the path
maze = generate_maze(width, height)
shortest_path = find_shortest_path(maze)

# Draw the maze with the optimal path
maze_image = draw_maze_with_path(maze, shortest_path, cell_size=20)

# Save the image to C:\Users\Vlad\Pictures
save_path = r"C:\Users\Vlad\Pictures\maze_with_path.png"
maze_image.save(save_path)
print(f"Maze with path saved to {save_path}")

# Optionally display the image
maze_image.show()
