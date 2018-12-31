package lucene;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.RAMDirectory;

import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Test {
    public static final int TEST_SIZE = 200;

    public static void main(String args[]) throws Exception {
        Analyzer analyzer = new StandardAnalyzer();

        // Store the index in memory:
        Directory directory = new RAMDirectory();
        IndexWriterConfig config = new IndexWriterConfig(analyzer);
        IndexWriter iwriter = new IndexWriter(directory, config);
        DataGenerator.getInstance().generate(iwriter, Test.TEST_SIZE);
        iwriter.close();
        // Now search the index:
        DirectoryReader ireader = DirectoryReader.open(directory);
        SearchService isearcher = SearchService.newInstance(ireader);

        Thread.dumpStack();

        /** Demo
         *
         */
        isearcher.searchAndPrint("text", "love");
        testTokenStream(analyzer);

        ireader.close();
        directory.close();

        f();
    }

    /**
     * 分词，标准分析器只对于英文有效
     *
     * @param analyzer
     * @throws IOException
     */
    private static void testTokenStream(Analyzer analyzer) throws IOException {
        TokenStream tokenstream = analyzer.tokenStream("1.txt", new StringReader("i dont't want to go work."));
        CharTermAttribute attribute = tokenstream.addAttribute(CharTermAttribute.class);
        tokenstream.reset();
        while (tokenstream.incrementToken()) {//判断是否还有下一个Token
            System.out.println(attribute);
        }
        tokenstream.end();
        tokenstream.close();
    }

    private static void f() {
        ExecutorService p = Executors.newFixedThreadPool(20);

        List<Callable<Integer>> array = new ArrayList<Callable<Integer>>(1);
        array.add(new Callable<Integer>() {
            @Override
            public Integer call() {
                int i = 23;
                while (true) {
                    i = 31;
                    if(123<1)  break;
                }
                return 2;
            }
        });


        try {
//            p.invokeAll(array);
            p.submit(new Callable<Integer>() {
                @Override
                public Integer call() {
                    int i = 23;
                    while (true) {
                        i = 31;
                        if(123<1)  break;
                    }
                    return 2;
                }
            }).get();

        } catch (Exception e) {
        }


        System.out.println(1231231);

//        List<Future<?>> array = new ArrayList<Future<?>>(20);
//        for (int i = 0; i < 20; i++) {
//            array.add(p.submit(new Callable<Integer>() {
//                @Override
//                public Integer call() {
//                    System.out.println(Thread.currentThread().toString());
//                    return 1;
//                }
//            }));
//        }
//
//        try {
//        for (int i = 0; i < 20; i++) {
//            System.out.println((Integer) (array.get(i).get()));
//        }}
//        catch (Exception e) {}
    }
}
