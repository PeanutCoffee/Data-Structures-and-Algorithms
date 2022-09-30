public class Triangle {
    public static void printInc(int r, int c) {
        if(r == 0)
            return;
        if(c < r) {
            printInc(r, c + 1);
            System.out.print("* ");
            
        } else {
            printInc(r - 1, 0);
            System.out.println();
            
        }
    }

    public static void printDec(int r, int c) {
        if(r == 0)
            return;
        if(c < r) {
            System.out.print("* ");
            printDec(r, c + 1);
            
        } else {
            System.out.println();
            printDec(r - 1, 0);
            
        }
    }

    public static void triangle(int n) {
        // printInc(n, 0);
        printDec(n, 0);

    }
    public static void main(String[] args) {
        triangle(5);
    }
}
