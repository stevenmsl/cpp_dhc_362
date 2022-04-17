#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
using namespace sol362;
using namespace std;

/*takeaways
  - if the number of hits per second is quite large, how
    do we deal with that?
  - we use a counter per timestamp for a time range
    of 5 minutes - we have 300 counters in total
  - as time progresses each counter will increment
    or reset accordingly
  - this design favors the hits method over the getHits
    method as getHits needs to walk through
    all counters to collect the hits that are still
    within 5 minutes timeframe and then sums them up
*/

void HitCounter::hit(int ts)
{
  auto bin = ts % 301;
  /* ts is monotonically increasing
     - so if we come back to the same
       bin and found the recorded timestamp
       is different that means 5 minutes
       has passed and we need to reset
       the counter and update the timestamp
       for this bin
  */
  if (ts != timeStamps[bin])
  {
    counters[bin] = 1;
    timeStamps[bin] = ts;
  }
  /* to deal with very large number of hits per second
     - you just increment the corresponding counter per
       that timestamp
  */
  else
    counters[bin]++;
}
int HitCounter::getHits(int ts)
{
  auto count = 0;
  /* you need to walk through all counters
     to collect the counts for those that
     have a timestamp within the pass 5
     minutes
  */
  for (auto i = 1; i < 301; i++)
    if (ts - timeStamps[i] < 300)
      count += counters[i];
  return count;
}