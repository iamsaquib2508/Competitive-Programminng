#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;

//a1 a2   c1 c2    xxxx
//b1 b2   d1 d2    yyyy

//ccw rot:
// cost  -sint
// sint   cost

double a1, a2, b1, b2, c1, c2, d1, d2;

void mull(double t)
{
    //c1=cos(t); c2=-sin(t);
    //d1=sin(t); d2=cos(t);


    double t1, t2, t3, t4;
    t1=a1*c1+a2*d1;
    t2=a1*c2*a2*d2;

    t3=b1*c1+b2*d1;
    t3=b1*c2+b2*d2;

    a1=t1, a2=t2, b1=t3, b2=t4;

    return;
}

void prod_res()
{
    double sx, sy;
    sx=a1*xxxx+a2*yyyy;
    sy=b1*xxxx+b2*yyyy;

    pf("%.9lf %.9lf\n", sx, sy);
}

int main()
{
    cin >> n >> q;
    cx=0, cy=0;
    ffrr(i,1,n)
    {
        cin >> x[i] >> y[i];
        cx+=x[i]; cy+=y[i];
    }
    cx/=n; cy/=n;

    curp1=1, curp2=2;
    //cur;

    a1=1, a2=0; b1=0, b2=1;

    while(q--)
    {
        cin >> com;
        if(com==1)
        {
            cin >> f >> t;
            if(f==curp1) cur=curp2;
            else cur=curp1;


        }
        else
        {
            cin >> num;
            xxxx=x[num]; yyyy=y[num];
            prod_res();
        }
    }
}
