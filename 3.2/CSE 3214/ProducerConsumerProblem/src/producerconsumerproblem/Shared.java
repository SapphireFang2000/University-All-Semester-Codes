/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumerproblem;

import java.util.concurrent.Semaphore;

/**
 *
 * @author ASUS
 */
public class Shared {
    private final int[] buffer;
    private int in;
    private int out;
    private final Semaphore mutex;
    private final Semaphore full;
    private final Semaphore empty;

    public Shared() {
        buffer = new int[5];
        in = 0;
        out = 0;
        mutex = new Semaphore(1);
        full = new Semaphore(0);
        empty = new Semaphore(5);
    }

    public void produce(int item, String producerName) throws InterruptedException {
        empty.acquire();
        mutex.acquire();

        buffer[in] = item;
        System.out.println(producerName + ": Data " + item + " is inserted in the buffer");
        in = (in + 1) % 5;

        mutex.release();
        full.release();

        printBufferStatus();
    }

    public void consume(String consumerName) throws InterruptedException {
        full.acquire();
        mutex.acquire();

        int item = buffer[out];
        System.out.println(consumerName + ": Consumed Data " + item + " from the buffer");
        out = (out + 1) % 5;

        mutex.release();
        empty.release();

        printBufferStatus();
    }

    private void printBufferStatus() {
        System.out.println("Empty space: " + empty.availablePermits());
        System.out.println("Full space: " + (5 - empty.availablePermits()));
        System.out.println();
    }
}
