class Solution {
public:
    string addBinary(string a, string b) {
         string result="";
         int carry=0;
        int asize=a.size()-1;
        int bsize=b.size()-1;
        
        while(asize>=0 || bsize>=0 || carry){
            
            if(asize>=0 && a[asize--]=='1'){
                ++carry;
            }
            if(bsize>=0 && b[bsize--]=='1'){
                ++carry;
            }
            result.insert(0,1, carry%2 == 1 ? '1': '0');
            carry /=2;
        }
        return result;
        
    }
};