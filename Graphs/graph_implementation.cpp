/*

Author : Siddheshwar P Sharma
Date   : 6th Feb 2016

*/


/// This code is simple implementation of dfs algorithm
/// Code uses adjacency list representation of Graph

#include "graph_implementation.h"

// Function to add an edge to graph
void Graph::insert_edges(int src, int dest){
	struct Node *new_node = (struct Node *)malloc(sizeof(Node ));
	new_node->dest_node = dest;
	new_node->next_node = NULL;
	if(node_list[src].head_node==NULL){
		node_list[src].head_node = new_node;
		cout<<"\nInserted node "<<dest<<" at "<<src;
	}
	else{
		struct Node *temp;
		temp = node_list[src].head_node;
		while(temp->next_node != NULL){
			temp = temp->next_node;
		}
		
		temp->next_node = new_node;
		cout<<"\nInserted node "<<dest<<" at "<<src;
	}
}

// Function to print Adjacency list representation of Graph 
void Graph::print_adj_graph(){
	for(int i=0;i<num_nodes;i++){
		struct Node *temp;
		temp = node_list[i].head_node;
		cout<<"\n Edge from "; 
		for(int j = 0;temp!=NULL;j++){
			cout<<"\t"<<i<<" to "<<temp->dest_node;
			temp = temp->next_node;
		}
	}
}

