class Solution
{
    public:
        long make_palindrome(long number, bool even)
        {
            long temp = number;

            if (!even)
            {
                number /= 10;
            }

            while (number)
            {
                temp = temp *10 + (number % 10);
                number /= 10;
            }

            return temp;
        }

    string nearestPalindromic(string s)
    {
        int n = s.length();
        int mid = n / 2;
        long first_half = stol(s.substr(0, n % 2 == 0 ? mid : mid + 1));

        vector<long> temp;
        temp.push_back(make_palindrome(first_half, n % 2 == 0));
        temp.push_back(make_palindrome(first_half + 1, n % 2 == 0));
        temp.push_back(make_palindrome(first_half - 1, n % 2 == 0));
        temp.push_back((long) pow(10, n) + 1);
        temp.push_back((long) pow(10, n - 1) - 1);

        long min_diff = LONG_MAX;
        long result = 0;
        long original_number = stol(s);

        for (long &it: temp)
        {
            if (it == original_number)
            {
                continue;
            }
            else if (abs(it - original_number) < min_diff)
            {
                min_diff = abs(it - original_number);
                result = it;
            }
            else if (abs(it - original_number) == min_diff)
            {
                result = min(result, it);
            }
        }
        return to_string(result);
    }
};