#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
const ll mod = 1e9 + 7;

//Union-Find tree

int find(int i, vector<int> &par)
{
  if (par[i] == i)
    return i;
  else
    return par[i] = find(par[i], par);
}

void merge(int i, int j, vector<int> &par, vector<int> &rank)
{
  int x = find(i,par);
  int y = find(j,par);
  if (x != y) 
    {
      if (rank[x] > rank[y]) 
	{
	  par[y] = x;
	  rank[x]++;
	}
      else 
	{
	  par[x] = y;
	  rank[y]++;
	}	  
    }
}

int main(void){
  ios_base::sync_with_stdio(false);
  int N, d;
  cin >> N >> d;
  vector<PI> coord(N+1);
  vector<set<int> > adj(N+1,set<int>());
  vector<int> par(N+1);
  vector<bool> repaired(N+1, false);
  vector<int> rank(N+1,0);
  REP(i,1,N+1)
    {
        int x, y;
	cin >> x >> y;
	coord[i] = PI(x,y);
	par[i] = i;
    }
  char op;
  REP(i,1,N+1)
    REP(j,1,N+1)
    {
      if (i!=j && pow(coord[i].first-coord[j].first,2)+pow(coord[i].second-coord[j].second,2) <= pow(d,2))
	{
	  adj[i].insert(j);
	  adj[j].insert(i);
	}
    }
  while (cin >> op)
    {
      int arg1, arg2;
      switch(op)
	{
	case 'O':
	  cin >> arg1;
	  repaired[arg1] = true;
	  REP(i,1,N+1)
	    for (set<int>::iterator j = adj[i].begin(); j != adj[i].end(); j++) 
	      {
	      if (find(*j, par) != find(i, par) && repaired[i] && repaired[*j])
		merge(i,*j,par,rank);
	      }
	  break;
	case 'S':
	  cin >>arg1 >> arg2;
	  if (repaired[arg1] && repaired[arg2] && find(arg1,par) == find(arg2, par))
	    cout << "SUCCESS"<<endl;
	  else
	    cout << "FAIL"<<endl;
	  break;
	default:
	  break;
	}
    }
}
