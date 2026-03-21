class MyThread extends Thread {
    public MyThread(String name) {
        super(name);
    }

    public void run() {
        System.out.println(getName() + " Priority: " + getPriority());

        for (int i = 1; i <= 3; i++) {
            System.out.println(getName() + " running...");
            try {
                Thread.sleep(500);
            } catch (Exception e) {}
        }
    }
}

public class Main2 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread("Thread1");
        MyThread t2 = new MyThread("Thread2");

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();
    }
}