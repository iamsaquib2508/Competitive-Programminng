#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    string s; int n;
    while(cin >> n >> s)
    {
        int sz=s.size(), i;
        ll ans=0;
        ffr(i,0,sz)
        {
            char a=s[i];
            if(a=='2' || a=='4' || a=='6' || a=='8' || a=='0')
            {
                ans+=(i+1);
            }
        }
        cout << ans << endl;
    }
}
