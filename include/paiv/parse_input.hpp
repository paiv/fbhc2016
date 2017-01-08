
namespace paiv {

template <typename T>
T
parse_input_line_1(istream& si = cin) {
  string buf;
  if (getline(si, buf)) {
    stringstream reader(buf);
    T x;
    if (reader >> x)
      return x;
  }
  return 0;
}


template <typename T>
vector<T>
parse_input_line_n(istream& si = cin) {
  vector<T> values;
  string buf;

  if (getline(si, buf)) {
    stringstream reader(buf);
    T x;

    while (reader >> x) {
      values.push_back(x);
    }
  }
  return values;
}


template <typename T>
vector<T>
parse_input_objects(istream& si = cin) {
  vector<T> res;
  auto n = parse_input_line_1<u32>(si);
  while (n-- > 0) {
    T x;
    if (si >> x) {
      res.push_back(x);
    }
    else {
      return {};
    }
  }
  return res;
}

}
