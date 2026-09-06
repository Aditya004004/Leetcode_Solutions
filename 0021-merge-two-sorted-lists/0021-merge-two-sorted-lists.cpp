class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nums;

        while (list1) {
            nums.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2) {
            nums.push_back(list2->val);
            list2 = list2->next;
        }

        sort(nums.begin(), nums.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for (int x : nums) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy.next;
    }
};