//Disjoint Sets

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int rank;
	Node* parent;;
};

map<int, Node*> mp;

void makeSet(int num){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=num;
	node->rank=0;
	node->parent=node;
	mp[num]=node;
}

Node* findSetUtil(int num){
	if((mp[num]->parent)->data==num){
		return mp[num];
	}else findSetUtil((mp[num]->parent)->data);
}

int findSet(int num){
	Node * nd = findSetUtil(num);
	mp[num]->parent=nd;
	return nd->data;
}

void mergeSets(int num1, int num2){
	if(findSet(num1)!=findSet(num2)){
		if(mp[num1]->rank>=mp[num2]->rank){
			mp[num1]->parent->rank=(mp[num1]->parent->rank==mp[num2]->parent->rank)?(mp[num1]->parent->rank)+1:mp[num1]->parent->rank;
			mp[num2]->parent->parent=mp[num1]->parent;
			mp[num2]->parent->rank=0;
			findSet(num2);
		}else{
			mp[num1]->parent->parent=mp[num2]->parent;
			mp[num1]->parent->rank=0;
			findSet(num1);
		}
	}
}

int main(){
	int num;
	cout<<"Enter the number of elements\n";
	cin>>num;
	for(int i=1;i<=num;++i){
		makeSet(i);
	}
	int edges;
	cout<<"Enter the number of edges\n";
	cin>>edges;
	cout<<"Enter the edges\n";
	for(int i=0;i<edges;++i){
		int a,b;
		cin>>a>>b;
		mergeSets(a,b);
	}
	cout<<"The representative of each member is :\n";
	for(int i=1;i<=num;++i){
		cout<<i<<" "<<findSet(i)<<"\n";
	}
	return 0;
}
