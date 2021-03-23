class Solution {
public:
    int maxDiff(int num) {
        
        string nums = to_string(num);
        cout<<nums<<endl;
        
        string nums1=nums;
        string nums2= nums;
        
        int pos1=-1;
        char value1;
        int pos2=-1;        
        char value2;
        
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]=='9'){
                continue;
            }else{
                pos1=i;
                value1=nums1[i];
                break;
            }
        }
       
        if(pos1==-1){
            nums1=nums;
        }else{
            while(pos1<nums1.size()){
                if(nums1[pos1]==value1){
                    nums1[pos1]='9';
                    pos1++;
                }else{
                    pos1++;
                }
            }
        }
        
         
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]=='1' || nums2[i]=='0'){
                continue;
            }else{
                pos2=i;
                value2=nums2[i];
                break;
            }
        }
        
        bool flag=false;
        if(pos2==0){
            flag=true;
        }
         if(pos2==-1){
            nums2=nums;
        }else{
            while(pos2<nums2.size()){
                if(nums2[pos2]==value2){
                    if(flag){
                        nums2[pos2]='1';
                    }else{
                        nums2[pos2]='0';
                    }
                    pos2++;
                }else{
                    pos2++;
                }
            }
        }
        cout<<nums1<<" "<<nums2<<endl;
        int number1= stoi(nums1);
        int number2= stoi(nums2);
        int diff= number1-number2;
        return diff;
        
    }
};