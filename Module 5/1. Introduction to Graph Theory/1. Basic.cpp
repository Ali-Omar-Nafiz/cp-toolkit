/*
GRAPH THEORY NOTES (Easy Words)
================================

1. Node (Vertex)
- A point in a graph.

2. Edge
- A connection between two nodes.

3. Adjacent Node
- Two nodes are adjacent if an edge connects them.

4. Degree
- Number of edges connected to a node.
- In directed graphs:
  - Indegree = incoming edges.
  - Outdegree = outgoing edges.

5. Path
- A sequence of connected nodes.

6. Cycle
- A path that starts and ends at the same node.

7. Connectivity
- A graph is connected if every node can reach every other node.

8. Shortest Path
- The path with the minimum distance or minimum number of edges.

9. Complete Graph
- Every pair of different nodes has an edge.

10. Self Loop
- An edge from a node to itself.

11. Simple Graph
- No self loops.
- No multiple edges between the same two nodes.

12. Directed Graph
- Edges have directions.

13. Undirected Graph
- Edges have no direction.

14. Weighted Graph
- Every edge has a weight (cost or distance).

15. Unweighted Graph
- Edges have no weights.

16. Tree
- A connected graph with no cycles.

Properties:
- No cycle.
- Connected.
- If there are N nodes, there are exactly N-1 edges.

17. Rooted Tree
- A tree with one chosen root node.

18. Unrooted Tree
- A tree without a chosen root.

19. Parent
- The node directly above another node.

20. Ancestor
- Any parent, grandparent, great-grandparent, etc.

21. Descendant
- Any child, grandchild, etc.

22. Sibling
- Nodes with the same parent.

23. Level / Depth
- Number of edges from the root to a node.

24. Height
- Number of edges on the longest path from a node to a leaf.
- Height of the tree = height of the root.

25. Subtree
- A node and all of its descendants.

26. Leaf Node
- A node with no children.
- In an undirected tree, a leaf usually has degree 1 (except a single-node tree).

27. Forest
- A collection of one or more separate trees.

28. Binary Tree
- Every node has at most two children.

29. Indegree
- Number of incoming edges.

30. Outdegree
- Number of outgoing edges.

31. Graph Representation

Adjacency Matrix
- Uses a 2D array.
- Matrix[i][j] tells whether an edge exists.
- Good for dense graphs.
- Uses more memory.

Adjacency List
- Stores a list of neighbors for every node.
- Good for sparse graphs.
- Uses less memory.

32. How to Find Leaf Nodes of a Tree
- Rooted tree:
  - Nodes with no children.
- Undirected tree:
  - Nodes with degree 1.
  - If the tree has only one node, that node is also a leaf.

33. Diameter of a Tree
- The longest shortest path between any two nodes.
- It is the maximum distance between two nodes.

34. Strongly Connected Component (SCC)
- Used only in directed graphs.
- A group of nodes where every node can reach every other node.
*/
