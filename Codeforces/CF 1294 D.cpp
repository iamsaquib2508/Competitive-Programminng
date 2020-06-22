




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

int x;

int ff(int inp, int n)
{

    int temp;
    if(n>0)
    {
        if(n>=inp) temp=1+(n-inp)/x;
        else temp=0;
    }
    else if(n==0)
    {
        if(inp==0) temp=1;
        else temp=0;
    }
    return temp;

}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int q, tmp, cnt, i, mex;
    int mod[400005];
    while(cin >> q >> x)
    {
        mm(mod,0);
        mex=0;
        ffr(i,0,q)
        {
            cin >> tmp;
            tmp%=x;
            mod[tmp]++;
            while(1)
            {
                if(mex==0)
                {
                    cnt=(tmp==0);
                }
                else
                cnt=mod[mex%x] - ( ff(mex%x, mex-1) );
                //cnt=extra

                //mod[tmp]++;
                if(cnt>0) mex++;
                else break;
            }
            cout << mex << "\n";
        }
    }




    return 0;
}
