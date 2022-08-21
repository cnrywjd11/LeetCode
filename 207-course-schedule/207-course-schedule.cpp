class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph
        vector<bool> visited(numCourses+1);
        vector<bool> finished(numCourses+1);
        vector<vector<int>> graph(numCourses+1);
        
        for (auto &edge : prerequisites) {
            auto v1 = edge[0];
            auto v2 = edge[1];
            
            graph[v1].push_back(v2);
        }
        
        // check cycle
        for (int i=0;i<numCourses;i++) {
            if (checkCycle(visited, finished, graph, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool checkCycle(vector<bool> &visited, vector<bool> &finished, vector<vector<int>> &graph, int v) {
        visited[v] = true;
        
        bool isCycle = false;
        
        for(auto &nv : graph[v]) {
            if (!visited[nv]) {
                if (checkCycle(visited, finished, graph, nv)) {
                    return true;
                }
            } else if (!finished[nv]) {
                isCycle = true;
            }
        }
        
        finished[v] = true;
        
        return isCycle;
    }
};