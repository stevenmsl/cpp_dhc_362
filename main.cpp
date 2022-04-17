#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol362;

/*
 HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);
*/
tuple<vector<int>, vector<int>> testFixture1()
{
  auto input = vector<int>{4, 300, 301};
  auto output = vector<int>{3, 4, 3};

  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  auto inputs = get<0>(f);
  auto ouputs = get<1>(f);
  HitCounter sol;
  sol.hit(1);
  sol.hit(2);
  sol.hit(3);
  cout << "Expect to see: " << to_string(ouputs[0]) << endl;
  cout << "Result: " << to_string(sol.getHits(inputs[0])) << endl;
  sol.hit(300);
  cout << "Expect to see: " << to_string(ouputs[1]) << endl;
  cout << "Result: " << to_string(sol.getHits(inputs[1])) << endl;
  cout << "Expect to see: " << to_string(ouputs[2]) << endl;
  cout << "Result: " << to_string(sol.getHits(inputs[2])) << endl;
}

main()
{
  test1();
  return 0;
}