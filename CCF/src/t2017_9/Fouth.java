package t2017_9;
import java.util.Scanner;
public class Fouth{
	/**@author : fjl2401 创建时间：2017年11月11日 下午11:35:48   
	4 4
	1 2
	1 3
	2 4
	3 4
	2 1
	3 1
	4 2
	4 3
	 * */
		int flag[];
		int m;
		 public Fouth() {
	m=0;
		}
	public int[][] input(){
		//input
			Scanner scanner=new Scanner(System.in);
			String xString=scanner.nextLine();
			String  string[]=xString.split(" ");
			//n操作次数，num节点数
			int num=Integer.parseInt(string[0]);
			int n=Integer.parseInt(string[1]);
			int all[][]=new int[n][2]; 
			for (int i = 0; i <n; i++) {
				String sd=scanner.nextLine();
				String sds[]=sd.split(" ");
				all[i]=transfer(sds);
			}
			scanner.close();
		     //deal 将得到的输入转换为二维数组，存在a中
					int b[][]=new int [num+1][num+1];
					for (int i = 0; i < b.length; i++) {
						for (int j = 0; j < b.length; j++) {
							b[i][j]=0;
						}
					}
					for (int i = 0; i < all.length; i++) {
						int v1=all[i][0];
						int v2=all[i][1];
						b[v1][v2]=1;
						if (all[i][0]<0||all[i][0]<0) {
							System.exit(0);
						}
					}
					return b;
	}
	void cal(int n,int a[][]){
		//标记是否经过
		flag=new int [n+1];
		for (int i =1; i <=n; i++) {
			for (int j = 0; j < flag.length; j++) {
				flag[j]=0;
			}
			Dfs(a, i);
			if (isflag()) {
				m++;
			}
		}
	}
	//是否经过全部的点
	boolean isflag(){
		for (int i = 1; i < flag.length; i++) {
			if (flag[i]==0) {
				return false;
			}
		}
		return true;
	}
	//dfs记录点经过的点
	void Dfs(int a[][],int source){
		flag[source]=1;
		for (int i = 1; i < a.length; i++) {
			if (a[source][i]==1) {
		flag[i]=1;
		Dfs(a, i);
			}
		}
	}
	//图反向
	int [][] reverse(int a[][]){
		int b[][]=new int [a.length][a.length];
		for (int i = 1; i < b.length; i++) {
			for (int j = 1; j < b.length; j++) {
				if (a[i][j]==1) {
					b[j][i]=1;
				}
			}
		}
		return b;
	}
	//string 数组转换为int 
	public  int[]  transfer(String as[]){
		int sum[]=new int [as.length];
		for (int i = 0; i < sum.length; i++) {
			  sum[i]=Integer.parseInt(as[i]);
		}
		return sum;
	}
	public static void main(String[] args) {
	Fouth aMain=new Fouth();
		int a[][]=aMain.input();
		aMain.cal(a.length-1, a);
		int b[][]=aMain.reverse(a);
	aMain.cal(a.length-1, b);
	System.out.println(aMain.m);
	}
	}

