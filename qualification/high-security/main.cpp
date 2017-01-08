#include <iostream>
typedef uint32_t u32;
typedef uint8_t u8;
using namespace std;

#define MAXN 1000
char G[2][MAXN];
u32 n;


u8
guard(u32 row, u32 x) {
  if (G[row][x] != '.') return false;

  if (G[1-row][x] != 'X')
    G[1-row][x] = 'G';

  for (u32 i = x; i > 0 && G[row][i-1] != 'X'; i--)
    G[row][i-1] = 'G';

  for (u32 i = x; i < n && G[row][i] != 'X'; i++)
    G[row][i] = 'G';

  return true;
}


u8
is_closed(u32 row, u32 x) {
  if (G[row][x] != '.') return false;
  if (x == 0) return G[row][x+1] == 'X';
  if (x == n-1) return G[row][x-1] == 'X';
  return G[row][x-1] == 'X' && G[row][x+1] == 'X';
}


int
main(int argc, char* argv[]) {
  u32 ntests; cin >> ntests;

  for (u32 test = 0; test < ntests; test++) {
    cin >> n;
    u32 guards = 0;
    for (u32 row = 0; row < 2; row++) {
      for (u32 x = 0; x < n; x++)
        cin >> G[row][x];
    }

    for (u32 row = 0; row < 2; row++) {
      for (u32 x = 0; x < n; x++) {
        if (is_closed(row,x))
          guards += guard(1-row,x) || guard(row,x);
      }
    }

    for (u32 row = 0; row < 2; row++) {
      for (u32 x = 0; x < n; x++) {
          guards += guard(row,x);
      }
    }

    // fprintf(stderr, "%.*s\n", n, G[0]);
    // fprintf(stderr, "%.*s\n\n", n, G[1]);

    printf("Case #%d: %d\n", test + 1, guards);
  }

  return 0;
}
