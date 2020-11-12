#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        ll n, k, got, getting, l1, l2, r1, r2, div, rem, ans=0, waste, t;
        cin >> n >> k;
        cin >> l1 >> r1;
        cin >> l2 >> r2;

        if(l1>l2){ t=l1; l1=l2; l2=t; t=r1; r1=r2; r2=t;}
        if(l2<=r1){
            if(r2>=r1){
                waste=0;
                got = r1-l2;
                getting = l2-l1 + r2-r1;
            }
            else{
                waste=0;
                got = r2-l2;
                getting = l2-l1 + r1-r2;
            }
        }
        else{
            waste=l2-r1;
            got=0;
            getting = r2-l1;
        }

        ll ans2=1e18, tomerge, temp;
        k -= got*n;
        if(k<=0)
            ans2=0;
        else{
            ffrr(tomerge,1,n){
                ans = tomerge*waste;
                if(getting*tomerge>=k) ans += k;
                else{
                    ans += (getting*tomerge);
                    temp = k - (getting*tomerge);
                    ans += (temp+temp);
                }
                //cout << ans << endl;
                ans2=minn(ans2,ans);
            }
        }
        cout << ans2 << endl;
    }
    cin >> tt;
}

/*
10 9118

201 942

504 776

ans = 8106
*/
