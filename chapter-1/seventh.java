class seventh{
    static boolean rotate(int [][] matrix) {
        if(matrix.length == 0 || matrix.length != matrix[0].length) return false;
        int n = matrix.length;//4

        for(int layer = 0; layer < n/2; layer++) {
            int first = layer;//0 then 1 coz less than n/2
            int last = n - 1 -layer;//4-1-0,4-1-1  last =3,2
            for(int i = first;i < last ; i++) {
                int offset = i - first;//loop from 0-> 3  offset = 0,1,2  then for last->offset=0,1
                int top = matrix[first][i]; //[0][0],[0][1],[0][2]
                //left -> top
                matrix[first][i] = matrix[last-offset][first];//[0][0] = [3][0]

                //bottom->left
                matrix[last-offset][first] = matrix[last][last-offset];//[3][0] = [3][3]

                //right->bottom
                matrix[last][last-offset] = matrix[i][last];//[3][3] = [0][3]

                //top->right
                matrix[i][last] = top;//[0][3] = [0][0]
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int matrix[][] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
        System.out.println("row = " + matrix.length + "column = " + matrix[0].length);
        System.out.println("Before Rotating:");
        for(int i = 0; i< matrix.length; i++) {
            for(int j= 0 ;j< matrix[0].length; j++) {
                System.out.print(matrix[i][j] + "    ");
            }
            System.out.println();
        }
        rotate(matrix);
        System.out.println("After Rotating:");
        for(int i = 0; i< matrix.length; i++) {
            for(int j= 0 ;j< matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}