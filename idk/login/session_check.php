<?php
// Set the session cookie path to the root directory
session_set_cookie_params([
    'path' => '/',         // Make the session cookie available site-wide
    'httponly' => true,    // Protect against JavaScript access
    'secure' => false,     // Set to true if using HTTPS
    'samesite' => 'Lax',   // Adjust SameSite attribute (Lax or Strict)
]);

session_start();
?>
