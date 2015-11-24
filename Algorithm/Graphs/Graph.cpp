#include "Graph.h"

void MyGraph::AddEdge(int u,int v)
            {
            adj[u].push_back(v);
            }

void MyGraph::PrintMyGraph()
            {
            for(int i=0;i<this->V;i++)
                {

                std::cout<<i;
                for(std::list<int>::iterator myItr=adj[i].begin();myItr!=adj[i].end();++myItr)
                   std::cout<<"->"<<*myItr;
                   std::cout<<"\n";
                }
            }

bool MyGraph::PathHelper(int src,int dest,int* Visited)
            {

            if(src==dest && Visited[src])
                return true;
             Visited[src]=1;
            std::list<int>::iterator itr;
            for(itr=adj[src].begin();itr!=adj[src].end();++itr)
                {
                if(*itr==dest)
                    return true;
                if(!Visited[*itr])
                return PathHelper(*itr,dest,Visited);//,Visited);
                }
              return false;

            }

bool MyGraph::PathHaiKya(int src,int dest)//,int *Visited)
           {
            int *Visited=new int[this->V];
             memset(Visited,0,sizeof(int)*this->V);

            return PathHelper(src,dest,Visited);

           }
