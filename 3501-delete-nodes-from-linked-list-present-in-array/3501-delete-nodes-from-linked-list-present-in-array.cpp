class Solution
{
    public:
        ListNode* modifiedList(vector<int> &nums, ListNode *head)
        {
            int n = nums.size();
            unordered_set<int> st;
            for (int i = 0; i < n; i++)
            {
                st.insert(nums[i]);
            }

            ListNode *prev = new ListNode();
            ListNode *temp = new ListNode();
            prev = temp;
            ListNode *curr = head;

            while (curr != nullptr)
            {
                if (st.find(curr->val) == st.end())
                {
                    temp->next = curr;
                    temp = temp->next;
                }
                curr = curr->next;
            }
            temp->next = nullptr;
            return prev->next;
        }
};