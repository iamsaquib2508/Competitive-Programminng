#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    string s, t;
    int i, a0, a1, ans;
    int ss[2], tt[2];
    int inf=100000000;
    while(cin >> s >> t)
    {
        // problem statement misunderstood



        mm(ss,0); mm(tt,0);

        for(char c:s)
        {
            ss[c-'0']++;
        }
        for(char c:t)
        {
            tt[c-'0']++;
        }
        if(tt[0]==0) a0=inf;
        else a0=ss[0]/tt[0];
        if(tt[1]==0) a1=inf;
        else a1=ss[1]/tt[1];
        ans=min(a0,a1);
        ffr(i,0,ans)
        {
            cout << t;
        }
        ss[0]-=ans*tt[0];
        ss[1]-=ans*tt[1];
        ffr(i,0,ss[0]) cout << '0';
        ffr(i,0,ss[1]) cout << '1';
        cout << endl;
    }
    return 0;
}
