class Buffer {
    private int data;
    private boolean available = false;

    public synchronized void produce(int value) {
        try {
            while (available) wait();

            data = value;
            System.out.println("Produced: " + value);
            available = true;

            notify();
        } catch (Exception e) {}
    }

    public synchronized void consume() {
        try {
            while (!available) wait();

            System.out.println("Consumed: " + data);
            available = false;

            notify();
        } catch (Exception e) {}
    }
}

class Producer extends Thread {
    Buffer b;

    Producer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.produce(i);
        }
    }
}

class Consumer extends Thread {
    Buffer b;

    Consumer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.consume();
        }
    }
}

public class Main3 {
    public static void main(String[] args) {
        Buffer b = new Buffer();

        new Producer(b).start();
        new Consumer(b).start();
    }
}