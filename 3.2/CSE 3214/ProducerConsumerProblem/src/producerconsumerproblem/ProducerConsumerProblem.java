/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumerproblem;

/**
 *
 * @author ASUS
 */
public class ProducerConsumerProblem {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Shared buffer = new Shared();
        Producer producer1 = new Producer(buffer, "Producer 1");
        producer1.start();
        Producer producer2 = new Producer(buffer, "Producer 2");
        producer2.start();
        Consumer consumer1 = new Consumer(buffer, "Consumer 1");
        consumer1.start();
        Consumer consumer2 = new Consumer(buffer, "Consumer 2");
        consumer2.start();
    }
    
}
