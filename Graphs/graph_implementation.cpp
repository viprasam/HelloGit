/*

Author : Siddheshwar P Sharma
Date   : 6th Feb 2016

*/


/// This code is simple implementation of dfs algorithm
/// Code uses adjucecny list representation of Graph

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

void Graph::insert_edges(int src, int dest){
	//cout<<"\nIn insert_edges";
	struct Node *new_node = (struct Node *)malloc(sizeof(Node ));
	//cout<<"\nMalloc success";
	new_node->dest_node = dest;
	//cout<<"\nSet dest value";
	new_node->next_node = NULL;
	//cout<<"\nInsert start";
	if(node_list[src].head_node==NULL){
		//cout<<"head[i] : "<<src<<" is null";
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
int main(){
	//cout<<"0";
	Graph g(5);
	//cout<<"1";
	g.insert_edges(0,4);		
	//cout<<"2";
	g.insert_edges(1,3);		
	//cout<<"3";
	g.insert_edges(2,1);		
	//cout<<"4";
	g.insert_edges(3,3);		
	//cout<<"5";
	g.insert_edges(3,2);		
	//cout<<"6";
	g.insert_edges(4,3);		
	//cout<<"7";
	g.insert_edges(3,0);		
	//cout<<"8";
	g.insert_edges(2,0);		
	//cout<<"9";
	g.insert_edges(1,4);
	//cout<<"10";
	g.print_adj_graph();		
	cout<<endl;
	return 0;
}
