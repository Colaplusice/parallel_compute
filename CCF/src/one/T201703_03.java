/**
 * 
 */
package one;
/**
 * @author fanjialiang2401
2017年9月13日
 */
import java.util.Scanner;
public class T201703_03{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = null;
        String preline = null;
        String text = "";
        int start,end;
        while(sc.hasNextLine()){
            line = sc.nextLine();
            if(line == null || line.length() == 0){
                if(preline == null){//连续空行，跳过
                    continue;
                }
                //遇到空行，说明区块结束了，可以输出区块的转换结果了
                if(preline.contains("<h")){
                    System.out.print(preline);
                }else if(preline.contains("<ul>")){
                    preline += "\n"+"</ul>"+"\n";
                    System.out.print(preline);
                }else if(preline.contains("<p>")){
                    preline += "</p>"+"\n";
                    System.out.print(preline);
                }
                //每次输出一个区块都要讲前面的preline置为null
                preline = null;
                continue;
            }
            //强调
            while((start = line.indexOf("_")) != -1){
                end = line.indexOf("_",start+1);
                text = line.substring(start, end+1);
                line = line.replace(text,"<em>"+text.substring(1,text.length()-1)+"</em>");
            }
            //超链接
            while((start = line.indexOf("[")) != -1){
                end = line.indexOf("]",start+1);
                text = line.substring(start+1, end);
                int khstart = line.indexOf("(",end);
                int khend = line.indexOf(")",khstart);
                String link = line.substring(khstart+1,khend);
                line = line.replace("["+text+"]"+"("+link+")","<a href=\""+link+"\""+">"+text+"</a>");
            }
            //处理区块
            //标题
            int num = 0;
            if(line.startsWith("#")){
                while(line.startsWith("#") && num <=6){
                    line = line.substring(1);
                    num++;
                }
                //忽略标题前的空格
                while(line.startsWith(" ")){
                    line = line.replaceFirst(" ","");
                }
                preline = "<h"+num+">"+line+"</h"+num+">"+"\n";
            //无序列表
            }else if(line.startsWith("*")){
                //消除星号
                line = line.replace("*", "");
                //消除星号后面的一个或多个空格
                while(line.startsWith(" ")){
                    line = line.substring(1);
                }
                if(preline == null){
                    preline = "<ul>"+"\n"+"<li>"+line+"</li>";
                }else{
                    preline += "\n"+"<li>"+line+"</li>";
                }
            }else{//段落
                if(preline == null){
                    preline = "<p>"+line;
                }else{
                    preline += "\n"+line;
                }
            }
        }
        //输入结束后还要输出最后一个区块的转换结果
        if(preline.contains("<h")){
            System.out.print(preline);
        }else if(preline.contains("<ul>")){
            preline += "\n"+"</ul>"+"\n";
            System.out.print(preline);
        }else if(preline.contains("<p>")){
            preline += "</p>"+"\n";
            System.out.print(preline);
        }
    }
}