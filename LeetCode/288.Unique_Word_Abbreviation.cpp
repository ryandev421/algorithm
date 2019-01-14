class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> dict;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string str : dictionary) {
            string abbreviation_str = getAbbreviationString(str);
            dict[abbreviation_str].insert(str);
        }
    }
    
    bool isUnique(string word) {
        string abbreviation_str = getAbbreviationString(word);
        
        return dict[abbreviation_str].count(word) == dict[abbreviation_str].size();
    }
    
    string getAbbreviationString(string &str)
    {
        return str[0] + to_string(max(0, (int)str.length() - 2)) + str.back();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */