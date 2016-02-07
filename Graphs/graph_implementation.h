/*

Author : Siddheshwar P Sharma
Date   : 7th Feb 2016

*/

#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
	int dest_node;
	Node *next_node;
};

struct Node_list{
	struct Node *head_node;
};

class Graph{
	int num_nodes;
	struct Node_list *node_list;
  public :
	Graph(int num);
	void insert_edges(int src, int dest);
	void print_adj_graph();
};

Graph::Graph(int num){
	num_nodes = num;
	node_list = (struct Node_list *)malloc(sizeof(struct Node_list )*num);
	//cout<<"init1"<<endl;
	for(int i=0;i<num;i++){
		//cout<<"init[i] : "<<i<<endl;
		node_list[i].head_node=NULL;
	}
	//cout<<"init done"<<endl;
}

