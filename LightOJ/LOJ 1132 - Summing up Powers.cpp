#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
#define modd(N) ((N<<32)>>32)
using namespace std;


ull MOD = (1ll<<32);

class matrix
{
public:
    int r, c;
    ull arr[52][52];
    matrix(){}
    matrix(int rr, int cc)
    {
        r=rr; c=cc;
        int i, j;
        ffr(i,0,r) ffr(j,0,c) arr[i][j]=0;
    }

    void print()
    {
        int i, j;
        ffr(i,0,r)
        {
            ffr(j,0,c)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }

};

matrix mul(matrix a, matrix b)
{
    int i, j, p;
    ull sum;
    matrix niu(a.r, b.c);
    ffr(i,0,a.r)
    {
        ffr(j,0,b.c)
        {
            sum=0;
            ffr(p,0,a.c)
            {
                uint temp = a.arr[i][p]*b.arr[p][j];
                sum+=temp;
            }
            niu.arr[i][j]=modd(sum);
        }
    }
    return niu;
}


matrix bigMod(matrix x, ull n)
{

    matrix res;
    bool unassigned=1;
    while ( n )
    {
        if ( n & 1 )
        {
            if(unassigned) res=x;
            else res = mul(x,res) ;
            unassigned=0;
        }
        x = mul(x,x) ;
        n >>= 1;
    }
    return res;
}

ull ncr[51][51];

void fiull_ncr()
{
    int n, r; ull temp;
    mm(ncr,0);
    ncr[0][0]=1ull;
    for(n=1;n<51;n++)
    {
        ncr[n][0]=1ull;
        for(r=1;r<=n;r++)
        {
            temp=ncr[n-1][r]+ncr[n-1][r-1];
            if(temp>=MOD) ncr[n][r]=modd(temp);
            else ncr[n][r]=temp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fiull_ncr();
    int tt, cc=1; scanf("%d", &tt);

    while(tt--)
    {
        ull N, k;
        int i, j, n, r;
        scanf("%lld %lld", &N, &k);
        if(N==1) {printf("Case %d: 1\n", cc++); continue;}
        if(k==0) {printf("Case %d: %lld\n", cc++, modd(N)); continue;}
        matrix mat(k+2,k+2);
        for(i=k+1;i>0;i--)
        {
            n=k+1-i;
            for(j=k+1, r=0;j>=i;j--,r++)
            {
                mat.arr[i][j]=ncr[n][r];
            }
        }
        ffr(j,1,k+2)
            mat.arr[0][j]=mat.arr[1][j];
        mat.arr[0][0]=1ll;

        matrix final = bigMod(mat,N-1);

        ull anss=0;
        ffr(i,0,k+2) {anss+=final.arr[0][i]; }
        //while(anss>=MOD) anss-=MOD;
        printf("Case %d: %lld\n", cc++, modd(anss) );
    }
    return 0;
}
