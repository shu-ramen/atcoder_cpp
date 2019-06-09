//=template==================================================================//
// include
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

// namespace
using namespace std;

// define
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(i,n) FOR(i,0,n)
#define MIN_V(v) *min_element(v.begin(), v.end())
#define MAX_V(v) *max_element(v.begin(), v.end())

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef long long LL;
typedef unsigned long long ULL;

// conversion
inline int toInt(string s) {int v; istringstream sin(s); sin>>v; return v;}
inline int countChar(string s, char c) {int cnt,i; cnt=0; REP (i,s.size()) {if (s[i]==c) cnt++;} return cnt;}
template<class T> inline string toString(T x) {ostringstream sout; sout<<x; return sout.str();}
//===========================================================================//

//=function prototype========================================================//

//===========================================================================//

//=variables=================================================================//

//===========================================================================//
int main(void)
{
  // Scan begin.
  int h, w;
  cin >> h >> w;
  VS s(h);
  REP(i, h) {
    cin >> s[i];
  }
  VVI vertical(w, VI(h));
  VVI horizontal(h, VI(w));
  // Scan done.

  // Code begin.
  REP(x,w) {
    int idx = 0;
    REP(y,h) {
      if (s[y][x] == '#') {
        FOR(i,idx,y) {
          vertical[x][i] = y - idx;
        }
        idx = y + 1;
        continue;
      }
      if (y==h-1) {
        FOR(i,idx,h) {
          vertical[x][i] = y - idx + 1;
        }
      }
    }
  }

  REP(y,h) {
    int idx = 0;
    REP(x,w) {
      if (s[y][x] == '#') {
        FOR(i,idx,x) {
          horizontal[y][i] = x - idx;
        }
        idx = x + 1;
        continue;
      }
      if (x==w-1) {
        FOR(i,idx,w) {
          horizontal[y][i] = x - idx + 1;
        }
      }
    }
  }

  int maxim = 0;
  REP(y, h) {
    REP(x,w) {
      maxim = max(maxim, vertical[x][y] + horizontal[y][x] - 1);
    }
  }

  cout << maxim << endl;
  // Code done.

  return 0;
}

//=functions=================================================================//

//===========================================================================//