




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



class vec
{
	public:

	ll x, y;
	vec (){
	}
	vec(ll xxx, ll yyy)
	{
		x=xxx, y=yyy;
	}
	vec operator +(const vec b) const
	{
		return vec(x+b.x,y+b.y);
	}
	vec operator -(const vec b) const
	{
		return vec(x-b.x,y-b.y);
	}
	vec operator *(ll b) const
	{
		return vec(x*b,y*b);
	}
	vec operator /(ll b) const
	{
		return vec(x/b,y/b);
	}
	bool operator <(const vec b) const
	{
		return (x<b.x) || ( (x==b.x) && (y<b.y) );
	}
	
};


vector<int> v;


bool ch(vec a, vec b)
{
    if(a.x*b.y==a.y*b.x) return 1;
    return 0;
}

vec a[100005];

bool checkin()
{
    int sz, i;
    sz=v.size();
    if(sz<3) return 1;
    vec cur, df;
    df=a[v[1]]-a[v[0]];
    ffr(i,2,sz)
    {
        cur=a[v[i]]-a[v[0]];
        if(!ch(cur,df)) return 0;
    }
    return 1;
}

int main()
{
    vec cur, df, aa, bb, cc;
    int i, n;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> a[i].x >> a[i].y;
    }
    if(n<5) cout << "YES\n";
    else
    {
        aa=a[0];
        bb=a[1];
        cc=a[2];
        df=bb-aa;
        ffr(i,0,n)
        {
            cur= a[i]-aa;
            if(ch(cur,df)) continue;
            else v.pb(i);
        }
        
        if(checkin())
        {
            cout << "YES\n"; return 0;
        }
        else
        {
            v.clear(); df=cc-aa;
        }
        ffr(i,0,n)
        {
            cur= a[i]-aa;
            if(ch(cur,df)) continue;
            else v.pb(i);
        }
        if(checkin())
        {
            cout << "YES\n"; return 0;
        }
        else
        {
            v.clear(); df=cc-bb;
        }
        ffr(i,0,n)
        {
            cur= a[i]-bb;
            if(ch(cur,df)) continue;
            else v.pb(i);
        }
        if(checkin())
        {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }
    return 0;
}
