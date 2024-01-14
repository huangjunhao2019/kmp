#include<iostream>
#include<vector>
using namespace std;
vector<int> kmpNext(string &pattern);
int main(){
    string pattern = "ABCDABD";
    vector<int> next = kmpNext(pattern);
    for(auto &num:next){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int> kmpNext(string &pattern){
    int n = pattern.size();
    vector<int> next(n,0);
    next[0] = 0;
    int len = 0;
    int i = 1;
    while(i<n){
        if(pattern[len] == pattern[i]){
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