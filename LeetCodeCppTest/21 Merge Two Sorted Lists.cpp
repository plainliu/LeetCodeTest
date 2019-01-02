/*
 *2019.01.02
 *Liu
 */

//12 ms,48.39%
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode*p,*later;
        if(l1->val<l2->val)
            p=l1;
        else{
            p=l2;l2=l1;l1=p;
        }
        while(p->next!=NULL&&l2!=NULL){
            if(l2->val<p->next->val){//del head of l2,insert behind p
                later=p->next;
                p->next=l2;
                l2=l2->next;
                p->next->next=later;
            }
            else
                p=p->next;
        }
        if(p->next==NULL)p->next=l2;
        return l1;
    }
};
