class Solution {
public:
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int k = nums[0];
    bool isA = true;

    for (int i = 0; i < n; i++) {
        if (nums[i] != (k + i) % n) {
            isA = false;
            break;
        }
    }

    if (!isA) {
        k = (n - 1 - nums[0] + n) % n;

        for (int i = 0; i < n; i++) {
            int expected = (n - 1 - (k + i) % n + n) % n;

            if (nums[i] != expected)
                return -1;
        }
    }

    int start = isA ? k : n + k;
    int target = 0;

    vector<int> dist(2 * n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int state = q.front();
        q.pop();

        if (state == target)
            return dist[state];

        int type = state / n; 
        int idx = state % n;

        int nextRotate = type * n + (idx + 1) % n;

        if (dist[nextRotate] == -1) {
            dist[nextRotate] = dist[state] + 1;
            q.push(nextRotate);
        }
        int nextReverse = (1 - type) * n + (n - idx) % n;

        if (dist[nextReverse] == -1) {
            dist[nextReverse] = dist[state] + 1;
            q.push(nextReverse);
        }
    }

    return -1;
}
};