class Solution {
private:
    map<int, set<int>> point;
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = numeric_limits<int>::max();
        
        generatePointMap(points);
        
        for (int i = 0; i < points.size(); i++ ) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i+1; j< points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                if (hasPoint(x1, y2) && hasPoint(x2,y1)) {
                    int area = abs((x1-x2)*(y1-y2));
                    ans = min(ans, area);
                }
            }
        }
        return ans != numeric_limits<int>::max() ? ans : 0;
    }
    
    void generatePointMap(const vector<vector<int>>& points)
    {
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            if (point.find(x) == point.end()) {
                set<int> y_points;
                point[x] = y_points;
            }
            if (point[x].find(y) == point[x].end()) {
                point[x].insert(y);
            }
        }
    }
    
    bool hasPoint(int x, int y)
    {
        map<int, set<int>>::iterator it = point.find(x);

        return (it != point.end() && it->second.find(y) != it->second.end());
    }
};