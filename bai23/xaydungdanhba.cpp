#include<bits/stdc++.h>
#define ll long long
#define MOD 10e9+7
using namespace std;

class node{
    public:
        int elem;
        node *child[26] = {};
        node(){elem = 1;}
};

void add(node *&H, char *p){
    if(!H) H = new node();
    else H->elem++;
    if(*p) add(H->child[*p - 'a'],p+1);
}

int get(node *H, char *p){
    if(!H) return 0;
    if(*p == 0) return H->elem;
    return get(H->child[*p - 'a'],p+1);
}

int main(){
    node *root = nullptr;
    vector<int> a;
    int n;
    char q[10],x[1000];
    cin >> n;
    while(n--){
        cin >> q >> x;
        if(q[0] == 'a') add(root,x);
        else{
            a.push_back(get(root,x));
        }
    }
    for(auto x : a){
        cout << x << endl;
    }
}