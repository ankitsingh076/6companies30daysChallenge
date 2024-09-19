class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    vector<int> res;

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];

        if (c == '+' || c == '-' || c == '*') {
            string left = input.substr(0, i);
            string right = input.substr(i + 1);

            vector<int> leftRes = diffWaysToCompute(left);
            vector<int> rightRes = diffWaysToCompute(right);

            for (int j = 0; j < leftRes.size(); j++) {
                for (int k = 0; k < rightRes.size(); k++) {
                    if (c == '+') {
                        res.push_back(leftRes[j] + rightRes[k]);
                    } else if (c == '-') {
                        res.push_back(leftRes[j] - rightRes[k]);
                    } else if (c == '*') {
                        res.push_back(leftRes[j] * rightRes[k]);
                    }
                }
            }
        }
    }

    if (res.empty()) {
        res.push_back(stoi(input));
    }
    return res;
}
};