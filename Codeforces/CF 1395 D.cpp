#include <bits/stdc++.h>
#define ll int64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define pb push_back
#define xx first
#define yy second
#define mp make_pair


using namespace std;

ll dp[100005], a[100005], n, d, m;

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

ll minn(ll a, ll b){
    if(a<b) return a; return b;
}

int main(){
    int tt=1;
    while (cin >> n >> d >> m) {

        ll i, x, lim, sid=0, bigsum=0, bigsize=0, ans, cur, j;
        vector<ll> big(n+n,0), small(n+n,0);

        ffr(i,0,n){
            cin >> x;
            if(x>m){
                big[bigsize]=x;
                bigsize++;
            }
            else small[sid++]=x;
        }
        ll rem = n%(d+1), extra;

        lim = minn((n/(d+1)) + (rem>0), bigsize);
        extra = n-(lim-1)*(d+1)-1;
        //cout << lim << endl;
        sort(big.rbegin(),big.rend());
        reverse(big.begin(),big.begin()+lim);
        sort(small.rbegin(),small.rend());

        for(auto aa: big) cout << aa << ' '; cout << endl;
        for(auto aa: small) cout << aa << ' '; cout << endl;

        ffr(i,0,lim){
            bigsum+=big[i];
        }
        ans=bigsum;
        ll fixd=0;
        ffr(i,0,extra) fixd+=small[i];
        sid=i;
        cur=0;
        ffr(i,0,lim){
            bigsum-=big[i];

            ffrr(j,0,d){
                cur+=small[sid+j];
            }
            sid+=(d+1);
            ans=maxx(ans,bigsum+cur);
        }
        cout << (ans+fixd) << endl;
    }
}
