
class Solution {
public:
    bool iscycledfs(int src, vector<int>& vis,
                    vector<int>& recpath,
                    vector<vector<int>>& edges) {

        vis[src] = true;
        recpath[src] = true;

        for(int i = 0; i < edges.size(); i++) {

            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {

                if(!vis[v]) {
                    if(iscycledfs(v, vis, recpath, edges)) {
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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, false);
        vector<int> recpath(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                if(iscycledfs(i, vis, recpath, prerequisites)) {
                    return false;
                }
            }
        }

        return true;
    }
};
