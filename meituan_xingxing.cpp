#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int check(int* x,int *y,int a,int b,int len){
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for (int i = 0; i < len;i++){
        if(x[i]==a&&y[i]>b)
            t1 = 1;
    }
    for (int i = 0; i < len;i++){
        if(x[i]==a&&y[i]<b)
            t2 = 1;
    }
    for (int i = 0; i < len;i++){
        if(x[i]<a&&y[i]==b)
            t3 = 1;
    }
    for (int i = 0; i < len;i++){
        if(x[i]>a&&y[i]==b)
            t4 = 1;
    }
    return t1 & t2 & t3 & t4;
}
int main(){
    int n;
    cin >> n;
    if(n==0)
        return 0;
    int *x = (int *)malloc(sizeof(int) * n);
    int *y = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n;i++){
        cin >> x[i];
        cin >> y[i];
    }
    int re= 0;
    for (int j = 0; j < n;j++){
        if(check(x,y,x[j],y[j],n)==1)
            re++;
    }
    cout << re;
    system("pause");
    return 0;
}