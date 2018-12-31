package mybatis;

import org.apache.ibatis.session.SqlSession;

import java.util.ArrayList;
import java.util.Random;

public class DaoImpl implements Dao{
    @Override
    public boolean add(int id, String name) {
        SqlSession session = Test.db.openSession();
//        TableMapper_annotation mapper = session.getMapper(TableMapper_annotation.class);
        TableMapper mapper = session.getMapper(TableMapper.class);

        try {
            mapper.insert_t2(id, name);
            ArrayList<Integer> tmp = new ArrayList<Integer>(3);
            tmp.add(new Random().nextInt());
            tmp.add(new Random().nextInt());
            mapper.insert_foreach(tmp);
            session.commit();
            System.out.println(mapper.query(2));
            System.out.println(mapper.query_all(-1126628409));
        } catch (Exception e) {
            e.printStackTrace();
            session.rollback();
            return false;
        }
        finally {
            session.close();
            System.out.println("session closed...");
        }
        return true;
    }
}
