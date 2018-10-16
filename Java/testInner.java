import java.lang.Class;
import java.lang.reflect.Field;

@Deprecated
public class testInner {

	static class staticInner {
		public static void f() {
			System.out.println("staticInner");
		}
	}

	@Deprecated
	class Inner {
		public int a = 1;
	}

	static {
		System.out.println("static block");
	}

	testInner() {
		System.out.println("constructor.");
	}

	// before object's constructor
	{
		System.out.println("no static block, before constructor.");
	}

	@Deprecated
	interface CallBack {
		public void f();
	}

	void testAnonymous() {
		new CallBack() { // recommend lambda instead of anonymous!
			@Override
			public void f() {
				System.out.println("an anonymous object of a class implements CallBack.");
				testInner.staticInner.f();
			}
		}.f();
	}

	public static void main(String[] args) {
		new testInner().testAnonymous();

		try {
			Class<?>[] clazz = ConstantSet.class.getDeclaredClasses();
			for (Class<?> x : clazz) {
				for (Field y : x.getFields()) {
						System.out.println(y.getName() + "=" + y.getInt(x));
				}
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}

@Deprecated
interface ConstantSet {
	public interface One {
		public final int A = 1;		
		public final int B = 2;
	}
	public interface Two {
		public final int C = 3;
		public final int D = 4;
	}
} 