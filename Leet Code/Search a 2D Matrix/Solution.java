class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; i++) {
            if(matrix[i][0] <= target && matrix[i][m-1] >= target )
                if (bs(matrix[i], target))
                    return true;
                else
                    break;
        }
        return false;
    }

    public boolean bs(int[] arr, int t) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (arr[m] == t)
                return true;
            else if (arr[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
}
