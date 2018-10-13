class Task implements Runnable {
	@Override
	public void run() {
		for (int i=0; i < 3; ++i) {
			String ctx = Thread.currentThread().getId() + "-" + String.valueOf(i);
			System.out.println("context:" + ctx);
			HTTPContextHolder.set(ctx);
			System.out.println(Thread.currentThread().toString() + HTTPContextHolder.get());
			HTTPContextHolder.remove(); // must!!!
			System.out.println(ctx + " removed.");
		}
		String finalString = (null == HTTPContextHolder.get()) ? "null" : "not null.";
		System.out.println("finally: " + Thread.currentThread().getId() + finalString);
	}
}

class HTTPContextHolder {
	
	/* Why static? ThreadLocal.java:
	 * int i = key.threadLocalHashCode & (table.length - 1);
	 * 一个key(static)对应一个副本，多个key(not static)对应多个副本。
	 */
	private static final ThreadLocal<String> holder = new ThreadLocal<String>();

	public static void set(String contenxt) {
		holder.set(contenxt);
	}

	public static String get() {
		return holder.get();
	}

	public static void remove() {
		holder.remove();
	}	
}

public class testThreadLocal {
	public static void main(String[] args) {
		Task foo = new Task();
		new Thread(foo).start();
		new Thread(foo).start();
	}
}