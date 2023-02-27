# graph-algorithms-and-dynamic-programming-algorithms
The intent of this assignment is to implement 4 programs to demonstrate important graph algorithms and dynamic programming algorithms and process a given map of planets using these algorithms

The given map (the graph) has connections (edges) between planets and each planet
(vertex) has its own coordinates, weight and profit.

Program 1 implements the graph and how the
graph is actually stored in memory as adjacency list or adjacency matrix; adding to that, program 1
sorts the planets according to their value and sorts the connections between planets according to
their distances.

Program 2 implements Dijkstra algorithm to find out the shortest distance to travel
from planet A to every other planet in the map. 

Program 3 implements Kruskal’s algorithm to find
out the minimum spanning tree that can be formed from the provided map. Both program 2 and
program 3 draws the produced map. 


Lastly, program 4 implements the 0/1 knapsack dynamic
programming algorithm to find out the optimum set of planets to visit to collect the maximum profit
provided a given maximum capacity. 

Besides the main programs, few classes we implemented to
represent the planet, edge, adjacency matrix, adjacency list and priority queue. 

  -The planet class represent a planet and stores planet information. The edge class represent an edge and stores
   edge information. 

  -The adjacency matrix class represent the actual implementation of graph in
   memory by using adjacency matrix. 

  -The adjacency list class represent the actual implementation of
   graph in memory by using adjacency list. 

  -The priority queue class is used to make a min heap
   priority queue to be utilised by Kruskal’s algorithm in program 3
