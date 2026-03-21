class Message {
    String msg;

    synchronized void write(String m) throws Exception {
        msg = m;
        notify();
    }

    synchronized void read() throws Exception {
        wait();
        System.out.println("Message: " + msg);
    }
}

public class Main2 {
    public static void main(String[] args) {
        Message m = new Message();

        new Thread(() -> {
            try { m.write("Hello Thread!"); } catch(Exception e) {}
        }).start();

        new Thread(() -> {
            try { m.read(); } catch(Exception e) {}
        }).start();
    }
}