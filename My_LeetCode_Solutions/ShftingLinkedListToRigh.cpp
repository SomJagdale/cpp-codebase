class Solution {
public:
    ListNode* rotateRight(ListNode* listHead, int rotateCount) 
    {    
        ListNode *slow = listHead;
        ListNode *fast = listHead;
        if (listHead == NULL) {
            return NULL;
        }
        ListNode *temp = listHead;
        int count = 0;
        while (temp!= NULL) {
            temp = temp->next;
            count ++;
        }
        rotateCount = rotateCount % count;
        for (int i = 0; i < rotateCount ; i++) {
            fast = fast->next;
        }
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = listHead;
        ListNode *result = slow->next;
        slow->next = NULL;
        return result;
    }
};