/**
 * 
 */
package one;

import java.util.Scanner;

/**
 * @author fanjialiang2401
2017年9月13日
 */
public class T2014_12_1 {
	public static void main(String[] args) {
Scanner scanner=new Scanner(System.in);
int  all=Integer.parseInt( scanner.nextLine());
int sd[]=new int [all];
String ssd[]=new String[all];
 String str=scanner.nextLine();
  ssd=str.split(" ");
 for (int i = 0; i < sd.length; i++) {
	sd[i]=Integer.parseInt(ssd[i]);
}
 int sum[]=new int [sd.length];
for (int i = 0; i < sum.length; i++) {
sum[i]=1;
	
}
for (int i = 0; i < sd.length; i++) {
	for (int j = 0; j <i; j++) {
     if (sd[i]==sd[j]) {
		sum[i]++;
	}
	}
}
for (int i = 0; i < sum.length; i++) {
	System.out.print(sum[i]+" ");
}
	}

}
