package mybatis;

import org.apache.ibatis.annotations.Param;

import java.util.ArrayList;
import java.util.List;

public interface TableMapper {
    /* @Param 多参数时，必须的注解。坑
     * java的配置很容易出错，不是开箱即用的。艹
     */
    int insert_t2(@Param("id") int id, @Param("name") String name) throws Exception;

    Model query(@Param("id") int id);

    Model query_all(@Param("id") int id);

    int insert_foreach(@Param("ids")ArrayList<Integer> ids) throws Exception;

}
