/* The following code explains the topics:
 	1. Sample BFS 
	2. sample DFS
	3. Taking input graph in Adjacency List
	4. BFS in Adjacency List graph 
	5. DFS in Adjacency List graph
	6. taking input graph in Adjacency Matrix 
	7. BFS in Adjacency Matrix graph 
	8. DFS in Adjacency Matrix graph
*/


#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};

//-----------------Sample BFS & DFS-----------------

void sample_dfs(Node *root){

	if(root == NULL) return;

	cout << root->data << " ";

	if(root->left != NULL) sample_dfs(root->left); 
	if(root->right != NULL) sample_dfs(root->right);
}



void sample_bfs(Node *root){

	if(root == NULL) return;


	queue<Node *> q;
	q.push(root);

	while(!q.empty()){
		Node *current_node = q.front();
		q.pop();

		cout << current_node->data << " ";
	

		if(current_node->left != NULL){
			q.push(current_node->left);
		}
		if(current_node->right != NULL){
			q.push(current_node->right);
		}
	}
}

//-----------------BFS & DFS in Adjacency List-----------------

void bfs_in_adjacency_list(vector<vector<int>> v){
	queue<int> q;
	q.push(1);

	map<int,bool> visited;
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(!visited[cur]){
			cout << cur << " ";
			visited[cur] = true;
		}
		for(int i=0;i<v[cur].size();i++){
			q.push(v[cur][i]);
		}
	}
}

map<int,bool> visited;

void dfs_in_adjacency_list(vector<vector<int>> v,int cur){

	if(visited[cur]) return;

	visited[cur] = true;
	cout << cur << " ";


	for(int i=0;i<v[cur].size();i++){
		dfs_in_adjacency_list(v,v[cur][i]);
	}
}

 
//-----------------BFS & DFS in Adjacency Matrix-----------------

void bfs_in_adjacency_matrix(vector<vector<int>> matrix){
	
	map<int,bool> visited;

	queue<int> q;
	q.push(1);


	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(!visited[cur]){
			
			visited[cur] = true;
			cout << cur << " ";

			for(int i=0;i<matrix.size();i++){
				if(matrix[cur-1][i] == 0) continue;

				q.push(i+1);
			}
		}
	}



}

map<int,bool> alreadyVisited;
void dfs_in_adjacency_matrix(vector<vector<int>> matrix, int cur){
	if(alreadyVisited[cur]) return;

	alreadyVisited[cur] = true;
	cout << cur << " ";

	for(int i=0;i<matrix.size();i++){
		if(matrix[cur-1][i] == 0) continue;

		dfs_in_adjacency_matrix(matrix, i+1);
	}
}

int main(){

//-----------------Graph input using Adjacency List-----------------



	// int v,e;
	//
	// cin >> v >> e;
	//
	// vector<vector<int>> matrix(v+1);
	//
	// for(int i=0; i<e;i++){
	// 	int nodeA, nodeB;
	// 	cin >> nodeA >> nodeB;
	// 	
	// 	matrix[nodeA].push_back(nodeB);
	// 	
	// }
	//	 cout << endl;
	//
	// cout << "BFS: ";
	// bfs_in_adjacency_list(matrix);
	// cout << endl;
	// 
	// cout << "DFS: ";
	// dfs_in_adjacency_list(matrix,1);


//-----------------Graph input using Adjacency Matrix-----------------




	// int m;
	// cin >> m;
	//
	//
	// vector<vector<int>> matrix(m,vector<int>(m));
	//
	//
	//
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<m;j++){
	// 		cin >> matrix[i][j]; 
	// 	}
	// }
	//
	// cout << endl;
	//
	// cout << "BFS: ";
	// bfs_in_adjacency_matrix(matrix);
	// cout << endl << "DFS: ";
	// 
	// dfs_in_adjacency_matrix(matrix,1);


	
}






/*

Adjacency List input:
	10 13
	1 2
	1 3
	1 4
	2 6
	6 10
	10 5
	9 10
	8 5
	3 8
	7 8
	7 9
	3 7
	4 7

output:
	BFS : 1 2 3 4 6 8 7 10 5 9  
	DFS : 1 2 6 10 5 3 8 7 9 4 




graph:
	0->
	1->2 3 4
	2->6
	3->8 7
	4->7
	5->
	6->10
	7->8 9
	8->5
	9->10
	10->5
//-----------------------------------------------------------------//

Adjecency Matrix input:
	5
	0 1 1 0 0
	0 0 0 0 1
	0 0 0 1 1
	0 1 0 0 0
	0 0 0 0 0
output: 
	BFS: 1 2 3 5 4
	DFS: 1 2 5 3 4
graph:
	1 → 2
	1 → 3
	2 → 5
	3 → 4
	3 → 5
	4 → 2




*/
