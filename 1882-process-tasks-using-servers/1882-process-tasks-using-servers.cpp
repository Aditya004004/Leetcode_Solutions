
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Available: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // Busy: {freeTime, weight, index}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [ft, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            if (available.empty()) {

                time = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [ft, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            auto [weight, index] = available.top();
            available.pop();

            ans[j] = index;

            busy.push({
                time + (long long)tasks[j],
                weight,
                index
            });
        }

        return ans;
    }
};
