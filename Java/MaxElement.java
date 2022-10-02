class MaxElement {
    public static final String RESET = "\u001B[0m";
    public static final String RED = "\u001B[31m";
    
    static int maxElement(int[] arr) {
        int max = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
    
    public static void main(String[] args) {
        int[] data = {7, 1, 2, -1, 3, 4, 10, -12, 3, 21, -9};
        System.out.println(RED + maxElement(data) + RESET);
    }    
}
