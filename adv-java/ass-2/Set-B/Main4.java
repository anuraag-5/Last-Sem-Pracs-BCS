class Task implements Runnable {
    public void run() {
        for(int i = 1; i <= 3; i++) {
            System.out.println(Thread.currentThread().getName() + " -> " + i);
        }
    }
}

public class Main4 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Task());
        Thread t2 = new Thread(new Task());

        t1.start();
        t2.start();
    }
}