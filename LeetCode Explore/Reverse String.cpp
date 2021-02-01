class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        cout<<"[";
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
};