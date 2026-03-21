class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - " + i);
            Thread.yield();
        }
    }
}

public class Main1 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        t1.setName("Custom Thread");

        t1.start();

        for (int i = 1; i <= 5; i++) {
            System.out.println("Main Thread - " + i);
        }
    }
}