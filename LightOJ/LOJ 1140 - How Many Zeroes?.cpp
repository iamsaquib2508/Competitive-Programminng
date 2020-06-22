#include <bits/stdc++.h>
#define ll int64_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define plolo pair<ll,ll>
#define mp make_pair

using namespace std;

string S;
int limit;
plolo arr[18][2];
ll poww[20];

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

plolo f(int pos, bool freee){
    if(arr[pos][freee].first!=-1) return arr[pos][freee];
    if(pos+1==limit) {
        if(freee) return mp(1,10);
        else return mp(1, S[pos]-'0'+1);
    }
    // the recurrence relations are pretty much self explanatory
    ll ans=0, num=0; plolo temp;
    int digit=S[pos]-'0';
    if(freee){
        ans=9*f(pos+1,1).first+ (f(pos+1,1).first+f(pos+1,1).second);
        num=9*f(pos+1,1).second+ (f(pos+1,1).second);
    }

    else if(digit==0){
        //   currentplace 0
        ans=  f(pos+1,0).first+f(pos+1,0).second;
        num=  f(pos+1,0).second;
    }
    else{
        // currentplace 1,2,...d-1       currentplace 0                      currentpalce d
        ans=(digit-1)*f(pos+1,1).first+ (f(pos+1,1).first+f(pos+1,1).second)+ f(pos+1,0).first;
        num=(digit-1)*f(pos+1,1).second+ (f(pos+1,1).second)+ f(pos+1,0).second;
    }
    //printf("%d pos %d freee : %lld ans %lld num\n", pos, freee, ans, num);
    return arr[pos][freee]=mp(ans,num);
}

ll extra(int len){
    ll temp=poww[len-1];
    for(int j=len-2;j>=0;j--) temp+=poww[j];
    return temp;
}

ll solve(string SS){
    mm(arr,-1);
    S=SS;
    limit=S.size();
    ll a=f(0,0).first, temp=extra(limit);
    //cout << a << ' ' << temp << endl;
    //cout << f(0,0).second << endl;
    return a-temp;
}

int main()
{
    ll j, put=1, temp, temp2;
    ffr(j,0,18) {
        poww[j]=put; put*=10;
    }
    int tt, cc=1; cin >> tt;
    while(tt--){
        string N, M;
        cin >> N >> M;
        ll ans = solve(M)-solve(N);

        for(char aa: N) if(aa=='0') ans++;
        printf("Case %d: %lld\n", cc++, ans);
        //cout << ans << endl;
    }
}
