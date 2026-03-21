class TicketBooking {
    private int tickets = 5;

    public synchronized void bookTicket(String name) {
        if (tickets > 0) {
            System.out.println(name + " booked a ticket");
            tickets--;
        } else {
            System.out.println(name + " - No tickets available");
        }
    }
}

class User extends Thread {
    TicketBooking t;

    User(TicketBooking t, String name) {
        super(name);
        this.t = t;
    }

    public void run() {
        t.bookTicket(getName());
    }
}

public class Main4 {
    public static void main(String[] args) {
        TicketBooking t = new TicketBooking();

        new User(t, "User1").start();
        new User(t, "User2").start();
        new User(t, "User3").start();
        new User(t, "User4").start();
        new User(t, "User5").start();
        new User(t, "User6").start();
    }
}