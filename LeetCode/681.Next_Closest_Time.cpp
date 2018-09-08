class Solution {
public:
    string nextClosestTime(string time) {
        string res;
        
        int mins[4] = {600, 60, 10, 1};
        int cur_min = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
        
        for (int i = 1; i <= 60 * 24; i++) {
            int next_min = (cur_min + i) % (24*60);
            string next_time = "";
            int d;
            for(d = 0; d < 4; d++) {
                char char_digit = next_min/mins[d] + '0';
                if (time.find(char_digit) == string::npos) break;
                next_time += char_digit;
                next_min %= mins[d];
            }
            if (d==4) {
                res = next_time.substr(0,2) + ":" + next_time.substr(2);
                break;
            }
        }
        return res;
    }
};
