class Solution
{
    public:
        ListNode* modifiedList(vector<int> &nums, ListNode *head)
        {
            unordered_set<int> s;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                s.insert(nums[i]);
            }
            ListNode *ans = head;
            while (ans != NULL && s.find(ans->val) != s.end())
            {
                ans = ans->next;	//Check for the head node excusively
            }
            head = ans;
            while (head != NULL && head->next != NULL)
            {
                if (s.find(head->next->val) != s.end())
                {
                    head->next = head->next->next;
                    continue;
                }
                head = head->next;
            }
            return ans;
        }
};