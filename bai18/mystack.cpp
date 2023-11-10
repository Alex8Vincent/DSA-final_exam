#include<bits/stdc++.h>
#ifndef _mystack.cpp
#define _mystack.cpp
#define ll long long
#define MOD 10e9+7
using namespace std;
template <class T>
class mystack{
    private:
        T *buf;
        int n, cap;
    public:
        mystack() {n = cap = 0; buf == NULL;}
        ~mystack() {if(buf) delete[]buf;}
        int size() {return n;}
        bool empty() {return n == 0;}
        void pop() {n--;}
        T &top() {return buf[n-1];}
        void push(t x){
            if(n==cap){
                cap = cap?cap*2:1;
                T *tmp = new T[cap];
                for(int i = 0; i < n; i++) tmp[i] = buf[i];
                if(buf) delete[]buf;
                buf = tmp;
            }
            buf[n++] =  x;
        }


};

#endif
int main(){}