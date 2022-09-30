import java.util.Arrays;

/**
 * BubbleSort
 */
public class BubbleSort {

    public static void print(int[] arr, int r, int c) {
        if(r == 0)
            return;
        
        if(c < r) {
            if (arr[c] > arr[c+1]) { // Ascending - arr[c] > arr[c+1], Descending - arr[c] < arr[c+1] 
                int temp = arr[c];
                arr[c] = arr[c+1];
                arr[c+1] = temp;
            }
            print(arr, r, c + 1);
        } else {
            print(arr, r - 1, 0);
        }
    }
    public static void BubbleSort(int[] arr) {
        print(arr,arr.length - 1,0);
    }
    public static void main(String[] args) {
        int[] arr = {7,8,4,6,5,1,2,3};
        BubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}