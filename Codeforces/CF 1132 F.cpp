#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    string s;
    int zz;
    while(cin >> zz >> s)
    {
        int i=0, sz=s.size();
        string t="";
        while(i<sz)
        {
            int cur=i;
            while(cur<sz && s[cur]==s[i])
            {
                i++;
            }
            t+=s[cur];
        }
        sz=t.size();
        int mlim=sz, j;
        stack<int> inext, limnext;
        int ans=sz;
        ffr(i,0,sz)
        {
            char cur=t[i];
            if(i==mlim)
            {
                mlim=limnext.top();
                limnext.pop();
                i--;
                continue;
            }
            ffr(j,i+1,mlim)
            {
                if(t[j]==cur)
                {
                    ans--;
                    limnext.push(mlim);
                    mlim=j;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
