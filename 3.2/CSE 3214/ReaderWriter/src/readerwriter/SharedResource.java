/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package readerwriter;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

/**
 *
 * @author ASUS
 */
public class SharedResource {
    private List<Integer> buffer;
    private Semaphore readMutex;
    private Semaphore writeMutex;
    private Semaphore resourceAccess;
    private int currentReadIndex;

    public SharedResource() {
        buffer = new ArrayList<>();
        //buffer.add(1);
        //buffer.add(5);
        //buffer.add(6);
       // buffer.add(7);
        //buffer.add(8);
        //buffer.add(9);
        //buffer.add(15);

        readMutex = new Semaphore(1);
        writeMutex = new Semaphore(1);
        resourceAccess = new Semaphore(1);
        currentReadIndex = 0;
    }

    public int readNumber() {
        if (currentReadIndex < buffer.size()) {
            int number = buffer.get(currentReadIndex);
            currentReadIndex++;
            return number;
        }
        return -1;
    }

    public void writeData(int newData1, int newData2) {
        buffer.add(newData1);
        buffer.add(newData2);
    }

    public void startReading() throws InterruptedException {
        readMutex.acquire();
        resourceAccess.acquire();
        readMutex.release();
    }

    public void stopReading() throws InterruptedException {
        resourceAccess.release();
    }

    public void startWriting() throws InterruptedException {
        writeMutex.acquire();
        readMutex.acquire();
        resourceAccess.acquire();
        readMutex.release();
    }

    public void stopWriting() {
        resourceAccess.release();
        writeMutex.release();
    }

    @Override
    public String toString() {
        return buffer.toString();
    }
}
