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

ll RR, GG, BB, dp[201][201][201];
vector<ll> R, G, B;

ll call(int rpos, int gpos, int bpos){
    if((rpos==RR && gpos==GG) || (bpos==BB && gpos==GG) || (rpos==RR && bpos==BB)){
        return 0;
    }
    else{
        if(rpos==RR){
            return dp[rpos][gpos][bpos] = call(rpos,gpos+1,bpos+1)+B[bpos]*G[gpos];
        }
        else if(gpos==GG){
            return dp[rpos][gpos][bpos] = call(rpos+1,gpos,bpos+1)+B[bpos]*R[rpos];
        }
        else if(bpos==BB){
            return dp[rpos][gpos][bpos] = call(rpos+1,gpos+1,bpos)+G[gpos]*R[rpos];
        }
    }
    if(dp[rpos][gpos][bpos]!=-1) return dp[rpos][gpos][bpos];

    ll a1 = call(rpos+1,gpos+1,bpos)+G[gpos]*R[rpos];
    ll a2 = call(rpos,gpos+1,bpos+1)+G[gpos]*B[bpos];
    ll a3 = call(rpos+1,gpos,bpos+1)+B[bpos]*R[rpos];
    return dp[rpos][gpos][bpos] = maxx(maxx(a1,a2),a3);
}

int main(){
    int tt=1;
    //cin >> tt;

    while(cin >> RR >> GG >> BB){
        ll i, x;
        R.clear(); G.clear(); B.clear();
        ffr(i,0,RR){
            cin >> x;
            R.pb(x);
        }

        ffr(i,0,GG){
            cin >> x;
            G.pb(x);
        }
        ffr(i,0,BB){
            cin >> x;
            B.pb(x);
        }
        sort(R.rbegin(),R.rend());
        sort(B.rbegin(),B.rend());
        sort(G.rbegin(),G.rend());

        mm(dp,-1);
        //cout << "hello\n";
        cout << call(0,0,0) << endl;
    }
}
