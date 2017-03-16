#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

bool adj[MAX][MAX];

void DFS(int node, bool visited[], int num){
	visited[node]=true;
	cout<<node<<"\n";
	for(int i=1;i<=num;++i){
		if(adj[node][i]==true && visited[i]==false){
			DFS(i, visited, num);
		}
	}
}

int main(){
	cout<<"Enter the vertices of graph\n";
	int vertices;
	cin>>vertices;
	for(int i=1;i<=vertices;++i){
		for(int j=1;j<=vertices;++j){
			adj[i][j]=false;
		}
	}
	int edges;
	cout<<"Enter the number of edges\n";
	cin>>edges;
	for(int i=0;i<edges;++i){
		int a, b;
		cin>>a>>b;
		adj[a][b]=true;
	}
	bool visited[vertices+1];
	for(int i=1;i<=vertices;++i)visited[i]=false;
	cout<<"Enter the starting vertex\n";
	int start;
	cin>>start;
	cout<<"DFS is:\n";
	DFS(start, visited, vertices);
	for(int i=1;i<=vertices;++i){
		if(!visited[i]){
			DFS(i, visited, vertices);
		}
	}
	return 0;
}
