#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int ff(int a)
{
    if(a==1) return 1;
    if(a<=4) return 2;
    if(a<=9) return 3;
    int sq=ceil(sqrt(a));
    return sq;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int sq=ff(n), ans;
        if(n<=sq*(sq-1)) ans=sq+sq-1;
        else ans=sq+sq;
        cout << ans << endl;
    }
    return 0;
}
