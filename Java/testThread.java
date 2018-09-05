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
	}
}

public class testThread {
	public static void main(String[] args) {  // default thread(No.1)
		System.out.println("Main_Begin: " + Thread.currentThread().toString() + Thread.currentThread().getState());
		Thread r = new Thread(new Job()); // NEW
		System.out.println(r.toString() + r.getState()); 
		r.start(); // RUNNABLE
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
	}
}