class JoinDemo extends Thread {
    public void run() {
        for(int i = 1; i <= 3; i++) {
            System.out.println("Thread: " + i);
        }
    }
}

public class Main4 {
    public static void main(String[] args) throws Exception {
        JoinDemo t = new JoinDemo();
        t.start();
        t.join(); // wait for thread to finish
        System.out.println("Main thread ends");
    }
}