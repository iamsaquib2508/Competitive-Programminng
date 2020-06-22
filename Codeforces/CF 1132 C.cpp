#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

class node
{
public:
    int l, r;
    node(){}
    node(int lll, int rrr)
    {
        l=lll; r=rrr;
    }

};

bool cmpt(node a, node b)
{
    if(a.l!=b.l) return a.l<b.l;
    if(a.l==b.l)
    {
        return a.r<b.r;
    }
    return false;
}


int main()
{
    while(cin >> n >> q)
    {
        ffr(i,0,q)
        {
            cin >> a[i].l >> a[i].r;
        }
        sort(a,a+q,cmpt);
        ffr(i,1,q)
        {
            if(got==2) break;
            if(a[i].l==a[i-1].l)
            {
                got++;
            }
        }
        if(got<2)
        {
            ffr(i,1,q)
            {
                if(got==2) break;
                if(a[i].r<=a[i-1].r)
                {
                    got++;
                }
            }
        }
        if(got<2)
        {
            loss[0]=a[1].l-a[0].l;
            ffr(i,1,q-1)
            {

                lim=max(a[i+1].l-a[i-1].r,0);
                my=(a[i].r-a[i-1].l,0)

                upl=max(a[i].r-a[i-1].r,0)-max(a[i].l-1-a[i-1].r,0);
                dwl=
            }
            loss[q-1]=a[n-1].r-a[q-2].r;
        }
        if(got==2)
        {
            int start=0, end=0, fakind=0;
            // if(fak[0]==0 && fak[1]==1)
            // {
            //     start=a[2].l;
            //     end=a[2].r;
            //     fakind=2;
            // }
            // else if(fak[0]==0)
            // {
            //     start=a[1].l;
            //     end=a[1].r;
            //     fakind=1;
            // }
            // else
            // {
            //     start=a[0].l;
            //     end=a[0].r;
            //     fakind=0;
            // }
            int ans=0;
            ffr(i,0,q)
            {
                if(i==fakind)
                {
                    fakind++; continue;
                }
                start=max(a[i].l,end+1);
                end=max(a[i].r,end);
                ans+=(end-start+1);

            }
        }
    }
}
