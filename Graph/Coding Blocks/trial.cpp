#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<pair<T,int>>> l;
    public:
        void addEdge(T x,T y,bool bdir,int wt)
        {
            l[x].push_back(make_pair(y,wt));
            if(bdir)
            {
                l[y].push_back(make_pair(x,wt));
            }
        }
        void printAdjList()
        {
            for(auto v: l)
            {
                cout<<v.first<<"->";
                for(auto nbr: v.second)
                {
                    cout<<"("<<nbr.first<<","<<nbr.second<<"),";}
                cout<<endl;
            }
        }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2,true,10);
    g.addEdge(1,3,true,15);
    g.addEdge(2,3,true,20);
    g.printAdjList();
    return 0;
}