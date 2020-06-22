#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int i, j, k, n;
    string L, R;
    vector<int> LL[27], RR[27];

    while(cin >> n)
    {
        vector<int> ans;
        ans.clear();
        cin >> L >> R;
        ffr(i,0,27)
        {
            LL[i].clear();
            LL[i].pb(1);
            RR[i].clear();
            RR[i].pb(1);
        }
        char cur;
        ffrr(i,1,n)
        {
            cur=L[i-1];
            if(cur!='?')
            LL[cur-'a'].pb(i);
            else LL[26].pb(i);

            cur=R[i-1];
            if(cur!='?')
            RR[cur-'a'].pb(i);
            else RR[26].pb(i);
        }

        /*
        ffr(i,0,26)
        {
            cout << (char)('a'+i);
            ffr(j,1,LL[i].size()) cout << " " << LL[i][j]; cout << endl;
        }
        cout << "LL end RR start\n";
        ffr(i,0,26)
        {
            cout << (char)('a'+i);
            ffr(j,1,RR[i].size()) cout << " " << RR[i][j]; cout << endl;
        }
        */
        ffr(i,0,26)
        {
            int mn=min(LL[i].size(), RR[i].size());
            ffr(j,1,mn)
            {
                ans.pb(LL[i][j]); ans.pb(RR[i][j]);
            }
            LL[i][0]=mn;
            RR[i][0]=mn;
        }
        ffr(i,0,26)
        {
            int mn=min(-LL[i][0]+LL[i].size(), -RR[26][0]+RR[26].size());
            ffr(j,0,mn)
            {
                ans.pb(LL[i][j+LL[i][0]] );
                ans.pb(RR[26][j+RR[26][0]] );
            }
            LL[i][0]+=mn;
            RR[26][0]+=mn;
        }
        ffr(i,0,26)
        {
            int mn=min(-RR[i][0]+RR[i].size(), -LL[26][0]+LL[26].size());
            ffr(j,0,mn)
            {
                ans.pb(LL[26][j+LL[26][0]] );
                ans.pb(RR[i][j+RR[i][0]] );

            }
            RR[i][0]+=mn;
            LL[26][0]+=mn;
        }

        {
            int mn=min(-RR[26][0]+RR[26].size(), -LL[26][0]+LL[26].size());
            ffr(j,0,mn)
            {
                ans.pb(LL[26][j+LL[26][0]] );
                ans.pb(RR[26][j+RR[26][0]] );

            }
            RR[26][0]+=mn;
            LL[26][0]+=mn;
        }
        ll sz=ans.size();
        cout << sz/2 << endl;
        ffr(i,0,sz)
        {
            cout << ans[i]; i++;
            cout << ' ' << ans[i] << endl;
        }
    }
    return 0;
}
