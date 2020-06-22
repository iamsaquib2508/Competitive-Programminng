




/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




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


class numberTheory{

public:
    numberTheory(){}

    plolo extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return plolo(1LL, 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return plolo(d.yy, d.xx - d.yy * (a / b));
        }

    }

    ll modularInverse(ll a, ll n) {
        plolo ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    ll bigMod(ll a, ll n , ll m)
    {
        
        ll res=1, x=a;
        while ( n )
    	{
        	if ( n & 1 ) 
        	{
            	res = ( res * x ) % m;
        	}
        	x = ( x * x ) % m;
        	n = n >> 1;
    	}
    	return res;
    }
    
};

class vec
{
	public:
	
	double x, y;
	vec (){
	}
	vec(ld xxx, ld yyy)
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
	vec operator *(double b) const
	{
		return vec(x*b,y*b);
	}
	vec operator /(double b) const
	{
		return vec(x/b,y/b);
	}
	bool operator <(const vec b) const
	{
		return (x<b.x) || ( (x==b.x) && (y<b.y) );
	}
	void print()
	{
		pf("%.10lf %.10lf", x, y);
	}
};



ld magnitude(vec a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}



/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */


#define eps 0.000000001

int main()
{
	double R, r;
	vec op, home, ans, fin;
	cin >> R >> home.x >> home.y >> op.x >> op.y ;
	if(abs(home.x-op.x)<=eps && abs(home.y-op.y)<=eps)
	{
		vec dir; dir.x=1; dir.y=0;
		
		fin=home+dir*R;
		
		ans=(op+fin)/2.0;
		r=(magnitude(ans-op));
		ans.print(); pf(" %.10lf\n", r);
		return 0;
	}
	double dist=magnitude(home-op);
	if(dist-R>eps)
	{
		home.print(); pf(" %.10lf\n", R);
		return 0;
	}
	vec dir=(home-op);
	dir=dir/(magnitude(dir));
	
	fin=home+dir*R;
	
	ans=(op+fin)/2.0;
	r=(magnitude(ans-op));
	ans.print(); pf(" %.10lf\n", r);

	return 0;
	
}
