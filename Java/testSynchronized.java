import java.util.Random;
import java.util.ArrayList;
import java.util.Iterator;

class Transfer implements Runnable {
	private static Random generator = new Random();

	private Integer nextPositveInt(int divisor) {
		if (divisor == 0)
			return 0;
		Integer ans = generator.nextInt();
		if (ans < 0)
			ans = -ans;
		return ans % divisor;
	}

	@Override
	public void run() {
		while (true) {
			Integer random_from = nextPositveInt(5);
			Integer random_to = nextPositveInt(5);
			while (random_to == random_from) {
				random_to = nextPositveInt(5);
			}
			Integer random_amount = nextPositveInt(10000);
			
			synchronized (testSynchronized.accountLock) {
				Integer balance = testSynchronized.account.get(random_from) - random_amount;
				if (balance > 0) {
					System.out.println(Thread.currentThread().toString() + "start:");
					testSynchronized.account.set(random_from, balance);
					System.out.println(Thread.currentThread().toString() + "interrupt?");
					testSynchronized.account.set(random_to, testSynchronized.account.get(random_to) + random_amount);
					System.out.println(Thread.currentThread().toString() + "end.");
				}
			}
		}
	}
}

class SumInfo implements Runnable {
	@Override
	public void run() {
		while (true) {
			synchronized (testSynchronized.accountLock) {
				int sum = 0;
				for (Integer x : testSynchronized.account) {
					sum += x;
					System.out.print(x + " | ");
				}
				System.out.println("SUM :" + sum);
				if (sum != 100000)
					System.out.println("Error happened! ");
			}
			try {
				Thread.sleep(1000);
			}
			catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}

public class testSynchronized {
	public static ArrayList<Integer> account = new ArrayList<Integer>(5); // capacity, not size
	public static Object accountLock = new Object();

	public static void main(String[] args) {
		//init
		for (int i = 0; i < 5; ++i) {
			account.add(20000);
		}

		//start
		Transfer transferTrade = new Transfer();
		for (int j = 0; j < 5; ++j) {
			new Thread(transferTrade).start();
		}

		//observe
		new Thread(new SumInfo()).start();
	}
}