#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define ld long double
#define pf printf
#define eps 1e-6
#define PI acos(-1.0)

using namespace std;

class vec
{
	public:
	
	ld x, y;
	vec (){
	}
	vec(ld xx, ld yy)
	{
		x=xx, y=yy;
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
		pf("x=%.21Lf y=%.21Lf\n", x, y);
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


ld findangle(vec a, vec b)
{
	ld t= dot(a,b)/magnitude(a)/magnitude(b) ; 
	ld hi=PI, lo=0, mid;
	while(hi-lo>eps)
	{
		mid=(lo+hi)/2;
		if(cos(mid)<t) hi=mid;
		else lo=mid;
	}
	return (lo+hi)/2; //acos(t)
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

ld fradius(vec dir, ld angle)
{
	return magnitude(dir)*sin(angle) ;
}

ld ft(line L, ld angle, vec Bc, ld Pr, ld hival)
{
	ld hi=hival, lo=0, mid, Nr, dis, temp=fradius(L.dir, angle), hudai;
	while(hi-lo>eps)
	{
		mid=(lo+hi)/2;
		vec Nc=L.f+L.dir*mid;
		Nr=temp*mid;
		dis=magnitude(Nc-Bc);
		if(abs(Nr+Pr-dis)<eps) break;
		if(Nr+Pr<dis) lo=mid;
		else hi=mid;
	}
	
	return (lo+hi)/2;
}

int CCW(vec a, vec b, vec c)
{
	ld tt=cross2D(c-b,a-b);
	if(tt>0) return 1;
	else if(tt<0) return -1;
	else return 0;
}


int main()
{
	//freopen("3 Circles.txt", "r", stdin);
	vec a, b, c;
	int hudai;
	while(1)
	{
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
		if(a.x==0 && a.y==0 && b.x==0 && b.y==0 && c.x==0 && c.y==0) return 0;
		cout << "edited and run from terminal\n";
		ld ABC=findangle(a-b,c-b);
		ld BCA=findangle(b-c,a-c);
		ld CAB=findangle(b-a,c-a);
		line lineb=line(b,rotate_CCWnT(c-b,ABC/2));
		line linec=line(c,rotate_CCWnT(a-c,BCA/2));
		line linea=line(a,rotate_CCWnT(b-a,CAB/2));
		
		
		ld intb= intersect1(lineb,linea);
		ld hi=intb, lo=0, mid, Ar, Br, Cr, dis, tb=fradius(lineb.dir,ABC/2);
		ld inta=intersect1(linea,lineb), intc=intersect1(linec,lineb);
		vec Ac, Bc, Cc;
		
		while(hi-lo>eps)
		{
			mid=(lo+hi)/2;
			Bc=lineb.f+lineb.dir*mid;
			Br=mid*tb;
			Ac=linea.f+ linea.dir* (ft( linea, CAB/2, Bc, Br, inta ));
			Cc=linec.f+ linec.dir* (ft( linec, BCA/2, Bc, Br, intc ));
			Ar=fradius(Ac-a,CAB/2), Cr=fradius(Cc-c,BCA/2), dis=magnitude(Ac-Cc);
			if(Ar+Cr>dis) lo=mid;
			else 
			{
				if(CCW(b,Bc,Ac)>0 && CCW(b,Bc,Cc)<0) hi=mid;
				else lo=mid;
			}
		}
		mid=(lo+hi)/2;
		Bc=lineb.f+lineb.dir*mid;
		Br=mid*tb;
		Ac=linea.f+ linea.dir* ft( linea, CAB/2, Bc, Br, inta );
		Cc=linec.f+ linec.dir* ft( linec, BCA/2, Bc, Br, intc );
		Ar=fradius(Ac-a,CAB/2), Cr=fradius(Cc-c,BCA/2);
		pf("%.9Lf %.9Lf %.9Lf\n", Ar, Br, Cr);
	}
	return 0;
}

