package one;

import java.util.Scanner;

public class T_2016_12_3 {
public static void main(String[] args) {
	int n;
	Scanner in=new Scanner(System.in);
	//
	n=in.nextInt();//权利数
	String s[]=new String[n];
	for (int i = 0; i < n; i++) {
	//	s[i]=System.in();
	}
	power sum[]=new  power[n];//权限的储存
//	for (int i = 0; i < sum.length; i++) {
//		if (Character.isDigit(s[i].charAt(s[i].length()-1))) {
//			int num=s[i].charAt(s[i].length());
//			sum[i]=new power(s[i], num);
//		}
//		else
//		{
//			sum[i]=new power(s[i]);
//		}
//	}
	for (int i = 0; i < sum.length; i++) {//检测
		System.out.println(s[i]);
	}
	
}
}
class power{
	String name;
	public power(String name) {
		this.name=name;//无等级权限
		
	}
	int num;
	public power(String name,int num) {
		this.name=name;
		this.num=num;//有等级权限
	}
}
class Rol{
	String name;
	int number;
	public Rol(String name, int number) {
		this.name=name;
		this.number=number;
		        //角色名字，权限数量	
	}
	
}