package batsmanselection;

public class Committee 
{
    public Batsman batObj;
    
    Committee(Batsman batObj)
    {
        this.batObj = batObj;
    }
    
    public void calculateAverage()
    {
        int average = batObj.getTotalRuns()/batObj.getTotalOuts();
        int temp = average, sum = 0, count = 0;
        
        while(temp!=0)
        {
            temp/=10;
            count++;
        }
        
        temp = average;
        
        while(temp!=0)
        {
            int digit = temp%10;
            temp /= 10;
            sum += Math.pow(digit, count);
            count--;
        }
        
        System.out.println("Average of Batsman is: " + average);
        
        if(average==sum)
            System.out.println("Batsman Selected");
        else
            System.out.println("Batsman Not Selected");
    }
}
