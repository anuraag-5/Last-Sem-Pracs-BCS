class YieldDemo extends Thread {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " : " + i);
            Thread.yield();
        }
    }
}

public class Main5 {
    public static void main(String[] args) {
        YieldDemo t1 = new YieldDemo();
        YieldDemo t2 = new YieldDemo();

        t1.start();
        t2.start();
    }
}