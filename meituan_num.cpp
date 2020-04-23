//超时
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){}
};
int main(){
    
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> no(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 0; i < n;i++){
        ListNode *temp = new ListNode(i + 1);
        p->next = temp;
        p = temp;
    }
    p->next = head ->next;
    for (int i = 0; i < n;i++){
        ListNode *q = head;
        for (int k = 0; k < nums[i];k++){
            q = q->next;
        }
        no[q->next->val - 1] = n-i;
        q->next = q->next->next;
    }
    for (int i = 0; i < n;i++){
        cout << no[i] << endl;
    }
    system("pause");
    return 0;
}