class Solution
{
    public:
        ListNode* insertGreatestCommonDivisors(ListNode *head)
        {
            if (head == nullptr || head->next == nullptr)
            {
                return head;
            }

            ListNode *first = head;
            ListNode *second = head->next;

            while (second != nullptr)
            {
                int n = __gcd(first->val, second->val);
                ListNode *middle = new ListNode(n);

                first->next = middle;
                middle->next = second;

                first = second;
                second = second->next;
            }
            return head;
        }
};