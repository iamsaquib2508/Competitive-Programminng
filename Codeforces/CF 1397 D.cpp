#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf
    
using namespace std;
    
ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}
    
ll minn(ll a, ll b){
    if(a<b) return a; return b;
}
    
int main(){
    int tt=1; 
    cin >> tt;
    while(tt--){
        ll n, i, a[102], mx=0, ans=1000;
        
        cin >> n;
        ll sum = 0, otsum;
        ffr(i,0,n){
            cin >> a[i];
            mx = maxx(mx,a[i]);
            sum += a[i];
        }
        //sort(a,a+n);
        bool lose;
        if(sum&1){
            //odd!
            otsum = sum - mx;
            lose=0;
        }
        else{
            otsum = sum - mx;
            if(otsum>=mx){
                lose=1;
            }
            else lose=0;
        }
        if(lose) cout << "HL\n";
        else cout << "T\n";
        
        //cout << ans << endl;
        
    }
}
