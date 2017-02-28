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

int main(void){
  ll L, N, M;
  scanf("%lld%lld%lld",&L, &N, &M);
  VL D(N+2);
  for (int i = 1; i <= N; i++)
    scanf("%lld",&D[i]);
  D[0] = 0;
  D[N+1] = L;
  sort(D.begin(),D.end());
  ll lb = 0;
  ll ub = L;
  ll max_min_distance = 0;
  //debugprint(D,N+2);
  while (lb <= ub)
    {
      ll min_distance = (lb+ub)/2;
      bool fail = false;
      ll m = 0;
      //cout << min_distance << endl;
      ll s = 0;
      for (int i = 1; i <= N+1; i++)
	{
	  //cout << "D["<<i+s<<"]-" << "D["<<i<<"]=" <<D[i+s]-D[i]<<endl;
	  if (D[i]-D[s]<min_distance)
	    m++;
	  else
	    s = i;
	}
      if (m > M)
	fail = true;
      //cout << "max_min_distance"<<max_min_distance<<endl;
      if (fail)
	{
	  ub = min_distance-1;
	}
      else
	{
	  max_min_distance = max(max_min_distance, min_distance);
	  lb = min_distance+1;
	}
    }
  printf("%lld\n",max_min_distance);
  return 0;
}
