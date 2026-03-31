class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int len=n+m-1;
        string word(len,'.');
        vector<bool>locked(len,false);
        //apply all forced T
        for(int i=0;i<n;i++){
            char ch=str1[i];
            if(ch=='T'){
                for(int j=0;j<m;j++){
                    if(word[i+j]=='.'||word[i+j]==str2[j]){
                        word[i+j]=str2[j];
                        locked[i+j]=true;
                    }else{
                        return "";
                    }
                }
            }
        }
        for(int i=0;i<len;i++){
            if(word[i]=='.'){
                word[i]='a';
            } 
        }
        //fix Fs
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool match=true;
                for(int j=0;j<m;j++){
                    if(word[i+j]!=str2[j]){
                        match=false;
                        break;
                    }
                }
                if(match){
                    bool changed=false;
                    for(int j=m-1;j>=0;j--){
                        if(!locked[i+j]){
                            for(char c='a';c<='z';c++){
                                if(c!=str2[j]){
                                    word[i+j]=c;
                                    changed=true;
                                    break;
                                }
                            }
                        }
                        
                        if(changed){
                            break;
                        }
                        
                    }
                    if(!changed){
                        return "";
                    }
                }
            }
        }
        return word;
    }
};
