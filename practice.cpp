#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<pair<int,int>>> &graph,
                      int cur,
                      vector<int> &visited,
                      stack<int> &st){

    if(visited[cur]) return;

    visited[cur] = true;

    for(auto child : graph[cur]){
        topological_sort(graph, child.first, visited, st);
    }

    st.push(cur);
}

void initialize_single_source(vector<int> &dist,
                              vector<int> &parent,
                              int source){

    for(int i=1;i<dist.size();i++){
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;
}

void relax(int u,
           int v,
           int weight,
           vector<int> &dist,
           vector<int> &parent){

    if(dist[u] != INT_MAX &&
       dist[u] + weight < dist[v]){

        dist[v] = dist[u] + weight;
        parent[v] = u;
    }
}

void print_path(int node, const vector<int> &parent){

    if(parent[node] == -1){
        cout << node;
        return;
    }

    print_path(parent[node], parent);
    cout << "->" << node;
}

void print_shortest_paths(int v,
                          const vector<int> &dist,
                          const vector<int> &parent){

    cout << "Vertex\tCost\tPath\n";

    for(int i=1;i<=v;i++){

        cout << i << "\t";

        if(dist[i] == INT_MAX){
            cout << "INF\tNo Path\n";
            continue;
        }

        cout << dist[i] << "\t";
        print_path(i, parent);
        cout << endl;
    }
}

void dag_shortest_path(vector<vector<pair<int,int>>> &graph,
                       int v,
                       int source){

    vector<int> visited(v+1,0);
    stack<int> st;

    for(int i=1;i<=v;i++){
        if(!visited[i])
            topological_sort(graph, i, visited, st);
    }

    vector<int> dist(v+1);
    vector<int> parent(v+1);

    initialize_single_source(dist, parent, source);

    while(!st.empty()){

        int u = st.top();
        st.pop();

        for(auto child : graph[u]){
            relax(u, child.first, child.second, dist, parent);
        }
    }

    print_shortest_paths(v, dist, parent);
}

int main(){

    int v,e;
    cin >> v >> e;

    vector<vector<pair<int,int>>> graph(v+1);

    for(int i=0;i<e;i++){

        int u,vtx,w;
        cin >> u >> vtx >> w;

        graph[u].push_back({vtx,w});
    }

    int source = 1;

    dag_shortest_path(graph, v, source);
}


/*
Adjacency List input:
	10 13
	1 2 1
	1 3 2
	1 4 3 
	2 6 4
	6 10 5
	10 5 6 
	9 10 7 
	8 5 8 
	3 8 9 
	7 8 10
	7 9 11
	3 7 12
	4 7 13

output:
	BFS : 1 2 3 4 6 8 7 10 5 9  
	DFS : 1 2 6 10 5 3 8 7 9 4 




	1    0   No path   
	2    4   1->2  
	3    5   1->2->3 
	4
	5
	6
	7
	8
	9
	10




*/
