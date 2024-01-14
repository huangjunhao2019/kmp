#include<iostream>
#include<vector>
using namespace std;

vector<int> kmpNext(string &p);
vector<int> kmpSearch(string &m, string &p, vector<int> &next);

int main(){
    string matchStr = "AABABADDABAC";
    string patternStr = "ABA";

    vector<int> next = kmpNext(patternStr);
    vector<int> res = kmpSearch(matchStr, patternStr, next);
    for(auto &index:res){
        cout<<index<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int> kmpNext(string &p){
    int n = p.size();
    vector<int> next(n,0);
    
    int len = 0;
    next[0] = 0;
    int i=1;
    while(i<n){
        if(p[i] == p[len]){
            len++;
            next[i] = len;
            i++;
        } else{
            if(len==0){
                next[i] = len;
                i++;
            } else{
                len = next[len-1];
            }
        }
    }
    return next;
}

vector<int> kmpSearch(string &m, string &p, vector<int> &next){
    int i=0, j=0;
    vector<int> res;
    while(i<m.size()){
        if(m[i]==p[j]){
            i++;
            j++;
        } else{
            if(j==0){
                i++;
            } else{
                j=next[j-1];
            }
        }
        if(j==p.size()){
            res.push_back(i-j);
            j = next[j-1];
        }
    }
    return res;
}