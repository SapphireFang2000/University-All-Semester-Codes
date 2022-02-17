package main;

import email.Gmail;
import email.YahooMail;

public class Main 
{
    public static void main(String[] args)  
    { 
        Gmail gm = new Gmail();
        YahooMail ym = new YahooMail();

        gm.login("200104125gmail.com");

        try
        {
            ym.login("200104125@yahoo.com");
        }
        catch(UnsupportedOperationException m)
        {
            System.out.println(m);
        }
    }
}
