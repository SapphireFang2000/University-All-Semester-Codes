package online01;

public abstract class PDFViewer implements Viewer
{

    public void highlight(String T)
    {
        System.out.println("Highlighting Text: " + T);
    }

    public void changeView(double S, String type)
    {
        System.out.println(type + ", Size by: " + S);
    }
}
