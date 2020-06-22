#include<bits/stdc++.h>
using namespace std;

int a[10000];

int main()
{

    int n, k, res = 0;

    cin>>n>>k;

    vector<int> v;

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        if(a[i]<=k){
            a[i] = k+1;
            res++;
        }
        else break;
    }

    for(int i = n-1; i>=0; i--){
        if(a[i]<=k){
            res++;
        }
        else break;
    }

    cout<<res<<endl;



    return 0;
}
