import java.lang.*;
import java.util.*;

/** The String class represents character strings. 
 All string literals in Java programs, such as "abc",
 are implemented as instances of this class. 
 Strings are constant; their values cannot be changed after they are created. 
 String buffers support mutable strings. 
 Because String objects are immutable they can be shared.
*/

/**frequently used methods:
-valueOf
-trim
-toLowerCase/toUpperCase
-substring
-split
-relace
-matches
-length
-indexOf
-getBytes
-compareTo
-format
*/
public class testString {
	public static void main(String[] args) {
		StringBuilder builder = new StringBuilder();
		builder.append("hello ");
		builder.append("world.".toUpperCase());
		System.out.println(builder.toString());

		// String str = new String("test");
		String str = "test_better";
		System.out.println(str.substring(4, 8));

		String space = "   tbz 1  ";
		System.out.println(space.trim());

		ArrayList<Integer> array = new ArrayList<Integer>(5);
		array.add(8);
		array.add(Integer.valueOf(666));
		String anyValueOf = String.valueOf(array);
		System.out.println(anyValueOf.codePointAt(0));

		String[] token = "t1|7|6.01|test|by|e|".split("\\|");
		for (String item : token){
			System.out.print(item + "~");
		}
	}
}