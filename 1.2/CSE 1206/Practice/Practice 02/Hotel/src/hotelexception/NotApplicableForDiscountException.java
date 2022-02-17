package hotelexception;

public class NotApplicableForDiscountException extends Exception{

   public NotApplicableForDiscountException(String s){
        System.out.println(s);
    }
    @Override
    public String getMessage() {
        return super.getMessage();
    }
}
