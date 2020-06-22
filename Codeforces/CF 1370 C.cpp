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
        int n, i;
        cin >> n;
        string one="Ashishgup\n", two="FastestFinger\n", ans;
        if(n==1){
            ans=two;
        }
        else if(n==2){
            ans=one;
        }
        else if(n&1){
            ans=one;
        }
        else{
            n/=2;
            if(n&1){
                ans=two;
                for(i=3;i*i<=n;i+=2){
                    if(n%i==0){
                        ans=one; break;
                    }
                }
            }
            else{
                n/=2;
                while(n%2==0) n>>=1;
                if(n==1){
                    ans=two;
                }
                else{
                    ans=one;
                }
            }
        }
        cout << ans;
    }
}
