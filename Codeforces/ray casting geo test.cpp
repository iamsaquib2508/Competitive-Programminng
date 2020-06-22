#include<bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pi acos(-1.0)


class pt3
{
public:
    double x, y, z;
    pt3(){}
    pt3(double xx, double yy, double zz)
    {
        x=xx; y=yy; z=zz;
    }
    pt3 operator +(const pt3 &b) const
    {
        return pt3(x+b.x,y+b.y,z+b.z);
    }
    pt3 operator -(const pt3 &b) const
    {
        return pt3(x-b.x,y-b.y,z-b.z);
    }
    pt3 operator *(const double &b) const
    {
        return pt3(x*b,y*b,z*b);
    }
    double dot(const pt3 &b) const
    {
        return x*b.x+y*b.y+z*b.z;
    }
    pt3 cross(const pt3 &b) const
    {
        return pt3(y*b.z-z*b.y, z*b.x-x*b.z, x*b.y-y*b.x);
    }
    pt3 normalize()
    {
        double val=(*this).dot(*this);
        val=sqrt(val);
        x/=val; y/=val; z/=val;
        return (*this);
    }

    inline double length() const
    {
        return sqrt(x*x+y*y+z*z);
    }
    inline double angle_2vectors(const pt3 b) const
    {
        return acos(this->dot(b)/(this->length())/b.length());
    }

    inline pt3 rotateVector(pt3 axis, double t) //vec and axis must be perpendicular
    {
        pt3 vec;
        vec = (*this);
        axis.normalize();
        pt3 perp=axis.cross(vec);
        perp=(perp*sin(t));
        vec=vec*cos(t);

        return perp+vec;
    }

    pt3 component(pt3 on)
    {
        on.normalize();
        return on*(this->dot(on));
    }
    pt3 rotateVectorNPerp(pt3 axis, double t) // ver and axis not necessarily perpendicular
    {
        pt3 vec=(*this);
        axis.normalize();
        pt3 up=(vec.cross(axis));
        up.normalize();
        pt3 on=axis.cross(up);
        on.normalize();
        on=vec.component(on);
        pt3 rem=vec-on;
        on=on.rotateVector(axis, t);
        return on+rem;
    }

    pt3 reflected(pt3 normal)
    {
        return ((*this)-normal*(2*this->dot(normal))).normalize();
    }
    void print()
    {
        cout << x << " x " << y << " y " << z << " z\n";
    }

};

inline pt3 setVector(double xx, double yy, double zz)
{ pt3 c(xx,yy,zz); return c;}


bool equalVector(pt3 a, pt3 b)
{
    if(abs(a.x-b.x)<=eps && abs(a.y-b.y)<=eps && abs(a.z-b.z)<=eps) {std::cout << "equal\n"; return true;}
    else cout << "noooooooooo\n"; return false;
}

bool parallelVector(pt3 a, pt3 b)
{
    pt3 c=a.cross(b), z(0,0,0);
    return equalVector(c, z);
}


class sphere
{
public:
    pt3 c;
    double rad;
    sphere(){}
    sphere(pt3 cc, double rr)
    {
        c=cc; rad=rr;
    }
    double intersect_ray(pt3 p, pt3 d)
    {
        p=p-c;
        d.normalize();
        double l=-(p.dot(d));
        if(l+eps<0) throw -1;
        double d2=p.dot(p)-l*l;
        if((d2-rad*rad)>eps) throw -1;
        double lin=sqrt(rad*rad-d2);
        return l-lin;
    }
    pt3 getnormal(pt3 p)
    {
        return (p-c).normalize();
    }
};

class plane
{
public:
    pt3 n, pn;
    plane(){}
    plane(pt3 nn, pt3 pp)
    {
        n=nn; pn=pp;
    }
    //n(p+td) = n.pn;
    // n.td = n.pn - n.p;
    double intersect_ray(pt3 p, pt3 d)
    {
        double unk=n.dot(d);
        if(abs(unk)<eps) throw -1;
        double t=( n.dot(pn) - n.dot(p) ) / unk ;
        if(t+eps<0) throw -1;
        return t;
    }
};

class triangle
{
public:
    pt3 a, b, c;
    triangle(){}
    triangle(pt3 aa, pt3 bb, pt3 cc)
    {
        a=aa; b=bb; c=cc;
    }
    double intersect_ray(pt3 p, pt3 d)
    {
        pt3 aa=a-b, bb=c-b;

        double sol_t;
        try{
            sol_t=(plane( (aa.cross(bb)).normalize() , b )).intersect_ray(p, d);

        }catch(int i){throw -1;}
        pt3 sol=p+d*sol_t-b;
        sol.print();
        // [ aa.x  bb.x ]   [ k1 ]      sol.x
        // [ aa.y  bb.y ]   [ k2 ]      sol.y
        double det= (aa.x*bb.y - bb.x*aa.y);
        double k1= (sol.x*bb.y - sol.y*bb.x)/det, k2= ( - sol.x*aa.y + sol.y*aa.x)/det ;

        if(eps<=k1 && k1+eps<=1 && eps<=k2 && k2+eps<=1) return sol_t;
        else throw -1;
    }
    pt3 getnormal(pt3 p)
    {
        return ((a-b).cross(c-b)).normalize();
    }
};

int main()
{
    pt3 a(0,0,0), b(1,0,0), c(0,1,0);
    pt3 p(0.001,0.001,1), dir(0,0,-1);
    triangle t(a,b,c);
    sphere s(pt3(0,0,-10), 0.5);
    try{
        //cout << ( plane(pt3(0,0,-1), pt3(0,0,0)) ).intersect_ray(p,dir) << endl;
        //cout << ( triangle(a,b,c) ).intersect_ray(p,dir) << endl;
        //(s.getnormal(pt3(0,0,.5))).print();
        cout << s.intersect_ray(p,dir) << endl;
        cout << t.intersect_ray(p,dir) << endl;
    }
    catch(int i){cout << "error\n";}

    cout << "end\n";
}
