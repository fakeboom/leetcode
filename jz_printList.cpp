/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vasd;
        while(head!=NULL){
            vasd.insert(vasd.begin(),head->val);
            head = head->next;
        }
        return vasd;

    }
};