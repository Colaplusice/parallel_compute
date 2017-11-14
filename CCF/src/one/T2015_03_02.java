/**
 * 
 */
package one;
import java.util.Scanner;
/**
 * @author fanjialiang2401
2017年9月14日
 */
public class T2015_03_02 {
public static void main(String[] args) {
	//input
	Scanner scanner=new Scanner(System.in);
	String num=scanner.nextLine();
   int number=Integer.parseInt(num);
	  String all=scanner.nextLine();
	  String sd[]=all.split(" ");
	  int sm[]=new int [sd.length];
	  for (int i = 0; i < sd.length; i++) {
		sm[i]=Integer.parseInt(sd[i]);
	}
	  //deal
	  int sf[]=new int [sd.length];
	  for (int i = 0; i < sf.length; i++) {
		sf[i]=1;
	}
	  for (int i = 0; i < sm.length; i++) {
		  int temp=sm[i];
	for (int j = i; j < sm.length; j++) {
		if (sm[j]==temp) {
			sf[temp]++;
		}
	}
	}
	  for (int i = 0; i < sf.length; i++) {
		System.out.println(sf[i]);
	}
}  
}