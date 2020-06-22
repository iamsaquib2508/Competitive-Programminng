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
    int n, m, i, j, x;
    while(cin >> n >> m)
    {
        set<int> s[n];
        int a[n][m];
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> x;
                a[i][j]=x;
                s[i].insert(x);
            }
        }
        int ans=0;
        int row=-1;
        ffr(i,0,n)
        {
            if(s[i].size()>1) row=i;
            ans^=(*s[i].begin());
        }
        if(row!=-1)
        {
            //succ
            cout << "TAK\n";

            ffr(i,0,n)
            {
                set<int>::iterator it=s[i].begin();
                int temp=(*it);

                if(i==row && ans==0) {it++; temp=(*it);}
                ffr(j,0,m)
                {
                    //cout << i << " i j " << j << endl;
                    if(a[i][j]==temp) {
                        cout << j+1 << " ";
                        break;
                    }
                }
            }
        }
        else
        {
            if(ans==0) cout << "NIE\n";
            else
            {
                cout << "TAK\n";
                ffr(i,0,n)
                {
                    int temp=(*s[i].begin());
                    ffr(j,0,m)
                    {
                        //cout << i << " i j " << j << endl;
                        if(a[i][j]==temp) {
                            cout << j+1 << " ";
                            break;
                        }
                    }
                }
            }
        }
    }
}
