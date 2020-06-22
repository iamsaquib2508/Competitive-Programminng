#include<bits/stdc++.h>
#define ffr(i,a,b) for(=ia;i<b;i++)
#define ffrr(i,a,b) for(=ia;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    int a, b, c, d, ans;
    while(cin >> a >> b >> c >> d)
    {
        ans=1;
        if(a!=d || (a==d && a==0 && c>0) )
        ans=0;
        cout << ans << "\n";
    }
    return 0;
}
