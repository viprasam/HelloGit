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
	node_list = (struct Node_list *)malloc(sizeof(struct Node *)*num);
	for(int i=0;i<num;i++)
		node_list[i].head_node->next_node=NULL;
}

void Graph::insert_edges(int src, int dest){
	struct Node *new_node = (struct Node *)malloc(sizeof(Node));
	new_node->dest_node = dest;
	new_node->next_node = NULL;
	if(node_list[src].head_node->next_node == NULL)
		node_list[src].head_node->next_node = new_node;
	else{
		struct Node *temp;
		temp = node_list[src].head_node;
		while(temp->next_node->next_node != NULL){
			temp = temp->next_node;
		}
		temp->next_node = new_node;
	}
}

void Graph::print_adj_graph(){
	for(int i=0;i<num_nodes;i++){
		cout<<endl;
		int j = 0;
		while(node_list[i].head_node[j].next_node != NULL)
			cout<<"\nedge from node "<<j<<" to "<<node_list[i].head_node[j].dest_node;
	}
}
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
	return 0;
}
