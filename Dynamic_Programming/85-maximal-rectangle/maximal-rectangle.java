class Solution {
    int histomax(int[] arr, int n){
        Stack<Integer> st = new Stack<>();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.peek()] > arr[i]){
                int el = st.pop();
                int l = st.empty()? -1:st.peek();
                maxArea = Math.max(maxArea, (i - l - 1) * arr[el]);
            }

            st.push(i);
        }

        while(!st.empty()){
            int el = st.pop();
            int l = st.empty()? -1:st.peek();
            maxArea = Math.max(maxArea, (n - l - 1) * arr[el]);
        }

        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int arr[][] = new int[n][m];
        int sum = 0;

        for(int j = 0; j < m; j++){
            sum = 0;
            for(int i = 0; i < n; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0') sum = 0;
                arr[i][j] = sum;
            }
        }
        sum = 0;

        for(int[] i:arr){
            sum = Math.max(sum, histomax(i, m));
        }

        return sum;
    }
}