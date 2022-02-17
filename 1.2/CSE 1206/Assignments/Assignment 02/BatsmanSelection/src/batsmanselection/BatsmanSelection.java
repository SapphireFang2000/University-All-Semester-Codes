package batsmanselection;

import java.util.Scanner;

public class BatsmanSelection 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Total Runs: "); 
        int totalRuns = scanner.nextInt();
        
        System.out.print("Total Outs: ");
        int totalOuts = scanner.nextInt();

        Batsman   bat1 =new Batsman(totalRuns,totalOuts);
        Committee com1 =new Committee(bat1);

        com1.calculateAverage();
    }
}
