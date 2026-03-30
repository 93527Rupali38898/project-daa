# Graph-Based Travel System using Dijkstra Algorithm (DAA Project)

A Data Structures and Algorithms (DAA) project that models a transportation network using graph data structures and computes the optimal path between cities using Dijkstra’s Algorithm.

---

## Overview

This project simulates a real-world transportation system consisting of multiple cities connected through routes.

The system allows users to:

* Find the shortest path between cities
* Optimize travel based on cost or time
* Select seat preferences (AC1, AC2, AC3, Sleeper, General)
* View complete route details along with transport information

The project includes two versions of implementation:

* `2023BTECH068.c` → Initial version (basic implementation)
* `2023BTECH068_2.c` → Improved version with extended features and optimizations

---

## Problem Statement

Given a network of cities and connections, the objective is to:

* Determine the optimal route between source and destination
* Minimize:

  * Travel cost
  * Travel time
* Incorporate real-world constraints such as pricing and travel duration

---

## Key Features

* Graph-based transportation network
* Adjacency List representation
* Dijkstra Algorithm for shortest path calculation
* Dual optimization:

  * Cost-based path
  * Time-based path
* Multiple ticket classes:

  * AC1, AC2, AC3
  * Sleeper
  * General
* Additional functionality such as meal options

---

## Data Structures Used

* Graph (Adjacency List)
* Linked List
* Arrays
* Structures (struct in C)

---

## Algorithm Used

### Dijkstra’s Algorithm

Used for:

* Shortest cost path
* Minimum time path

---

## Project Structure

```text
project-daa/
│── 2023BTECH068.c        # Initial version
│── 2023BTECH068_2.c      # Updated and improved version
│── README.md
```

---

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/93527Rupali38898/project-daa.git
cd project-daa
```

### 2. Compile the program (recommended: latest version)

```bash
gcc 2023BTECH068_2.c -o project
```

### 3. Run the program

```bash
./project
```

> On Windows:

```bash
project.exe
```

---

## Sample Workflow

1. Enter source city
2. Enter destination city
3. Choose optimization:

   * 1 → Cost
   * 2 → Time
4. Select seat preference
5. Output includes:

   * Route path
   * Transport identifiers
   * Total cost
   * Total time

---

## Example Output

```
Total Cost: 2500
Time Taken: 5 hours 30 minutes
Path: Delhi -> Jaipur -> Ahmedabad
```

---

## Learning Outcomes

* Practical implementation of graph data structures
* Understanding of Dijkstra’s Algorithm in real-world scenarios
* Handling optimization problems (cost vs time)
* Memory management in C
* Improved problem-solving and logical thinking

---

## Future Improvements

* Graphical User Interface (GUI)
* Integration with real-time data
* Dynamic input-based graph generation
* Web or mobile application version

---

## Author

Rupali Goyal

---

## Note

This project was developed as part of DAA (Design and Analysis of Algorithms) coursework and demonstrates the application of graph algorithms in transportation systems.
