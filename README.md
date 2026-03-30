# Multi-Modal Travel Optimization System using Graph Algorithms (DAA Project)

A Data Structures and Algorithms (DAA) project that models a real-world transportation system using graph data structures and multiple algorithms to compute optimal travel routes.

---

## Overview

This project simulates a **multi-modal transportation system** connecting cities through:

* Train
* Bus
* Aeroplane

The system allows users to:

* Find optimal routes between cities
* Optimize travel based on cost or time
* Handle flexible user input using string matching
* Select travel preferences and classes

Two versions of implementation are included:

* `2023BTECH068.c` → Initial version
* `2023BTECH068_2.c` → Updated version with advanced features and algorithms

---

## Problem Statement

Given a network of cities connected through multiple transport modes, the objective is to:

* Determine the best route between source and destination
* Minimize:

  * Travel cost
  * Travel time
* Handle real-world constraints such as pricing and route variations
* Improve user input handling and matching

---

## Key Features

* Multi-modal transport system:

  * Train network
  * Bus network
  * Aeroplane network
* Graph-based implementation using adjacency lists
* Multiple optimization strategies
* Class-based travel options:

  * Train → AC1, AC2, AC3, Sleeper, General
  * Bus → AC / Non-AC
  * Aeroplane → Economy / Business / First
* Intelligent input handling using string matching

---

## Algorithms Used

### 1. Dijkstra’s Algorithm

* Used for shortest path computation
* Optimizes:

  * Cost
  * Time

---

### 2. Bellman-Ford Algorithm

* Handles more flexible graph conditions
* Useful for:

  * Edge case handling
  * More generalized shortest path scenarios

---

### 3. Levenshtein Distance

* Used for string matching
* Helps in:

  * Handling incorrect user input
  * Matching similar city names

---

## Data Structures Used

* Graph (Adjacency List)
* Linked List
* Arrays
* Structures (struct in C)

---

## Project Structure

```text id="final001"
project-daa/
│── 2023BTECH068.c        # Initial version
│── 2023BTECH068_2.c      # Updated version with multiple algorithms
│── README.md
```

---

## How to Run

### 1. Clone the repository

```bash id="run201"
git clone https://github.com/93527Rupali38898/project-daa.git
cd project-daa
```

### 2. Compile the program

```bash id="run202"
gcc 2023BTECH068_2.c -o project
```

### 3. Run the program

```bash id="run203"
./project
```

> On Windows:

```bash id="run204"
project.exe
```

---

## How It Works

1. Select transport mode:

   * Train
   * Bus
   * Aeroplane

2. Enter:

   * Source city
   * Destination city

3. System:

   * Matches input using Levenshtein Distance
   * Applies shortest path algorithm (Dijkstra / Bellman-Ford)

4. Choose optimization:

   * Cost
   * Time

5. Output includes:

   * Route path
   * Transport identifiers
   * Total cost
   * Total time

---

## Example Output

```id="out201"
Total Cost: 5200
Time Taken: 3 hours 20 minutes
Path: Delhi -> Jaipur -> Mumbai
```

---

## Learning Outcomes

* Implementation of graph algorithms in real-world systems
* Understanding of Dijkstra and Bellman-Ford algorithms
* Application of string matching using Levenshtein Distance
* Multi-algorithm optimization techniques
* Memory management in C

---

## Future Improvements

* Combine all transport modes into a unified graph
* Add real-time data integration
* Develop GUI or web interface
* Enhance algorithm selection dynamically

---

## Author

Rupali Goyal

---

## Note

This project demonstrates the integration of multiple algorithms (graph + string matching) to solve real-world transportation problems efficiently.
