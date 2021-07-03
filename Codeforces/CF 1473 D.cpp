#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pf printf
#define sf scanf
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int minn(int a, int b){
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

class node{
    public:
    int mx, mn, end;
    node(){}
    node(int aa, int bb, int cc){
        mx=aa, mn=bb, end=cc;
    }
    void print(){
        printf("mx %d mn %d end %d\n", mx, mn, end);
    }
};

int n;
node arr[800012];
string st;

node build(int pos, int CL, int CR)
{
	
	if(CL==CR)
	{
        int val = 1;
        if(st[CL] == '-') val = -1;
        arr[pos].mx = maxx(0,val);
        arr[pos].mn = minn(0,val);
        arr[pos].end = val;
		return arr[pos];
		
	}
	int mid=(CL+CR)/2;
	int pos2 = pos+pos;
	node lf = build(pos2,CL,mid);
	node rt = build(pos2+1,mid+1,CR);
	
    arr[pos].end = lf.end + rt.end;
    arr[pos].mx = maxx(lf.mx, lf.end + rt.mx);
    arr[pos].mn = minn(lf.mn, lf.end + rt.mn);
	return arr[pos];
}


node qr(int pos, int CL, int CR, int lo, int hi)
{
	if(lo>hi) return node(0,0,0);
	if(hi<CL || CR<lo) return node(0,0,0);
	if(lo<=CL && CR<=hi) 
	{
		return arr[pos];
	}
	
    int pos2 = pos+pos;
	int mid=(CL+CR)/2;
	
	
	node lf = qr(pos2, CL, mid, lo, hi);
	node rt = qr(pos2+1, mid+1, CR, lo, hi);
	node ans;
    ans.end = lf.end + rt.end;
    ans.mx = maxx(lf.mx, lf.end + rt.mx);
    ans.mn = minn(lf.mn, lf.end + rt.mn);

	return ans;
}


int main()
{
    int cc=1, tt;
	cin >> tt;
	while(tt--)
	{
		int q, l, r, i;
		cin >> n >> q;
		cin >> st;
        st = ' '+st;
		build(1,1,n);
		
		while(q--)
		{
			{
				cin >> l >> r;
				node lf=qr(1,1,n,1,l-1);
                // lf.print();
                node rt=qr(1,1,n,r+1,n);
                // rt.print();
                node ans;
                ans.end = lf.end + rt.end;
                ans.mx = maxx(lf.mx, lf.end + rt.mx);
                ans.mn = minn(lf.mn, lf.end + rt.mn);
                // ans.print();
                cout << ans.mx - ans.mn + 1 << endl;
			}
		}
		
	}
	return 0;
}