#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005
#define bug() cout << "hello\n"

using namespace std;

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt=1; cin >> tt;
    ll p1, p2;
    while(cin >> p1 >> p2){
        ll cn1, cn2, w1, w2;
        ll wt=0;
        ll lim = minn(cn1,p1/w1);
        ll rem = ( p1 - lim*w1 );
        ll rem2 = rem/w2
    }
}
