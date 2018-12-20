import java.io.*;
import java.util.zip.*;
import java.io.Reader.*;

public class testIO {
	
	// test data
    private static final int LEN = 5;
    private static final byte[] ArrayLetters = {   // abcdefghijklmnopqrsttuvwxyz
        0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A
    };


    // File
    private static void testFileInputOutputStream() throws IOException {
		System.out.println("[testFileInputOutputStream]:");

		FileOutputStream out = new FileOutputStream("PART3_IN_EPCC.log.1", true); //append
		out.write("good bye.".getBytes());
		out.close();

		FileInputStream in = new FileInputStream("PART3_IN_EPCC.log.1");
		byte[] buf = new byte[100];
		in.read(buf);
		System.out.println(new String(buf));
	}
    
    // Serializable and Externalizable object
    private static void testObjectInputStreamOutputStream() throws IOException, ClassNotFoundException {
    	System.out.println("[testObjectInputStreamOutputStream]:");

    	FileOutputStream fout = new FileOutputStream("test.obj");
    	ObjectOutputStream out = new ObjectOutputStream(fout);
    	out.writeObject(String.valueOf("test"));
    	out.writeObject(Double.valueOf(1.23));
    	fout.close();
    	out.close();

		FileInputStream fin = new FileInputStream("test.obj");
    	ObjectInputStream in = new ObjectInputStream(fin);
    	System.out.println(in.readObject());
    	System.out.println(in.readObject());
    	fin.close();
    	in.close();
    }

    // multithread message queue
    private static void testPipedStream() throws IOException {
    	System.out.println("[testPipedStream]:");
    	PipedOutputStream out = new PipedOutputStream();
    	PipedInputStream in = new PipedInputStream();
    	out.connect(in);
    	out.write(ArrayLetters);
    	byte[] buf = new byte[26];
    	in.read(buf);
    	System.out.println(new String(buf));
    	
    	out.close();
    	in.close();
    }

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

        bais.close();
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

        baos.close();
    }

	public static void main(String[] args) {
		try {
			testByteArrayInputStream();
			testByteArrayOutputStream();
			testPipedStream();
			testObjectInputStreamOutputStream();
			testFileInputOutputStream();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}