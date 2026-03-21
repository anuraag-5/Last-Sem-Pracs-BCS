import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// Print task
class PrintJob implements Runnable {
    private String document;

    PrintJob(String document) {
        this.document = document;
    }

    public void run() {
        System.out.println(Thread.currentThread().getName() +
                " Printing: " + document);

        try {
            Thread.sleep(1000); // simulate printing time
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(Thread.currentThread().getName() +
                " Finished: " + document);
    }
}

// Main class
public class Main2 {
    public static void main(String[] args) {

        // Fixed thread pool of 3 printers
        ExecutorService printerPool = Executors.newFixedThreadPool(3);

        // Employees sending print jobs
        printerPool.execute(new PrintJob("Doc1"));
        printerPool.execute(new PrintJob("Doc2"));
        printerPool.execute(new PrintJob("Doc3"));
        printerPool.execute(new PrintJob("Doc4"));
        printerPool.execute(new PrintJob("Doc5"));

        printerPool.shutdown();
    }
}