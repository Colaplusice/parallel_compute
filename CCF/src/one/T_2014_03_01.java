/**
 * 
 */
package one;

import java.util.Scanner;

public class T_2014_03_01 {
	public static void main(String[] args) {
		//input
Scanner scanner=new Scanner(System.in);
String num=scanner.nextLine();
String x=scanner.nextLine();
String sum[]=x.split(" ");
int all[]=new int [sum.length];
for (int i = 0; i < sum.length; i++) {
	all[i]=Integer.parseInt(sum[i]);
}
	//deal
	int s=0;
	for (int j = 0; j < all.length; j++) {
		for (int j2 = 0; j2 < all.length; j2++) {
			if (all[j]+all[j2]==0) {
				s++;
			}
		}
		
	}
	System.out.println(s/2);

	
	}
}
