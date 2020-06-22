#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
using namespace std;

class matrix
{
public:
    int r, c;
    int arr[52][52];
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
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    matrix operator + (const matrix &b) const
    {
        int i, j;
        matrix niu(r,c);
        ffr(i,0,r)
        {
            ffr(j,0,c)
            {
                int temp = arr[i][j]+b.arr[i][j];
                if(temp>=10) temp-=10;
                niu.arr[i][j] = temp;
            }
        }
        return niu;
    }
    matrix operator * (const matrix &b) const
    {
        int i, j, p;
        int sum;
        matrix niu(r, b.c);
        ffr(i,0,r)
        {
            ffr(j,0,b.c)
            {
                sum=0;
                ffr(p,0,c)
                {
                    int temp = arr[i][p]*b.arr[p][j];
                    sum+=temp;
                }
                niu.arr[i][j]=sum%10;
            }
        }
        return niu;
    }
};

matrix bigMod(matrix x, int n)
{
    matrix res(x.r,x.c);
    bool unassigned=1;
    while (n>0)
    {
        if (n&1)
        {
            if(unassigned) res=x;
            else res = x*res ;
            unassigned=0;
        }
        x = x*x ;
        n >>= 1;
    }
    return res;
}

matrix func(matrix A, int k)
{
    if(k==0)
        return matrix(A.r,A.c);
    matrix ans(A.r,A.c), fn2 = func(A,k/2), ak2 = bigMod(A,k/2);
    if(k&1)
        ans=bigMod(A,k);
    return ans + fn2 + ak2*fn2;
}

/*

fn = a + a^2 + a^3 + ... a^n
   = f(n/2) + a^(n/2) . f(n/2) + (n is odd)? a^n:0

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cc=1, tt; cin >> tt;
    while(tt--)
    {
        int k, N, i, j, x;
        cin >> N >> k;
        matrix A(N,N);
        ffr(i,0,N)
        {
            ffr(j,0,N)
            {
                cin >> x;
                if(x==10) x=0;
                A.arr[i][j]=x;
            }
        }
        matrix S = func(A,k);
        cout << "Case " << cc++ << ":\n";
        S.print();
    }
}
