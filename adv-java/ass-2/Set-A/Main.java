class EvenThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 20; i++) {
            if (i % 2 == 0)
                System.out.println("Even: " + i);
        }
    }
}

class OddThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 20; i++) {
            if (i % 2 != 0)
                System.out.println("Odd: " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new EvenThread());
        Thread t2 = new Thread(new OddThread());

        t1.start();
        t2.start();
    }
}