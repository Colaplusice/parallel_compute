package one;
import java.util.Scanner;
public class T_2016_12_1 {
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
       int half=n/2;
  int t=0,w=0;
       for (int i = 0; i < st.length; i++) {
		if (a[i]>a[half]) {
			t++;
		}
		else if (a[i]==a[half]) {
			continue;
		}
		else{
			w++;
		}
	}
		if (t==w) {
			System.out.println(a[half]);
		}
		else {
			System.out.println(-1);
		}
	} catch (Exception e) {
	e.printStackTrace();

	}
	in.close();
}
}
