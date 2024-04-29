/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package readerwriter;

import java.util.Random;

/**
 *
 * @author ASUS
 */
public class Writer implements Runnable{
    private final int id;
    private final SharedResource resource;

    public Writer(int id, SharedResource resource) {
        this.id = id;
        this.resource = resource;
    }
    //SharedResource resource = new SharedResource();
    public void run() {
        while (true) {
            try {
                resource.startWriting();
                int newData1 = new Random().nextInt(100);
                int newData2 = new Random().nextInt(100);
                resource.writeData(newData1, newData2);
                System.out.println("Writer " + id + ": Writes in the system " + newData1 + ", " + newData2);
                System.out.println("Data in Buffer: " + resource);
                Thread.sleep(2000); // Simulating writing operation
                resource.stopWriting();
                Thread.sleep(1000); // Simulating idle time for the writer
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
