#include<iostream>
#include<vector>
using namespace std;
vector<int> kmpNext(string &s);
int kmpSearch(string &m, string &p, vector<int> &next);

int main(){
    string matchStr = "AABABADDABAC";
    string patternStr = "ABA";

    vector<int> next = kmpNext(patternStr);
    int res = kmpSearch(matchStr, patternStr, next);
    cout<<"res= "<<res<<endl;
    return 0;
}

vector<int> kmpNext(string &p){
    int n= p.size();
    vector<int> next(n,0);
    next[0] = 0;
    int i = 1;
    int len = 0;
    while(i<n){
        if(p[i] == p[len]){
            len++;
            next[i] = len;
            i++;
        } else{
            if(len==0){
                next[i] = 0;
                i++;
            } else{
                len = next[len-1];
            }
        }
    }
    return next;
}

int kmpSearch(string &m, string &p, vector<int> &next){
    int i=0, j=0;
    while(i<m.size() && j<p.size()){
        if(m[i] == p[j]){
            i++;
            j++;
        } else{
            if(j==0){
                i++;
            } else{
                j = next[j-1];
            }
        }
    }
    return j == p.size()?i-j:-1;
}