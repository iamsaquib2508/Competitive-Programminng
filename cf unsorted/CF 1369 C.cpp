#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        ll n, k, i, temp;
        vector<ll> a, w;
        cin >> n >> k;
        ffr(i,0,n){
            cin >> temp;
            a.pb(temp);
        }
        sort(a.begin(),a.end());
        ll one=0, ans=0;
        ffr(i,0,k){
            cin >> temp;
            if(temp==1) one++;
            else w.pb(temp-1);
        }
        sort(w.begin(),w.end());
        ll aid, wid, curw;
        aid=n-1;
        wid=0;
        ans=0;
        ffr(i,0,one) {ans+=(a[aid]<<1); aid--;}
        one=wid;
        //aid=n-1;
        //ffr(i,0,k) ans+=a[aid];
        while(wid<w.size()){
            wid++;
            //if(curw==0) continue;

            ans+=a[aid]; aid--;
        }
        ffr(wid,0,w.size()){
            curw=w[wid];
            ffr(i,1,curw) aid--;
            ans+=a[aid]; aid--;
        }
        cout << ans << endl;
    }
}
