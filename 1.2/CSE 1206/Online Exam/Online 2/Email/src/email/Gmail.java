package email;

public class Gmail 
{
    public void login(String gmail)
    {
        try 
        {
            if (gmail.contains("@") && gmail.endsWith("gmail.com")) 
            {
                System.out.println("Gmail ID  login successful");
            }
            else
                throw new InterruptedException("Login Unsuccessful");
        }
        catch(InterruptedException e)
        {
            System.out.println(e);
        }
    }
}
