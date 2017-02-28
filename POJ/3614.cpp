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
  int C, L;
  cin >> C >> L;
  vector<PI> cows(C);//(maxSPF, minSPF)
  vector<PI>  lotions(L); //(SPF, remain)
  int tmp1, tmp2;
  REP(i,0,C)
    {
      cin >> tmp1 >> tmp2;
      cows[i] = pair<int, int>(tmp2,tmp1);
    }
  sort(cows.begin(),cows.end());
  REP(i,0,L)
    {
      cin >> tmp1 >> tmp2;
      lotions[i] = PI(tmp1,tmp2);
    }
  sort(lotions.begin(), lotions.end());
  int count = 0;
  REP(i,0,C)
    REP(j,0,L)
    {
      if (lotions[j].second > 0 && cows[i].second <= lotions[j].first && lotions[j].first <= cows[i].first)
	{
	  count++;
	  lotions[j].second--;
	  break;
	}
    }
  cout << count << endl;
  return 0;
}
