#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt=1;
    cin >> tt;
    int n;
    while(cin >> n){
        ll a[200005], i;

        ffr(i,0,n){
            cin >> a[i];
        }
        ll ans=0;
        if(n>1){
            for(i=n-2;i>=0;i--){
                while(i>=0 && a[i]<=a[i+1]) i--;
                if(i<0) break;
                ans += (a[i]-a[i+1]);
            }
        }
        cout << ans << endl;
    }
}
