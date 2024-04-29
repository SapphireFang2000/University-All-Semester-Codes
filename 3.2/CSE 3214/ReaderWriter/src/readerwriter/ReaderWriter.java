/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package readerwriter;

/**
 *
 * @author ASUS
 */
public class ReaderWriter {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        SharedResource resource = new SharedResource();
        int numReaders = 3;
        int numWriters = 3;

        System.out.println("Data in Buffer: " + resource);

        for (int i = 1; i <= numReaders; i++) {
            Reader reader = new Reader(i, resource);
            new Thread(reader).start();
        }

        for (int i = 1; i <= numWriters; i++) {
            Writer writer = new Writer(i, resource);
            new Thread(writer).start();
            //System.out.println("Data in Buffer: " + resource);
        }
    }
}
    

