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

//Kruskal + Union-Find

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
const ll mod = 1e9 + 7;

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
  int N;
  while (cin >> N)
    {
      vector<int> par(N);
      vector<int> rank(N,0);
      for (int i =0; i < N; i++)
	par[i] = i;
      typedef pair<int,pair<int,int> > PIPII;
      vector<PIPII> c(N*N);
      for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	  {
	    int cost;
	    cin >> cost;
	    c[i*N+j] = pair<int, PI>(cost, PI(i,j));
	  }
      sort(c.begin(), c.end());
      int total_cost = 0;
      REP(i,0,N*N)
	{
	  PIPII p = c[i];
	  int cost = p.first;
	  int src = p.second.first;
	  int dest = p.second.second;
	  if (find(src,par)!=find(dest,par))
	    {
	      merge(src,dest,par,rank);
	      total_cost += cost;
	    }
	}
      cout << total_cost << endl;
    }
}
