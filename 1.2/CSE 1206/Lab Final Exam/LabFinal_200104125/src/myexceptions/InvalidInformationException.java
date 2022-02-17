package myexceptions;

public class InvalidInformationException extends Exception
{

    public InvalidInformationException ()
    {
        super();
    }

    public InvalidInformationException (String message)
    {
        super(message);
    }
}
