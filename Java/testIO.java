import java.io.*;
import java.util.zip.*;
import java.io.Reader.*;

public class testIO {

	// private static void stdIO() {
	// 	try {
	// 		InputStreamReader in = new InputStreamReader(System.in);
	// 		PrintWriter out = new PrintWriter(new FileWriter("test.txt"), true);
	// 		out.print(in.read());
	// 	}
	// 	catch (IOException e) {
	// 		e.printStackTrace();
	// 	}
	// }

	// private static void fileIO() {
	// 	try {
	// 		InputStream fin = new FileInputStream("test.txt");
	// 		byte b = (byte)fin.read();
	// 		DataInputStream din = new DataInputStream(fin);
	// 		double value = din.readDouble();

	// 		ZipInputStream zin = new ZipInputStream(fin);

	// 		InputStreamReader encode = new InputStreamReader(fin, "ISO8859_5");
	// 	}
	// 	catch (IOException e) {
	// 		e.printStackTrace();
	// 	}
	// }

    private static final int LEN = 5;
    // abcdefghijklmnopqrsttuvwxyz
    private static final byte[] ArrayLetters = {
        0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A
    };
    
    private static void testByteArrayInputStream() throws IOException {
    	System.out.println("[testByteArrayInputStream]:");
        ByteArrayInputStream bais = new ByteArrayInputStream(ArrayLetters);

        // read
        for (int i=0; i<LEN; ++i) {
            if (bais.available() >= 0) {
                int tmp = bais.read();
                System.out.println(Integer.toHexString(tmp));
            }
        }
        
        // skip
        if (bais.markSupported()) {
        	bais.mark(0);
        }
        bais.skip(5);
        byte[] buf = new byte[LEN];
        bais.read(buf, 0, LEN);
        System.out.printf("%s\n", new String(buf));
    
    	// mark-reset
        if (bais.markSupported()) {
        	byte[] buf1 = new byte[LEN+2];
        	bais.reset();
	        bais.read(buf1, 0, LEN+2);
        	System.out.printf("%s\n", new String(buf1));
        }
        else {
        	System.out.println("Not support mark.");
        }
    }

    private static void testByteArrayOutputStream() throws IOException {
    	System.out.println("[testByteArrayOutputStream]:");
    	ByteArrayOutputStream baos = new ByteArrayOutputStream(10);
    	baos.write(0x41);
    	baos.write(0x42);
        System.out.printf("%s\n", baos);
    	baos.write(0x43);
    	baos.write(0x64);        
        System.out.printf("%s\n", new String(baos.toByteArray()));
    }

	public static void main(String[] args) {
		try {
			testByteArrayInputStream();
			testByteArrayOutputStream();

		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}