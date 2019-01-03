/**
 *2019.01.04
 *Liu
 *
 */
 
//20 ms,50.47%
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        stack<ListNode*>s;
        ListNode*subtail=NULL,*presubtail=NULL,*p=NULL,*later=head;
        int count=0;
        bool ifFstK=true;//first k nodes
        while(later!=NULL){
            if(!ifFstK)
                presubtail=subtail;
            subtail=later;
            count=0;
            p=later;
            while(count<k&&p!=NULL){//push k nodes
                if(count==k-1)later=p->next;
                s.push(p);
                p=p->next;
                ++count;
            }
            if(count!=k){
                if(presubtail!=NULL)
                    presubtail->next=later;
                return head;}//at the end;
            p=s.top();
            s.pop();
            if(ifFstK){
                head=p;ifFstK=false;}
            else
                presubtail->next=p;
            while(!s.empty()){
                p->next=s.top();
                p=s.top();
                s.pop();
            }
            p->next=NULL;//tail
        }
        return head;
    }
};
