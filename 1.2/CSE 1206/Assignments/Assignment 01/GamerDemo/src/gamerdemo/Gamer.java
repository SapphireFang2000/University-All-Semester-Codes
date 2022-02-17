package gamerdemo;

public class Gamer 
{
    public double totalScore,totalMatches;
    public String gamerType ;
    
    Gamer()
    {
        gamerType = "null";
        totalScore = -1.0;
        totalMatches = -1.0;
    }
    
    Gamer(String gt, double ts, double tm)
    {
        gamerType = gt;
        totalScore = ts;
        totalMatches = tm;
    }
    
    public double calculateFinalScore()
    {
        if("noob".equals(gamerType))
             return (2*totalScore*totalMatches)/(totalMatches+totalScore);
        else
            return totalScore/totalMatches;
    }
}
