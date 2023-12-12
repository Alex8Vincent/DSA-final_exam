#include <bits/stdc++.h>
#define ll long long
#define MOD 10e9 + 7
#ifndef _trienode_cpp_
#define _trienode_cpp
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
    ~TrieNode(){
        for(int i = 0; i  < 26; i++){
            delete[] child[i];
        }
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
    void run()
    {
        int n;
        cin >> n;

        vector<int> a;
        while (n--)
        {
            string q, x;
            cin >> q >> x;
            if (q == "add")
            {
                this->addString(x);
            }
            else
            {
                a.push_back(this->getCount(x));
            }
        }
        for (auto x : a)
        {
            cout << x << endl;
        }
    }
    ~Trie(){
        if(root){
            delete[]root;
        }
    }
};
 #endif
