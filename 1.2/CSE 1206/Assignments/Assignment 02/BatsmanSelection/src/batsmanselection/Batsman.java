package batsmanselection;

public class Batsman 
{
    private int totalRuns, totalOuts;
    
    Batsman (int totalRuns, int totalOuts)
    {
        this.totalRuns = totalRuns;
        this.totalOuts = totalOuts;
    }

    public int getTotalRuns() 
    {
        return totalRuns;
    }

    public void setTotalRuns(int totalRuns) 
    {
        this.totalRuns = totalRuns;
    }

    public int getTotalOuts() 
    {
        return totalOuts;
    }

    public void setTotalOuts(int totalOuts) 
    {
        this.totalOuts = totalOuts;
    }
}
