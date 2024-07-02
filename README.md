# Algorithm Visualizer

A graphical application for visualizing various algorithms, including graph traversal algorithms and sorting algorithms. The visualizer provides a dynamic way to understand how algorithms work by showing their intermediate states and progress.

### **Graph Algorithms**
- **Depth-First Search (DFS)**: Explore a graph starting from a root node and visiting nodes in a depthward motion.
- **Breadth-First Search (BFS)**: Traverse a graph level by level from the starting node.

### **Sorting Algorithms**
- **Bubble Sort**: A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
- **Merge Sort**: A divide-and-conquer algorithm that splits the array into halves, recursively sorts them, and merges the sorted halves.
- **Quick Sort**: A fast sorting algorithm that partitions the array into smaller sub-arrays based on a pivot element and recursively sorts them.

### **Grid Manipulation**
- Toggle grid cells between obstacle and free space for graph algorithms.

### **Interactive Visualization**
- Visualize the execution of algorithms with real-time updates.
- Click to toggle obstacles in the grid.
- Use keyboard shortcuts to select different algorithms and perform actions.

## Installation

To run the Algorithm Visualizer on your local machine, follow these steps:

### Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).

### Clone the Repository

```bash
git clone https://github.com/OmKumarIITG/Algorithm-Visualiser.git
```
### Build the Project
Navigate to parent directory
```bash
cd Algorithm-Visualiser
```
Compile the code
```bash
mingw32-make src=visualisation.cpp
```
Run compiled code
```bash
.\out
```

## Usage

### Keyboard Instructions

- **1**: Reset the grid and vector to random values.
- **2**: Start the Depth-First Search (DFS) algorithm.
- **3**: Start the Breadth-First Search (BFS) algorithm.
- **4**: Start the Bubble Sort algorithm.
- **5**: Start the Merge Sort algorithm.
- **6**: Start the Quick Sort algorithm.


## Acknowledgments

- Thanks to the [SDL2](https://www.libsdl.org/) community for providing the graphics library.
- Inspired by various algorithm visualization tools and educational resources.


