class Solution {
    public int maximalSquare(char[][] matrix) {

        for (int i = 0; i < matrix.length - 1; i++) {
            for (int j = 0; j < matrix[0].length - 1; j++) {
                if (matrix[i][j] != '0' && matrix[i + 1][j] != '0' && matrix[i][j + 1] != '0'
                        && matrix[i + 1][j + 1] != '0') {
                    int a = matrix[i][j] - '0';
                    int b = matrix[i + 1][j] - '0';
                    int c = matrix[i][j + 1] - '0';

                    int min = Math.min(a, Math.min(b, c));

                    matrix[i + 1][j + 1] = (char) (min + 1 + '0');
                }
            }
        }

        int max = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                max = Math.max(max, matrix[i][j] - '0');
            }
        }

        return max * max;
    }
}