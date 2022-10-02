// Author: PunGrumpy
// Description: Christmas Tree

class ChristmasTree {
    public static final String RESET = "\u001B[0m";
    public static final String GREEN = "\u001B[32m";
    public static final String BLACK = "\u001B[30m";
    
    public static void main(String args[]) {
        int step = 5;
        int start = 0;
        int leaves = 4;
        int space = leaves * 4;
        int stem = leaves;
        int height = 1;
        
        // Leaf
        for(int xmas = 1; xmas <= leaves; xmas++) {
          for(int i = start; i <= step; i++) {
            for(int j = space; j > i; j--) {
              System.out.print(" ");
            }
            for(int k = 1; k <= i; k++) {
              System.out.print(GREEN + "* " + RESET);
            }
            System.out.println();
          }
          start +=3;
          step += 3;
        }
    
        // Stem
        for  (int i = 0; i < stem + height; i++) {
          for (int j = 0; j <= stem + 1; j++) {
              System.out.print("  ");
          }
          for (int k = 0; k < stem; k++) {
              System.out.print(BLACK + "* " + RESET);
          }
          System.out.println();
        }
    }
}
    