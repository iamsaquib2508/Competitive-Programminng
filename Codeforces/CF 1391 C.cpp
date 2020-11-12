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
    int tt=1;
    while(tt--){
        int n, i;
        cin >> n;
        ll ans=1, MOD=1000000007, fact=n;
        ffr(i,1,n){
            ans+=ans;
            ans%=MOD;
            fact*=i; fact%=MOD;
        }
        ll temp = (fact%MOD-ans%MOD);
        if(temp<0) temp+=MOD;
        cout << temp << endl;
    }
    cin >> tt;
}
