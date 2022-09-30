import java.util.Arrays;

/**
 * SelectionSort
 */
public class SelectionSort {

    public static void print(int[] arr, int r, int c, int max) {
        if(r == 0)
            return;
        
        if(c < r) {
            if (arr[c] > arr[max]) { // Ascending - arr[c] > arr[c+1], Descending - arr[c] < arr[c+1] 
                print(arr, r, c+1, c);
            } else {
                print(arr, r, c+1, max);
            }
        } else {
            int temp = arr[max];
            arr[max] = arr[r-1];
            arr[r-1] = temp;
            print(arr, r - 1, 0, 0);
        }
    }
    public static void Selection(int[] arr) {
        print(arr, arr.length, 0, 0);
    }
    public static void main(String[] args) {
        int[] arr = {7,8,4,6,5,1,2,3};
        Selection(arr);
        System.out.println(Arrays.toString(arr));
    }
}