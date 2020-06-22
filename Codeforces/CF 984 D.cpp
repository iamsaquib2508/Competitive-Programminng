




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

int mm=5002;


/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */


int main()
{
    int i, j, n, q, x, prev, mul, t, cumm[mm];
    int a[mm], ans[mm][mm], brek[mm], dif, mx, l, r;
    bool v;
    cin >> n;
    prev=0;
    ffrr(i,1,n)
    {
        cin >> x;
        a[i]=x;
        prev^=x;
        cumm[i]=prev;
    }

    ffrr(i,1,n)
    {
        mul=1;
        t=i;
        while(t>0)
        {
            v=t&1; t>>=1;
            if(v) mul+=mul;
            else break;
        }
        //cout << i << " i brek[i] " << mul << endl;
        brek[i]=mul;
    }
    //ffrr(i,1,n) ans[1][i]=cumm[i];
    cumm[0]=0;
    ffrr(i,1,n)
    {

        ans[i][i]=a[i];
        ffrr(j,i+1,n)
        {
            dif=j-i;
            x=brek[dif];
            if(x>dif)
            {
                ans[i][j]=cumm[j]^cumm[i-1];
            }
            else
            {

                ans[i][j]=(cumm[i+x-1]^cumm[i-1])^(cumm[j]^cumm[j-x]);
            }
        }
    }



    ffrr(i,1,n)
    {
        mx=ans[i][i];
        ans[i][i]=mx;
        ffrr(j,i+1,n)
        {
            mx=max(mx,ans[i][j]);
            ans[i][j]=mx;
        }
    }


    for(j=n; j>0;j--)
    {
        mx=ans[j][j];
        ans[j][j]=mx;
        for(i=j-1;i>0;i--)
        {
            mx=max(mx,ans[i][j]);
            ans[i][j]=mx;
        }
    }
    /*
    cout << "ans showing\n";
    ffrr(i,1,n)
    {
        ffrr(j,1,n) cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << "start showing\n";
    ffrr(i,1,n)
    {
        ffrr(j,1,n) cout << start[i][j] << " ";
        cout << endl;
    }
    cout << "end showing\n";
    ffrr(i,1,n)
    {
        ffrr(j,1,n) cout << end[i][j] << " ";
        cout << endl;
    }
    */
    //cout << ans[1][2] << endl;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }


    return 0;
}
