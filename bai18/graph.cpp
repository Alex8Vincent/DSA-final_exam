#include <bits/stdc++.h>
#include "mystack.cpp"
#ifndef _graph_cpp
#define _graph_cpp
#define ll long long
#define INF LLONG_MAX
#define MOD 10e9+7
using namespace std;

class Graph
{
private:
    int size;
    vector<vector<int>> matrixQ;

public:
    Graph() { size = 0; }
    Graph(int vertices) : size(vertices), matrixQ(vertices, vector<int>(vertices, 0)) {}
    void add_edge(int u, int v, int weight)
    {
        matrixQ[u-1][v-1] = weight;
        matrixQ[v-1][u-1] = weight;
    }
    void print_graph()
    {
        if (size == 0)
        {
            cout << "Do thi trong ! " << endl;
            return;
        }
        cout << "Ma tran ke: " << endl;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cout << matrixQ[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void readfile(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            file >> size;
            if (size <= 0)
            {
                cerr << "Chi so khong hop !" << endl;
                file.close();
                return;
            }

            matrixQ = vector<vector<int>>(size, vector<int>(size, 0));
            int edges;
            file >> edges;
            if (edges <= 0)
            {
                cerr << "Chi so khong hop le !" << endl;
                file.close();
                return;
            }
            int u, v, weight;
            while (edges--)
            {
                file >> u >> v >> weight;
                if (u <= 0 || u > size || v <= 0 || v > size)
                {
                    cerr << "Chi so khong hop le !" << endl;
                    continue;
                }
                add_edge(u, v, weight);
            }
            file.close();
        }
        else
        {
            cerr << "Khong the tao hoac mo tep :" << filename << endl;
        }
    }

    void writefile(const string &filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "So dinh: " << size << endl;
            int edges = 0;
            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (matrixQ[i][j] > 0)
                    {
                        edges++;
                    }
                }
            }
            file << "So canh: " << edges << endl;
            for (int i = 0; i < size; i++)
            {
                file << "Dinh " << i + 1 << " ket noi voi: " << endl;
                for (int j = 0; j < size; j++)
                {
                    if (matrixQ[i][j] > 0)
                    {
                        // file << " ket noi voi:" << endl;
                        file << "\tDinh " << j + 1 << " co trong so: " << matrixQ[i][j] << endl;
                    }
                }
            }

            file.close();
        }
        else
        {
            cerr << "Khong the tao hoac mo tep: " << filename << endl;
        }
    }
    void DFS(int u)
    {
        mystack<int> s;
        vector<bool> visited(size, false);
        s.push(u);
        visited[u] = true;
        cout << "DFS: ";
        while (!s.empty())
        {
            int check = s.top();
            s.pop();
            cout << check  + 1<< ' ';
            visited[check] = true;
            for (int i = 0; i < matrixQ[check].size(); ++i)
            {
                if (!visited[i])
                {              // kiem tra xem co canh noi tu check den i va i chua duoc duyet khong
                    s.push(i); // dua ke i chua duyet vao stack
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    
    void dijkstra(int start, int end)
    {
        vector<int> dist(size+1, INT_MAX), res(size+1);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();
          //  if (w > dist[u - 1])
           //     continue;
            for (int v = 0; v < matrixQ[u].size(); v++)
            {
                if (dist[u] + matrixQ[u][v] < dist[v] && matrixQ[u][v] != 0)
                {
                    res[v] = u;
                    dist[v] = dist[u] + matrixQ[u][v];
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        int i = res[end];
        vector<int> _r;
        _r.push_back(end);
        while (i != start)
        {
           _r.push_back(i);
           i = res[i];
        }
        _r.push_back(start);
        for(int i =_r.size() - 1; i >= 0; i--)
            cout << _r[i]+1 << " ";
        cout << "\nKhoang cach: " << dist[end] << endl;
    }
};

#endif
