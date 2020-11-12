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
    // cin >> tt;
    while(tt--){
        ll n, i, a[100005], mx=0, ans=10000000000009;
        string s;
        cin >> n;
        ffr(i,0,n){
            cin >> a[i];
            mx = maxx(mx,a[i]);
        }
        sort(a,a+n);
        
        ffr(i,1,400000){
            ll j=0;
            ll temp = 0, cur=1;
            while(j<n){
                if(cur>1000000000009) break;
                temp += abs(cur-a[j]);
                cur*=i;
                
                j++;
            }
            //cout << temp << endl;
            if(j==n)
            ans = minn(ans, temp);
            else break;
        }
        cout << ans << endl;
        
    }
}
