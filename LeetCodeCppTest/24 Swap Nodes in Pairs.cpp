/**
 *2019.01.03
 *Liu
 */
 
 //4 ms,56.91%
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;//size==1
        ListNode*pre,*later;
        later=head->next->next;//swap 1 2
        head->next->next=head;
        head=head->next;
        head->next->next=later;
        pre=head->next;
        while(pre->next!=NULL){//swap after 2
            if(pre->next->next==NULL)//only one at the end
                return head;
            later=pre->next->next->next;//swap
            pre->next->next->next=pre->next;
            pre->next=pre->next->next;
            pre=pre->next->next;
            pre->next=later;
        }
        return head;
    }
};
