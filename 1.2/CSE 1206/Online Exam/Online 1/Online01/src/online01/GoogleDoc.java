package online01;

public class GoogleDoc implements Editor
{
    @Override
    public void openFile(String fileName) 
    {
        System.out.println("Opening: " + fileName);
    }

    @Override
    public void view(String fileName) 
    {
        System.out.println("Displaying: " + fileName);
    }

    public void changeFont(String F)
    {
        System.out.println("Changing Font: " + F);
    }
}
