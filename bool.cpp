//bool运算
//使用栈
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int check(stack<bool> &a){
    if(a.empty())
        cout << "error" << endl;
    else
        return 1;
    return 0;
}
int main(){
    stack <bool> nums;
    stack <char> cc;
    char* ss= (char *)malloc(1000);
    cin.getline(ss,1000);
    int i = 0;
    int state = 0;
    int ff = 0;
    while(ss[i]!='\0'){
        switch (ff){
            case 0:
                if(ss[i]=='t'&& strncasecmp(ss+i,"true",4) == 0){
                    nums.push(true);
                    i+=4;
                    if(state == 1){
                        if(!check(nums))
                            return 0;
                        bool a = nums.top();
                        nums.pop();
                        if(!check(nums))
                            return 0;
                        bool b = nums.top();
                        nums.pop();
                        cc.pop();
                        nums.push(a&b);
                        state = 0;
                    }
                    ff = 1;
                }
                else if(ss[i]=='f'&& strncasecmp(ss+i,"false",5) == 0){
                    nums.push(false);
                    i+=5;
                    if(state == 1){
                        if(!check(nums))
                            return 0;
                        bool a = nums.top();
                        nums.pop();
                        if(!check(nums))
                            return 0;
                        bool b = nums.top();
                        nums.pop();
                        nums.push(a&b);
                        cc.pop();
                        state = 0;
                    }
                        ff = 1;
                }
                else if(ss[i]==' ')
                    i++;
                else{
                    cout << "error" << endl;
                    return 0;
                }

                break;
            case 1:
                if(ss[i]=='o'&& strncasecmp(ss+i,"or",2) == 0){
                    cc.push('|');
                    i+=2;
                    ff = 0;
                }
                else if(ss[i]=='a'&& strncasecmp(ss+i,"and",3) == 0){
                    cc.push('&');
                    i += 3;
                    state = 1;
                    ff = 0;
                }
                else if(ss[i]==' ')
                    i++;
                else{
                    cout << "error" << endl;
                    return 0;
                }

                break;
        }
       
    }
    while (cc.size() != 0 && nums.size() > 1)
    {
        bool a = nums.top();
                nums.pop();
                bool b = nums.top();
                nums.pop();
                nums.push(a|b);
                cc.pop();
    }
    if(nums.size()==1&&cc.size()==0){
        nums.top() ? cout << "true" << endl : cout << "false" << endl;
    }
    else cout<<"error"<<endl;
    system("pause");
    return 0;
    
}