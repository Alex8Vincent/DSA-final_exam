#include <bits/stdc++.h>
#define ll long long
#define MOD 10e9 + 7
using namespace std;

class TrieNode
{
private:
    TrieNode *child[26];
    int exist, count;

protected:
    friend class Trie;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        exist = count = 0;
    }
};

class Trie
{
private:
    int cur;
    TrieNode *root;

public:
    Trie() : cur(0)
    {
        root = new TrieNode();
    }

    void addString(string s)
    {
        TrieNode *p = root;
        for (auto c : s)
        {
            int temp = c - 'a';
            if (p->child[temp] == NULL)
                p->child[temp] = new TrieNode();
            p = p->child[temp];
            p->count++;
        }
        p->exist++;
    }

    // bool delete_string_recursive(TrieNode *p, string& s, int i){
    //     if(i != (int)s.size()){
    //         int temp = s[i] - 'a';
    //         bool isChildDeleted = delete_string_recursive(p->child[temp],s,i+1);
    //         if(isChildDeleted) p->child[temp] = NULL;
    //     }else p->exist--;
    //     if(p != root){
    //         p->count--;
    //         if(p->count == 0){
    //             delete p;
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // bool find_string( string s){
    //     TrieNode *p = root;
    //     for(auto f : s){
    //         int c = f -  'a';
    //         if(p->child[c] == NULL) return false;
    //         p = p->child[c];
    //     }
    //     return(p->exist != 0);
    // }

    // void delete_string( string s){
    //     if(find_string(s) == false) return;
    //     delete_string_recursive(root,s,0);
    // }

    int getCount(string s)
    {
        TrieNode *p = root;
        for (auto c : s)
        {
            int temp = c - 'a';
            if (p->child[temp] == NULL)
                return 0;
            p = p->child[temp];
        }
        return p->count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Trie *trie = new Trie();
    vector<int> a;
    while (n--)
    {
        string q, x;
        cin >> q >> x;
        if (q == "add")
        {
            trie->addString(x);
        }
        else
        {
            a.push_back(trie->getCount(x));
        }
    }
    for (auto x : a)
    {
        cout << x << endl;
    }
}