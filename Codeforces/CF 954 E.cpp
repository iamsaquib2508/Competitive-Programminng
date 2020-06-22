




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

class node
{
    public:
    double a, t;
    node(){
    }
    node(int aaa, int ttt)
    {
        a=aaa*1.0, t=ttt*1.0;
    }
};

bool cmp(node aaaa, node bbbb)
{
    return aaaa.t<bbbb.t;
}

#define MX 200005
#define eps 1e-12

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, T, i, j, aa[MX], tt[MX], lo, hi, sz;
    double ans=0, mn, sm, bg, x;
    bool chotopaisi=0, boropaisi=0;
    
    cin >> n >> T;
    ffr(i,0,n)
    {
        cin >> aa[i];
    }
    ffr(i,0,n)
    {
        cin >> x;
        tt[i]=x;
        if(x<T) chotopaisi=1;
        else if(x>T) boropaisi=1;
        else ans+=aa[i];
    }
    
    if( !chotopaisi || !boropaisi)
    {
        cout << setprecision(15) << ans << endl;
        return 0;
    }
    
    vector< node > v; v.clear();
    
    ffr(i,0,n)
    {
        if(tt[i]==T)
        {
            continue;
        }
        else
        {

            v.pb(node(aa[i], tt[i]));
            
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    sz=v.size();
    i=0;
    while(i<sz)
    {
        if(v[i].t<T) i++;
        else
        {
            lo=i-1; hi=i; break;
        }
    }
    //cin >> i;
    for(i=lo, j=hi; i>=0 && j<sz; )
    {
        if(v[i].a<eps)
        {
            i--; continue;
        }
        if(v[j].a<eps)
        {
            j++; continue;
        }
        
        sm=T-v[i].t; bg=v[j].t-T;
        
        mn=min( (v[i].a*1.0/bg), (v[j].a*1.0/sm) );
        
        ans+= ( (bg+sm)*mn );
        //cout << mn << endl;
        //cin >> n;
        
        v[i].a-=bg*mn; v[j].a-=sm*mn;
        
        
    }
    
    cout << setprecision(15) << ans << endl;
    
    //fix size
    return 0;
}
