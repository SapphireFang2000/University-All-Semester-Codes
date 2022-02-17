package email;

public class YahooMail 
{
    public void login(String yahoo)throws UnsupportedOperationException
    {
        if(yahoo.contains("@") && (yahoo.endsWith("yahoo.com")||yahoo.endsWith("ymail.com")))
        {
            System.out.println("Yahoo Mail ID login successful");
        }
        else
            throw new UnsupportedOperationException("Login Unsuccessful");
    }
}
