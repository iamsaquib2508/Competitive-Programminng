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
    int T;
    while(cin >> T)
    {
        while(T--)
        {
            int k, x, y, i;
            map<int,set<int> > row, col;
            cin >> k >> k >> k;
            ffr(i,0,k)
            {
                cin >> x >> y;
                row[x].insert(y);
                col[y].insert(x);
            }
            map<int,set<int> >::iterator mapit;
            set<int>::iterator setit;
            set<int> ss;
            int ans=0, prev, cur;
            //cout << "row running\n";
            for(mapit=row.begin();mapit!=row.end();mapit++)
            {
                ss=mapit->second;
                prev=-2;
            //    cout << mapit->first << " :";
                for(setit=ss.begin();setit!=ss.end();setit++)
                {
                    cur=(*setit);
            //        cout << " " << cur;
                    if(prev+1==cur) ans++;
                    prev=cur;
                }
            //    cout << endl;
            }
            //cout << "col running\n";
            for(mapit=col.begin();mapit!=col.end();mapit++)
            {
                ss=mapit->second;
                prev=-2;
            //    cout << mapit->first << " :";
                for(setit=ss.begin();setit!=ss.end();setit++)
                {
                    cur=(*setit);
            //        cout << " " << cur;
                    if(prev+1==cur) ans++;
                    prev=cur;
                }
            //    cout << endl;
            }
            ans+=ans;
            cout << 4*k-ans << endl;
        }
    }
    return 0;
}
