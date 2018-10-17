package mysqlUtil;

import java.sql.DriverManager;
import java.sql.Connection;

public class dbUtil {
	// 连接数据库的语句
	private static String dbUrl = "jdbc:mysql://localhost:3306/XJGL?useUnicode=true&characterEncoding=UTF-8";
	// 用户名
	private static String dbUserName = "root";
	// 用户密码
	private static String dbPassword = "q11222321";
	// 数据库driver
	private static String jdbcName = "com.mysql.jdbc.Driver";

	public Connection getCon() throws Exception {
		try {
			Class.forName(jdbcName);
			Connection con = DriverManager.getConnection(dbUrl, dbUserName, dbPassword);
			System.out.println("连接数据库\n");
			return con;
		} catch (Exception e) {
			// TODO: handle exception
			 System.out.println("连接失败");
			return null;
		}
	}
//关闭连接
	public void close(Connection con) throws Exception {
		if (con != null) {
			con.close();
		}
	}
}
