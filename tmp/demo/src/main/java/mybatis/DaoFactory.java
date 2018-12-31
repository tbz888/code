package mybatis;

public class DaoFactory {
    private static Dao instance = new DaoImpl();

    public static Dao getInstance() {
        while (null == instance) {}
        return instance;
    }
}
