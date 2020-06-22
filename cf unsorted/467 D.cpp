




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

/* ?????? ??????? ??????????? ????????? */


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

using namespace std;




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */


#define MAX 100005

vector<int> v[MAX];
vector<int> sorted;
bool cycle, vis[MAX];
int state[MAX];

void dfsv(int s)
{
	vis[s]=true;
	int i, sz=v[s].size();
	if(sz==0)
	{
			 sorted.pb(s);
			 state[s]=4;
			 return;
	}
	ffr(i,0,sz)
	{
		if(!vis[v[s][i]])
		{
			dfsv(v[s][i]);
		}
		

	}
	
	sorted.pb(s);
	return;
}

void ff(int s, int loo)
{
	cout << s ;
	int i=s, j;
	int ss=v[s].size(), next;
	if(ss>0) cout << " ";
	
	ffr(j,0,ss)
	{
		next=v[i][j];

		if(loo==0 && (state[next]==4 || state[next]==7) )
		{
			ff(next, 1);
   return;
		}
		else if(loo==1)
		{
			if( state[next]==2 || state[next]==7)
			{
				ff(next, 0);
    return;
			}

		}

	}
	ffr(j,0,ss)
	{
		next=v[i][j];

		if(loo==0 && (state[next]==5) )
		{
			ff(next, 1);
   return;
		}
		else if(loo==1)
		{
			if( state[next]==3)
			{
				ff(next, 0);
    return;
			}

		}

	}
	return;
}

 		//1 cycle
		//2 win
		//3 wd
		//4 lose
		//5 ld
		//6 7 wl   //target 0 win, 1 lose, 2 draw

int main()
{
	sorted.clear();
	int n, m, next, loop, i, j, ruti, a, sz;
	ffr(i,0,MAX) v[i].clear();
	mm(vis,0);
	mm(state,-1);
	
	cin >> n >> m;
	ffrr(i,1,n)
	{
		cin >> sz;
		ffr(j,0,sz)
		{
			cin >> a;
			v[i].pb(a);
		}
		if(sz==0) state[i]=4;
	}
	cin >> ruti;
	
	dfsv(ruti);
	sz=sorted.size(); 
	ffr(loop,0,sz)
	{
		i=sorted[loop];
		if(state[i]==4) continue;
		bool drawflag=0;
		bool loseflag=0;
		bool winflag=0;
		int ss=v[i].size();
		ffr(j,0,ss)
		{
			next=v[i][j];
			
			//pf("i %d next %d statenext %d\n", i, next, state[next]);
			if(state[next]==-1 || state[next]==3 || state[next]==5 || state[next]==1) drawflag=1;
			if( state[next]==2 || state[next]==3 || state[next]==7) winflag=1;
			if(state[next]>3) loseflag=1;
				

		}
		if(state[i]==-1) state[i]=4;
		int temp=4*winflag+2*loseflag+drawflag;
		if (temp==6) temp++;
		state[i]=temp;
		//1 cycle
		//2 win
		//3 wd
		//4 lose
		//5 ld
		//6 7 wl
		
	}
	if(state[ruti]==2 || state[ruti]==3 || state[ruti]==7)
	{
					  cout << "Win\n";
					  //target 0 win, 1 lose, 2 draw
					  ff(ruti,0);
	}
	else if(state[ruti]==1 || state[i]==5) cout << "Draw";
	else if(state[ruti]==4) cout << "Lose";
	cout << endl;
	//ffr(i,0,sz) cout << sorted[i] << " "; cout << endl;
	//ffrr(i,1,n) cout << state[i]                    << " ";
	return 0;

}
