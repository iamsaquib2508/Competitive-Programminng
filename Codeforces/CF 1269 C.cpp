#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 100003
#define pil pair<int,ll>
#define mp make_pair

using namespace std;

char maxx(char a, char b)
{
    if(a>b) return a; return b;
}


int main()
{
    ll n, k;
    while(cin >> n >> k)
    {
        string s;
        cin >> s;
        ll cur, i, sz;
        char ans[k+3];
        mm(ans,0);
        cur=0;
        sz=s.size();
        i=k;
        while(i<sz)
        {
            //if(ans[cur]==MMAX) continue;
            if( s[i]<s[cur] )
            {
                //ans[cur]=maxx(ans[cur],)
            }
            else if(s[i]==s[cur])
            {
                ans[cur]=maxx(ans[cur],s[i]);
            }
            else
            {
                if(s[i]<'9')
                {
                    ans[cur]=maxx(ans[cur],s[i]);
                }
                else
                {
                    ans[cur]='9';
                }
            }
            cur++;
            if(cur==k) cur=0;
            i++;
            //cout << i << " ";
        }
        for(i=k-1;i>=0;i--)
        {
            if(ans[i]>s[i])
            {
                //done with this
                break;
            }
        }
        string t="";
        ffr(cur,0,i)
        {
            t+=((char) s[cur]);
        }
        //cout << t.size();
        if(i<0) i=0;
        ffr(i,i,k) t+=((char) ans[i]);

        //cout << t.size() << " sz\n";
        ll lim=n/k; cur=0;
        //cout << cur << endl;
        ffr(i,0,lim) {cout << t; cur+=t.size();}
        //cout << cur << endl;
        i=0;
        ffr(cur,cur,n) {cout << t[i]; i++;}

    }
}
