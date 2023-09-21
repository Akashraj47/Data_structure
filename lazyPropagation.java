// Range Update and Range Sum (Segment Tree with lazy propagation)

import java.util.Scanner;
public class Main
{
    public static void updateRange(int []arr,int []segTree,int []lazy,int ind,int low,int high,int val,int segLeft,int segRight){
        if(lazy[ind] != 0){
            segTree[ind] += (segRight - segLeft + 1) * lazy[ind];
            if(segLeft != segRight){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        
        if(segRight < low || high < segLeft ) return ;
        
        else if(low <= segLeft &&  segRight <= high){
            segTree[ind] += (segRight - segLeft + 1) * val;
            if(segLeft != segRight){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            lazy[ind] = 0;
        }
        
        else{
            int mid = (segLeft + segRight) / 2;
            updateRange(arr,segTree,lazy,2*ind+1,low,high,val,segLeft,mid);
            updateRange(arr,segTree,lazy,2*ind+2,low,high,val,mid+1,segRight);
            segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
        }
    }
    public static int rangeSum(int []arr,int []segTree,int []lazy,int ind,int low,int high,int segLeft,int segRight){
        if(lazy[ind] != 0){
            segTree[ind] += (segRight - segLeft + 1) * lazy[ind];
            if(segLeft != segRight){
                lazy[2*ind+1] = lazy[ind];
                lazy[2*ind+2] = lazy[ind];
            }
            lazy[ind] = 0;
        }
        
        if(segRight < low || high < segLeft) return 0;
        
        else if(segLeft >= low && segRight <= high){
            return segTree[ind];
        }
        
        else{
            int mid = (segLeft + segRight) / 2;
            return rangeSum(arr,segTree,lazy,2*ind+1,low,high,segLeft,mid) + rangeSum(arr,segTree,lazy,2*ind+2,low,high,mid+1,segRight);
        }
    }
    public static void buildSegTree(int []arr,int []segTree,int ind,int left,int right){
        if(left == right){
            segTree[ind] = arr[left];
            return ;
        }
        int mid = (left + right) / 2;
        buildSegTree(arr,segTree,2*ind+1,left,mid);
        buildSegTree(arr,segTree,2*ind+2,mid+1,right);
        segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter size of an array:- ");
	    int n;
	    n = sc.nextInt();
	    int []arr = new int[n];
	    int []segTree = new int[4*n];
	    int []lazy = new int[4*n];
	    
	    System.out.println("Enter value in array:- ");
	    for(int i = 0;i<n;i++) arr[i] = sc.nextInt();
	    buildSegTree(arr,segTree,0,0,n-1);
	    int q;
	    System.out.println("Enter number of queries:- ");
	    q = sc.nextInt();
	    while(q > 0){
	        System.out.println("Select an option:- \n1. Update a Range\n2. Sum of a Range");
	        int choice;
	        choice = sc.nextInt();
	        if(choice == 1){
	            System.out.println("Enter left, right and value to update of a range:- ");
	            int low,high,val;
	            low = sc.nextInt();
	            high = sc.nextInt();
	            val = sc.nextInt();
	            updateRange(arr,segTree,lazy,0,low,high,val,0,n-1);
	        }
	        else if(choice == 2){
	            System.out.println("Enter left and right to find sum of a range:- ");
	            int low,high;
	            low = sc.nextInt();
	            high = sc.nextInt();
	            int sum = 0;
	            sum = rangeSum(arr,segTree,lazy,0,low,high,0,n-1);
	            System.out.println(sum);
	        }
	        q--;
	    }
	     
	}
}
