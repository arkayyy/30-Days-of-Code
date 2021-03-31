#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    map<int,list<int>> adjList;

    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int x,int y);

    bool isCyclic(int v,bool visited[],int parent);

    bool isTree();

};

void Graph::addEdge(int x,int y)
    {
        adjList[x].push_back(y);
        adjList[y].push_back(x);

    }


bool Graph::isCyclic(int v,bool visited[],int parent)
{
visited[v]=true;
int i;
for(auto i:adjList[i])
{
    if(!visited[i])
        if(isCyclic(i,visited,v))
            return true;
    else if(i!=parent)
        return true;
}
return false;
}


bool Graph::isTree()
{
     bool *visited = new bool[V];
     for (int i = 0; i < V; i++)
        visited[i] = false;
    if (isCyclic(0, visited, -1))
             return false;
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
  
    return true;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
  
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
  
    return 0;
}