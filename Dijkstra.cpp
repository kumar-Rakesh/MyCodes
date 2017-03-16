#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int adj[MAX][MAX];

int getMin(int pathLength[], bool visited[],int pred[], int current, int num){
	int mini=INT_MAX, node=-1;
	for(int i=1;i<=num;++i){
		if(visited[i]==false && adj[current][i]!=-1){
			int distance=pathLength[current]+adj[current][i];
			if(pathLength[i]>distance){
				pathLength[i]=distance;
				pred[i]=current;
			}
			if(mini>pathLength[i]){
				mini=pathLength[i];
				node=i;
			}
		}
	}
	return node;
}

int main(){
	int num;
	cout<<"Enter the number of vertices\n";
	cin>>num;
	for(int i=1;i<=num;++i){
		for(int j=1;j<=num;++j)adj[i][j]=-1;
	}
	int edges=0;
	cout<<"Enter the edges and their weights(-1 -1 -1 to stop)\n";
	while(true){
		int a,b,w;
		cin>>a>>b>>w;
		if(a==-1||b==-1||w==-1)break;
		adj[a][b]=w;
	}
	bool visited[num+1];
	for(int i=1;i<=num;++i){
		visited[i]=false;
	}	
	int pred[num+1],pathLength[num+1];
	for(int i=1;i<num;++i){
		pred[i]=-1;
		pathLength[i]=INT_MAX;
	}
	cout<<"Enter the source vertex\n";
	int src, current;
	cin>>src;
	pathLength[src]=0;
	visited[src]=true;
	current=src;
	while(true){
		int node=getMin(pathLength, visited, pred, current, num);
		if(node==-1)break;
		visited[node]=true;
		current=node;
	}
	cout<<"Distance of "<<src<<" from all the nodes and predecssor all the nodes is\nis\n";
	for(int i=1;i<=num;++i){
		cout<<src<<" "<<i<<" "<<pathLength[i]<<" "<<pred[i]<<"\n";
	}
	return 0;
}
