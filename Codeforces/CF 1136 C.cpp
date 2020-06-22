#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int n, m;

bool valid(int i, int j)
{
    if(i<0 || j<0 || i==n || j==m) return 0;
    return 1;
}

int main()
{
    while(cin >> n >> m)
    {
        int i, j, k;
        int a[502][502], b[502][502];
        vector<int> v1, v2;

        int ui, uj;
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> a[i][j];
            }
        }

        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> b[i][j];
            }
        }

        for(i=0;i<n;i++)
        {
            ui=i;
            for(j=0;j<m;j++,ui--)
            {
                if(valid(ui,j))
                {
                    v1.pb(a[ui][j]);
                    v2.pb(b[ui][j]);
                }
                else break;
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            ffr(k,0,j)
            {
                if(v1[k]!=v2[k]) break;
            }
            if(k<j) break;
            v1.clear();
            v2.clear();
        }
        if(i<n)
        {
            cout << "NO\n";
        }
        else
        {
            for(j=1;j<m;j++)
            {
                uj=j;
                for(i=n-1;i>=0;i--,uj++)
                {
                    if(valid(i,uj))
                    {
                        v1.pb(a[i][uj]);
                        v2.pb(b[i][uj]);
                    }
                    else break;
                }
                sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
                int sz=v1.size();
                ffr(k,0,sz)
                {
                    if(v1[k]!=v2[k]) break;
                }
                if(k<sz) break;
                v1.clear();
                v2.clear();
            }
            if(j<m)
            {
                cout << "NO\n";
            }
            else cout << "YES\n";
        }
    }
    return 0;
}
