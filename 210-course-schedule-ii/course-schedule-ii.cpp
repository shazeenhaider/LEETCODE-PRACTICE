
class Solution {
public:
    bool iscycledfs(int src, vector<int>& recpath,
                    vector<int>& vis, vector<vector<int>>& pre) {

        vis[src] = true;
        recpath[src] = true;

        for(int i = 0; i < pre.size(); i++) {

            int v = pre[i][0];
            int u = pre[i][1];

            if(u == src) {

                if(!vis[v]) {
                    if(iscycledfs(v, recpath, vis, pre)) {
                        return true;
                    }
                }
                else if(recpath[v]) {
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false;
    }

    void topologicalsort(int src, vector<int>& vis,
                         vector<vector<int>>& prerequisites,
                         stack<int>& s) {

        vis[src] = true;

        for(int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(src == u && !vis[v]) {
                topologicalsort(v, vis, prerequisites, s);
            }
        }

        // Push after exploring all neighbours
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, false);
        vector<int> recpath(numCourses, false);

        // Cycle detection
        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(iscycledfs(i, recpath, vis, prerequisites)) {
                    return {};
                }
            }
        }

        // Reset visited array
        vis.assign(numCourses, false);

        // Topological sorting
        stack<int> s;

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                topologicalsort(i, vis, prerequisites, s);
            }
        }

        // Store stack elements in answer
        vector<int> ans;

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
