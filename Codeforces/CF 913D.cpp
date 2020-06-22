




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */


#define MX 200005

class info
{
    public:

    int val, tm, id;
    info(){
    }
    info(int vv, int tt, int ii)
    {
        val=vv; tm=tt; id=ii;
    }
};

bool cmp(info a, info b)
{
    return (a.tm<b.tm) || (a.tm==b.tm && a.val>b.val) || (a.tm==b.tm && a.val==b.val && a.id<b.id);
}

int n, T;
info v[MX];


bool possible(int k)
{
    int taken=0, s=0, i;
    //cout << "in k " << k;
    ffr(i,0,n)
    {
        if(s>T) return 0;
        if(taken==k) break;
        if(v[i].val<k) continue;
        taken++;
        s+=v[i].tm;
    }
    if(s>T || taken<k) return 0;
    //cout << " got 1\n";
    
    return 1;
}

//AC

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int vl, ttm, i, hi, lo, mid, ans, taken;
    cin >> n >> T;
    ffr(i,0,n)
    {
        cin >> vl >> ttm;
        v[i]=info(vl, ttm, i+1);
    }
	sort(v, v+n, cmp);
	lo=0, hi=n;
	while(hi-lo>1)
	{
	    mid=(hi+lo)/2;
	    if(!possible(mid))
	    {
	        hi=mid;
        }
        else
        {
            lo=mid;
        }
    }
    
    if(possible(hi)) ans=hi;
    else ans=lo;
    
    cout << ans << endl << ans << endl;
    taken=0;
    ffr(i,0,n)
    {
        
        if(taken==ans) break;
        if(v[i].val<ans) continue;
        taken++;
        cout << v[i].id << " ";
    }
	//fix size
    return 0;
}

/*
5 300
3 100
4 150
4 80
2 90
2 300
*/
