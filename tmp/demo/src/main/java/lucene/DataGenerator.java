package lucene;

import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.IndexWriter;

import java.io.IOException;
import java.util.Random;

public class DataGenerator {
    private static final DataGenerator instance = new DataGenerator();
    private DataGenerator(){}
    public static DataGenerator getInstance() {
        return instance;
    }

    private static final String[] examples = {"one love xyz","two test tbz","third fuck you"};

    public void generate(IndexWriter source, int count) throws IOException {
        Document doc = new Document();
        Random r = new Random();
        for (int i = 0; i < count; ++i) {
            doc.clear();
            doc.add(new Field("id", String.valueOf(i), TextField.TYPE_STORED));
            doc.add(new Field("author", String.valueOf(Math.abs(r.nextInt())), TextField.TYPE_STORED));
            doc.add(new Field("text", examples[Math.abs(r.nextInt() % 3)], TextField.TYPE_STORED));
            source.addDocument(doc);
        }
    }
}

