#include <iostream>
#include "Graph.h"


using namespace std;
int main()
{

MyGraph G(11);
G.AddEdge(0,2);
G.AddEdge(0,3);
G.AddEdge(0,4);
G.AddEdge(1,3);
G.AddEdge(1,5);
G.AddEdge(2,6);
G.AddEdge(3,4);
G.AddEdge(3,7);
G.AddEdge(4,7);
G.AddEdge(4,8);
G.AddEdge(5,10);
G.AddEdge(7,9);
G.AddEdge(7,10);
G.AddEdge(6,7);
G.AddEdge(8,7);
G.AddEdge(5,4);
//G.AddEdge(5,10);


G.PrintMyGraph();
if((G.PathHaiKya(0,5)))//,Visited)
    cout<<"\nYES";
else cout<<"\nNO";

cout<<"\n";
return 0;


}
