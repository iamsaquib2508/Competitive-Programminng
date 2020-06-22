#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

vector<int> v[1003];
int ans[1003];

int query(int lo, int hi)
{
    int n=0, i, j, maxxx;
    //cout << lo << " lo hi " << hi << endl;
    if(lo==hi) return -1;
    ffr(i,lo,hi) n+=v[i].size();

    cout << "? " << n;
    ffr(i,lo,hi) ffr(j,0,v[i].size()) cout << ' ' << v[i][j];
    cout << endl;
    cin >> maxxx;
    return maxxx;
}

void ff(int lo, int hi, int maxxx, int maxot=0)
{
    int mid=(lo+hi)/2, i, maxlo, maxhi, spc=0;
    if(lo+1==hi)
    {
        ans[lo]=maxot;
        return;
    }
    maxlo=query(lo,mid);
    maxhi=query(mid,hi);

    if(maxlo==maxhi)
    {
        ffr(i,lo,hi) ans[i]=maxxx;
    }
    else
    {
        if(maxlo==maxxx)
        {
            ffr(i,mid,hi) ans[i]=maxxx;
            //if(lo+1<mid)
                ff(lo,mid,maxxx,maxx(maxhi,maxot));
        }
        else if(maxhi==maxxx)
        {
            ffr(i,lo,mid) ans[i]=maxxx;
            //if(mid+1<hi)
                ff(mid,hi,maxxx,maxx(maxlo,maxot));
        }
    }
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, k, i, j, temp, sz;
        cin >> n >> k;
        ffr(i,0,k)
        {
            cin >> sz;
            v[i].clear();
            ffr(j,0,sz) {cin >> temp; v[i].push_back(temp);}
        }

        int maxxx=query(0,k);
        ff(0,k,maxxx,0);
        cout << '!';
        ffr(i,0,k)
        {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
}
