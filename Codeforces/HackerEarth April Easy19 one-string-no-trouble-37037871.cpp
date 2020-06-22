#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define max(q,w) (q<w)? w:q
#define min(q,w) (q>w)? w:q

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        int i, sz=s.size(), len=0, ans=0;
        char prev=1, cur;
        ffr(i,0,sz)
        {
            cur=s[i];
            if(cur!=prev)
            {
                len++;
                prev=cur;
            }
            else
            {
                ans=max(ans,len);
                len=1;
                prev=cur;
            }
        }
        //len++;
        ans=max(ans,len);
        cout << ans << endl;
    }
}
