#include<bits/stdc++.h>
using namespace std;


template<typename T> //defining a dynamic/customizable datatype
class Graph
{
    map<T,list<T>> l;
    
    public:
        void addEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void bfs(T src)
        {
            map<T,bool> visited;
            queue<T> q;
            q.push(src);
            visited[src]=true;
            while(!q.empty())
            {
                T node = q.front();
                q.pop();
                //cout<<node<<endl;
                for(auto nbr:l[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
            for(auto v: visited)
            {
                cout<<v.first<<" ";
            }
        }
};

int main()
{
Graph<int> g; //adding the <int> for the dynamic datatype
g.addEdge(1,2);
g.addEdge(1,3);
g.addEdge(2,3);
g.bfs(1);
return 0;
}