package one;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
class Role
{
	int attack;
	int life;
Role(int attack,int life){
		this.life=life;
		this.attack=attack;
	}
void setlife(int life){
	this.life=life;
}
void setattack(int attack){
	this.attack=attack;
}
	int getlife(){
		return life;
		
	}
	int getattack(){
		return attack;
	}
}
public class T2016_09_3 {

	public static void main(String[] args) {
		List<Role> p1 = new ArrayList<Role>(8);
		List<Role> p2 = new ArrayList<Role>(8);
		boolean win=false;
		p1.add(new Role(0,30));
		p2.add(new Role(0, 30));
		for(int i=1;i<8;i++){
			p1.add(new Role(-1, -1));
			p2.add(new Role(-1, -1));
		}
		//从p1回合开始
		List< Role>cuRoles=p1;
		List<Role>Def=p2;
		Scanner in=new Scanner(System.in);
		String a=new String();
		a=in.nextLine();
		String str[]=null;
		try {
			int n=Integer.parseInt(a);
			for (int i = 0; win==false&&i<n; i++) {
				a=in.nextLine();
				str=a.split(" ");
			
			switch (str[0]) {
			case "summon":
				Role current=cuRoles.get(Integer.parseInt(str[1]));
				if (current.getlife()<0) {
					cuRoles.set(Integer.parseInt(str[1]), new Role(Integer.parseInt(str[2]), Integer.parseInt(str[3])));
				}else {
					cuRoles.add(Integer.parseInt(str[1]), new Role(Integer.parseInt(str[2]), Integer.parseInt(str[3])));
				}
				break;
			case "attack":
				Role attacks=cuRoles.get(Integer.parseInt(str[1]));
			Role defender=Def.get(Integer.parseInt(str[2]));
			if (attacks.life-defender.attack>0) {
				cuRoles.set(Integer.parseInt(str[1]), new Role(attacks.attack, attacks.life-defender.attack));
			}
			else {
				cuRoles.set(Integer.parseInt(str[1]), new Role(-1, -1));
			}
			if (defender.life-attacks.attack>0) {
				Def.set(Integer.parseInt(str[2]), new Role( defender.attack,defender.life-attacks.attack));
			}
			else {
				if (Integer.parseInt(str[2])==0) {
					win=true;
					Def.set(0, new Role(0, 0));
					
				}
				Def.set(Integer.parseInt(str[2]), new Role(-1, -1));
				break;
			}
			case "end":
				cuRoles=(cuRoles==p1)?p2:p1;
				Def=(Def==p2)?p1:p2;
			default:
				break;
			}
		
		} 
			in.close();
		}catch (Exception e) {
		
		}
		//output
		if (win==false) {
			System.out.println(0);
		}
		else if (cuRoles==p1) {
			System.out.println(1);
		}
		else {
			System.out.println(-1);
		}
		int count=0;
		for (int i = 1; i < 8; i++) {
			if (p1.get(i).getlife()>0) {
				count++;
			}
		}		
		System.out.println(p1.get(0).getlife());
		System.out.print(count+" ");
		for(int i=1;i<8&p1.get(i).getlife()>0;i++){
			System.out.print(p1.get(i).getlife()+" ");
		}
		System.out.println();
		int count1=0;
		for (int i = 1; i < 8; i++) {
			if (p2.get(i).getlife()>0) {
				count1++;
			}
		}
		System.out.println(p2.get(0).getlife()+" ");

		System.out.print(count1+" ");
		for(int i=1;i<8&p2.get(i).getlife()>0;i++){
			System.out.print(p2.get(i).getlife()+" ");
		}
	}
}
