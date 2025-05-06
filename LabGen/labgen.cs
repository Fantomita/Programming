using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;

class MazeGenerator
{
    static void Main(string[] args)
    {
        int width = 21, height = 21; // Dimensions must be odd
        int cellSize = 20; // Size of each cell in the image

        int[,] maze = GenerateMaze(width, height);
        List<(int, int)> path = FindShortestPath(maze);

        DrawMazeWithPath(maze, path, cellSize, @"C:\Users\Vlad\Pictures\maze_with_path.png");
        Console.WriteLine("Maze with path saved to C:\\Users\\Vlad\\Pictures\\maze_with_path.png");
    }

    // Generates a random maze using depth-first search
    static int[,] GenerateMaze(int width, int height)
    {
        int[,] maze = new int[height, width];
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                maze[y, x] = 1; // Fill with walls

        Stack<(int, int)> stack = new();
        Random rand = new();
        maze[1, 1] = 0;
        stack.Push((1, 1));

        int[] dx = { 0, 0, 2, -2 };
        int[] dy = { 2, -2, 0, 0 };

        while (stack.Count > 0)
        {
            var (x, y) = stack.Peek();
            List<int> directions = Enumerable.Range(0, 4).OrderBy(_ => rand.Next()).ToList();
            bool moved = false;

            foreach (int dir in directions)
            {
                int nx = x + dx[dir], ny = y + dy[dir];
                int wallX = x + dx[dir] / 2, wallY = y + dy[dir] / 2;

                if (nx > 0 && ny > 0 && nx < height - 1 && ny < width - 1 && maze[nx, ny] == 1)
                {
                    maze[wallX, wallY] = 0; // Remove wall
                    maze[nx, ny] = 0; // Mark as path
                    stack.Push((nx, ny));
                    moved = true;
                    break;
                }
            }

            if (!moved)
                stack.Pop(); // Backtrack
        }

        return maze;
    }

    // Finds the shortest path from (1, 1) to (height-2, width-2)
    static List<(int, int)> FindShortestPath(int[,] maze)
    {
        int height = maze.GetLength(0), width = maze.GetLength(1);
        Queue<(int x, int y, List<(int, int)> path)> queue = new();
        HashSet<(int, int)> visited = new();

        queue.Enqueue((1, 1, new List<(int, int)> { (1, 1) }));

        while (queue.Count > 0)
        {
            var (x, y, path) = queue.Dequeue();

            if (x == height - 2 && y == width - 2)
                return path;

            if (visited.Contains((x, y)))
                continue;

            visited.Add((x, y));

            foreach (var (dx, dy) in new[] { (0, 1), (1, 0), (0, -1), (-1, 0) })
            {
                int nx = x + dx, ny = y + dy;
                if (nx > 0 && ny > 0 && nx < height && ny < width && maze[nx, ny] == 0)
                {
                    var newPath = new List<(int, int)>(path) { (nx, ny) };
                    queue.Enqueue((nx, ny, newPath));
                }
            }
        }

        return new List<(int, int)>();
    }

    // Draws the maze and the shortest path, and saves it as an image
    static void DrawMazeWithPath(int[,] maze, List<(int, int)> path, int cellSize, string savePath)
    {
        int width = maze.GetLength(1), height = maze.GetLength(0);
        using Bitmap bmp = new(width * cellSize, height * cellSize);
        using Graphics g = Graphics.FromImage(bmp);

        g.Clear(Color.White);

        // Draw maze
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (maze[y, x] == 1)
                {
                    g.FillRectangle(Brushes.Black, x * cellSize, y * cellSize, cellSize, cellSize);
                }
            }
        }

        // Draw path
        using Pen pen = new(Color.Red, 3);
        for (int i = 0; i < path.Count - 1; i++)
        {
            var (x1, y1) = path[i];
            var (x2, y2) = path[i + 1];
            g.DrawLine(pen,
                x1 * cellSize + cellSize / 2, y1 * cellSize + cellSize / 2,
                x2 * cellSize + cellSize / 2, y2 * cellSize + cellSize / 2);
        }

        // Save the image
        bmp.Save(savePath, ImageFormat.Png);
    }
}
