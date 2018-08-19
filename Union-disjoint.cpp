
// This is the implementation of union disjoint data structure

#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int data;
	int parent;
	int size;
};

void unionds(struct node graph[], int u, int v);
void findelem(int u,struct node graph[]);
int main(){
	int n;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	struct node graph[n];
	int temp;
	for (int i=0; i<n;i++){
		graph[i].size = 1;
		graph[i].data = i;
		graph[i].parent = i;
	}
	cout<<"Enter the number of unions, you'd wish to perform\n";
	int size;
	cin>>size;
	cout<<"Enter the nodes to perform Union on \n";
	for (int i=0; i<size; i++){
			
			int m, n;
			cin>>m>>n;
			unionds(graph, m, n);
	}
	cout<<" Enter the element to find\n";
	int u;
	cin>>u;
	findelem(u, graph);
	return 0;
}

void unionds(struct node graph[], int u, int v){
	int temp1 = graph[u].size;
	if(graph[u].size == graph[v].size){
		graph[u].parent = v;
		graph[v].size+=temp1;
	}

	else if (graph[u].size > graph[v].size){
		graph[u].size+=graph[v].size;
		graph[v].parent = u;
	}

	else{
		graph[v].size+=temp1; 
		graph[u].parent = v;
	}
	}

void findelem(int u, struct node graph[]){
	struct node nd  = graph[u];
	while(nd.parent!= nd.data){
		nd = graph[nd.parent];
	}
	cout<<u<<" belongs to the set containing "<<nd.parent<<"\n";
}
