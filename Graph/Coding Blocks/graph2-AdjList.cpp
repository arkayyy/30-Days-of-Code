#include <bits/stdc++.h>
using namespace std;

class Graph
{
    //Adj list
    unordered_map<string,list<pair<string,int>>> l;
    public:
        void addEdge(string x, string y,bool bdir,int wt)
        {
            l[x].push_back(make_pair(y,wt));
            if(bdir)
            {
                l[y].push_back(make_pair(x,wt));
            }
        }

        void printAdjList()
        {
            //Iterate over all the keys in the map
            for(auto p:l)
            {
                string city=p.first;
                list<pair<string,int>> nbrs=p.second;
                cout<<city<<"->";
                for(auto nbr:nbrs)
                {
                    string dest=nbr.first;
                    int dist=nbr.second;
                    cout<<dest<<" "<<dist<<",";
                }
                cout<<endl;
            }
        }
};

int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.printAdjList();
    return 0;
    
}