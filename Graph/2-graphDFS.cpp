#include<bits/stdc++.h>
using napespace std;

template<typename T>
class Graph{
map<T,list<T>> l;

public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited)
    {
        cout<<src<<" ";

        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
               dfs_helper(nbr,visited);
            }
        }
    }


    void dfs(T src)
    {
        map<T,bool> visited;
        //Mark all nodes as not visited in the beginning
        for(auto p:l)
        {
            T node=p.first;
            visited[node]=false;
        }
    }


};

int main()
{

}