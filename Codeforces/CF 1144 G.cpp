#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

vector<int> inc, decc;

bool incdo(int x)
{
    if(inc.size()==0) return 1;
    if(inc[inc.size()-1]<x) return 1;
    return 0;
}

bool deccdo(int x)
{
    if(decc.size()==0) return 1;
    if(x<decc[decc.size()-1]) return 1;
    return 0;
}

char ans[200005];

int main()
{
    int n, a[200005], i;
    
    inc.clear(); decc.clear();
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> a[i];
        }

        int cur, next;
        ffr(i,0,n)
        {
            cur=a[i];
            bool in=incdo(cur), decb=deccdo(cur);
            //cout << a[i] << ' ' << in << decb << endl;
            if(in && !decb)
            {
                inc.pb(cur);
                ans[i]='0';
            }
            else if(!in && decb)
            {
                decc.pb(cur);
                ans[i]='1';
            }
            else if(!in && !decb)
            {
                break;
            }
            else
            {
                if(i+1==n)
                {
                    inc.pb(cur);
                    ans[i]='0';
                }
                else
                {
                    next=a[i+1];
                    if(next>cur)
                    {
                        inc.pb(cur);
                        ans[i]='0';
                    }
                    else
                    {
                        decc.pb(cur);
                        ans[i]='1';
                    }
                }
            }
        }
        if(i<n)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << ans[0];
            ffr(i,1,n)
            {
                cout << ' ' << ans[i];
            }
            cout << endl;
        }
        inc.clear();
        decc.clear();
    }
    return 0;
}
