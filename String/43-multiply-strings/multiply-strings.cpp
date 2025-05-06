class Solution {
public:
    string multiply(string num1, string num2) {
        if("0" == num1 || "0" == num2) return "0";
        int n = num1.size(), m = num2.size();
        vector<int> store(n + m, 0);

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + store[i+j+1];

                store[i+j+1] = sum % 10;
                store[i+j] += sum / 10;
            }
        }

        string result = "";
        for (int num : store) {
            if (!(result.empty() && num == 0)) {
                result += (num + '0');
            }
        }

        return result.empty() ? "0" : result;
    }
};