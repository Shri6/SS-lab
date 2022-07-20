import java.util.Scanner;

public class bankersinternal{
	int max[][], need[][], available[][], allocated[][];
	int np, nr;
	boolean flag=false;
	Scanner sc = new Scanner(System.in);
	
	public void input(){
		System.out.println("Enter the no. of processes : ");
		np = sc.nextInt();
		System.out.println("Enter the no. of resources : ");
		nr = sc.nextInt();
		max = new int[np][nr];
		need = new int[np][nr];
		allocated = new int[np][nr];
		available = new int[1][nr];
		System.out.println("Enter the allocation matrix : ");
		for(int i=0; i<np; i++){
			for(int j=0; j<nr; j++){
				allocated[i][j] = sc.nextInt();
			}
		}
		System.out.println("Enter the max matrix : ");
		for(int i=0; i<np; i++){
			for(int j=0; j<nr; j++){
				max[i][j] = sc.nextInt();
			}
		}
		System.out.println("Enter the available matrix : ");
		for(int i=0; i<nr; i++){
			available[0][i] = sc.nextInt();
		}
		sc.close();
	}
	
	public void call(){
		for(int i=0; i<np; i++){
			for(int j=0; j<nr; j++){
				need[i][j] = max[i][j] - allocated[i][j];
			}
		}
	}
	
	public boolean check(int p){
		for(int i=0; i<nr; i++){
			if(need[p][i] <= available[0][i]){
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	
	public void algorithm(){
		call();
		int c=0;
		boolean status[] = new boolean[np];
		while(c < np){
			boolean alloc = false;
			boolean ret;
			for(int i=0; i<np; i++){
				ret = check(i);
				if(!status[i] && ret){
					status[i] = true;
					alloc = true;
					c++;
					System.out.println("Allocated process : " +i);
					for(int j=0; j<nr; j++)
						available[0][j] = available[0][j] + allocated[i][j]; 
				}
				
			}
			if(!alloc){
				break;
			}
		}
		if(c == np)
			System.out.println("system successfull");
		else
			System.out.println("system failed");
	}
	
	public static void main (String args[]){
		bankersinternal obj = new bankersinternal();
		
		obj.input();
		obj.algorithm();
	}
}
			
