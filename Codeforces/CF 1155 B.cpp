#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    int n, i;
    while(cin >> n)
    {
        string s;
        cin >> s;
        int rem=n-11, cnt=0;
        int doo=rem/2;
        ffr(i,0,rem)
        {
            if(s[i]=='8') cnt++;
        }
        if(cnt<doo)
        {
            cout << "NO\n";
        }
        else if(cnt==doo && s[rem]!='8') cout << "NO\n";
        else cout << "YES\n";
    }
}
