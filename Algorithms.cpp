``````````````````````````````````````````````````````````````````````````````````````````````````````1``````````````````````````````````````````````````````````````````````````````````
MARKS DISTB
  - Attendance : 20
  - Offline    : 24   [2,4,8,11]
  - Online     : 36 [3,5,6,9,10,12]
  - Mid        : 10
  - Final      : 10 



Settings > Compiler > Linker Settings > Add > OK











  

  
``````````````````````````````````````````````````````````````````````````````````````````````````````2``````````````````````````````````````````````````````````````````````````````````


#include <bits/stdc++.h>
using namespace std;

// double f(double x){
//     return sin(x * x) + x / 3.0 - x / 2.0;
// }
//
// void findRoot(double a, double b){
//
//     cout << fixed << setprecision(7);
//
//     if(f(a) * f(b) > 0){
//         cout << "Invalid Interval";
//         return;
//     }
//
//     cout << "No\t"
//          << "a\t\t"
//          << "b\t\t"
//          << "f(a)\t\t"
//          << "f(b)\t\t"
//          << "x0\t\t"
//          << "f(x0)\t\t"
//          << "Rel Error\t"
//          << "Interval\t"
//          << "Update\n";
//
//     int counter = 0;
//
//     double prev = a;
//     double current;
//     double error;
//
//     do{
//
//         current = (a + b) / 2.0;
//         error = fabs((current - prev) / current);
//
//         if(f(a) * f(current) < 0){
//             b = current;
//
//             cout << counter + 1 << "\t"
//                  << a << "\t"
//                  << b << "\t"
//                  << f(a) << "\t"
//                  << f(b) << "\t"
//                  << current << "\t"
//                  << f(current) << "\t"
//                  << error << "\t"
//                  << b - a << "\t"
//                  << "b\n";
//         }
//         else{
//             a = current;
//
//             cout << counter + 1 << "\t"
//                  << a << "\t"
//                  << b << "\t"
//                  << f(a) << "\t"
//                  << f(b) << "\t"
//                  << current << "\t"
//                  << f(current) << "\t"
//                  << error << "\t"
//                  << b - a << "\t"
//                  << "a\n";
//         }
//
//         prev = current;
//         counter++;
//
//     }while(error >= 0.00001);
//
//     cout << "\nFinal Root (Approx): " << current << endl;
//     cout << "Total Iterations: " << counter << endl;
// }





void initialize_single_source(vector<int> &dist, vector<int> &parent, int source){
    for(int i=1;i<dist.size();i++){
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;
}


void relax(int u, int v, int weight,
           vector<int> &dist, vector<int> &parent){

    if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
        dist[v] = dist[u] + weight;
        parent[v] = u;
    }
}


void print_path(int node, vector<int> &parent){
    if(node == -1) return;

    print_path(parent[node], parent);
    cout << node << " ";
}


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

    cout << "Node\tDistance\tPath\n";

    for(int i=1;i<=v;i++){

        cout << i << "\t";

        if(dist[i] == INT_MAX){
            cout << "INF\t\tNo Path\n";
            continue;
        }

        cout << dist[i] << "\t\t";
        print_path(i, parent);
        cout << endl;
    }

}


void dijkstra(vector<vector<pair<int,int>>> &graph, int source){

    int n = graph.size() - 1;

    vector<int> dist(n+1);
    vector<int> parent(n+1);

    initialize_single_source(dist, parent, source);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, source});

    while(!pq.empty()){

        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip outdated entries
        if(d != dist[u]) continue;

        for(auto child : graph[u]){

            int v = child.first;
            int weight = child.second;

            int oldDist = dist[v];

            relax(u, v, weight, dist, parent);

            if(dist[v] != oldDist){
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Node\tDistance\tPath\n";

    for(int i=1;i<=n;i++){

        cout << i << "\t";

        if(dist[i] == INT_MAX){
            cout << "INF\t\tNo Path\n";
            continue;
        }

        cout << dist[i] << "\t\t";
        print_path(i, parent);
        cout << endl;
    }
}



void bellman_ford(vector<vector<pair<int,int>>> &graph,
                  int vertices, int source){

    vector<int> dist(vertices+1);
    vector<int> parent(vertices+1);

    initialize_single_source(dist, parent, source);

    // |V|-1 passes
    for(int i=1;i<=vertices-1;i++){

        // Relax every edge
        for(int u=1;u<=vertices;u++){

            for(auto child : graph[u]){

                int v = child.first;
                int weight = child.second;

                relax(u, v, weight, dist, parent);
            }
        }
    }

    cout << "Node\tDistance\tPath\n";

    for(int i=1;i<=vertices;i++){

        cout << i << "\t";

        if(dist[i] == INT_MAX){
            cout << "INF\t\tNo Path\n";
            continue;
        }

        cout << dist[i] << "\t\t";
        print_path(i, parent);
        cout << endl;
    }
}



int main(){



    int v, e;
    cin >> v >> e;

    vector<vector<pair<int,int>>> graph(v+1);

    for(int i=0;i<e;i++){
        int u, vtx, w;
        cin >> u >> vtx >> w;

        graph[u].push_back({vtx, w});
    }

    int source;
    cin >> source;

    dag_shortest_path(graph, v, source);


    return 0;
}


-----------------------------------------------------------------------------------------------------------------------------











  //00724105101017

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(vector<vector<int>> times){


    vector<vector<int>> res;


    sort(times.begin(), times.end(), [](auto x, auto y){
            if(x[1] == y[1]){
                int gap1 = x[1]-x[0];
                int gap2 = y[1]-y[0];

                int pr1 = x[2];
                int pr2 = y[2];
                if(gap1 < gap2){
                    return x[1];
                }
                else if(gap1 > gap2){
                    return y[1];
                }
                else{
                    if(pr1 > pr2){
                        return x[2];
                    }
                    return y[2];
                }
            }
            if(x[1] < y[1]){
                return x[1];
            }
            return y[1];
         });


    cout << endl;

    for(auto time: times){
            cout << time[0] << " " << time[1] << " " << time[2] << endl;
    }

    cout << endl;



    int last_end = -1;

    for(auto time: times){
        if(time[0] > last_end){
            last_end = time[1];
            res.push_back(time);
        }
    }


    return res;


}


int main(){

    vector<vector<int>> times = {
        {1,2,3},
        {1,3,5},
        {2,3,4},
        {3,4,2},
        {3,5,6},
        {4,5,7},
        {5,6,8}
    };


    vector<string> course_codes = {
        "CSE101",
        "CSE105",
        "CSE110",
        "CSE115",
        "CSE120",
        "CSE125",
        "CSE130",
    };

    map<vector<int>, string> mp;


    int i = 0;
    for(auto time: times){
        mp[time] = course_codes[i];
        i++;
    }


    vector<vector<int>> res = solve(times);
    for(auto a: res){
        cout << mp[a] << "->";
    }




}

