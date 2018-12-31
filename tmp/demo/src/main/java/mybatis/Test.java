package mybatis;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.Random;

public class Test {

    private static final String ERROR = "ERROR";
    private static final String WARN = "WARN";
    private static final String INFO = "INFO";
    public static SqlSessionFactory db;

    /**
     * 省事，应该用slf4j
     */
    private static void log(String level, String message) {
        StringBuilder sb = new StringBuilder("[");
        sb.append(level);
        sb.append("] ");
        sb.append(message);
        System.out.println(sb);
    }

    public static void main(String[] args) {
        System.out.println("start mybatis.");

        db = init();
        if (null == db) {
            log(ERROR, "init failed.");
        }
        else {
            log(INFO, "init success.");
        }

        DaoFactory.getInstance().add(new Random().nextInt() % 8, "damn");

        System.out.println("end mybatis.");
    }

    private static SqlSessionFactory init() {
        String resource = "dbsource.xml";
        InputStream inputStream = null;
        try {
            inputStream = Resources.getResourceAsStream(resource);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return new SqlSessionFactoryBuilder().build(inputStream);
    }

}
