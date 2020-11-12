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
        int n, k, i, div, rem, id, aa, bb;
        cin >> n;
        string a, b;
        vector<int> q; q.clear();
        cin >> a >> b;
        ffr(i,0,n){
            div=i/2;
            rem=i&1;
            if(!rem) id=div;
            else id=n-1-div;
            aa=a[id];
            if(rem){
                aa='0'+'1'-aa;
            }
            bb=b[n-1-i];
            if(aa==bb){
                q.pb(1);
                q.pb(n-i);
            }
            else{
                q.pb(n-i);
            }
        }
        cout << q.size();
        for(int k: q) cout << " " << k;
        cout << endl;
    }
    cin >> tt;
}
