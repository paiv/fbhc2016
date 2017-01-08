
namespace paiv {

typedef vector<night> problem;
typedef vector<string> solution;


problem
parse_input() {
  return parse_input_objects<night>();
}


static inline u32
star_distance(const star& a, const star& b) {
  u32 dx = b.x - a.x;
  u32 dy = b.y - a.y;
  return dx*dx + dy*dy;
}

u32
boomerangs_of(const star& star, const night& sky) {
  u32 res = 0;
  for (auto& a : sky.stars) {
    if (a == star) continue;
    for (auto& b : sky.stars) {
      if (a == b || b == star) continue;

      auto da = star_distance(a, star);
      auto db = star_distance(b, star);
      res += (da == db);
    }
  }
  return res / 2;
}


u32
solve_night(const night& sky) {
  u32 res = 0;
#if 0
  for (auto& star : sky.stars) {
    res += boomerangs_of(star, sky);
  }
#else
  auto nstars = sky.stars.size();
  for (size_t n = 0; n < nstars; n++)
  for (size_t j = n + 1; j < nstars; j++)
  for (size_t k = j + 1; k < nstars; k++) {
    auto da = star_distance(sky.stars[j], sky.stars[n]);
    auto db = star_distance(sky.stars[k], sky.stars[n]);
    auto dc = star_distance(sky.stars[k], sky.stars[j]);
    res += (da == db) + (da == dc) + (db == dc);
  }
#endif

  return res;
}


solution
solve(const problem& prob) {
  solution sol;

  u32 count = 0;
  for (auto sky : prob) {

    auto x = solve_night(sky);

    stringstream so;
    so << "Case #" << ++count << ": " << x;
    sol.push_back(so.str());
  }

  return sol;
}

}
