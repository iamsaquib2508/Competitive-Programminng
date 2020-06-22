#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

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
    void normalize()
    {
        double val=(*this).dot(*this);
        val=sqrt(val);
        x/=val; y/=val; z/=val;
    }
};

int main()
{
    //freopen("scene.txt", "r", stdin);
    ofstream st1;
    st1.open("stage1.txt", ofstream::out);
    string line;
    while( getline(cin, line) )
    {
        //cout << line << endl;
        st1 << line << endl;
    }
    return 0;
}
