package online01;

public class AdobeAcrobat extends PDFViewer
{
    @Override
    public void view(String fileName) 
    {
        System.out.println("Displaying: " + fileName);
    }
}
