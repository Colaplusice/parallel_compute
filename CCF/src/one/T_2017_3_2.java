/**
 * 
 */
package one;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/**
 * @author fanjialiang2401
2017年8月24日
 */

public class T_2017_3_2 {
	public static void main(String[] args) {
		try{
		Scanner ac=new Scanner(System.in);
		//总数
		int sum=Integer.parseInt(ac.nextLine());
		if (1000<sum||sum<1) {
			throw  new Exception();
		}
		List<Integer> aList=new ArrayList<>();
		int all[]=new int [sum];
		//操作次数
		int s=Integer.parseInt(ac.nextLine());
	for (int i = 1; i <=sum; i++) {
			aList.add(i);
		}
	for(int i=0;i<all.length;i++){
		all[i]=i+1;
	}
		
	//每次的具体操作
		  for(int i=0;i<s; i++)
		  {
			  String sd=ac.nextLine();
				String t[]=sd.split(" ");
				int which=0;
				for(int m=0;m<sum;m++){
				if (all[m]==Integer.parseInt(t[0])) {
					which=m;
				}	
				}
				int temp=all[which];
				if (Integer.parseInt(t[1])>0) {
					for (int j=which; j <Integer.parseInt(t[1])+which; j++) {
			       		 all[j]=all[j+1];
					}
					all[Integer.parseInt(t[1])+which]=temp;
				}
				else if (Integer.parseInt(t[1])<0) {
					for (int j=which; j >which+Integer.parseInt(t[1]) ; j--) {
			       		all[j]=all[j-1];
					}
					all[which+Integer.parseInt(t[1])]=temp;
				}
		  }
		  
		  //output
		  for (int i = 0; i < all.length; i++) {
			System.out.print(all[i]+" ");
		}
		}
		catch (Exception e) {
e.printStackTrace();
		}
		
	}
}
