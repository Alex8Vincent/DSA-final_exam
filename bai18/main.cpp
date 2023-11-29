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
    Q.DFS();
    Q.print_graph();
    Q.dijkstra();
}