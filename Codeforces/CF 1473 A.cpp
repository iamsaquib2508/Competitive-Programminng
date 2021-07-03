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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        int i, x, n, aa, d, bb, lim;
        int a[300005];
        cin >> n >> d;
        ffr(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        if (a[n-1]<=d) {cout << "YES\n"; continue;}
        
        aa = a[0];
        bb = a[1];
        ffr(i,2,n) a[i]=aa+bb;
        if (a[n-1]<=d) {cout << "YES\n"; continue;}
        a[1]=a[0]+a[2];
        sort(a,a+n);
        if (a[n-1]<=d) {cout << "YES\n"; continue;}
        a[0]=a[1]+a[2];
        sort(a,a+n);
        if (a[n-1]<=d) cout << "YES\n";
        else cout << "NO\n";
    }
}