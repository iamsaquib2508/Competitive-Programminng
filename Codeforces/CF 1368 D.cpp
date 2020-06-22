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
    int n;
    while(cin >> n){
        int x, i, j;
        ll cur, ans=0;
        vector<int> v[20];

        ffr(i,0,n){
            cin >> x;
            ffr(j,0,20){
                v[j].pb(x&1); x>>=1;
            }
        }
        ffr(j,0,20){
            sort(v[j].begin(),v[j].end(),greater<int>());
        }
        ffr(i,0,n)
        {
            cur=0;
            ffr(j,0,20){
                cur<<=1;
                cur|=v[19-j][i];
            }
            ans+=(cur*cur);
        }
        cout << ans << endl;
    }
}
