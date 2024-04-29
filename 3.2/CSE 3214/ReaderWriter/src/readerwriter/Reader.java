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
public class Reader implements Runnable{
    private final int id;
    private final SharedResource resource;

    public Reader(int id, SharedResource resource) {
        this.id = id;
        this.resource = resource;
    }

    public void run() {
        while (true) {
            try {
                resource.startReading();
                int number = resource.readNumber();
                System.out.println("Reader " + id + ": Reading " + number);
                Thread.sleep(1000); // Simulating reading operation
                resource.stopReading();
                Thread.sleep(1000); // Simulating idle time for the reader
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
