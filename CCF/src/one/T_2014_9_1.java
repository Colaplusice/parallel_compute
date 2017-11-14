/**
 * 
 */
package one;
import java.util.Scanner;
/**
 * @author fanjialiang2401
2017年9月12日
 */
public class T_2014_9_1 {
public static void main(String[] args) {

	//input
	Scanner in=new Scanner(System.in);
	String xString;
	xString=in.nextLine();
	try {
		int n=Integer.parseInt(xString);
		if (n>1000||n<1) {
			throw new Exception();
		}
		int a[]=new int [n];
			String str=in.nextLine();
			String st[]=str.split(" ");
			for(int i=0;i<st.length;i++){
				a[i]=Integer.parseInt(st[i]);
				if (a[i]>1000||a[i]<1) {
					throw new Exception();
				}
			}
			//sort
		for (int j = 0; j < a.length; j++)  {
			for (int i = 0; i < a.length-1-j; i++){
			if (a[i]>a[i+1]) {
				int temp;
				temp=a[i+1];
				a[i+1]=a[i];
				a[i]=temp;
			}
		}
		}
		//deal
		int all=0;
     for (int i = 0; i < st.length; i++) {
		for (int j = 0; j < st.length; j++) {
			if (a[i]-1==a[j]) {
				all++;
			}
		}
	}
       System.out.println(all);
	} catch (Exception e) {
	e.printStackTrace();
	}
	in.close();
}
}
