// 解法一：BFS拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, {});
        into.assign(numCourses, 0);
        for (auto &edge : prerequisites) {
            int start = edge[1];
            int end = edge[0];
            graph[start].push_back(end);
            into[end]++;
        }

        vector<int> finish;
        for (int i = 0; i < numCourses; i++) {
            if (into[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            finish.push_back(cur);
            q.pop();
            for (auto next : graph[cur]) {
                into[next]--;
                if (into[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (finish.size() == numCourses) {
            return finish;
        }

        return {};
    }

    vector<vector<int>> graph;
    queue<int> q;
    vector<int> into;
};

// 解法2：DFS拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, {});
        into.assign(numCourses, 0);
        visted.assign(numCourses, 0);
        for (auto &edge : prerequisites) {
            int start = edge[1];
            int end = edge[0];
            graph[start].push_back(end);
        }
        valid = true;
        for (int i=0; i < numCourses; i++) {
            if (visted[i] == 0) {
                dfs(i); 
            }
        }
        if (valid) {
            reverse(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }

    void dfs(int start) {
        visted[start] = 1;
        for (auto next : graph[start]) {
            if (visted[next] == 1) {
                valid = false;
            }
             if (visted[next] == 0) {
                dfs(next);    
             }
        }
        visted[start] = 2;
        ans.push_back(start);
    }

    vector<vector<int>> graph;
    queue<int> q;
    vector<int> into;
    vector<int> visted;
    vector<int> ans;
    int valid;
};