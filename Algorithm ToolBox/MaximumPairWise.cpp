#include<bits/stdc++.h>
using namespace std;

//Brute Force
long long MaxPairWise(const vector<int> &member){
    int n = member.size();
    long long max = INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(member[i]*member[j]>max)
                max = member[i]*member[j];
        }
    }
    return max;
}

// optimize solution
long long MaxPairWiseFast(const vector<int> &member){
    int n=member.size();

    int max_Index1 = -1;
    for(int i=0;i<n;i++){
        if((max_Index1 == -1) || (member[i]>member[max_Index1]))
            max_Index1 = i;
    }

    int max_Index2 = -1;
    for(int j=0; j<n;j++){
        if((j != max_Index1) && ((max_Index2 == -1)||(member[j])>member[max_Index2]))    //we replace member[j]!=member[max_Index1] to j != max_Index1
            max_Index2 = j;  //It condition fail when two max  elements are present in arr for example [2,3,9,4,6,9]
    }

    return ((long long)(member[max_Index1])*member[max_Index2]);

}

int main(){

    //Stress Testing 
    /*
    while(true){
        int n = rand()%10 +2;
        cout<<n<<endl;
        vector<int> a;
        for(int i=0;i<n;i++){
            a.push_back(rand()%100000);
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        long long res1 = MaxPairWise(a);
        long long res2 = MaxPairWiseFast(a);

        if(res1!=res2){
            cout<<"Wrong Answer"<<res1<<' '<<res2<<endl;
            break; 
        }
        else{
            cout<<"OK"<<endl;
        }

    }
    */
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    long long result;

    result = MaxPairWiseFast(numbers);
    cout<<result<<endl;
}