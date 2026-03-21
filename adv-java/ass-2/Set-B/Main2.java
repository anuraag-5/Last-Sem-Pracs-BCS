class AliveDemo extends Thread {
    public void run() {
        System.out.println("Thread running...");
    }
}

public class Main2 {
    public static void main(String[] args) throws Exception {
        AliveDemo t = new AliveDemo();

        System.out.println("Before start: " + t.isAlive());
        t.start();
        System.out.println("After start: " + t.isAlive());
    }
}