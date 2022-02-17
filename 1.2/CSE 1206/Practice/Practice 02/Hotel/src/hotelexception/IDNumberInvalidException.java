package hotelexception;

public class IDNumberInvalidException extends Exception{
   public IDNumberInvalidException(String s){
        System.out.println(s);
    }
   
    @Override
    public String getMessage() {
        return super.getMessage();
    }

}
