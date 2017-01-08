#include <iostream>
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
using namespace std;

#define MAXN 100000


int
main(int argc, char* argv[]) {
  u32 ntests; cin >> ntests;

  u32 B[MAXN];
  u32 n, price;

  for (u32 test = 0; test < ntests; test++) {
    cin >> n >> price;
    for (u32 i = 0; i < n; i++)
      cin >> B[i];

#if 1
    u64 count = 0;

    for (u32 k = 0, i = 0; i < n; i++, k = i) {
      for (u32 sum = 0; k < n && sum + B[k] <= price; k++) {
        sum += B[k];
      }
      count += k - i;
    }

#else
    u32 k = 1, sum = B[0];
    u64 count = sum <= price;

    for (u32 i = 0; i + k < n || k > 1; ) {
      if (k == 1) {
        sum += B[i + k];
        k += 1;
      }
      else if (sum >= price || i == 0) {
        i += k - 1;
        k = 1;
        sum = B[i];
      }
      else {
        i--;
        k++;
        sum += B[i];
      }

      count += (sum <= price);
    }
#endif
    cout << "Case #" << (test + 1) << ": " << count << endl;
  }

  return 0;
}
