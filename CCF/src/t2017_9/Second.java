/**
 * 
 */
package t2017_9;

import java.util.Scanner;

/**
 * @author fanjialiang2401
2017年9月21日
 *
 *教师上课取钥匙，钥匙出队列，放钥匙，从最左边进入 求最后的结果
5 3
1 2 7
4 3 6
2 1 9 
 */
public class Second {
	public static void main(String[] args) {
	//input
		Scanner scanner=new Scanner(System.in);
		String x=scanner.nextLine();
		String str[]=x.split(" ");
		int s=Integer.parseInt(str[0]);
		int all[]=new int [s];
		//init
		key sum[]=new key[Integer.parseInt(str[1])*2];
		 for (int i = 0; i < sum.length; i++) {
	sum[i]=new key();
		}
		int t=0;
	for (int i = 0; i <Integer.parseInt(str[1]); i++) {
String string=scanner.nextLine();
String temp[]=string.split(" ");
sum[t].num=Integer.parseInt(temp[0]);
sum[t].time=Integer.parseInt(temp[1]);
sum[t].flag=0;
t++;
sum[t].num=Integer.parseInt(temp[0]);
sum[t].time=Integer.parseInt(temp[1])+Integer.parseInt(temp[2]);
sum[t].flag=1;
t++;
	}
	
	scanner.close();
	 sum=Sort(sum);
//	 for (int i = 0; i < sum.length; i++) {
//			System.out.println(sum[i].num+" "+sum[i].time+" "+sum[i].flag);
//		}
	 int v[]=new int [Integer.parseInt(str[0])+1];
	 for (int i = 1; i < v.length; i++) {
		v[i]=i;
	}

	 //deal
	 for (int i = 0; i < sum.length; i++) {
		 for (int j = 0; j < v.length; j++) {
			 if (sum[i].num==j&&sum[i].flag==0) {
					v[j]=99;
				}
			 else if (sum[i].num==j&&sum[i].flag==1){
				 for (int j2 = 0; j2 < v.length; j2++) {
				if (v[j2]==99) {
					v[j2]=sum[i].num;
				break;
				}
			}  
			 }
		}
	 }
	 for (int i = 1; i < v.length; i++) {
		System.out.print(v[i]+" ");
	}
}
private static key[] Sort(key sum[]){
int s=sum.length;
for (int i = 0; i < sum.length; i++) {
	for (int j = i; j < sum.length; j++) {
		key flag;
		if (sum[i].time>sum[j].time) {
          flag=sum[i];
          sum[i]=sum[j];
          sum[j]=flag;
		}
	}
}
	return sum;
}
	}
class key {
	/**
	 * 
	 */
	public key() {
    num=0;
    flag=0;
    time=0;
	}
	
	int num;
	/**
	 * @return the num
	 */
	public int getNum() {
		return num;
	}
	/**
	 * @param num the num to set
	 */
	public void setNum(int num) {
		this.num = num;
	}
	/**
	 * @return the time
	 */
	public int getTime() {
		return time;
	}
	/**
	 */
	public void setTime(int time) {
		this.time = time;
	}
	/**
	 * @return the flag
	 */
	public int getFlag() {
		return flag;
	}
	/**
	 * @param flag the flag to set
	 */
	public void setFlag(int flag) {
		this.flag = flag;
	}
	int time;
	int flag;
}

