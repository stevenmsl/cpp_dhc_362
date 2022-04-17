
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol362
{
    class HitCounter
    {
    private:
        vector<int> timeStamps;
        vector<int> counters;

    public:
        HitCounter() : timeStamps(301), counters(301){};
        void hit(int ts);
        int getHits(int ts);
    };
}
#endif