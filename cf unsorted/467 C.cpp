




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


class numberTheory
{

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

	ld x, y;
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
	vec operator *(ld b) const
	{
		return vec(x*b,y*b);
	}
	vec operator /(ld b) const
	{
		return vec(x/b,y/b);
	}
	bool operator <(const vec b) const
	{
		return (x<b.x) || ( (x==b.x) && (y<b.y) );
	}
	void print()
	{
		pf("x=%.15Lf y=%.15Lf\n", x, y);
	}
};

class line
{
	public:
	vec f, dir;
	line(){
	}
	line(vec ff, vec dirr)
	{
		f=ff, dir=dirr;
	}
};


ld magnitude(vec a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

ld dot(vec a, vec b)
{
	return (a.x*b.x+a.y*b.y);
}

ld cross2D(vec a, vec b)
{
	return (a.x*b.y-a.y*b.x);
}


vec rotate_CCWnT(vec a, ld t)
{
	return vec(a.x*cos(t)-a.y*sin(t), a.x*sin(t)+a.y*cos(t));
}

ld intersect1(line a, line b)
{
	ld temp=b.dir.x*a.dir.y-a.dir.x*b.dir.y;
	ld temp2=b.dir.x*(b.f.y-a.f.y)-b.dir.y*(b.f.x-a.f.x);
	return temp2/temp;
}



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

double good, bad;
double k, d, t, onspeed, offspeed, unit;

double ff(double tt)
{
	double ans;
	if(good*onspeed>tt)
		{
			ans=tt/onspeed;
		}
		else
		{
			double temp=tt-good*onspeed;
			ans=temp/offspeed+good;
		}
		return ans;
}


int main()
{
	//while(1)
	{

	double ans, temp, x;
	cin >> k >> d >> t;
	onspeed=1.0/t;
	offspeed=1.0/t/2.0;
		good=k;
		bad=ceil(k*1.0/d)*d-k;
	unit=good*onspeed+bad*offspeed;
	
	if(t<=good)
	{
		ans=t;
	}
	
	else if(unit>1)
	{
		ans=ff(1.0);
	}
	else
	{
		temp=floor(1.0/unit);
		x=1-temp*(unit);
		ans=temp*(good+bad)+ff(x);
	}
	cout << setprecision(15) << ans << endl;
}
	
	return 0;

}
