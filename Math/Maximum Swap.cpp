//T.C : O(n*n)
//S.C : O(n) // string approach 
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        for(int i=0; i<n; i++){
            char maxi=s[i];
            int ind=i;
            for(int j=i+1; j<n; j++){
                if(s[j]>=maxi){
                    maxi=s[j];
                    ind=j;
                }
            }
            if(ind!=i && s[i]!=s[ind]){
                swap(s[ind],s[i]);
                return stoi(s);
            }
        }
        return num;
    }
};

// MATH APPROACH
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) {
            return num;
        }
        int bestdigit = num % 10;
        // Keep backup
        int swapvalueLp = 1;
        int swapvalueGp = 1;
        // Current swap pairs, could be a nonexample
        int swapvalueL = 1;
        int swapvalueG = 1;
        int digit;
        for (int placevalue = 10; num / placevalue; placevalue *= 10) {
            digit = (num / placevalue) % 10;
            if (digit > bestdigit) {
                // Save previous swap candidate
                // Update only if it makes sense to, since we could get several inapplicables in a row
                if (swapvalueG != swapvalueL) {
                    swapvalueGp = swapvalueG;
                    swapvalueLp = swapvalueL;  
                }
                // Set best digit and a new set of swapvalues
                bestdigit = digit;
                swapvalueL = placevalue;
                swapvalueG = placevalue;
            }
            else if (digit < bestdigit) {
                swapvalueG = placevalue;
            }
            //cout << swapvalueG << "(" << swapvalueGp << ")" << "," << swapvalueL << "(" << swapvalueLp << ")"<< "\n";
        }
        // If no better pairs to swap, use the backup
        if (swapvalueG == swapvalueL) {
            swapvalueG = swapvalueGp;
            swapvalueL = swapvalueLp;
        }
        
        bestdigit = (num / swapvalueL) % 10;
        digit = (num / swapvalueG) % 10;
        //cout << swapvalueG << "(" << digit << ")" << "," << swapvalueL << "(" << bestdigit << ")"<< "\n";
        
        return num - swapvalueL*bestdigit - swapvalueG*digit + swapvalueL*digit + swapvalueG*bestdigit;
    }
};
