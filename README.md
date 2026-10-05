AOA PBLE 2 – Campus Shortest Route Finder
📌 Project Description

The Campus Shortest Route Finder is a menu-driven C program that finds the shortest route between different locations on a college campus using Dijkstra’s Algorithm. The campus is represented as a weighted graph using an adjacency matrix, where locations are represented as vertices and roads are represented as edges with distances. The user can enter campus locations, define the distances between them, select a source location, and calculate the shortest distance and path to every other location. A parent array is used to reconstruct the shortest paths.

🎯 Objectives
Represent the campus as a weighted graph.
Use an adjacency matrix to store distances.
Implement Dijkstra’s shortest path algorithm.
Find the shortest distance from a selected source.
Display the complete shortest path to each destination.
Provide a simple menu-driven interface.
🛠️ Technologies Used
Language: C
Algorithm: Dijkstra’s Algorithm
Data Structure: Weighted Graph
Graph Representation: Adjacency Matrix
Compiler: GCC / Turbo C / Code::Blocks / VS Code
⚙️ Features
Enter Campus Graph
Display Adjacency Matrix
Select Source Location
Find Shortest Distance
Display Shortest Paths
Display distances from source to all locations
Exit
🗺️ Example Campus Locations

The program can be tested using locations such as:

Main Gate
Library
Computer Department
Laboratory
Auditorium

Example shortest route:

Main Gate
    ↓
Library
    ↓
Computer Department
    ↓
Laboratory
    ↓
Auditorium
📊 Sample Output
Source Location: Main Gate

Destination                Shortest Distance     Shortest Path
-------------------------------------------------------------------------------
Library                     4                     Main Gate -> Library
Computer Department         7                     Main Gate -> Library -> Computer Department
Laboratory                  9                     Main Gate -> Library -> Computer Department -> Laboratory
Auditorium                  12                    Main Gate -> Library -> Computer Department -> Laboratory -> Auditorium
🧠 Algorithm
Initialize the distance of the source vertex to 0.
Initialize the distance of all other vertices to infinity.
Select the unvisited vertex with the smallest distance.
Mark it as visited.
Update the distances of its adjacent vertices.
Store the previous vertex in the parent array whenever a shorter path is found.
Repeat until all reachable vertices are processed.
Use the parent array to reconstruct and display the shortest paths.
⏱️ Time Complexity

For an adjacency matrix implementation:

Time Complexity: O(V²)

where V is the number of campus locations.

📁 Project Structure
AOA-PBLE2-Dijkstra-Campus-Shortest-Route/
│
├── campus_shortest_route.c
└── README.md
▶️ How to Run
Compile
gcc campus_shortest_route.c -o campus_shortest_route
Run

Windows:

campus_shortest_route.exe

Linux/macOS:

./campus_shortest_route
👩‍💻 PBLE Information

Subject: Analysis of Algorithms (AOA)
Practical: PBLE 2
Topic: Campus Shortest Route Finder using Dijkstra’s Algorithm
Language: C
