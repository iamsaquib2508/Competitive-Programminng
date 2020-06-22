



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
#define inf 1e15

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll i, j, sz, ans, len[200005], n, x, k, sum[200005], s;
    vector<ll> a[200005], v;
    map<ll,ll> mp;
    cin >> k;
    ffr(i,0,k)
    {
        cin >> n;
        len[i]=n;
        s=0;
        ffr(j,0,n)
        {
            cin >> x;
            //x+=10000;
            a[i].pb(x);
            s+=x;
        }
        sum[i]=s;
        ffr(j,0,n)
        {
            //sss[i].insert(s-a[i][j]);

            if(mp.find(s-a[i][j])==mp.end())
            {
                mp[s-a[i][j]]=i;
            }
            else if(mp[s-a[i][j]]==i) continue;
            else
            {
                if(v.size()==0)
                {
                    v.pb(mp[s-a[i][j]]);
                    v.pb(i);
                    ans=s-a[i][j];
                }
            }
        }
    }
    if(v.size()==0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        i=v[0];
        sz=len[i];
        ffr(j,0,sz)
        {
            if(sum[i]-a[i][j]==ans)
            {
                cout << i+1 << " " << j+1 << endl;
                break;
            }
        }
        i=v[1];
        sz=len[i];
        ffr(j,0,sz)
        {
            if(sum[i]-a[i][j]==ans)
            {
                cout << i +1 << " " << j+1 << endl;
                break;
            }
        }


    }




    return 0;
}
