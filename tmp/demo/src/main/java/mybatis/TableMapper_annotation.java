package mybatis;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

public interface TableMapper_annotation {
    /* @Param 多参数时，必须的注解。坑
     * java的配置很容易出错，不是开箱即用的。艹
     */
    @Insert("insert into tbz (id, name) values (#{id}, #{name});")
    int insert_annotaion(@Param("id") int id, @Param("name") String name) throws Exception;
}
