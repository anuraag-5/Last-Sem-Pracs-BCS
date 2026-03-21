class Shared {
    int data;
    boolean available = false;

    synchronized void produce(int value) throws InterruptedException {
        while(available)
            wait();

        data = value;
        System.out.println("Produced: " + value);

        available = true;
        notify();
    }

    synchronized void consume() throws InterruptedException {
        while(!available)
            wait();

        System.out.println("Consumed: " + data);

        available = false;
        notify();
    }
}

class Producer extends Thread {
    Shared s;

    Producer(Shared s) { this.s = s; }

    public void run() {
        try {
            for(int i = 1; i <= 5; i++) {
                s.produce(i);
            }
        } catch(Exception e) {}
    }
}

class Consumer extends Thread {
    Shared s;

    Consumer(Shared s) { this.s = s; }

    public void run() {
        try {
            for(int i = 1; i <= 5; i++) {
                s.consume();
            }
        } catch(Exception e) {}
    }
}

public class Main1 {
    public static void main(String[] args) {
        Shared s = new Shared();

        Producer p = new Producer(s);
        Consumer c = new Consumer(s);

        p.start();
        c.start();
    }
}