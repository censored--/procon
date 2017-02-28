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
    	  rank[x] += rank[y];
    	}
      else 
    	{
    	  par[x] = y;
    	  rank[y] += rank[x];
    	}	  
    }
}
     
int main(void){
  int N, K, L;
  cin >> N >> K >> L;
  VI cars(N+1, 0);
  VI trains(N+1, 0);
  VI rank(N+1,1);
  REP(i,1,N+1)
    {
      cars[i] = i;
      trains[i] = i;
    }
  REP(i,1,K+1)
    {
      ll p , q;
      cin >> p >> q;
      merge(p, q, cars,rank);
    }
  REP(i,1,L+1)
    {
      ll p , q;
      cin >> p >> q;
      merge(p, q, trains,rank);
    }
  map<PI,int> pair;
  REP(i,1,N+1)
    if (pair.find(PI(find(i,cars),find(i,trains)))!=pair.end())
      pair[PI(find(i,cars),find(i,trains))]++;
    else
      pair[PI(find(i,cars),find(i,trains))] = 1;
  REP(i,1,N+1)
    cout << pair[PI(find(i,cars),find(i,trains))] << " ";
  
  cout << endl;
}
