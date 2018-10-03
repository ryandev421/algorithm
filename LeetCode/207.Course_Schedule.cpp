class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inPathCount(numCourses, 0);
        vector<int> outPath[numCourses];
        bool visited[numCourses] = {0};
        
        for (int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> prerequiste = prerequisites[i];
            inPathCount[prerequiste.first]++;
            outPath[prerequiste.second].push_back(prerequiste.first);
        }
        
        for (int i = 0; i < numCourses; i++) {
            int course;
            for (course = 0; course < numCourses; course++) {
                if (visited[course]) continue;
                if (inPathCount[course] == 0) break;
            }
            
            if (course != numCourses) {
                visited[course] = true;
                for (int p = 0; p < outPath[course].size(); p++) {
                    inPathCount[outPath[course][p]]--;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
