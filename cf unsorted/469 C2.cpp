




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

using namespace std;


/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v[200002];
    int id; string s;
    bool vis[200002];
        id=0;
        mm(vis,0);
    //while(1)
    {
        cin >> s;
        int i, j, k, sz, temp, loo, z=0, on=0, idloo=0;;
        sz=s.size();
        if(s[0]!='0' || s[sz-1]!='0')
        {
            cout << "-1\n"; return 0;
        }
        
        
        ffr(i,0,sz)
        {
            if(s[i]=='0') z++;
            else on++;
        }
        if(on>z)
        {
            cout << "-1\n"; return 0;
        }
        
        loo=0;
        ffr(i,0,sz)
        {

            if(vis[i]==1) 
            {
                idloo=0; continue;
            }
            if(s[i]=='0')
            {
                idloo=0;
                v[id].pb(i);
                id++;
            }
            else
            {
                bool su2=0;
                loo=max(loo,i+1);
                ffr(j,loo,sz)
                {
                    if(s[j]=='0' && vis[j]==0)
                    {
                        loo=j+1;
                        bool su=0;
                        vis[j]=1;
                        ffr(k,idloo,id)
                        {
                            if(v[k][v[k].size()-1]<i)
                            {
                                su=1; su2=1;
                                v[k].pb(i); v[k].pb(j);
                                idloo=k;
                                break;
                            }
                        }
                        if(su==0)
                        {

                            cout << "-1\n"; return 0;
                        }
                        else break;
                    }
                    
                }
                if(su2==0)
                {
                    cout << "-1\n"; return 0;
                }
            }
        }
        cout << id << endl;
        ffr(i,0,id)
        {
            sz=v[i].size();
            cout << sz;
            ffr(j,0,sz)
            {
                cout << " " << v[i][j]+1;
            }
            cout << endl;
        }

    }
	return 0;

}
