#include <vector>

class ContestTraining {
    public:
    std::vector<long long> practice(long long heavyDays, long long lightDays, long long heavyProblems, long long lightProblems, std::vector<long long> queries) {
        long long all = heavyDays + lightDays;
        long long all_p = heavyProblems * heavyDays + lightProblems * lightDays;
        std::vector<long long> res;
        for (long long q : queries) {
            long long pas = q / all_p;

            pas *= all;
            long long which = q % all_p;
            if (which <= heavyDays * heavyProblems) {
                pas += (which / heavyProblems);
                pas += (which % heavyProblems > 0);
            } else {
                pas += heavyDays;
                which -= (heavyDays * heavyProblems);
                pas += (which / lightProblems);
                pas += (which % lightProblems > 0);
            }
            res.push_back(pas);

        }
        return res;
    }
};