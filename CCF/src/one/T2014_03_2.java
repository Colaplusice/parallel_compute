/**
 * 
 */
package one;

import java.util.Scanner;

/**
 * @author fanjialiang2401
2017年9月13日
 */

public class T2014_03_2 {
public static void main(String[] args) {
	//input
	Scanner scanner=new Scanner(System.in);
	String deal=scanner.nextLine();
String de[]=deal.split(" ");
int all=Integer.parseInt(de[0]);
int input=Integer.parseInt(de[1]);
int tu[][]=new int [all][4];

for (int i = 0; i < tu.length; i++) {
	String xString=scanner.nextLine();
	String string[]=xString.split(" ");
	for (int j = 0; j < string.length; j++) {
		tu[i][j]=Integer.parseInt(string[j]);
	}
}
//标记位
int flag[]=new int [tu.length];
for (int i = 0; i < flag.length; i++) {
	flag[i]=0;
}
String output[]=new String[input];
for (int i = 0; i < output.length; i++) {
	output[i]="1";
}
//deal
for (int i = 0; i < input; i++) {
	int x[][]=new int [input][2];
	String string=scanner.nextLine();
	String string2[]=string.split(" ");
    for (int j = 0; j < string2.length; j++) {
		x[i][j]=Integer.parseInt(string2[j]);
	}
    int which=0;
   for (int j = 0; j <tu.length; j++) {
	if ((tu[j][0]<=x[i][0]&&x[i][0]<=tu[j][2])&&(tu[j][1]<=x[i][1]&&x[i][0]<=tu[j][3])) {
        if (flag[j]==0) {
			which=j;
		}
        else{
        	which=j;
        	output[i]=which+++"";
        	break;
        }
        int sd=which;
        output[i]=sd+++"";
	}
	  else {
			if (output[i]=="1") {
				output[i]="IGNORED"; 
			}
}
}
   flag[which]=1;
   //System.out.println("which"+which);
}
for (int i = 0; i < output.length; i++) {
	System.out.println(output[i]);
}

}
}
