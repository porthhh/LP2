#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int startNode);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void Graph::BFS(int startNode)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int neighbor : adj[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int choice;
    cout << "Choose traversal method:\n";
    cout << "1. Depth-First Search (DFS)\n";
    cout << "2. Breadth-First Search (BFS)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Depth First Traversal starting from vertex 2:\n";
        g.DFS(2);
        break;
    case 2:
        cout << "Breadth First Traversal starting from vertex 0: ";
        g.BFS(0);
        break;
    default:
        cout << "Invalid choice!";
    }

    return 0;
}
