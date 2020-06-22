#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 300002
ll maxxx(ll a, ll b) {return (a>b)? a:b;}

using namespace std;
int n;

pii fff(ll* aa, bool inv)
{
    int i;
    ll *arr;
    if(inv)
    {
        arr=new ll [n];
        ffr(i,0,n) arr[i]=-aa[i];
    }
    else arr=aa;
    ll sum=0, ans=0;
    bool needst=1;
    int st, nd;
    ffr(i,0,n)
    {
        if(needst)
        {
            st=i; needst=0;
        }
        sum+=arr[i];
        if(sum>ans)
        {
            ans=sum;
            nd=i;
        }
        if(sum<0)
        {
            needst=1;
            sum=0;
        }
    }
    if(ans==0) return mp(0,-1);
    return mp(st,nd);
}

ll summ(ll* aa, bool inv)
{
    int i;
    ll *arr;
    if(inv)
    {
        arr=new ll [n];
        ffr(i,0,n) arr[i]=-aa[i];
    }
    else arr=aa;
    ll sum=0, ans=0;
    bool needst=1;
    int st, nd;
    ffr(i,0,n)
    {
        if(needst)
        {
            st=i; needst=0;
        }
        sum+=arr[i];
        if(sum>ans)
        {
            ans=sum;
            nd=i;
        }
        if(sum<0)
        {
            needst=1;
            sum=0;
        }
    }
    return ans;
}

int main()
{
    int x, i;
    ll a[mmxx];
    while(cin >> n >> x)
    {
        ffr(i,0,n)
        {
            cin >> a[i];
        }

        if(x==0)
        {
            pii cur=fff(a,0);
            int st=cur.first, nd=cur.second;
            ll sum=0, ans=0;
            ll put=summ(a,0);
            bool needst=1;
            int sss, nnn;
            ffr(i,st+1,nd)
            {
                if(needst)
                {
                    sss=i; needst=0;
                }
                sum-=a[i];
                if(sum>ans)
                {
                    ans=sum;
                    nnn=i;
                }
                if(sum<0)
                {
                    needst=1;
                    sum=0;
                }
            }
            ll b[n];
            ffr(i,0,n) b[i]=a[i];
            if(ans!=0)
            {
                ffrr(i,sss,nnn) b[i]=0;
                put=maxxx(put,summ(b,0));
            }

            sum=0; ans=0;
            ffr(i,0,st)
            {
                if(needst)
                {
                    sss=i; needst=0;
                }
                sum-=a[i];
                if(sum>ans)
                {
                    ans=sum;
                    nnn=i;
                }
                if(sum<0)
                {
                    needst=1;
                    sum=0;
                }
            }
            ffr(i,0,n) b[i]=a[i];
            if(ans!=0)
            {
                ffrr(i,sss,nnn) b[i]=0;
                put=maxxx(put,summ(b,0));
            }

            sum=0, ans=0;
            ffr(i,nd+1,n)
            {
                if(needst)
                {
                    sss=i; needst=0;
                }
                sum-=a[i];
                if(sum>ans)
                {
                    ans=sum;
                    nnn=i;
                }
                if(sum<0)
                {
                    needst=1;
                    sum=0;
                }
            }
            ffr(i,0,n) b[i]=a[i];
            if(ans!=0)
            {
                ffrr(i,sss,nnn) b[i]=0;
                put=maxxx(put,summ(b,0));
            }

            cout << put << endl;

        }
        else if(x<0)
        {
            pii cur=fff(a,1);
            int st=cur.first, nd=cur.second;
            ffrr(i,st,nd) a[i]*=x;
            cout << summ(a,0) << endl;
        }
        else if(x>0)
        {
            pii cur=fff(a,0);
            int st=cur.first, nd=cur.second;
            ffrr(i,st,nd) a[i]*=x;
            cout << summ(a,0) << endl;
        }
    }
    return 0;
}
