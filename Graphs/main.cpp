/*

Author : Siddheshwar P Sharma
Date   : 6th Feb 2016

*/

#include "graph_implementation.h"

// Function to take input, drive the graph and give output
int main(){
	Graph g(5);
	g.insert_edges(0,4);		
	g.insert_edges(1,3);		
	g.insert_edges(2,1);		
	g.insert_edges(3,3);		
	g.insert_edges(3,2);		
	g.insert_edges(4,3);		
	g.insert_edges(3,0);		
	g.insert_edges(2,0);		
	g.insert_edges(1,4);
	g.print_adj_graph();		
	cout<<endl;
	return 0;
}
