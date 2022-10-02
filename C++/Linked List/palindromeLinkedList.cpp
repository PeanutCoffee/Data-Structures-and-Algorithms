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
    int length(ListNode*head){
        int count = 0;
        ListNode*temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        int n = length(head);
        stack<ListNode*>nodes;
        
        int mid = n/2;
        int curr =1;
        ListNode*temp = head;
        
        while(temp!=NULL){
            if(curr>mid){
                break;
            }
            nodes.push(temp);
            temp = temp->next;
            curr++;
        }
        if(n%2!=0){
            temp= temp->next;
        }       
        int flag=0;
        while(!nodes.empty() && temp!=NULL){
            if(nodes.top()->val != temp->val){
                flag=1;
                break;
            }
            nodes.pop();
            temp= temp->next;
        }
        if(flag==1){
            return false;
        }
        return true;
    }
};
