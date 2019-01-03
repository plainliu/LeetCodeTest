/*
 *
 *
 */
 
//Approach 2: Compare one by one
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator it;
        for(it=lists.begin();it!=lists.end();){//del NULL list,308 ms,13.05% 
            if(*it==NULL)
                it=lists.erase(it);
            else
                ++it;
        }
        /*while(find(lists.begin(),lists.end(),nullptr)!=lists.end())
            lists.erase(find(lists.begin(),lists.end(),nullptr));//332 ms,11.58%*/
        if(lists.size()==0)return NULL;
        //if(lists.size()==1)return lists[0];
        ListNode*ans=new ListNode(0);
        ListNode*tail=ans;
        while(!lists.empty()){
            int i=0,k=0;
            for(auto list:lists){//find
                if(list->val<lists[k]->val)k=i;
                ++i;
            }
            tail->next=lists[k];
            tail=lists[k];
            lists[k]=lists[k]->next;
            tail->next=NULL;
            if(lists[k]==NULL)
                lists.erase(lists.begin()+k);
        }
        return ans->next;
    }
};
