/**
 * 
 */
package one;
import java.util.Scanner;
public class T_2014_9_2 {
public static void main(String[] args) {
	//input
		Scanner in=new Scanner(System.in);
		String xString;
		xString=in.nextLine();
		try {
			int n=Integer.parseInt(xString);
			if (n>1000||n<0) {
				throw new Exception();
			}
			int a[][]=new int [n][4];
			for (int i = 0; i < a.length; i++) {
				String str=in.nextLine();
				String st[]=str.split(" ");
				for(int j=0;j<st.length;j++){
					a[i][j]=Integer.parseInt(st[j]);
					if (a[i][j]>1000||a[i][j]<0) {
						throw new Exception();
					}
				}
			}
			//deal
			int size=0;
			int squar[][] =new int [100][100];
			for (int i = 0; i < squar.length; i++) {
				for (int j = 0; j < squar.length; j++) {
					squar[i][j]=0;
				}
			}
                for (int i = 0; i < a.length; i++) {
					for (int j = a[i][0]; j <a[i][2]; j++) {
					for (int j2 = a[i][1]; j2 <a[i][3]; j2++) {
						squar[j][j2]=1;
					}
					}
				}
for (int i = 0; i < squar.length; i++) {
	for (int j = 0; j < squar.length; j++) {
		if (squar[i][j]==1) {
			size++;
		}
	}
}
System.out.println(size);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
}
}