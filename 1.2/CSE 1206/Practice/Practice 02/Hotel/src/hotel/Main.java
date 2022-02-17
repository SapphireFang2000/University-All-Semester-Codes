package hotel;


import hotelexception.IDNumberInvalidException;
import hotelexception.NotApplicableForDiscountException;

public class Main {
    public static void main(String[] args) {
        Booking bk = new Booking();

        try{
            bk.checkID("10007","Small");
        }
        catch (IDNumberInvalidException e){
            System.out.println(e);
        }

        try{
            bk.giveDiscount(21,20000);
        }
        catch(NotApplicableForDiscountException m){
            System.out.println(m);
        }
    }
}
