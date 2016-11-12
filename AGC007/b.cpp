#include <algorithm>
#include <iostream>
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

using namespace std;
typedef long long int ll;

int main(void){
  int N;
  cin >> N;
  vector<int> p(N+1);
  vector<ll> a(N+1,0),b(N+1,0),c(N+1);
  REP(i,1,N+1)
    {
      cin >> p[i];
      c[p[i]] = N+i;
    }
  a[1] = 1;
  b[1] = c[1]-1;  
  REP(i,2,N+1)
    {
      a[i] = max(a[i-1]+1,c[i] - b[i-1] + 1);
      b[i] = min(b[i-1]- 1,c[i] - a[i-1] - 1);
    }
  REP(i,1,N+1)
      b[i] += 1 - b[N];
  REP(i,1,N+1)
    cout << a[i] << " ";
  cout << endl;
  REP(i,1,N+1)
    cout << b[i] << " ";
  cout << endl;
}
