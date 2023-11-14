#include<bits/stdc++.h>
#include "graph.cpp"
#define ll long long
#define INF LLONG_MAX
#define MOD 10e9+7
using namespace std;


int main(){
    Graph Q;
    Q.readfile("input.txt");
    Q.writefile("output.txt");
    cout << "Chon dinh de duyet: ";
    int x; cin >> x;
    Q.DFS(x - 1);
    // Q.floydWarshall();
    Q.print_graph();
    int start_node, end_node;
    cout << "Enter the starting node for Dijkstra: ";
    cin >> start_node ;
    cout << endl <<  "Enter the ending node for Dijkstra: ";
    cin >> end_node;
    Q.dijkstra(start_node-1, end_node-1);
}