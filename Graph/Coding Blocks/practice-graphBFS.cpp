#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T>> l;
    public:
        void addEdge(T x, T y)
        {l[x].push_back(y); l[y].push_back(x);}
        void bfs(T src)
        {
            queue<T> q;
            map<T,bool> visited;
            
        }
}