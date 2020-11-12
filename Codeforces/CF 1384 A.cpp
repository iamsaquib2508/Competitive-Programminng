#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
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

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int i, j, mx=0, ex='b', a[102], n;
        cin >> n;

        ffr(i,0,n){
            cin >> a[i];
            mx=maxx(mx,a[i]);
        }
        mx+=5;
        string s="", t="";
        ffr(i,0,mx) s+='a'; cout << s; cout << endl;
        ffr(i,0,n){
            t="";
            ffr(j,0,a[i]) t+=s[j];
            ffr(j,j,mx) t+=ex;
            cout << t;
            cout << "\n";
            ex++;
            if(ex>'z') ex='b';
            s=t;
        }

    }
}
