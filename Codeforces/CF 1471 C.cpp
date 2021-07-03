#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
#define ll long long int
#define pb push_back
using namespace std;
    
int main()
{
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        ll n, m, i, sum=0, mx=0, c[300005], x;
        vector<ll> a;
        a.clear();
        a.pb(30000005);
        cin >> n >> m;
        ffrr(i,1,n){
            cin >> x;
            a.pb(x);
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        ffrr(i,1,m){
            cin >> c[i];
        }
        ffrr(i,1,n){
            if(a[i]>=i){
                sum += c[i];
            }
            else{
                sum += c[a[i]];
            }
        }
        cout << sum << endl;
    }
}