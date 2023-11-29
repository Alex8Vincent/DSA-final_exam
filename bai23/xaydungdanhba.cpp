#include<bits/stdc++.h>
#define ll long long
#define MOD 10e9+7
using namespace std;

class trie{
    public:
        int elem;
        trie *child[26] = {};
        trie(){elem = 1;}
};

void addString(trie *&H, char *p){
    if(!H) H = new trie();
    else H->elem++;
    if(*p) addString(H->child[*p - 'a'],p+1);
}

int get(trie *H, char *p){
    if(!H) return 0;
    if(*p == 0) return H->elem;
    return get(H->child[*p - 'a'],p+1);
}

int main(){
    trie *root = nullptr;
    vector<int> a;
    int n;
    char q[10],x[1000];
    cin >> n;
    while(n--){
        cin >> q >> x;
        if(q[0] == 'a') addString(root,x);
        else{
            a.push_back(get(root,x));
        }
    }
    for(auto x : a){
        cout << x << endl;
    }
}