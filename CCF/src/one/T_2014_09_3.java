/**
 * 
 */
package one;

import java.util.Scanner;
/**
 * @author fanjialiang2401
2017年9月13日
 */
public class T_2014_09_3 {
	public static void main(String[] args) {
Scanner scanner=new Scanner(System.in);
String string=scanner.nextLine();
try {
	int  is= Integer.parseInt(scanner.nextLine());
	int num=Integer.parseInt(scanner.nextLine());;
	String all[]=new String[num];
	String right[]=new String[num];
	for (int i = 0; i < all.length; i++) {
		 all[i]=scanner.nextLine();
	    right[i]="";
	}
	for (int i = 0; i < all.length; i++) {
		if (is==1) {
			if (all[i].indexOf(string)!=-1) {
				right[i]=all[i];
			}
		}
		else if (is==0) {
		  String low[]=new String[right.length];
		  String aString=string.toLowerCase();
			for (int j = 0; j < right.length; j++) {
              low[j]=all[j].toLowerCase();			
		}
			for (int j = 0; j < low.length; j++) {
				if (low[j].indexOf(aString)!=-1) {
					right[j]=all[j];
				}
			}
		}  	
	}
	for (int i = 0; i < right.length; i++) {
		if (right[i]=="") {
			continue;
		}
		System.out.println(right[i]);
	}
}
catch (Exception e) {
e.printStackTrace();
}
	}
}
