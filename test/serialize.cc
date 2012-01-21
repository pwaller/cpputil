#include <iostream>
#include <sstream>

#include "serialize.h"

using namespace cpputil;
using namespace std;

template <typename _Sequence>
void tests(_Sequence& s)
{
  for ( auto i = 0; i < 10; ++i )
    s.push_back(i);
  
  ostringstream oss;
  serialize(oss, s);

  cout << "[" << oss.str() << "]" << endl;

  istringstream iss(oss.str());
  deserialize(iss, s);

  for ( auto v : s )
    cout << v << " ";
  cout << endl;
}

template <typename _Associative>
void testa(_Associative& a)
{
  for ( auto i = 0; i < 10; ++i )
    a[i] = i;

  ostringstream oss;
  serialize(oss, a);

  cout << "[" << oss.str() << "]" << endl;

  istringstream iss(oss.str());
  deserialize(iss, a);

  for ( auto v : a )
    cout << "(" << v.first << ", " << v.second << ") ";
  cout << endl;
}

int main()
{
  map<int, int> m;
  vector<int> v;

  testa(m);
  tests(v);

  set<string> ss;
  ss.insert("[Hello]");
  ss.insert("[World!]");
  ss.insert("[foo]");
  serialize(cout, ss);
  cout << endl;

  map<int, set<string>> mss;
  mss[0].insert("Hello");
  mss[0].insert("World!");
  mss[1].insert("foo");
  serialize(cout, mss);
  cout << endl;

  set<map<int,int>> sm;
  sm.insert(m);
  serialize(cout, sm);
  cout << endl;


  return 0;
}
