class Solution {
public:
   
    string addbinary(string s){
        
        int carry=1;
        string result="";
        int i=s.size()-1;
        
        while(i>=0){
            if(s[i]=='1' && carry==1){
                result.push_back('0');
                carry=1;
                i--;
            }else if(s[i]=='0' && carry==1){
                result.push_back('1');
                carry=0;
                i--;
            }else if(s[i]=='1' && carry==0){
                result.push_back('1');
                carry=0;
                i--;
            }else{
                result.push_back('0');
                carry=0;
                i--;
            }
        }
        if(carry==1){
            result.push_back('1');
        }
        reverse(result.begin(),result.end());
        return result;
    }
    int numSteps(string s) {
        int count=0;
        while(s.length()-1){
            if(s[s.length()-1]=='1'){
                //string curr = addBinary(s, "1");
                string curr= addbinary(s);
                s= curr;
                count++;
            }else{
                count++;
                s=s.substr(0,s.length()-1);
            }
            
        }
        return count;
        
    }
};