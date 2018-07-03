// This is the Ford Fulkerson Algorithm for finding maxflow in a network

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int bfs(int source,int sink, int n);
int augment_residue(int maxflow, int source, int sink, int n);
int fordfulkerson(int source, int sink, int n);



vector<vector<int> > graph;
vector<vector<int> > weight;
vector <int> path1;

int main(){
	
	cout<<"Enter the number of nodes in the graph\n";
	int n;
	cin>>n;
	vector <int> row(n+1);
	graph.push_back(row);
	weight.push_back(row);
	for (int i=1; i<=n; i++){
		cout<<"Enter the out - degree of node "<<i<<"\n";
		int deg;
		cin>>deg;
		int node;
		int wt;
		vector<int> nbr(n+1,0);
		vector<int> nbw(n+1,0);
		if(deg>0)
		{	cout<<"Enter the neighbours of the nodes, with weights\n";
			for (int j=1; j<=deg; j++){
				cin>>node>>wt;
				nbr[node]=1;
				nbw[node]=wt;
		}
	}
		graph.push_back(nbr);
		weight.push_back(nbw);
	
}
	cout<<"\n The Maximum Flow is "<<fordfulkerson(1,n,n)<<"\n";
	return 0;
}

int fordfulkerson(int source, int sink, int n){
	int mf=0;

	for(int i=0; i<n+1;i++){
		path1.push_back(0);
	}
	while(bfs(source,sink,n)){
		mf = augment_residue(mf,source, sink, n);
	}
	return mf;
}

int bfs(int source,int sink, int n){
	int visited[n+1];

	for(int i=0; i<n+1;i++){
		visited[i]=0;
	}

	queue<int> q;
	q.push(source);
	visited[source]=1;
	while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=1; v<n+1; v++)
        {
            if (visited[v]==0 && graph[u][v] > 0)
            {
                q.push(v);
                path1[v] = u;
                visited[v] = 1;
            }
        }
    }
	if(visited[sink] == 1){
		return 1;
	}
	else{
		return 0;
	}

}



int augment_residue(int maxflow, int source, int sink, int n){

	int i= sink;
	int temp=10000;
	while(i>source){
		temp = min(weight[path1[i]][i],temp);
		i = path1[i];
	}
	maxflow+=temp;

	i=sink;
	while(i>source){
		weight[path1[i]][i]-=temp;
		weight[i][path1[i]]+=temp;
		if(weight[path1[i]][i]==0){
			graph[path1[i]][i] = 0;

		}
		if(weight[i][path1[i]]>0)
		{
			graph[i][path1[i]]=1;
		} 
		i = path1[i];
	}

	std::fill(path1.begin(), path1.end(), 0);

		return maxflow;
	}

