import java.util.*;
public class Main
{
    public static void buildSegTree(int []arr,int []segTree,int ind,int left,int right){
        
        if(left == right){
            segTree[ind] = arr[left];
            return ;
        }
        int mid = (int)((left + right) / 2);
        buildSegTree(arr,segTree,2*ind+1,left,mid);
        buildSegTree(arr,segTree,2*ind+2,mid+1,right);
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
        // segTree[ind] = Math.max(segTree[2*ind+1] , segTree[2*ind+2]);
    }
    public static void updatePoint(int []arr,int []segTree,int ind,int key,int val,int left,int right){
        if(left == right && left == key){
            arr[left] += val;
            segTree[ind] += val;
            return ;
        }
        int mid = (int)(left+right) / 2;
        if(left <= key && key <= mid){
            updatePoint(arr,segTree,2*ind+1,key,val,left,mid);
        }
        else{
            updatePoint(arr,segTree,2*ind+2,key,val,mid+1,right);
        }
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
    }
    public static int rangeSum(int []segTree,int ind,int segLeft,int segRight,int queryLeft,int queryRight){
        if(segLeft >= queryLeft && segRight <= queryRight) return segTree[ind];
        if(segLeft > queryRight || segRight < queryLeft) return 0;
        else{
            int mid = (int)(segLeft + segRight) / 2;
            return rangeSum(segTree,2*ind+1,segLeft,mid,queryLeft,queryRight) + rangeSum(segTree,2*ind+2,mid+1,segRight,queryLeft,queryRight);
        }
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter the size of array:- ");
	    int n,q;
	    n = sc.nextInt();
	    int []arr = new int[n];
	    int []segTree = new int[4*n];
	    for(int i = 0;i<n;i++) arr[i] = sc.nextInt();
	    buildSegTree(arr,segTree,0,0,n-1);
	    System.out.print("Enter the number of queries:- ");
	    q = sc.nextInt();
	    while(q > 0){
	        int choice;
	        System.out.println("1. Update a value in array\n2. Find sum of a range");
	        choice = sc.nextInt();
	        if(choice == 1){
	            System.out.print("Enter the index and value:- ");
	            int key,val;
	            key = sc.nextInt();
	            val = sc.nextInt();
	            updatePoint(arr,segTree,0,key,val,0,n-1);
	            System.out.println("Updated array is :- ");
	            for(int i = 0;i<n;i++) System.out.print(arr[i] + " ");
	            System.out.println();
	        }else if(choice == 2){
	            int queryLeft , queryRight;
    	        System.out.print("Enter left and right bound of a query:- ");
    	        queryLeft = sc.nextInt();
    	        queryRight  = sc.nextInt();
    	        
    	        int ans = rangeSum(segTree,0,0,n-1,queryLeft,queryRight);
    	        System.out.println(ans);
	        }
	        
	        q--;
	    }
		
	}
}
