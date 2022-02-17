package labfinal_200104125;

import java.util.Scanner;
import myexceptions.*;
public class App 
{
    public static void main(String[] args) throws Exception 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input a Code");
        int   code = scanner.nextInt();

        Transceiver transobj =  new Transceiver();
        
        transobj.setCode(code);

        try {
            transobj.inspectSignal();
        } catch (InvalidInformationException e) {
            System.out.println("Exception is" + e);
        }
    }
}
