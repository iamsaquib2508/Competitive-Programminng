#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

class node
{
public:
    int val, id;
    node(){}
    node(int xx, int idd){val=xx; id=idd;}
};

class qq
{
public:
    int k, pos, id;
    qq(){}
    qq(int kk, int p, int i){k=kk; pos=p; id=i;}
};


bool cmp(node aa, node bb)
{
    if(aa.val<bb.val) return true;
    if(aa.val>bb.val) return false;
    if(aa.id>bb.id) return true;
    return false;
}

bool cmp2(qq a, qq b)
{
    if(a.k<b.k) return true;
    if(a.k==b.k && a.pos<b.pos) return true;
    return false;
}

bool cmp3(node aa, node bb)
{
    if(aa.id<bb.id) return true;
    return false;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int m, i, x, k, poss, ansid;
        node a[200005];
        qq q[200005];

        ffr(i,0,n)
        {
            cin >> x;
            a[i]=node(x,i);
        }
        sort(a,a+n,cmp);
        //ffr(i,0,n) cout << a[i].id << " ";

        cin >> m;
        ffr(i,0,m)
        {
            cin >> k >> poss;
            poss--;
            q[i]=qq(k,poss,i);
        }
        sort(q,q+m,cmp2);

        int ans[200005];
        ffr(i,0,m)
        {
            k=q[i].k;
            //cout << k << " ";
            poss=q[i].pos;
            ansid=q[i].id;
            //cout << poss << "\n";
            sort(a+n-k,a+n, cmp3);
            ans[ansid]=a[n-k+poss].val;
        }
        //cout << endl;
        ffr(i,0,m)
        {
            cout << ans[i] << endl;
        }
    }
}
