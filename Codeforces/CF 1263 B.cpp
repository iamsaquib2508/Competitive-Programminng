#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, i;
        string s;

        cin >> n ;
        map< string, set<int> > mpp;
        mpp.clear();
        ffr(i,0,n)
        {
            cin >> s;
            mpp[s].insert(i);
        }
        map< string, set<int> >::iterator it;
        string ans[10];

        int cng=0;
        set<string> used; used.clear();

        for(it=mpp.begin(); it!=mpp.end(); it++)
        {
            //int cnt=it->second.size();
            set<int>::iterator st=it->second.begin();
            s=it->first;
            ans[(*st)]=s;
            used.insert(s);
        }

        for(it=mpp.begin(); it!=mpp.end(); it++)
        {
            int cnt=it->second.size(), val;
            set<int>::iterator st=it->second.begin();
            s=it->first;
            if(cnt>1)
            {
                st++;
                for(;st!=it->second.end();st++)
                {
                    for(i=0;i<4;i++)
                    {
                        for(val=1;val<10;val++)
                        {
                            s[i]=(s[i]-'0'+val)%10+'0';
                            if(used.find(s)!=used.end())
                            {
                                s[i]=(s[i]-'0'-val+10)%10+'0';
                            }
                            else break;
                        }
                        if(val<10) break;
                    }

                    ans[(*st)]=s;
                    used.insert(s);
                    cng++;
                }
            }
        }
        cout << cng << endl;
        ffr(i,0,n)
        {
            cout << ans[i] << endl;
        }
    }
}
