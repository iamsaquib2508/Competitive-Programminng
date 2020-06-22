#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;

int ax, bx, cx, dx, ay, by, cy, dy, ex, ey, fx, fy, gx, gy, hx, hy;
int x, y, xx, yy, tx, ty;
int m, mid;

bool in()
{
    int i, j, len;
    len=gx-ex;
    mid=len/2;

    ffrr(i,0,len)
    {
        m=mid-abs(i-mid);

        xx=ex+i;
        //cout << "xx " << xx << endl;
        if(xx!=x) continue;

        ffrr(j,0,m)
        {
            yy=ey+j;
            //cout << xx << " x y " << yy << endl;
            if(y==yy) return true;

            yy=ey-j;
            //cout << xx << " x y " << yy << endl;
            if(y==yy) return true;
        }
    }
    return false;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int len, i, j;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    cin >> ex >> ey >> fx >> fy >> gx >> gy >> hx >> hy;
    len=max(abs(bx-ax),abs(ay-by))+1;
    if(ey!=gy)
    {
        tx=ex, ty=ey;
        ex=fx, ey=fy;
        fx=gx, fy=gy;
        gx=hx, gy=hy;
        hx=tx, hy=ty;
    }
    if(gx<ex)
    {
        tx=ex;
        ex=gx;
        gx=tx;
    }
    //cout << ex << " ex gx " << gx << endl;
    if(ax==bx)
    {
        if(ay<by)
        {
            if(ax>dx)
            {
                ax=dx;
            }
        }
        else
        {
            if(ax<dx)
            {
                ay=by;
            }
            else
            {
                ay=by; ax=cx;
            }
        }
    }
    else
    {
        if(ay<dy)
        {
            if(ax>bx) ax=bx;
        }
        else
        {
            ay=dy;
            if(ax>bx) ax=cx;
        }
    }

    ffr(i,0,len)
    {
        x=ax+i;
        ffr(j,0,len)
        {
            y=ay+j;

            if(in())
            {
                //cout << x << y;
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}

/*
6  0 6 6 0 6 0 0
0 2 -1 1 -2 2 -1 3
*/
