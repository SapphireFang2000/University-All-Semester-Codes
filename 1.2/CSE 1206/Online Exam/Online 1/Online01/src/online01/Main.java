package online01;

public class Main {

    public static void main(String[] args) 
    {
        AdobeAcrobat adobe = new AdobeAcrobat();
        GoogleDoc doc = new GoogleDoc();

        adobe.highlight("HelloWorld");
        adobe.changeView(15.5,"Increase");
        adobe.view("Online lab one");

        System.out.println();
        System.out.println();

        doc.openFile("CSE 1200");
        doc.view("Online lab ");
        doc.changeFont("Arial");
    }
}