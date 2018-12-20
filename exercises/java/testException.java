import java.io.EOFException;
import java.lang.Exception;

class TbzException extends Exception {
	// private String errorMsg = null;

	TbzException(String content){
		super(content);
		// errorMsg = content;
	}

	// @Override
	// public String toString() {
	// 	return errorMsg;
	// }
}

class WrappedTbzException extends TbzException {
	WrappedTbzException(String content){
		super(content);
	}
}

public class testException {

	private static void makeException() throws EOFException {
		throw new EOFException("test");
	}

	private static void makeTbzException() throws TbzException {
		throw new TbzException("tbz");
	}

	private static void makeExceptionLink() throws WrappedTbzException {
		try {
			makeTbzException();
		}
		catch (Exception eTbz2){
			WrappedTbzException ret = new WrappedTbzException("Wrap-test");
			ret.initCause(eTbz2);
			throw ret;
		}
	}

	public static void main(String[] args) {
		try {
			makeException();       		// order 1
			makeTbzException();			// order 2
		}
		catch (EOFException eEOF) {  	// order 1
			eEOF.printStackTrace();
		}
		catch (TbzException eTbz) {		// order 2
			eTbz.printStackTrace();
		}
		finally {
			System.out.println("beginning.");
		}

		try {
			makeExceptionLink();
		}
		catch (WrappedTbzException e) {
			e.printStackTrace();
			Throwable innerException = e.getCause();
			innerException.printStackTrace();
		}
		finally {
			System.out.println("exception chain.");
		}
	}
}