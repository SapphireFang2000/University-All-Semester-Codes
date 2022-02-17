package labfinal_200104125;

import myexceptions.*;
public class Transceiver extends ControlCenter 
{
    @Override
    public void inspectSignal() throws InvalidInformationException 
    {
        int number = getCode();

        int  i, flag = 0;

        for (i = 2; i <= number / 2; ++i) 
        {
            if (number % i == 0) 
            {
              flag = 1;
              break;
            }
        }
        
        if (flag == 0)
        {
            System.out.println("Signal Received with Information!");
            Translator translator = new Translator();
            translator.decodeSignal(getCode());
        }

         else
            throw new InvalidInformationException("Invalid Signal Received! Please Discard it");
    }
    
}

