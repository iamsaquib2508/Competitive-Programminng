#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> x;

            if(x==-1)
            {
                //neg++;
                m1++;
                a[i]=-1;
            }
            else if(x<0)
            {
                neg++;
                if(x<mn)
                {
                    mn=x;
                    mnindex=i;
                }
                //a[i]=-x-1;
            }
            else if(x>0)
            {
                pos++;

                if(x>mx)
                {
                    mx=x;
                    mxindex=i;
                }
                a[i]=-x-1;
            }
            else
            {
                z++;
                a[i]=-1;
                //neg++;
                //mn=min(mn,-1);
            }
        }
        if(m1+z==n)
        {
            if(n&1)
            {
                ffr(i,0,n) cout << "0 "; cout << endl;
            }
            else
            {
                ffr(i,0,n) cout << "-1 "; cout << endl;
            }
        }
        else
        {
            if((m1+z)%2==0)
            {
                if(neg&1 && pos&1)
                {
                    if(mx*(-mn-1)>(-mx-1)*mn)
                    {
                        a[mxindex]=-a[mxindex]-1;
                        a[mnindex]=-a[mnindex]-1;
                    }

                }
                else if(neg&1)
                {
                    a[mxindex]=-a[mxindex]-1;
                }

            }
            else
            {
                if(neg&1==0 && pos&1==0)
                {
                    if(mx*(-mn-1)>(-mx-1)*mn)
                    {
                        a[mxindex]=-a[mxindex]-1;
                        a[mnindex]=-a[mnindex]-1;
                    }

                }
                else if(neg&1)
                {
                    a[mnindex]=-a[mnindex]-1;
                }

            }
        }
    }
}
