#include<iostream>
#include<cstring>
#include<algorithm>
using  namespace std;
int main(){
    char str[] = "we are hh";
    int length = strlen(str);
    int i = 0;
        while(str[i]!='\0'){
            if(str[i]== ' '){
                char *temp = (char *)malloc(length);
                strcpy(temp,str+i+1);
                str[i] = '\0';
                strcat(str,"%20");
                i+=strlen("%20");
                length+=strlen("%20");
                strcat(str,temp);
                free(temp);
            }
            else i++;
        }
        cout << str << endl;
        system("pause");
}