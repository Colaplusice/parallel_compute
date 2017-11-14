package t2017_9;

import java.util.Random;

public class Example {

	public static void main(String[] args) {
		
 Random aRandom=new Random();
 float all=0;
 float allpi=0;
 float avg=0;
 while(allpi<10000){
	 for (int i = 0; i < 1000000; i++) {
		 float a=aRandom.nextFloat();
		 float b=aRandom.nextFloat();
		 if ((a*a)+(b*b)<=1) {
			all++;
		}
	}
	 float pi=(all*4)/1000000;
	 allpi+=1;
	 avg+=pi;
 }
System.out.println(avg/allpi);
	}
} 
