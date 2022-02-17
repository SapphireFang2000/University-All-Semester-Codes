package labfinal_200104125;

public class Translator {

    void decodeSignal(int code)
    {
        if (code == 2)
        {
            System.out.println("Minerals Found");
        }

        else if (code == 3)
        {
            System.out.println("Microorganism Found");
        }
        
        else
        {
            System.out.println("Water Found");
        } 
    } 
}
