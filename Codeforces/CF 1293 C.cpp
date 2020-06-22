#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

bool a[2][100003];

int getnum(int cc)
{
    return a[0][cc]*2+a[1][cc];
}

int main()
{
    int n, q, i, hi, rr, cc;
    while(cin >> n >> q)
    {
        set<int> f[4]; ffr(i,0,4) f[i].clear();

        ffr(i,0,n) f[0].insert(i);

        int num, cur, prenum;
        set<int>::iterator it;

        mm(a,0);
        while(q--)
        {
            cin >> rr >> cc; rr--; cc--;

            prenum=a[0][cc]*2+a[1][cc];
            f[prenum].erase(cc);
            if(a[rr][cc]) //good
            {
                if(rr==0) num=prenum-2;
                else num=prenum-1;
                a[rr][cc]=0;

                //
                if(cc==n-1)
                {
                    if(nop.find(cc)!=nop.end()) nop.erase(cc);
                }
                else if(cc==0)
                {
                    //if(nop.find(cc)!=nop.end()) nop.erase(cc);
                }
                else
                {
                    int temp=getnum(cc-1);
                    if(temp==2)
                    {
                        if(num==1 || num==3) nop.erase(cc);
                    }
                }

                //

            }
            else
            {
                if(rr==0) num=prenum+2;
                else num=prenum+1;
                a[rr][cc]=1;

                //
                //
            }
            f[num].insert(cc);
            //cout << num << endl;


            if(a[1][0]) cur=1;
            else cur=0;
            //cout << cur;
            hi=0;
            while(hi<n)
            {

                //if(f[3].find(hi+1)!=f[3].end()) break;
                int arr[4];
                ffr(i,0,4)
                {
                    if(i==cur) continue;
                    it=f[i].upper_bound(hi);
                    if(it!=f[i].end())
                        arr[i]=(*it);
                    else arr[i]=n+i;
                }

                if(cur==1)
                {
                    if(arr[0]<arr[2] && arr[0]<arr[3])
                    {
                        hi=arr[0]; cur=0;
                    }
                    else break;
                }
                else if(cur==2)
                {
                    if(arr[0]<arr[1] && arr[0]<arr[3])
                    {
                        hi=arr[0]; cur=0;
                    }
                    else break;
                }
                else //cur=0
                {
                    if(arr[3]<arr[1] && arr[3]<arr[2]) break;
                    else if(arr[2]<arr[1])
                    {
                        hi=arr[2]; cur=2;
                    }
                    else {hi=arr[1]; cur=1;}
                }
            }

            if(hi>=n-1) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
