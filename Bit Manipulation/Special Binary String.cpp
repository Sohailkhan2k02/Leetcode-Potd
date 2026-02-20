class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> special;
        int count = 0, start = 0;

        for(int i = 0; i<s.size(); i++){
          if(s[i] == '1') count++;
          else count--;
          if(count == 0){
          string inner = s.substr(start+1, i - start -1);
          string processed = '1'+ makeLargestSpecial(inner) + '0';
          special.push_back(processed);
          start = i +1;
        }
        }

        // sort
        sort(special.begin(), special.end(), greater<string>());

        string result = "";
        for(string &str : special){
          result += str;
        }

        return result;
    }
};
