/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* remove_head(ListNode* head){
        ListNode* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
     ListNode* remove_tail(ListNode* head){
        ListNode* temp=head;
         ListNode* del=NULL;
        while(temp){
            if(temp->next->next==NULL){
                del=temp->next;
                temp->next=NULL;
            }
            temp=temp->next;
        }
         delete(del);
        return head;
    }
     ListNode* between(ListNode* head,int n){
        ListNode* temp=head;
        for(int i=0;i<n-1;i++){
            temp=temp->next;
        }
        ListNode* temp1=temp->next;
        temp->next=temp->next->next;
        delete(temp1);
        return head; 
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp){
            count+=1;
            temp=temp->next;
        }
        int x=count-n+1;
        if(x==1){
            return remove_head(head);
        }
        if(x==count){
            return remove_tail(head);
        }
        return between(head,x-1);
    }
};