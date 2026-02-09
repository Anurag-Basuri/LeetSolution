class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int count = 0, r = 0;

        for (char car : directions) {
            if (!st.empty()) {
                if (car == 'L' && st.top() == 'S')
                    count++;
                else if (car == 'L' && st.top() == 'R') {
                    count += r + 1;
                    r = 0;
                    st.push('S');
                } else if (car == 'S' && st.top() == 'R') {
                    count += r;
                    r = 0;
                    st.push(car);
                } else
                    st.push(car);
            } else if (car != 'L')
                st.push(car);
            
            if(car == 'R') r++;
        }

        return count;
    }
};