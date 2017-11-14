/**
 * 
 */
package t2017_9;

import java.util.Scanner;

/**
 * @author fanjialiang2401
2017年9月21日
10块钱一瓶酱油，买3瓶送一瓶，买5瓶送两瓶，问最多能买多少瓶
60
8
 */

public class First {
public static void main(String[] args) {
	Scanner scanner=new Scanner(System.in);
	String string=scanner.nextLine();
	int money=Integer.parseInt(string);
	int sum=0;
	money=money/10;
	sum=(money/5)*7;
	money=money%5;
	sum+=(money/3)*4;
	money=money%3;
	sum+=money;
	System.out.println(sum);
}
}
