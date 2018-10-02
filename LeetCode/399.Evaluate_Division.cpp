typedef pair<string, string> division;

class Solution {
public:
    vector<double> calcEquation(vector<division> equations, vector<double>& values, vector<division> queries) {
    	vector<string> formats = getFormats(equations);
    	map<string, int> format_to_index_map;
    	for (int i = 0; i < formats.size(); i++) {
    		format_to_index_map[formats[i]] = i;
    	}       
        vector<vector<double>> map = generateBaseMap(format_to_index_map, equations, values);
        
        for (int k = 0; k < formats.size(); k++) {
            for (int i = 0; i < formats.size(); i++) {
                for (int j = 0; j < formats.size(); j++) {
                    if (map[i][k] >= 0 && map[k][j] >= 0) {
                        map[i][j] = map[i][k] * map[k][j];
                    }
                }
            }
        }
        
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
        	if (format_to_index_map.find(queries[i].first) == format_to_index_map.end()
        		|| format_to_index_map.find(queries[i].second) == format_to_index_map.end()) {
        		res.push_back(-1.0);
        	} else {
        		int first_format_idx = format_to_index_map[queries[i].first];
        		int second_format_idx = format_to_index_map[queries[i].second];
            	res.push_back(map[first_format_idx][second_format_idx]);
        	}
        }
        
        return res;
    }

    vector<string> getFormats(const vector<division>& equations)
    {
    	set<string> showed_set;
        vector<string> formats;
        for (auto node : equations) {
            if (showed_set.find(node.first) == showed_set.end()) {
                showed_set.insert(node.first);
                formats.push_back(node.first);
            }
            if (showed_set.find(node.second) == showed_set.end()) {
                showed_set.insert(node.second);
                formats.push_back(node.second);
            }
        }
        return formats;
    }
    
    vector<vector<double>> generateBaseMap(map<string, int>& format_to_index_map, const vector<division>& equations, const vector<double>& values)
    {
        vector<vector<double>> res(format_to_index_map.size(), vector<double>(format_to_index_map.size(), -1.0));
        for (int idx = 0; idx < equations.size(); idx++) {
            division cur_equation = equations[idx];
            int first_format_idx = format_to_index_map[cur_equation.first];
        	int second_format_idx = format_to_index_map[cur_equation.second];

            res[first_format_idx][second_format_idx] = values[idx];
            res[second_format_idx][first_format_idx] = 1/values[idx];
        }   
        return res;
    }
};
