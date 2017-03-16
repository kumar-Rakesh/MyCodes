#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

bool adj[MAX][MAX];

struct node{
	int data;
	node* next;
}*head=NULL, *last=NULL;

void enqueue(int num){
	node *rf=new node;
	rf->next=NULL;
	rf->data=num;
	if(head==NULL){
		head=last=rf;
	}else{
		last->next=rf;
		last=rf;
	}
}

int dequeue(){
	node *rf=head;
	int num=rf->data;
	head=head->next;
	free(rf);
	return num;
}

bool isEmpty(){
	if(head==NULL)return true;
	else return false;
}

int main(){
	int num;
	cout<<"Enter the number of vertices\n";
	cin>>num;
	for(int i=1;i<=num;++i){
		for(int j=1;j<=num;++j)adj[i][j]=false;
	}
	int edges=0;
	int inDegree[num+1];
	for(int i=1;i<=num;++i)inDegree[i]=0;
	cout<<"Enter the edges(-1 -1 to stop)\n";
	while(true){
		int a,b;
		cin>>a>>b;
		if(a==-1||b==-1)break;
		adj[a][b]=true;
		inDegree[b]++;
		++edges;
	}
	for(int i=1;i<=num;++i){
		if(inDegree[i]==0)enqueue(i);
	}
	bool visited[num+1];
	for(int i=1;i<=num;++i)visited[i]=false;
	std::vector<int> ans;
	while(true){
		if(isEmpty()==true)break;
		int node=dequeue();
		visited[node]=true;
		ans.push_back(node);
		for(int i=1;i<=num;++i){
			if(adj[node][i]==true){
				if(inDegree[i]>0){
					if(--inDegree[i]==0)enqueue(i);
				}
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=num;++i){
		if(visited[i]==false){
			flag=false;
			cout<<"Not possible\n";
			break;
		}
	}
	if(flag){
		cout<<"Topological Order is :\n";
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
