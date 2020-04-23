//递归
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int compare(char *s1, char *s2, int l1, int l2){
    if(l1== 0&&l2 == 0)
        return 1;
    else if(s1[0] == '*'&& l2 ==0&&l1 ==1)
        return 1;
    else if(l1 == 0||l2 ==0)
        return 0;
    if(s1[0] == s2[0]){
        return compare(s1 + 1, s2 + 1, l1 - 1, l2 - 1);
    }else if(s1[0] == '?') return compare(s1 + 1, s2 + 1, l1 - 1, l2 - 1);
    else if(s1[0] == '*')
        return compare(s1 + 1, s2 , l1 - 1, l2 ) | compare(s1, s2 + 1, l1, l2 - 1);
    else
        return 0;
} 
int main()
{
    char s1[20], s2[20];
    cin.getline(s1, 20);
    cin.getline(s2, 20);
    cout << compare(s1,s2,strlen(s1),strlen(s2)) << endl;
    system("pause");
}