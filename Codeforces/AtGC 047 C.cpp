#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    ll n, i, sum=0, ans=0, a[200005], MOD=200003;
    cin >> n;
    ffr(i,0,n){
        cin >> a[i];
        sum+=a[i];
    }
    //sum%=MOD;
    //cout << sum << endl;
    ffr(i,0,n){
        sum-=a[i];
        //if(sum<0) sum+=MOD;
        //cout << (sum*a[i])%MOD << endl;
        ans += ((sum*a[i])%MOD) ;
        cout << ans << endl;
    }
    cout << ans << endl;
    cin >> n;
}

// ? wtf
