



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

int a1, a2;
void andor(int andd, int orr)
{
    if(andd==0)
    {
        a1=0, a2=orr;
    }
    else if(andd==1)
    {
        if(orr==1 || orr==3)
        {
            a1=1; a2=orr;
        }
        else {a1=-1; a2=-1;}
    }
    else if(andd==2)
    {
        if(orr==2 || orr==3)
        {
            a1=2, a2=orr;
        }
        else {a1=-1; a2=-1;}
    }
    else if(andd==3)
    {
        if(orr==3)
        {
            a1=3; a2=3;
        }
        else {a1=-1; a2=-1;}
    }

    return;
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int n, i, j, nexts, next1, next2;
    int ored[100005], anded[100005];
    int due;
    vector<int> v; v.clear();

    cin >> n;
    n--;
    ffr(i,0,n)
    {
        cin >> ored[i];
    }
    ffr(i,0,n) cin >> anded[i];
    andor(anded[0], ored[0]);
    //cout << a1 << " a1 a2 " << a2 << endl;
    if(a1==-1 || a2==-1)
    {
        cout << "NO\n";
        return 0;
    }
    next1=a1; next2=a2;
    nexts=2;
    due=2;

    ffr(i,1,n)
    {
        andor(anded[i], ored[i]);
        //cout << a1 << " a1 a2 " << a2 << endl;
        if(a1==-1 || a2==-1)
        {
            cout << "NO\n";
            return 0;
        }
        if(nexts==1)
        {
            if(a1==next1)
            {
                v.pb(a2);
                next1=a2;
                nexts=1;
            }
            else if(a2==next1)
            {
                v.pb(a1);
                next1=a1;
                nexts=1;
            }
            else {cout << "NO\n"; return 0;}
        }
        else if(a1==next1 && a2==next2)
        {
            due++; nexts=2;
        }
        else if(a2==next1 && a1==next2)
        {
            due++; nexts=2;
        }

        else if(a1==next1 && a2!=next2)
        {
            ffr(j,0,due)
            {
                v.pb(next1);
                j++;
                if(j<due) v.pb(next2);
            }
            reverse(v.begin(), v.end());
            v.pb(a2); next1=a2; nexts=1; due=0;
        }
        else if(a2==next1 && a1!=next2)
        {
            ffr(j,0,due)
            {
                v.pb(next1);
                j++;
                if(j<due) v.pb(next2);
            }
            reverse(v.begin(), v.end());
            v.pb(a1); next1=a1; nexts=1; due=0;
        }
        else if(a1==next2 && a2!=next1)
        {
            ffr(j,0,due)
            {
                v.pb(next2);
                j++;
                if(j<due) v.pb(next1);
            }
            reverse(v.begin(), v.end());
            v.pb(a2); next1=a2; nexts=1; due=0;
        }
        else if(a2==next2 && a1!=next1)
        {
            ffr(j,0,due)
            {
                v.pb(next2);
                j++;
                if(j<due) v.pb(next1);
            }
            reverse(v.begin(), v.end());
            v.pb(a1); next1=a1; nexts=1; due=0;
        }
        else
        {
            cout << "NO\n"; return 0;
        }
    }
    if(v.size()==0)
    {
        ffr(i,0,due)
        {
            v.pb(next1);
            i++;
            if(i<due) v.pb(next2);
        }
    }
    int sz=v.size();
    cout << "YES\n";
    ffr(i,0,sz)
    {
        cout << v[i] << ' ';
    }
    cout << endl;



    return 0;
}
