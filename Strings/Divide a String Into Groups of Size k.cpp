class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        string temp = "";
        for(int i=0;i<s.size();i++){
             if(temp.size() == k){
                v.push_back(temp);
                temp = "";
             }
                temp.push_back(s[i]);
             
        }

        if(temp.size() == 0){
            return v;
        }else{
            //cout << temp << endl;
            int num = k - temp.size();
            while(num--){
                temp.push_back(fill);
            }
             v.push_back(temp);
        }
        return v;
    }
};
