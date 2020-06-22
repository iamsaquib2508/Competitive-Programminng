




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

class node
{
    public:
    int id, val;
    node(){}
    node (int ii, int vv)
    {
        id=ii, val=vv;
    }
};

bool cmp(node a, node b)
{
    return a.val<b.val;
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    stack<int> st;
    int n, i, x, idd;
    char c;
    node a[200005];
    cin >> n;
    ffr(i,0,n)
    {
        cin >> x;
        a[i]=node(i,x);
    }
    sort(a,a+n,cmp);
    n+=n; idd=0;
    ffr(i,0,n)
    {
        cin >> c;
        if(c=='1')
        {
            x=st.top(); st.pop(); cout << x << " ";
        }
        else
        {
            x=a[idd].id+1;
            idd++;
            st.push(x);
            cout << x << " ";
        }

    }


    return 0;
}
