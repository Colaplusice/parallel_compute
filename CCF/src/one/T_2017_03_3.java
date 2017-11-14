/**
 * 
 */
package one;
import java.util.Scanner;
import java.util.regex.*;
/**
 * @author fanjialiang2401
2017年8月27日
markdown 现在要实现的是  逐行输入 输入没有空格 判断区块 不同区块  用空格隔开
最后全部输出
 */
public class T_2017_03_3 {
public static void main(String[] args) {
Scanner scanner=new Scanner(System.in);
String aString="";
String  sa[]=new String[100];
int sum=0;
boolean end=false;
String perline="";
while (scanner.hasNextLine()) {
	String line =scanner.nextLine();
	if (line.equals("")) {
		if (perline.startsWith("*")) {
			sa[sum++]="</ul>";
			System.out.println(sa[sum-1]);
		}
		continue;
	}
	int num=0;
	
	if ((num=line.indexOf("#"))==0) {
		if (perline.startsWith("#")) {
			perline=line;
			sa[sum++]=deal_h(line);
			System.out.println(sa[sum-1]);
		}
		else if (perline.startsWith("*")) {
			sa[sum++]="</ul>";
			sa[sum++]="";
			perline=sa[sum];
			System.out.println(sa[sum-1]);
		}
		else{
			perline=line;
			sa[sum++]=deal_h(line);
			System.out.println(sa[sum-1]);
		}
}
else if ((num=line.indexOf("*"))==0) {
	if (perline.startsWith("*")) {
		perline=line;
		sa[sum++]=deal_li(line);
		System.out.println(sa[sum-1]);
	}
	else{
		sa[sum++]="";
		System.out.println(sa[sum-1]);
		sa[sum++]="<ul>";
		System.out.println(sa[sum-1]);
		perline=line;
		sa[sum++]=deal_li(line);
		System.out.println(sa[sum-1]);
	}
}
else  {
	
 if (perline.startsWith("#")) {
sa[sum++]=line;	
System.out.println(sa[sum-1]);
}
 else if (perline.startsWith("*")) {
	 sa[sum++]="</ul>";
	 System.out.println(sa[sum-1]);
}
 else {
	 if (line.indexOf("[")!=-1) {
			sa[sum++]=deal_href(line);
			System.out.println(sa[sum-1]);
		}
		 else if (line.indexOf("_")!=-1) {
			sa[sum++]=deal_xia(line);
			System.out.println(sa[sum-1]);
						}
		 else {
			sa[sum++]="<p>"+line+"</p>";
			System.out.println(sa[sum-1]);
		}
}
}
}
for (int i = 0; i < sum; i++) {
	System.out.println(sa[i]);
}
}
public static int  number(String all,String str) {
	int i=all.length()-all.replace("#", "").length();
	return i;
}
public static String  deal_li(String line) {
	line=line.replace("*", "");
	line=line.replace(" ", "");
	line="<li>"+line+"<li>";
 return line;
}
public static void  deal_p(String line) {
}
public static String  deal_h(String line) {
	int n=number(line, "#");
		line=line.replace("#", "");
		line=line.replace(" ", "");
		line="<h"+n+">"+line+"</h"+n+">";
         return line;
}
public static String  deal_href(String aString) {
	aString=aString.substring(0, 2)+aString.substring(8);
	aString=aString.replace("(", "<a href=\"");
	aString=aString.replace(")", "\">link</a>");
	aString="<p>"+aString+"</p>";
	return aString;
}
public static String deal_xia (String aString ) {
	boolean is=false;
	while (aString.indexOf("_")!=-1 ) {
		if (is==false) {
			int n=aString.indexOf("_");
			aString=aString.substring(0, n)+"<em>"+aString.substring(n+1);
			is=true;
		}
		else {
			int n=aString.indexOf("_");
			aString=aString.substring(0,n)+"</em>"+aString.substring(n+1);
		}
	}
	aString="<p>"+aString+"</p>";
	return aString;
	
}
}
