package gamerdemo;

public class GamerDemo 
{
    public static void main(String[] args) 
    {
        Gamer gamer1 = new Gamer("Professional", 60, 80);
        
        System.out.println("Type of Gamer : " + gamer1.gamerType);
        System.out.println("Total Score : " + gamer1.totalScore);
        System.out.println("Total Matches : " + gamer1.totalMatches);
        System.out.println("Mean score : " + gamer1.calculateFinalScore());   
    }
    
}
