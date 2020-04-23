//不知道哪里错了9%
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    char s[100];
    cin.getline(s, 100);
    while(strlen(s)>0){
        char sout[100];
        int min = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        if(s[0]=='-'){
            sout[j++] = '(';
            sout[j++] = '$';
            i++;
            min = 1;
        }
        else {
            sout[j++] = '$';
        }
        for (k = 0; k < strlen(s);k++){
            if(s[k]=='.')
                break;
        }
         for (; i < k;i++){
            sout[j++] = s[i];
            if((k-i-1)%3==0&&k-i!=1){
                sout[j++] = ',';
            }
        }
        if(k==strlen(s)){
            sout[j++] = '\0';
            strcat(sout, ".00");
            if(min == 1)strcat(sout, ")");
            cout << sout << endl;
            cin.getline(s, 100);
            continue;
            
        }
       
        i++;
        sout[j++] = '.';
        if(i<strlen(s)){
            sout[j++] = s[i++];
        }
        else {
            sout[j++] = '0';
        }
        if(i<strlen(s)){
            sout[j++] = s[i++];
        }
        else {
            sout[j++] = '0';
        }
        sout[j++] = '\0';
            if(min == 1)strcat(sout, ")");
        cout << sout << endl;
        cin.getline(s, 100);
    }
    return 0;
}