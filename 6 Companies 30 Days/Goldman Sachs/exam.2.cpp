#include <vector>
#include <algorithm>
#include <climits>

class CircularRouteCalculator {
private:
    std::vector<int> costs;
    int stations;

    long long calculateDirectionalCost(int begin, int end, bool isClockwise) {
        long long total = 0;
        while (begin != end) {
            if (isClockwise) {
                total += costs[begin];
                begin = (begin + 1) % stations;
            } else {
                begin = (begin - 1 + stations) % stations;
                total += costs[begin];
            }
        }
        return total;
    }

public:
    CircularRouteCalculator(const std::vector<int>& ticketCosts) : costs(ticketCosts), stations(ticketCosts.size()) {}

    long long computeMinimumCost(int departure, int arrival) {
        if (departure == arrival) return 0;

        int adjustedStart = departure - 1;
        int adjustedEnd = arrival - 1;

        long long clockwiseCost = calculateDirectionalCost(adjustedStart, adjustedEnd, true);
        long long counterclockwiseCost = calculateDirectionalCost(adjustedStart, adjustedEnd, false);

        return std::min(clockwiseCost, counterclockwiseCost);
    }
};

long long findMinCost(int N, int start, int finish, std::vector<int>& Ticket_cost) {
    CircularRouteCalculator calculator(Ticket_cost);
    return calculator.computeMinimumCost(start, finish);
}