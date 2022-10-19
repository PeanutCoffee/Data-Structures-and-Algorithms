fn main() {
    // sorting integers
    let mut numbers = [4, 5, 6, 32, 1, 10, 9, -1]; // change array if required
    println!("Before: {:?}", numbers);
    bubble_sort(&mut numbers);
    println!("After: {:?}", numbers);

    // sorting strings
    let mut strings = ["beach", "hotel", "airplane", "car", "house", "art"];
    println!("Before {:?}", strings);
    bubble_sort(&mut strings);
    println!("After {:?}", strings);
}

// using generic datatype T with Ord trait 
pub fn bubble_sort<T: Ord>(arr: &mut [T]) {
    for i in 0..arr.len() {
        for j in 0..arr.len() - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}
