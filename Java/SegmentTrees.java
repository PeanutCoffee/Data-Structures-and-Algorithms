
public class SegmentTrees {
    long[] sum;
    int size;
    SegmentTrees(int n){
        size = 1;
        while(size<=n) size *= 2;
        sum = new long[2*size -1];
    }

    private void build(int[] arr, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<arr.length){
                sum[x] = arr[lx];
            }
            return;
        }
        int mid = (lx+rx)/2;
        build(arr, x*2+1, lx, mid);
        build(arr, x*2+2, mid, rx);
        sum[x] = sum[x*2+1] + sum[x*2+2];
    }

    public void build(int[] arr){
        build(arr, 0, 0, size);
    }

    public void set(int idx, int val){
        set(idx, val, 0, 0, size);
    }

    private void set(int idx, int val, int x, int lx, int rx){
        if(rx-lx==1){
            sum[x] = val;
            return;
        }
        int mid = (lx+rx)/2;
        if(mid<=idx){
            set(idx, val, 2*x+2, mid, rx);
        }
        else{
            set(idx, val, 2*x+1, lx, mid);
        }
        sum[x] = sum[x*2+1] + sum[x*2+2];
    }

    public long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }

    private long sum(int l, int r, int x, int lx, int rx){
        // System.out.println("l:"+l+" r:"+r+" lx:"+lx+" rx"+rx);
        if(l>=rx || r<=lx) //case 1: outside range
            return 0;
        else if(l<=lx && r>=rx)
            return sum[x];
        else  //case3: completely in range
        {
            int mid = (lx+rx)/2;
            return sum(l, r, x*2+1, lx, mid) + sum(l, r, x*2+2, mid, rx);
        }
    }
}
