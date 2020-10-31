//write an algorithm such that if an element in an MxN matrix is zero ,it's entire row or column would be set to zero
class eight{

    static void nullifyRow(int [][] matrix, int row) {
        for(int j = 0;j < matrix[0].length; j++) {
            matrix[row][j] = 0;
        }
    }

    static void nullifyColumn(int [][] matrix, int col) {
        for(int i = 0; i < matrix.length;i++) {
            matrix[i][col] = 0;
        }
    }

    static void setZeroes(int [][] matrix) {
        boolean rowHasZero = false;
        boolean colHasZero = false;

        //check if first row has zero
        for(int i = 0; i< matrix[0].length; i++) {
            if(matrix[0][i] == 0) {
                rowHasZero = true;
                break;
            }
        }

        //check if first column has zero
        for(int j = 0; j < matrix.length; j++) {
            if(matrix[j][0] == 0) {
                colHasZero = true;
                break;
            }
        }

        //check for zeroes in the rest of the array
        for(int i = 1; i < matrix.length; i++) {
            for(int j = 1; j < matrix.length; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //Nullify rows based on values in first column
        for(int i =1; i < matrix.length;i++) {
            if(matrix[i][0] == 0) {
                nullifyRow(matrix, i);
            }
        }
        //Nullify columns based on values in first column
        for(int j =1; j < matrix[0].length;j++) {
            if(matrix[0][j] == 0) {
                nullifyColumn(matrix, j);
            }
        }

        //Nullify first row and column as necesaary
        if(rowHasZero) nullifyRow(matrix, 0);
        if(colHasZero) nullifyColumn(matrix, 0);

    }
    public static void main(String[] args) {
        int matrix[][] = {{2,0,2,3,4,5},{2,1,2,0,4,5},{2,1,2,3,4,5},{2,1,2,3,4,5},{2,1,2,3,4,5},{2,1,2,3,4,5}};
        System.out.println("row = " + matrix.length + "column = " + matrix[0].length);
        setZeroes(matrix);
        System.out.println("After SetZero:");
        for(int i = 0; i< matrix.length; i++) {
            for(int j= 0 ;j< matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}