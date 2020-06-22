#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;



int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int ttt; cin >> ttt;
    while(ttt--)
    {
        string s, t;
        cin >> s >> t;

        int i=0, ssz=s.size(), tsz, pi, id, cur;
        set<int> sett[26];
        ffr(i,0,26) {sett[i].clear(); sett[i].insert(ssz);}
        i=0;
        for(char a: s)
        {
            sett[(int)(a-'a')].insert(i);
            i++;
        }

        ssz=i;
        tsz=t.size();
        //ffr(i,0,26)
        i=0; pi=0;

        int ans=0;
        while(i<tsz)
        {
            cur=-1;
            while(cur<ssz && i<tsz)
            {
                id=t[i]-'a';
                cur=(*(sett[(int)id].upper_bound(cur)));
                //cout << cur << " cur\n";
                i++;
            }
            if(cur==ssz) i--;
            if(i>pi) {ans++; pi=i;}
            else
            {
                ans=-1; break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
