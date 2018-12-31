package lucene;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;

import java.io.IOException;

public class SearchService {

    private SearchService(DirectoryReader path) {
        isearcher = new IndexSearcher(path);
    }
    public static SearchService newInstance(DirectoryReader path) {
        return new SearchService(path);
    }

    private IndexSearcher isearcher;
    private static final Analyzer analyzer = new StandardAnalyzer();

    public void searchAndPrint(String field, String key) throws Exception{
        print(search(field, key));
    }

    private ScoreDoc[] search(String field, String key) throws Exception{
        // Parse a simple query that searches for "text":
        QueryParser parser = null;
        if (field.equalsIgnoreCase("id")) {
            parser = new QueryParser("id", analyzer);
        } else if (field.equalsIgnoreCase("author")) {
            parser = new QueryParser("author", analyzer);
        } else if (field.equalsIgnoreCase("text")) {
            parser = new QueryParser("text", analyzer);
        } else {
            return null;
        }
        Query query = parser.parse(key);
        return isearcher.search(query, Test.TEST_SIZE).scoreDocs;
    }

    private void print(ScoreDoc[] hits) throws IOException {
        if (null == hits)   return;
        System.out.println("Total:" + hits.length);
        for (ScoreDoc scorcDoc : hits) {
            Document hitDoc = isearcher.doc(scorcDoc.doc);
            System.out.println(hitDoc.get("id") + "-" + hitDoc.get("author") + "-" + hitDoc.get("text"));
        }
    }
}
