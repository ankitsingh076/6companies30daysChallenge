class Solution
{
    public:
        bool isCircularSentence(string sentence)
        {
            stringstream ss(sentence);
            string token;
            vector<string> words;
            while (ss >> token)
            {
                words.push_back(token);
            }

            char last = words[words.size() - 1].back();

            for (int i = 0; i < words.size(); i++)
            {
                if (words[i].front() != last)
                {
                    return false;
                }
                last = words[i].back();
            }
            return true;
        }
};