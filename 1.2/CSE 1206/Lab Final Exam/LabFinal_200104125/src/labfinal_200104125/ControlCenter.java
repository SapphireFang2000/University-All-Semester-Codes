package labfinal_200104125;

public abstract class ControlCenter implements Signal 
{
    private int code;

    public int getCode() {
        return code;
    }
    public void setCode(int code) {
        this.code = code;
    }   
}
