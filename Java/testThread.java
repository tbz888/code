class MyHandler implements Thread.UncaughtExceptionHandler {
	@Override
	public void uncaughtException(Thread t, Throwable e) {
		System.out.println("[ERROR_LOG]: ");
		System.out.println(t.toString());
		e.printStackTrace();
	}
}

class Job implements Runnable {  // user's thread(No.2)
	@Override
	public void run() {
		while (!Thread.currentThread().isInterrupted()) {
			try {
				System.out.println("sleep.");
				Thread.currentThread().sleep(1000); // TIMED_WAITING
				System.out.println("wakeup.");
			}
			catch (Exception e) { // thread was interrupted during sleep or wait
				e.printStackTrace();
				System.out.println("Job interrupted.");
				break;
			}
		}
		// System.out.println(1/0); // make checked exception
		throw new RuntimeException("testHandler");
	}
}

public class testThread {
	protected static void testJoin() {

		Runnable join1 = () -> {
			for (int i=0; i<50; ++i) {
				System.out.println(i);
			}
		};

		Runnable join2 = () -> {
			for (int i2=50; i2<100; ++i2) {
				System.out.println(i2);
			}
		};

		Thread t1 = new Thread(join1);
		Thread t2 = new Thread(join2);

		try {
			t1.start();
			t2.start();
			t1.join(2); // get control for 2ms
			t2.join(); // get control in t2
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {  // default thread(No.1)
		System.out.println("Main_Begin: " + Thread.currentThread().toString() + Thread.currentThread().getState());
		Thread r = new Thread(new Job()); // NEW
		r.setUncaughtExceptionHandler(new MyHandler()); // bind checked exception handler
		System.out.println(r.toString() + r.getState()); 
		r.start(); // RUNNABLE
		Thread.currentThread().yield(); // give up
		System.out.println(r.toString() + r.getState()); 
		System.out.println("Main_End: " + Thread.currentThread().toString() + Thread.currentThread().getState() + "\n");

		int times = 0;
		while (!r.getState().toString().equals("TERMINATED"))
		{
			try {
				Thread.sleep(600);
			}
			catch (Exception e) {
				e.printStackTrace();
			}

			++times;
			if (times > 15)
				r.interrupt();
			System.out.println("::Job_state: " + r.toString() + r.getState()); 
		}

		testJoin(); //serial
	}
}