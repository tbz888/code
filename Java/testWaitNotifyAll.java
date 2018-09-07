import java.util.*;

class Request implements Runnable {
	private static Random rand = new Random();

	@Override
	public void run() {
		String source = String.valueOf(rand.nextInt()%50);
		Handler h = new Handler(source);
		System.out.println("未加入队列：" + source);
		HandlerPool.getInstance().add(h);
		System.out.println("已加入队列：" + source);
		System.out.println("已收到响应：" + HandlerPool.getInstance().getAndRemove(h));
	}
}

class Response implements Runnable {
	@Override
	public void run() {
		while (true) {
			System.out.println("未处理队列：" + new Date());
			HandlerPool.getInstance().setAll();
			System.out.println("已处理完成队列：" + new Date());
		}
	}
}

class Handler {
	private String message; 
	private Boolean isChecked = false;

	public Handler(String message) {
		setHandler(message);
	}

	public String getHandler() {
		return message;
	}

	public void setHandler(String message) {
		this.message = message;
	}

	public void setChecked() {
		isChecked = true;
	}

	public Boolean getChecked() {
		return isChecked;
	}
}

class HandlerPool {
	private ArrayList<Handler> queue = new ArrayList<Handler>();
	private static HandlerPool instance = null;
	
	private HandlerPool() {}

	public static HandlerPool getInstance() {
		if (instance == null)
			instance = new HandlerPool();
		return instance;
	}

	public synchronized void add(Handler h) {
		System.out.println("add_start:" + h.getHandler());
		if (h != null)
			queue.add(h);
		System.out.println("add_end:" + h.getHandler());
		this.notifyAll();
	}

	public synchronized Boolean isAllChecked() {
		Boolean ret = true;
		for (Handler h : HandlerPool.getInstance().queue) {
			if (h.getChecked() == false) {
				ret = false;
				break;
			}
		}
		return ret;
	}

	public synchronized void setAll() {
		while (queue.size() == 0 || isAllChecked())
		{
			try {
				this.wait();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		System.out.println("setAll_start:");
		for (Handler h : HandlerPool.getInstance().queue)
		{
			if (h.getChecked() == false) {
				h.setHandler(h.getHandler() + " x " + h.getHandler() + " = ?");
				h.setChecked();
			}
		}
		System.out.println("setAll_end:");
		this.notifyAll();
	}

	public synchronized String getAndRemove(Handler h) {
		String ret = null;
		if (h != null)
		{
			int toDel = queue.indexOf(h);
			ret = queue.get(toDel).getHandler();
			while (!ret.contains("x")) {	
				try {
					this.wait();
				} catch (Exception e) {
					e.printStackTrace();
				}
				toDel = queue.indexOf(h);
				ret = queue.get(toDel).getHandler();
			} 
			System.out.println("getRemove_start:" + h.getHandler());
			queue.remove(toDel);
		}
		System.out.println("getRemove_end:" + h.getHandler());
		return ret;
	}
}

public class testWaitNotifyAll {
	public static final int mockCount = 10000;

	public static void main(String[] args) {
		new Thread(new Response()).start();
		for (int i = 0; i < mockCount; ++i) {
			new Thread(new Request()).start();
		}
	}
}