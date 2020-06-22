#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 100005

using namespace std;

int tree[4*mmxx], a[mmxx];

void myinit(int pos, int L, int R)
{
    if(L==R)
    {
        tree[pos]=a[L];
        return;
    }
    int mid=(L+R)/2, rt=pos+pos+1, lt=pos+pos;
    myinit(lt,L,mid);
    myinit(rt,mid+1,R);
    tree[pos]=max(tree[rt],tree[lt]);
}

int query(int pos, int qL, int qR, int cL, int cR)
{
    if(qL<=cL && cR<=qR) return tree[pos];
    if(cR<qL || qR<cL) return 0;
    if(cL==cR) return tree[pos];

    int mid=(cL+cR)/2, rt=pos+pos+1, lt=pos+pos;
    int a1=query(lt,qL,qR,cL,mid);
    int a2=query(rt,qL,qR,mid+1,cR);

    return max(a1,a2);
}

int main()
{
    int T, n, i, q, l, r, cc=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n >> q;
            mm(a,0);
            mm(tree,0);
            ffrr(i,1,n) cin >> a[i];

            myinit(1,1,n);
            cout << "Case #" << cc << ":\n";
            cc++;
            while(q--)
            {
                cin >> l >> r;
                cout << query(1,l,r,1,n) << endl;
            }
        }
    }
}
