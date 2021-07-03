#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
#define ll long long int
using namespace std;
    
int main()
{
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        ll n, x, i, sum=0, mx=0, a[100005];
        cin >> n >> x;
        ffr(i,0,n){
            cin >> a[i];
            sum += a[i];
            mx += a[i]/x + (a[i]%x > 0);
        }
        sum = sum/x + (sum%x>0);
        cout << sum << ' ' << mx << endl;
    }
}