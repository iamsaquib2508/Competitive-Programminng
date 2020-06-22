



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

#define MX 100000


/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

class frac
{
    public:
    ll a, b;
    frac(){
    }
    frac(ll aa, ll bb)
    {
        a=aa; b=bb;
    }
    bool operator <(const frac q) const
    {
        ll aa=a, bb=b, qa=q.a, qb=q.b;
        if(bb<0)
        {
            aa=-aa; bb=-bb;
        }
        if(qb<0)
        {
            qa=-qa; qb=-qb;
        }
        return (aa*qb<bb*qa);
    }
    void operator =(const frac q)
    {
        a=q.a; b=q.b;
        return;
    }
    void print()
    {
        cout << a << "/" << b << endl;
    }

};

ll ans;


class info
{
    public:
    int id; frac ab;
    info(){
    }
    info(int ii, frac abab)
    {
        id=ii, ab=abab;
    }
    void operator =(const info q)
    {
        id=q.id;
        ab=q.ab;
        return;
    }
};


bool cmp(info pp, info qq)
{
    //frac p=pp.ab, q=qq.ab;
    if(pp.ab<qq.ab) return 1;
    if(qq.ab<pp.ab) return 0;
    if(pp.ab.a*qq.ab.a<0)
    {
        return pp.ab.a<0;
    }
    else return pp.ab.a>qq.ab.a;

}



void msort(info* arr, int r)
{
    if(1==r) return ;

    int mid=(r)/2, i, j, k;
    msort(arr,mid);
    msort(arr+mid,r-mid);

    info *temp=new info[r];
    j=0; k=mid;

    ffr(i,0,r)
    {
        if(j==mid)
        {
            temp[i]=arr[k]; k++;
        }
        else if(k==r)
        {
            temp[i]=arr[j]; j++;
        }
        else if(arr[j].ab<arr[k].ab)
        {
            temp[i]=arr[j]; j++;
        }
        else
        {
            ans+=(mid-j);
            temp[i]=arr[k]; k++;
        }
    }
    ffr(i,0,r)
    {
        arr[i]=temp[i];
    }
}


int main()
{
    //pf("ok\n");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w, i, idd;
    ll xx, vv;
    info *a=new info[MX];
    frac *plusw=new frac[MX];
    frac minw, nfrac;
    ans=0;
    cin >> n >> w;
    ffr(i,0,n)
    {
        cin >> xx >> vv;
        minw=frac(xx,vv-w);
        //minw.print();
        a[i]=info(i,minw);
        plusw[i]=frac(xx,vv+w);
    }
    sort(a,a+n,cmp);
    ffr(i,0,n)
    {
        idd=a[i].id;
        //cout << idd << " ";
        a[i].ab=plusw[idd];
    }
    //pf("\n");
    msort(a,n);
    //ffr(i,0,n) cout << a[i].id << " "; pf("\n");

    cout << ans << endl;

    //fix size
    return 0;
}
