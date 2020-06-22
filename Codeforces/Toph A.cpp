#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mx 100005

using namespace std;

struct info {
    int prop, sum;
} tree[mx * 4], tree2[mx * 4];

int a[mx];

void myinit(int pos, int L, int R)
{
    if(L==R)
    {
        tree[pos].sum=0;
        tree[pos].prop=0;
        return;
    }
    int mid=(L+R)/2, rt=pos+pos+1, lt=pos+pos;
    myinit(lt,L,mid);
    myinit(rt,mid+1,R);
    tree[pos].sum=(tree[rt].sum+tree[lt].sum);
    tree[pos].prop=0;
}

void update(int pos, int cL, int cR, int i, int j)
{
    if (i > cR || j < cL)
        return;
    if ( i <= cL && cR <= j)
    {
        tree[pos].sum += (cR - cL + 1);
        tree[pos].prop++ ;
        return;
    }
    int lt = pos+pos;
    int rt = lt + 1;
    int mid = (cR + cL) / 2;
    update(lt, cL, mid, i, j);
    update(rt, mid+1, cR, i, j);
    tree[pos].sum = tree[lt].sum + tree[rt].sum + (cR - cL + 1) * tree[pos].prop;
}

int ff(int pos, int cL, int cR, int i, int j, int carry = 0)
{
    if (i > cR || j < cL)
        return 0;

    if (i <= cL and cR <= j)
        return (tree[pos].sum + carry * (cR - cL + 1));

    int Left = pos << 1;
    int Right = Left + 1;
    int mid = (cL + cR) >> 1;

    int p1 = ff(Left, cL, mid, i, j, carry + tree[pos].prop);
    int p2 = ff(Right, mid + 1, cR, i, j, carry + tree[pos].prop);

    return (p1 + p2);
}

void myinit2(int pos, int L, int R)
{
    if(L==R)
    {
        tree2[pos].sum=0;
        tree2[pos].prop=0;
        return;
    }
    int mid=(L+R)/2, rt=pos+pos+1, lt=pos+pos;
    myinit2(lt,L,mid);
    myinit2(rt,mid+1,R);
    tree2[pos].sum=(tree2[rt].sum+tree2[lt].sum);
    tree2[pos].prop=0;
}

void update2(int pos, int cL, int cR, int i, int j)
{
    if (i > cR || j < cL)
        return;
    if ( i <= cL && cR <= j)
    {
        tree2[pos].sum += (cR - cL + 1);
        tree2[pos].prop++;
        return;
    }
    int lt = pos+pos;
    int rt = lt + 1;
    int mid = (cR + cL) / 2;
    update2(lt, cL, mid, i, j);
    update2(rt, mid+1, cR, i, j);
    tree2[pos].sum = tree2[lt].sum + tree2[rt].sum + (cR - cL + 1) * tree2[pos].prop;
}

int ff2(int pos, int cL, int cR, int i, int j, int carry = 0)
{
    if (i > cR || j < cL)
        return 0;

    if (i <= cL and cR <= j)
        return (tree2[pos].sum + carry * (cR - cL + 1));

    int Left = pos << 1;
    int Right = Left + 1;
    int mid = (cL + cR) >> 1;

    int p1 = ff2(Left, cL, mid, i, j, carry + tree2[pos].prop);
    int p2 = ff2(Right, mid + 1, cR, i, j, carry + tree2[pos].prop);

    return (p1 + p2);
}

int n;

int resp(int aa)
{
    int od=ff(1,1,n+1,aa,n+1);
    int ev=ff2(1,1,n+1,aa,n+1);
    //cout << aa << " aa (l or r+1) : " << od << " odd even " << ev << endl;

    int k=n-aa+1;
    int cur=((k%2==1)?1:2)%3;
    int ret=a[aa];
    if(aa&1)
    {
        ret+=od*cur+ev*(3-cur); ret%=3;
    }
    else ret+=ev*cur+od*(3-cur); ret%=3;;
    //cout << ret << " ret\n";
    return ret;
}

int by2(int z)
{
    if(z==0) return 0;
    return 3-z;
}

int main()
{
    while(cin >> n)
    {
        string s;
        cin >> s;
        int rem=0, i, q, l, r, tp;
        a[n+1]=0;
        int mul=2;
        for(i=n-1;i>=0;i--)
        {
            mul=3-mul;
            rem=(mul*(s[i]-'0'))+rem;
            while(rem>=3) rem-=3;
            a[i+1]=rem;
        }
        myinit(1,1,n+1);
        myinit2(1,1,n+1);
        //ffrr(i,1,n) cout << a[i] << ' ';
        cin >> q;
        while(q--)
        {
            cin >> tp;
            if(tp==1)
            {
                cin >> l;
                l++;
                if(s[l-1]=='0')
                {
                    s[l-1]='1';
                    if(l&1) update(1,1,n+1,l,l);
                    else update2(1,1,n+1,l,l);
                }
            }
            else
            {
                cin >> l >> r;
                l++; r++;

                int a1=resp(l);
                int a2=resp(r+1);
                //cout << a1 << " a1 a2 " << a2 << endl;
                int k=n-r, ans;
                if(k&1) ans=by2((a1-a2+3)%3);
                else ans=(a1-a2+3)%3;
                cout << ans << endl;
            }
        }
    }
    return 0;
}
