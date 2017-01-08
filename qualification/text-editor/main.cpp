#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

#define MAXN 300

typedef struct node {
  typedef array<u32, MAXN+4> costs_t;
  unordered_map<char, node> children;
  u8 is_word = false;
  costs_t costs;

  void add(const char* word) {
    if (*word == '\0')
      is_word = true;
    else
      children[*word].add(word + 1);
  }

  void update_costs(u32 n) {
    costs.fill(0x7fffffff);
    costs[is_word] = 1;

    for (auto& it : children) {
      auto& child = it.second;
      child.update_costs(n);

      costs_t update = costs;

      for (u32 i = 0; i <= n; i++) {
        for (u32 j = 0; j <= n - i; j++) {
          update[i+j] = min(update[i+j], costs[i] + child.costs[j]);
        }
      }

      costs = update;
    }

  }
} node;


int
main(int argc, char* argv[]) {
  u32 ntests; cin >> ntests;

  for (u32 test = 0; test < ntests; test++) {
    u32 n, k, count = 0;
    cin >> n >> k;

    node trie;

    for (u32 i = 0; i < n; i++) {
      string word; cin >> word;
      trie.add(word.c_str());
    }

    trie.update_costs(n);
    count = (trie.costs[k] - 1) * 2 + k;

    cout << "Case #" << (test + 1) << ": " << count << endl;
  }

  return 0;
}
