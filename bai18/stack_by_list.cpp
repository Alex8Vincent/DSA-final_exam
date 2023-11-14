#include<bits/stdc++.h>
#ifndef _stack_by_list_cpp
#define _stack_by_list_cpp
#define ll long long
#define MOD 10e9+7
using namespace std;

template<class T>
class node{
    private:
        T buf;
        node<T> *next;
    public:
        node<T> (T x, node<T> *N = nullptr){
            buf = x;
            next = N;
        }
        node<T> &getnext() { return next;}
        T &getbuf() {return buf;}    
};

template <class T>
class stack_by_list{
    private:
        unsigned n;
        node<T> *head;
    public:
        stack_by_list() {
            n = 0;
            head = nullptr;
        }
        unsigned size(){return n;}
        bool empty(){ return n == 0;}
        T &top() {return head->buf;}
        void pop(){
            if(n <= 1) {
                n = 0;
                head = nullptr;
                return;
            }
            head = head->getnext();
            n--;
        }
        void push(T x){
            head = new node<T> (x,head);
            n++;
        }
};



#endif
