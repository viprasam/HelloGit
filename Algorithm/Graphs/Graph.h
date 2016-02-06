#ifndef GRAPH_H
#define GRAPH_H


//#include "Graph.cpp"
#include<iostream>
#include<list>
#include<string.h>
//using namespace std;
//int *Visited=new int[11];

class MyGraph{
            int V;
            std::list<int> *adj;


            public:

            MyGraph(int v)
            {
            this->V=v;
            adj=new std::list<int>[v];
            }

            void AddEdge(int u,int v);
            void PrintMyGraph();
            bool PathHelper(int src,int dest,int* Visited);
            bool PathHaiKya(int src,int dest);//,int *Visited)

};

#endif
