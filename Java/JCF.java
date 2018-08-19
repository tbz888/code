import java.util.*;

public class JCF{
	public static void main(String[] args) {	
		long beginTime = System.currentTimeMillis();

		//visit a list with iterator
		ArrayList<String> list = new ArrayList<String>();
		list.add(new String("Monday")); // push_back
		list.add(new String("Tuesday"));
		list.add(new String("Wensday"));
		Iterator<String> it = list.iterator();
		while(it.hasNext()){
		    String weekday = it.next();
		    System.out.println(weekday.toUpperCase());
		}

		list.remove(1);
		for(String weekday : list){//enhanced for statement
		    System.out.println(weekday);
		}

		list.set(1, "tbz");
		System.out.println(list.get(1));


		LinkedList<Integer> list2 = new LinkedList<Integer>();
		list2.add(0, 1);
		list2.add(2);
		list2.add(1,6);
		for (int x : list2){
			System.out.println(x);
		}

		System.out.println("Run Time: " + (System.currentTimeMillis() - beginTime));
	}
}