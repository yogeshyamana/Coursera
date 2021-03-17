#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int> v){

    long long result=0;
    sort(v.begin(), v.end(),greater<int>());
    vector<int>::iterator it;
    for(it = v.begin() ; it!=v.end();it++){
        result = result*10 + *it;
        v.erase(it);
        it--;
    }
    return result;
}

int main(){
    int  n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<solve(v);

}