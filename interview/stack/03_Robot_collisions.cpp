class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        // Combine positions, healths, directions, and original indices
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // Sort robots based on their positions
        sort(robots.begin(), robots.end());

        stack<tuple<int, int, char, int>> st;
        vector<int> result(n, -1); // Initialize result with -1 indicating robot did not survive

        for (auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char dir = get<2>(robot);
            int index = get<3>(robot);

            if (dir == 'R') {
                st.push(robot);
            } else {
                while (!st.empty() && get<2>(st.top()) == 'R' && health > 0) {
                    auto [r_pos, r_health, r_dir, r_index] = st.top();
                    if (r_health == health) {
                        st.pop();
                        health = 0;
                    } else if (r_health > health) {
                        get<1>(st.top())--;
                        health = 0;
                    } else {
                        health--;
                        st.pop();
                    }
                }
                if (health > 0) {
                    st.push({pos, health, dir, index});
                }
            }
        }

        // Process remaining robots in the stack
        while (!st.empty()) {
            auto [pos, health, dir, index] = st.top();
            result[index] = health;
            st.pop();
        }

        // Filter out robots that did not survive
        vector<int> survivors;
        for (int i = 0; i < n; ++i) {
            if (result[i] != -1) {
                survivors.push_back(result[i]);
            }
        }

        return survivors;
    }
};
