class BankAccount {
    private int balance = 1000;

    synchronized void deposit(int amount) {
        balance += amount;
        System.out.println(Thread.currentThread().getName() +
                " Deposited: " + amount + " | Balance: " + balance);
    }

    synchronized void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(Thread.currentThread().getName() +
                    " Withdraw: " + amount + " | Balance: " + balance);
        } else {
            System.out.println(Thread.currentThread().getName() +
                    " Insufficient Balance!");
        }
    }
}

class User extends Thread {
    BankAccount acc;

    User(BankAccount acc, String name) {
        super(name);
        this.acc = acc;
    }

    public void run() {
        acc.deposit(500);
        acc.withdraw(700);
    }
}

public class Main1 {
    public static void main(String[] args) {

        BankAccount acc = new BankAccount();

        User t1 = new User(acc, "User1");
        User t2 = new User(acc, "User2");

        t1.start();
        t2.start();
    }
}