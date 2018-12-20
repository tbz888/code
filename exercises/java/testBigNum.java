import java.math.*;

public class testBigNum {
	public static void main(String[] args) {
		BigInteger n = BigInteger.valueOf(Integer.parseInt("30"));
		BigInteger ans = n.add(n);
		ans = ans.multiply(n);
		System.out.println(ans.toString());

		BigDecimal f = BigDecimal.valueOf(1.6f);
	}
}