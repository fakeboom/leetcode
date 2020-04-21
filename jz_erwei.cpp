class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int hn = array.size()-1;
        int ln = array[0].size()-1;
        if(hn == 0|| ln ==0) return false;
        while(true){
            if(target>array[hn][ln]) return false;
            else if(target < array[hn][0]){
                hn --;
            }
            else if(target >= array[hn][0]){
                for(int i = 0;i<=ln;i++){
                    if(target == array[hn][i]) return true;
                }
                hn--;
            }
            if(hn< 0) return false;
        }
    }
};
//利用递增
