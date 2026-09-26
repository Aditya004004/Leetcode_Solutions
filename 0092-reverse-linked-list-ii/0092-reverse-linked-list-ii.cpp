class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;

        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        reverse(arr.begin() + left - 1, arr.begin() + right);

        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};