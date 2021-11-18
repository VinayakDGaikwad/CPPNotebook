// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

// Number of vertices in the graph
#define V 5
#define INT_MAX 50

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
  // Initialize min value
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}


void printMST(int parent[], int graph[V][V])
{
  cout << "Edge \t\t\tWeight\n";
  string name;
  string name2;
  cout << "Ground";
  for (int i = 1; i < V; i++) {
    switch(i)
    {

    case 1:
      name2 = "MBA BUilding";
    case 2:
      name2 = "PK's Lab";
      break;
    case 3:
      name2 = "Entrance";
      break;
    case 4:
      name2 = "School";
      break;
    }

    switch (parent[i])
    {

    case 1:
      name = "MBA BUilding";
    case 2:
      name = "PK's Lab";
      break;
    case 3:
      name = "Entrance";
      break;
    case 4:
      name = "School";
      break;
    }

    cout << name << " - " << name2 << " \t" << graph[i][parent[i]] << " \n";
  }
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
  // Array to store constructed MST
  int parent[V];

  // Key values used to pick minimum weight edge in cut
  int key[V];

  // To represent set of vertices included in MST
  bool mstSet[V];

  // Initialize all keys as INFINITE
  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  // Always include first 1st vertex in MST.
  // Make key 0 so that this vertex is picked as first vertex.
  key[0] = 0;
  parent[0] = -1; // First node is always root of MST

  // The MST will have V vertices
  for (int count = 0; count < V - 1; count++)
  {
    // Pick the minimum key vertex from the
    // set of vertices not yet included in MST
    int u = minKey(key, mstSet);

    // Add the picked vertex to the MST Set
    mstSet[u] = true;

    // Update key value and parent index of
    // the adjacent vertices of the picked vertex.
    // Consider only those vertices which are not
    // yet included in MST
    for (int v = 0; v < V; v++)

      // graph[u][v] is non zero only for adjacent vertices of m
      // mstSet[v] is false for vertices not yet included in MST
      // Update the key only if graph[u][v] is smaller than key[v]
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }

  // print the constructed MST
  printMST(parent, graph);
}

class DSU
{
  int* parent;
  int* rank;

public:
  DSU(int n)
  {
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++)
    {
      parent[i] = -1;
      rank[i] = 1;
    }
  }

  // Find function
  int find(int i)
  {
    if (parent[i] == -1)
      return i;

    return parent[i] = find(parent[i]);
  }
  // union function
  void unite(int x, int y)
  {
    int s1 = find(x);
    int s2 = find(y);

    if (s1 != s2)
    {
      if (rank[s1] < rank[s2])
      {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      }
      else
      {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }
};

class Graph
{
  vector<vector<int>> edgelist;
  int v;

public:
  Graph(int v)
  {
    this->v = v;
  }

  void addEdge(int x, int y, int w)
  {
    edgelist.push_back({ w, x, y });
  }

  int kruskals_mst()
  {
    // 1. Sort all edges using bubble sort
    int i, j;
    int n = 5;
    //int temp;
    std::vector<int> temp ;

    for (i = 0; i < n - 1; i++) { //loop for iterations
      for (j = 0; j < (n - 1) - i; j++) {  //reduce comparisons for every itteration
        if (edgelist[j] > edgelist[static_cast<std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>>::size_type>(j)+1]) {
          temp = edgelist[j];
          edgelist[j] = edgelist[j+1];
          edgelist[j +1] = temp;
        }
      }
    }

    // Initialize the DSU
    DSU s(V);
    int ans = 0;
    for (auto edge : edgelist)
    {
      int w = edge[0];
      int x = edge[1];
      int y = edge[2];

      // take that edge in MST if it does form a cycle
      if (s.find(x) != s.find(y))
      {
        s.unite(x, y);
        ans += w;
      }
    }
    return ans;
  }
};

// Driver code
int main()
{
  /* the following graph
    2 3
  (0)--(1)--(2)
  | / \ |
  6| 8/ \5 |7
  | / \ |
  (3)-------(4)
      9	 */
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 } };

  Graph g(4);
  g.addEdge(0, 1, 1);
  g.addEdge(1, 3, 3);
  g.addEdge(3, 2, 4);
  g.addEdge(2, 0, 2);
  g.addEdge(0, 3, 2);
  g.addEdge(1, 2, 2);

  // Print the solution
  cout << "Minimum Spanning Tree for college Prim's alogrithm:\n";
  primMST(graph);
  cout << "Minimum Spanning Tree for college Krushal's alogrithm:\n";
  cout << g.kruskals_mst();

  return 0;
}
