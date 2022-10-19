//package LinkedList;
//
public class LinkedList{
    //
        Node head;
        Node tail;
        int size;
        public LL(){ this.size = 0;}
    
        public static void main(String[] args) {
            LL list = new LL();
            for (int i = 7; i > 0; i--) {
                list.insertLast(i);
            }
            list.display();
            list.bubbleSort();
            list.display();
        }
        class ListNode {
            int val;
            LLPrac.ListNode next;
    
            public ListNode() {
            }
    
            ListNode(int x){
                val = x;
                next = null;
            }
        }
    //
        //Recursion reverse
        private void reverseRec(Node node){
            if (node == tail){
                head = tail;
                return;
            }
            reverseRec(node.next);
            tail.next = node;
            tail = node;
            tail.next = null;
        }
    //    //in place reversal
    //    // EAsy  https://leetcode.com/problems/reverse-linked-list
        public ListNode reverseList(ListNode head) {
            if (head == null){
                return head;
            }
            ListNode prev = null;
            ListNode present = head;
            ListNode next = head.next;
    
            while (present != null){
                present.next = prev;
                prev = present;
                present = next;
                if (next != null){
                    next = next.next;
                }
            }
            return prev;
        }
    //
    //    //Easy https://leetcode.com/problems/intersection-of-two-linked-lists
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            if(headA == null || headB == null) return null;
            ListNode s1 = headA;
            ListNode s2 = headB;
            while(s1 != s2){
                s1 = s1 == null? headB : s1.next;
                s2 = s2 == null? headA : s2.next;
            }
            return s1;
            
        }
    
        // Bubble Sort
        public void bubbleSort(){
            bubbleSort(size-1,0);
        }
        private void bubbleSort(int row, int col){
            if (row == 0){
                return;
            }
    
            if (col < row){
                Node first = get(col);
                Node second = get(col + 1);
    
                if (first.val > second.val){
                    //swap
                    if(first == head){
                        head = second;
                        first.next = second.next;
                        second.next = first;
                    }else if (second == tail){
                        Node prev = get(col-1);
                        prev.next = second;
                        tail = first;
                        first.next = null;
                        second.next = tail;
                    }else{
                        Node prev = get(col-1);
                        prev.next = second;
                        first.next = second.next;
                        second.next = first;
                    }
                }
                bubbleSort(row, col+1);
            }else{
                bubbleSort(row-1,0);
            }
        }
        // BubbleSort End
    
       public void insertFirst(int val){
            Node node = new Node(val);
                node.next = head;
                head = node;
            if(tail == null) tail = head;
            size++;
        }
    
        public void display(){
            Node temp = head;
            while(temp != null){
                System.out.print(temp.val + " -> ");
                temp = temp.next;
            }
            System.out.println("END");
        }
        public void insertLast(int val){
            if(tail == null) {
                insertFirst(val);
                return;
            }
            Node node = new Node(val);
            tail.next = node;
            tail = node;
            size += 1;
        }
    
        public void insert(int val ,int index){
            if(index == 0) insertFirst(val);
            if(index == size) insertLast(val);
    
            Node temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp.next;
            }
            Node node = new Node(val,temp.next);
            temp.next = node;
            size++;
        }
    
        public int deleteFirst(){
            int value = head.val;
            head = head.next;
            if(head == null) tail = null;
            size--;
            return value;
        }
    
        public int deleteLast(){
            if(size <= 1) return deleteFirst();
            Node secondLast = get(size-2);
            int val = tail.val;
            tail = secondLast;
            tail.next = null;
            size--;
            return val;
        }
    
        public int delete(int index){
            if(index == 0) return deleteFirst();
            if(index == size-1) return deleteLast();
            Node prev = get(index-1);
            int value = prev.next.val;
            prev.next = prev.next.next;
            size--;
            return value;
        }
    
        public int find(int value){
            Node node = head;
            while(node != null){
                if(node.val == value) {return node.val;}
    
                node = node.next;
            }
            return -1;
        }
    
        public Node get(int index){
            Node node = head;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        }
    
        public void insertRec(int val, int index){
            head = insertRec(val, index, head);
    
        }
    
        private Node insertRec(int val , int index,Node Currentnode){
            if(index == 0){
                Node node = new Node(val,Currentnode);
                size++;
                return node;
            }
            Currentnode.next = insertRec(val, --index, Currentnode.next);
            return Currentnode;
        }
    
        class Node {
            int val;
            Node next;
    
            public Node(int val){
              this.val = val;
            }
            public Node(int val,Node next){
                this.val = val;
                this.next = next;
            }
        }
    }
    