/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumerproblem;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class Producer extends Thread{
    private Shared buffer;
    private String producerName;
    Scanner sc = new Scanner(System.in);

  
    public Producer(Shared buffer ,String producerName){
        this.buffer = buffer;
        this.producerName= producerName;
    }
    @Override
    public void run(){
        try {
            for(int i=1;i<=5;i++)
            {
                System.out.println(producerName+ ":Data to insert in the buffer ");
                int item = sc.nextInt();
                buffer.produce(item, producerName);
                sleep(100);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
