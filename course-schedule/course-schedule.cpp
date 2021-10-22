class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree = vector<int> (numCourses);
        vector<vector<int>> neighborhoods(numCourses);
        for (auto& courseInfo: prerequisites) {
            inDegree[courseInfo[0]]++;
            neighborhoods[courseInfo[1]].push_back(courseInfo[0]); // initialize graph
        }
       
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        if (q.empty()) return false;
        int coursePick = 0;  
        while (!q.empty()) {
            auto cur = q.front(); q.pop();           
            coursePick++;
            for (int connectedNode : neighborhoods[cur]) {
                inDegree[connectedNode]--;
                if (inDegree[connectedNode] == 0) {
                    q.push(connectedNode);
                }
            }           
        }
        return coursePick == numCourses;
    }
};