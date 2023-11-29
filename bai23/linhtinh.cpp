#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* con[26];
    int dem;

    TrieNode(){
        for(int i=0;i<26;i++){
            con[i]=nullptr;
        }
        dem=0;
    }
};

class DanhBa{
public:
    TrieNode* goc;

    DanhBa(){
        goc=new TrieNode();
    }

    ~DanhBa(){
        delete goc;
    }

    void ThemTu(const string& Tu){
        TrieNode* hientai=goc;
        for(char c : Tu){
            int index = c - 'a';
            if(hientai->con[index]==nullptr){
            	hientai->con[index]=new TrieNode();
            }
            hientai=hientai->con[index];
            hientai->dem++;
        }
    }

    int TimSoLuong(const string& tu){
        TrieNode* hientai=goc;
        for(char c : tu){
            int index = c - 'a';
            if(hientai->con[index]==nullptr){
                return 0; 
            }
            hientai=hientai->con[index];
        }
        return hientai->dem;
    }
};

int main() {
    DanhBa danhba;
    int n;
    cin>>n;
    cin.ignore();
	string ThaoTac[n], LienHe[n];
    for(int i=0;i<n;i++){
        cin>>ThaoTac[i]>>LienHe[i];
    }
    for(int i=0;i<n;i++){
    	if(ThaoTac[i]=="add"){
            danhba.ThemTu(LienHe[i]);
        }else if(ThaoTac[i]=="find"){
            int dem=danhba.TimSoLuong(LienHe[i]);
            cout<<dem<<endl;
        }
	}
    return 0;
}