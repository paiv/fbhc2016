#pragma once

namespace paiv {

typedef struct star {
  s16 x;
  s16 y;
} star;

typedef struct night {
  vector<star> stars;
} night;


bool operator == (const star& a, const star& b) {
  return a.x == b.x && a.y == b.y;
}

istream& operator >> (istream& si, star& obj) {
  auto v = parse_input_line_n<s16>(si);
  if (v.size() == 2) {
    obj.x = v[0];
    obj.y = v[1];
  }
  else {
    si.setstate(ios::failbit);
  }
  return si;
}

istream& operator >> (istream& si, night& obj) {
  obj.stars = parse_input_objects<star>(si);
  return si;
}


}
