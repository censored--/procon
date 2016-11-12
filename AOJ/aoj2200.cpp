#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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

int main(void){
  int N, M, R;
  while (cin >> N >> M) 
    {
      if (N == 0 && M == 0)
	break;
      int x,y,t;
      char sl;
      vector<VI> land(N, VI(N, INT_MAX/4)), sea(N, VI(N, INT_MAX/4));
      REP(i,0,M)
	{
	  cin >> x >> y >> t >> sl;
	  if (sl == 'L') 
	    {
	      land[x-1][y-1] = t;
	      land[y-1][x-1] = t;
	    }
	  else
	    {
	      sea[x-1][y-1] = t;
	      sea[y-1][x-1] = t;
	    }
	}
      cin >> R;
      VI z(R);
      REP(i,0,R)
	{
	  cin >> z[i];
	  z[i]--;
	}
      REP(i,0,N)
	{
	  land[i][i] = 0;
	  sea[i][i] = 0;
	}
      for (int r = 0; r < N; r++)
	for (int p = 0; p < N; p++)
	  for (int q = 0; q < N; q++)
	    {
	      if (land[p][q] > land[p][r] + land[r][q])
		land[p][q] = land[p][r] + land[r][q];
	      if (sea[p][q] > sea[p][r] + sea[r][q])
		sea[p][q] = sea[p][r] + sea[r][q];
	    }
      vector<vector<ll> > dp(N, vector<ll>(R, INT_MAX/2));
      dp[0][z[0]] = 0;
      REP(i,1,R)
	  REP(j,0,N)
	      REP(k, 0, N)
		  dp[i][j] = min(dp[i][j], dp[i-1][k] + land[z[i-1]][k]+ sea[k][j] + land[j][z[i]]);
      ll min_cost = dp[R-1][0];
      REP(i, 1,R)
	min_cost = min(min_cost, dp[R-1][i]);
      cout << min_cost<<endl;
    }
}
