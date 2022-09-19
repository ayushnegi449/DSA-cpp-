What is a Graph Data Structure ? | Important Graph Terms & Properties

Formal Definition –  
Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes.
Basically a Graph is a non-linear data structure consisting of nodes and edges.

----------------Graph Mathematical representation –----------------
A graph is a set of pair – (V, E), where V is the set of vertices and E is the set of edges, connecting the pairs of vertices.


----------------Graph Terms & Properties –----------------

1.Adjacency − Two node or vertices are adjacent if they are connected to each other through an edge.
2.Path − Path represents a sequence of edges between the two vertices. 
3.Self-Loop − Is an edge that connects a vertex to itself. A simple graph contains no loops.
4.Multi Edge − two or more edges that are connecting to the same two vertices.
5.Simple Graph − Graphs without loops or parallel edges are called simple graphs.
6.The degree of a node − The degree of a node is the no of edges incident/attached on it.
7.Path − A path can be defined as the sequence of nodes that are followed in order to reach some terminal node E from the initial node A.
8.Simple Path − A path is a Simple path if no vertices(and thus edges) are not repeated
9.Cycle − A cycle can be defined as the path which has no repeated edges or vertices except the first and last vertices.

------------------Some Graph Types –-----------------

Weighted vs Unweighted Graphs –
A weight is a numerical value attached to each individual edge in the graph.
Weighted Graph will contains weight on each edge where as unweighted does not.


----------------Directed(Di-graph) vs Undirected Graph –----------------

1.Directed (Digraph) – A directed graph is a set of vertices (nodes) 
connected by edges, with each node having a direction associated with it.
Edges are usually represented by arrows pointing in the direction the graph can be traversed.

2.Undirected Graphs – In an undirected graph the edges are bidirectional, with no direction associated with them. 
Hence, the graph can be traversed in either direction. The absence of an arrow tells us that the graph is undirected.
directed vs undirected graph data structure

Graph Applications –
1.Dijkstra’s Algorithm
2.Prims’s Algorithm
3.Kruskal’s Algorithm
4.Graphs are used to define the flow of computation.
5.Graphs are used to represent networks of communication.
6.Graphs are used to represent data organization.
7.Graph theory is used to find shortest path in road or a network.
8.In Google Maps, various locations are represented as vertices or nodes and the roads are represented as edges 
  and graph theory is used to find the shortest path between two nodes.