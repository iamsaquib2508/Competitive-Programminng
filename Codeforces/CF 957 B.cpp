




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

    vector<int> v[502];
bool match(int i, int j)
{
    int sz=v[i].size(), k;
    if(sz!=v[j].size()) return 0;
    ffr(k,0,sz)
    {
        if(v[i][k]!=v[j][k]) return 0;
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c, rows[502], col[502], sz, i, j, k, x, tm, sz1;
    
    
    mm(rows,0); mm(col,0);
    string s;
    
    cin >> r >> c;
    ffr(i,0,r)
    {
        cin >> s;
        ffr(j,0,c)
        {
            x=s[j];
            
            if(x=='#') v[i].pb(j);
        }
        
    }
    ffr(i,0,r)
    {
        if(rows[i]==1) continue;
        rows[i]=1;
        sz1=v[i].size();
        ffr(k,0,sz1)
        {
            tm=v[i][k];
            if(col[tm]==1)
            {
                pf("No\n"); return 0;
            }
            else col[tm]=1;
        }
        ffr(j,i+1,r)
        {
            if(match(i,j))
            {
                rows[j]=1;
            }
        }
    }
    pf("Yes\n");
    //fix size
    return 0;
}
