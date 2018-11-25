class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res = 0;
        set<string> received_emais;
        
        for (string email : emails) {
            string extracted_email = extractEmail(email);
            if (received_emais.find(extracted_email) == received_emais.end()) {
                res++;
                received_emais.insert(extracted_email);
            }
        }
        return res;
    }
    
    string extractEmail(string email)
    {
        int index_of_at = email.find("@");
        string local_name = email.substr(0, index_of_at);
        string domain_name = email.substr(index_of_at);
        
        int index_of_plus = local_name.find("+");
        if (index_of_plus != string::npos) {
            local_name = local_name.substr(0, index_of_plus);
        }
        
        while (local_name.find(".") != string::npos) {
            int index_of_point = local_name.find(".");
            local_name.erase(local_name.begin() + index_of_point);
        }
        
        return local_name + domain_name;
    }
};