class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            for (long a = 0; a * a <= c; a++)
            {

                int x = c - (int)(a *a);
               	//b *b == x (we need to find the b which satisfies this)

                int b_start = 0, b_end = x;

                while (b_start <= b_end)
                {
                    long mid = b_start + (b_end - b_start) / 2;

                    if (mid *mid == x)
                    {
                        return true;
                    }
                    else if (mid * mid < x)
                    {
                        b_start = mid + 1;
                    }
                    else
                    {
                        b_end = mid - 1;
                    }
                }
            }

            return false;
        }
};