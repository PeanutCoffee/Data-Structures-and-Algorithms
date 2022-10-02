public class DynamicStack {
    int capacity = 2;

    int stack[] = new int[capacity];
    int top = 0;
    
    public void push(int data) {
        if (top == capacity) {
            // System.out.println("Stack is full");
            expand();
        } else {
            stack[top++] = data;
        }
    }
    public int pop() {
        int data = 0;
        if(isEmpty()) {
            System.out.println("Stack is empty");
        } else {
            data = stack[top--];
            stack[top] = 0;
            shrink();
        }
        return data;
    }
    public int peek() {
        int data;
        data = stack[top-1];
        return data;
    }
    public int size() {
        return top;
    }
    public boolean isEmpty() {
        return top<=0;
    }
    public void show() {
        for (int i : stack) {
            System.out.print(i+" ");   
        }
        System.out.println();
    }
    public void expand() {
        int length = size();
        int newStack[] = new int[capacity*2];
        System.arraycopy(stack, 0  , newStack, 0, length);
        stack = newStack;
        capacity *= 2;
    }
    private void shrink() {
        int length = size();
        if(length<=(capacity/2)/2) {
            capacity = capacity/2;
        }
        int newStack[] = new int[capacity];
        System.arraycopy(stack, 0  , newStack, 0, length);
        stack = newStack;
    }
}
