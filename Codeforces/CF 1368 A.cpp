#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        ll a, b, n, cnt=0, t;
        cin >> a >> b >> n;

        while(1){
            if(b>n) break;
            if(a<b){
                t=a; a=b; b=t;
            }
            b+=a;
            cnt++;

        }
        cout << cnt << endl;
    }
}
