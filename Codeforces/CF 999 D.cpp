




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

#define MX 200002
ll inp[MX], a[MX];
queue<ll> arr[MX], q;
#define bug pf("dfgdfg\n")

/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll n, m, tar, i, j, k, xxx, nnn, hand, cost=0, x, t, need, p, now;
    mm(a,0);
    ll s=0, mn=1e17;

    cin >> n >> m;
    tar=n/m;
    ffr(i,0,n)
    {
        cin >> x;
        inp[i]=x;
        t=x%m;
        arr[t].push(i);
        a[t]++;
    }
    ffr(i,0,m)
    {
        s+=a[i]-tar;
        mn=min(s,mn);
    }

    //ffr(i,0,m) cout << a[i] << endl
    cout << mn << endl;
    hand=0;
    for(i=m-1;i>=0;i--)
    {
        if(mn==0) break;
        if(a[i]==tar) continue;


        x=a[i]-tar;
        mn+=(x);
        if(a[i]<tar) continue;
        ffr(p,0,x)
        {

            xxx=arr[i].front();
            arr[i].pop();
            q.push(xxx);
        }
        hand+=x;

        //cout << hand << endl;
        cost+=(m-i)*x;
        a[i]=tar;

    }
    cost-=hand;
    cout << hand << " hand cost " << cost << endl;
    ffr(i,0,m)
    {
        //cout << "hand " << hand << " cost " << cost << endl;
        if(a[i]==tar) continue;
        if(a[i]<tar)
        {
            cost+=hand;
            need=tar-a[i];
            ffr(p,0,need)
            {
                now=q.front();
                //cout << now << endl;
                q.pop();
                nnn=inp[now];
                t=nnn%m;
                if(t<i) inp[now]+=(i-t);
                else inp[now]+=(i+m-t);

                //now=arr[i].front();

            }
            hand-=need;
        }
        else
        {

            cost+=hand;
            //cout << "cost " << cost << endl;
            x=a[i]-tar;
            ffr(p,0,x)
            {
                xxx=arr[i].front();
                arr[i].pop();
                q.push(xxx);

            }
            hand+=x;
            //bug;
        }

        //bug;
    }
    cout << cost << endl;
    ffr(i,0,n) cout << inp[i] << " ";




    return 0;
}

/*
15 5
0 0 1 1 1 1 1 3 3 3 3 4 4 4 4
15 5
1 1 1 1 1 1 1 2 2 2 2 2 2 2 2
*/
