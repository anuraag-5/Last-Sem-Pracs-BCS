class MyThread extends Thread {
    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Child Thread: " + i);
                Thread.sleep(1000);
            }
        } catch (Exception e) {}
    }
}

public class Main4 {
    public static void main(String[] args) throws Exception {
        MyThread t = new MyThread();
        t.start();

        for (int i = 1; i <= 5; i++) {
            System.out.println("Main Thread: " + i);
            Thread.sleep(1000);
        }
    }
}