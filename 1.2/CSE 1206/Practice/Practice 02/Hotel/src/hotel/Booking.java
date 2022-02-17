package hotel;

import hotelexception.IDNumberInvalidException;
import hotelexception.NotApplicableForDiscountException;

public class Booking {
    public void checkID(String id, String catagory)throws IDNumberInvalidException{
        if(catagory=="passport" && id.length()<9){
            throw new IDNumberInvalidException("Passport number is invalid");
        }
        else if(catagory=="nid" && id.length()==10){
            throw new IDNumberInvalidException("Nid is invalid");
        }
        else
            System.out.println("ID is valid");

    }

    public void giveDiscount(int age ,double roomRate)throws NotApplicableForDiscountException{
        double dis;
        if(age >=60 || age <=10){
            dis = 125 /10;
            System.out.println("Giving "+ dis +" discount");
            roomRate = (roomRate*dis)/100;
            System.out.println("After applying discount room rate is : "+roomRate );
        }
        else
            throw new NotApplicableForDiscountException("Age group not included in discount offer");

    }
}
