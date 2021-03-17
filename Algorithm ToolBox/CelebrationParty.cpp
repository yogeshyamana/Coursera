#include<bits/stdc++.h>
using namespace std;

int celebrationParty(vector<float> age , int n){
    int group=0;
    int lastchild = n;
    int startingPoint =0;
    int currentChild=1;

    while(currentChild<lastchild){
        if(age[currentChild]-age[startingPoint]>1){
            startingPoint = currentChild;
            group++;
        }
        if(currentChild == lastchild-1){
            group++;
        }
        currentChild++;
    }
    return group;
}

int main(){
    int n;
    cin>>n;
    vector<float> ag(n);
    for(int i=0;i<n;i++){
        cin>>ag[i];
    }

    int min_gropus; 
    min_gropus = celebrationParty(ag ,n);

    cout<<min_gropus;
}