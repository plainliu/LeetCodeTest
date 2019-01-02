/*
 *2019.01.02
 *Liu
 */

//scan twice,first time get length of the list,second time Remove (num-N+1)th Node From head of List
//8 ms,50.40% O(2n)=O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {//List without head node
        if(head->next==NULL)return NULL;//size==1
        ListNode* p=head,*del=NULL;
        int num=0;
        while(p!=NULL){++num;p=p->next;}
        if(n==num){
            del=head;head=head->next;delete(del);
            return head;
        }
        int k=1;
        p=head;
        while(k<num-n){++k;p=p->next;}
        del=p->next;
        p->next=del->next;
        delete(del);
        return head;
    }
};

//at first move fst n times,then move fst&pre together
//8 ms,50.40%,O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {//List without head node
        if(head->next==NULL)return NULL;//size==1
        ListNode* pre=head,*fst=head,*del=NULL;
        int k=0;
        while(k<n){++k;fst=fst->next;}//move fst n times
        if(fst==NULL){//del first node
            del=head;head=head->next;delete(del);
            return head;
        }
        while(fst->next!=NULL){//move together
            fst=fst->next;
            pre=pre->next;
        }
        del=pre->next;pre->next=del->next;
        delete(del);
        return head;
    }
};
