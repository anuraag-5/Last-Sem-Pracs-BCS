class SleepDemo extends Thread {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch(Exception e) {}
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SleepDemo t = new SleepDemo();
        t.start();
    }
}