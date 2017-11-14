/**
 * 
 */
package one;
import java.util.Scanner;
public class T2017_03_4{
public static void main(String[] args) {
	Scanner scanner=new Scanner(System.in);
	String s=scanner.nextLine();
	String sd[]=s.split(" ");
	String road[][]=new String[Integer.parseInt(sd[1])][];
int maxint=99;
	int len=Integer.parseInt(sd[0]);
	int sum[][]=new int [len+1][len+1];
	int flag[]=new int [len+1];
	for (int i = 0; i < len+1; i++) {
		for (int j = 0; j <len+1; j++) {
            sum[i][j]=maxint;
		}
	}
		for (int i = 0; i <Integer.parseInt(sd[1]); i++) {
			String ro=scanner.nextLine();
		     road[i]=ro.split(" ");
		     sum[Integer.parseInt(road[i][0])][Integer.parseInt(road[i][1])]=Integer.parseInt(road[i][2]);
		     sum[Integer.parseInt(road[i][1])][Integer.parseInt(road[i][0])]=Integer.parseInt(road[i][2]);
		}
		int di= DJSTL(sum);
			System.out.println(di);
}
public static int DJSTL(int sum[][]){
	int len=sum.length;
	 int distance=0;
	int dis[]=new int[len];
	for (int i = 0; i < dis.length; i++) {
		dis[i]=99;
	}
	for (int i = 2; i < dis.length; i++) {
		dis[i]=sum[i][1];
	}
	int flag[]=new int [len];
	for (int i =1; i <flag.length; i++) {
		if (i==1) {
			flag[1]=1;
			continue;
		}
		else{
			flag[i]=0;
		}
	}
	for(int i=2;i<=flag.length;i++){
		int temp=99;
	     int u=1;
	     for (int j = 1; j < dis.length; j++) {
	    	 if (flag[j]==0&&dis[j]<temp) {
					temp=dis[j];
					u=j;
				}
		}
		 flag[u]=1;
		
		for (int j = 1; j < dis.length; j++) {
			if (flag[j]==0&&sum[j][u]<99) {
				int newdist=dis[u]+sum[j][u];
				if (newdist<dis[j]) {
					dis[j]=newdist;
					if (sum[j][u]>distance) {
						distance=sum[j][u];
					}
				}else {
				}
			}
			else{
			}
		}
	}
	return distance;
}
}
