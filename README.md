# AOA PBLE 2 – Campus Shortest Route Finder

## 📌 Project Description

The Campus Shortest Route Finder is a menu-driven C program that uses Dijkstra’s Algorithm to find the shortest route between different locations on a college campus. The campus is represented as a weighted graph using an adjacency matrix, where locations are vertices and roads are edges with distances. The program allows the user to enter locations, define distances, select a source location, and find the shortest distance and path to all other locations.

## 🎯 Objectives

- Represent the campus as a weighted graph.
- Store the graph using an adjacency matrix.
- Implement Dijkstra’s shortest path algorithm.
- Find the shortest distance from a selected source location.
- Display the shortest path to each destination.
- Use a parent array for path reconstruction.
- Provide a simple menu-driven interface.

## 🛠️ Technologies Used

- Language: C
- Algorithm: Dijkstra’s Algorithm
- Data Structure: Weighted Graph
- Graph Representation: Adjacency Matrix
- Compiler: GCC / Code::Blocks / VS Code

## ⚙️ Features

1. Enter Campus Graph
2. Display Adjacency Matrix
3. Select Source Location
4. Find Shortest Distance
5. Display Shortest Paths
6. Display Distance from Source to All Locations
7. Exit

## 🗺️ Example Locations

The program can be tested using:

- Main Gate
- Library
- Computer Department
- Laboratory
- Auditorium

## 🧠 Algorithm Used

1. Initialize the distance of the source vertex as 0.
2. Initialize the distance of all other vertices as infinity.
3. Select the unvisited vertex with the smallest distance.
4. Mark the selected vertex as visited.
5. Update the distances of its adjacent vertices.
6. Store the previous vertex in the parent array whenever a shorter path is found.
7. Repeat the process until all reachable vertices are processed.
8. Use the parent array to reconstruct and display the shortest paths.

⏱️ Time Complexity

The time complexity of Dijkstra’s Algorithm using an adjacency matrix is:

O(V²)

where V represents the number of locations in the campus.

📁 Project Structure

AOA-PBLE2-Dijkstra-Campus-Shortest-Route/

│

├── campus_shortest_route.c

└── README.md

▶️ How to Run

Compile
gcc campus_shortest_route.c -o campus_shortest_route
Run on Windows
campus_shortest_route.exe
Run on Linux/macOS
./campus_shortest_route

🎓 PBLE Information

Subject: Analysis of Algorithms (AOA)
Practical: PBLE 2
Topic: Campus Shortest Route Finder using Dijkstra’s Algorithm
Programming Language: C

👩‍💻 Conclusion

The project demonstrates the practical application of Dijkstra’s Algorithm for finding the shortest routes between campus locations. It provides an efficient way to determine minimum distances and display the corresponding paths between different location

## 📊 Sample Output

```Source Location: Main Gate

Destination                Shortest Distance     Shortest Path
-------------------------------------------------------------------------------
Library                     4                     Main Gate -> Library
Computer Department         7                     Main Gate -> Library -> Computer Department
Laboratory                  9                     Main Gate -> Library -> Computer Department -> Laboratory
Auditorium                  12                    Main Gate -> Library -> Computer Department -> Laboratory -> Auditorium 
