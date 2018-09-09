import java.lang.Class;
import java.util.ArrayList;
import java.lang.reflect.*;
import java.lang.annotation.*;

/**
Reflection: get Runtime Class information
*/
public class testReflection {
	public static void main(String[] args) {
		ArrayList<String> foo = new ArrayList<String>();
		Class<?> fooClass = foo.getClass();
		System.out.println(fooClass);
		try {
			// class
			Class<?> map = Class.forName("java.util.HashMap");
			System.out.println(map);
			Class set = java.util.HashSet.class;
			System.out.println(set);

			// field
			Field[] fooField = fooClass.getDeclaredFields();
			for (Field x : fooField) {
				System.out.println("-" + x);
			}
			System.out.println();

			// method
			Method[] fooMethod = fooClass.getMethods();
			for (Method x : fooMethod) {
				System.out.println("+" + x);
				if (x.getName().equals("add") && x.getParameterCount() == 1) {
					x.invoke(foo, "test");
				}
			}
			System.out.println();

			// super
			Type fooSuperClass = fooClass.getGenericSuperclass();
			System.out.println(fooSuperClass);
			Type[] fooSuperInterfaces = fooClass.getGenericInterfaces();
			for (Type x : fooSuperInterfaces) {
				System.out.print(x + "/");
			}
			System.out.println();

			// instanceof
			System.out.println(Class.forName("java.util.ArrayList").isInstance(foo));

			// annotation
			for (Annotation x : Class.forName("java.lang.annotation.Retention").getAnnotations()) {
				System.out.println(x);
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		for (String x : foo) {
			System.out.print(x + "|");
		}
	}
}