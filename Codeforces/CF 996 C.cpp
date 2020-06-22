



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
int cn;
int a[102][102];
int n, ok;
vector<int> v;
bool tem;

void show(string s, int p)
{
    int i, j;
    cout << s << p << endl;
    ffr(i,0,4)
    {
        ffr(j,0,n)
        cout << a[i][j] << " "; cout << endl;
    }
}

void dhuk(int aa, int bb, int cc)
{
    v.pb(aa); v.pb(bb); v.pb(cc); cn++;
    //pf("%d id in i=%d j=%d\n", aa, bb, cc);
}


void rotate()
{
    int i, j, curi, curj, k;
    ffr(i,1,3)
    {
        ffr(j,0,n)
        {
            if(a[i][j]==0)
            break;
        }
        if(j<n) break;
    }
    if(i==3) return;
    curi=i;
    curj=j;

    if(curi==1)
    {
        // a[1][0]=a[1][1];
        ffr(k,curj+1,n)
        {
            a[1][k-1]=a[1][k];
            if(a[1][k]>0) dhuk(a[1][k],2,k);

        }
        a[1][n-1]=a[2][n-1];
        if(a[2][n-1]>0) dhuk(a[2][n-1],2,n);
        for(k=n-1;k>0;k--)
        {
            a[2][k]=a[2][k-1];
            if(a[2][k-1]>0) dhuk(a[2][k],3,k+1);
        }
        if(curj==0)
        {
            a[2][0]=0; return;
        }
        a[2][0]=a[1][0];
        if(a[1][0]>0) dhuk(a[1][0],3,1);
        ffr(k,1,curj)
        {
            //cout << k << " k\n";
            a[1][k-1]=a[1][k];
            if(a[1][k]>0) dhuk(a[1][k],2,k);
        }

        a[1][curj-1]=0;
    }
    else if(curi==2)
    {
        // a[1][0]=a[1][1];

        for(k=curj;k>0;k--)
        {
            a[2][k]=a[2][k-1];
            if(a[2][k-1]>0) dhuk(a[2][k],3,k+1);
        }
        a[2][0]=a[1][0];
        if(a[1][0]>0) dhuk(a[1][0],3,1);
        ffr(k,1,n)
        {
            a[1][k-1]=a[1][k];
            if(a[1][k]>0) dhuk(a[1][k],2,k);
        }
        //if(curj==n-1) return;
        if(curj==n-1)
        {
            a[1][n-1]=0; return;
        }
        a[1][n-1]=a[2][n-1];
        if(a[2][n-1]>0) dhuk(a[2][n-1],2,n);
        for(k=n-1;k>curj+1;k--)
        {
            //cout << k << " k\n";
            a[2][k]=a[2][k-1];
            if(a[2][k-1]>0) dhuk(a[2][k],3,k+1);
        }

        a[2][curj+1]=0;

    }


}

void check()
{
    //curi=spi; curj=spj;
    tem=0;
    int i, j;
    ffr(j,0,n)
    {
        if(a[1][j]>0 && a[1][j]==a[0][j])
        {
            v.pb(a[1][j]);
            v.pb(1);
            v.pb(j+1);
            a[1][j]=0;
            cn++;
            ok++;
            tem=1;
        }
    }
    ffr(j,0,n)
    {
        if(a[2][j]>0 && a[2][j]==a[3][j])
        {
            v.pb(a[2][j]);
            v.pb(4);
            v.pb(j+1);
            a[2][j]=0;
            cn++;
            ok++;
            tem=1;
        }
    }
    //cout << cn << " cn\n";
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int i, j, id, kkk, done;
    cin >> n >> kkk;
    ok=0;
    i=0;
    ffr(j,0,n)
    {
        cin >> a[i][j];
    }
    ffr(i,1,3)
    {
        ffr(j,0,n)
        {
            cin >> a[i][j];
            if(a[i][j]==0)
            {
                //spi=i; spj=j;
            }
        }
    }
    ffr(j,0,n)
    {
        cin >> a[i][j];
    }
    done=0;
    cn=0;
    check();
    while(1)
    {
        if(done>20000) break;
        if(ok==kkk) break;

        rotate();
        //show("rotated ", ok);
        check();
        //show("checked ", ok);
        done++;
    }
    ffr(i,1,3)
    {
        ffr(j,0,n)
        {
            if(a[i][j])
            {
                cout << "-1\n"; return 0;
            }
        }
    }

    cout << cn << endl;
    id=0;
    ffr(i,0,cn)
    {
        cout << v[id] << " " << v[id+1] << " " << v[id+2] << endl;
        id+=3;
    }







    return 0;
}
