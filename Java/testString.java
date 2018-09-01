import java.lang.*;
import java.util.*;

/** 
 The String class represents character strings. 
 All string literals in Java programs, such as "abc", are implemented as instances of this class. 
 Strings are constant; their values cannot be changed after they are created. 
 String buffers support mutable strings. Because String objects are immutable they can be shared.
 Instances of StringBuilder are not safe for use by multiple threads. If such synchronization is required then it is recommended that StringBuffer be used.
 String modification -> other String literal.
*/

/**  frequently used methods:
-valueOf
-trim
-toLowerCase/toUpperCase
-substring
-split
-replace
-matches
-length
-indexOf
-getBytes
-compareTo
-format
-equals(@override)
-charAt/codePointAt
-startsWith/endsWith
-join
*/
public class testString {
	public static void main(String[] args) {
		StringBuilder builder = new StringBuilder(); // like StringBuffer
		builder.append("hello ");
		builder.append("world.".toUpperCase());
		builder.insert(5, "+");
		System.out.println(builder.toString());

		// String str = new String("test");
		String str = "test_better";
		System.out.println(str.substring(4, 8));

		String space = "   tbz 1  ";
		System.out.println(space.trim());
		System.out.println(space);

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