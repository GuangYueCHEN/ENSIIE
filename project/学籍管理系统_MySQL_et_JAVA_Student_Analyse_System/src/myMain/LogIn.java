package myMain;
//登陆界面
import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import mysqlUtil.dbUtil;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

public class LogIn extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = -331049625997065771L;
	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;
	private String userName = null;
	private String userPassword = null;

	/**
	 * 主函数 --登陆界面
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LogIn frame = new LogIn();//建立界面	
					frame.setVisible(true);//界面设置为可见
				} catch (Exception e) {
					e.printStackTrace();
				}//捕捉错误
			}
		});
	}

	/**
	 * 建立login界面的fonction
	 */
	public LogIn() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel label = new JLabel("\u7528\u6237\u540D");
		label.setBounds(118, 106, 54, 15);
		contentPane.add(label);

		JLabel label_1 = new JLabel("\u5BC6\u7801");
		label_1.setBounds(118, 142, 54, 15);
		contentPane.add(label_1);

		textField = new JTextField();
		textField.setBounds(182, 103, 111, 21);
		contentPane.add(textField);
		textField.setColumns(10);

		textField_1 = new JTextField();
		textField_1.setBounds(182, 142, 111, 21);
		contentPane.add(textField_1);
		textField_1.setColumns(10);
		//设置界面的用户名及密码输入并且保存在textField中
		
		//设置按钮
		JButton button = new JButton("\u767B\u9646");
		button.setBounds(92, 191, 93, 23);
		//设置listenner 监视鼠标点击
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				userName = textField.getText();
				userPassword = textField_1.getText();
				//得到用户名密码
				dbUtil util = new dbUtil();
				Connection connection = null;
				try {
					connection = util.getCon();
					String sql = "select * from logIn where name = ? and code = ?";
					PreparedStatement preparedStatement = connection.prepareStatement(sql);
					preparedStatement.setString(1, userName);
					preparedStatement.setString(2, userPassword);
					//与登录表匹配 ， 匹配成功进入管理界面
					ResultSet resultSet = preparedStatement.executeQuery();
					if (resultSet.next()) {
						
						dispose();
						ManagerFrame.mainManager();
					} else {
						ErrorTipLog.mainErrorTipLog();
					}
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					ErrorTipMistake.mainErrorTipMistake();
					e1.printStackTrace();
				}

			}
		});
		contentPane.add(button);

		JButton button_1 = new JButton("\u9000\u51FA");
		button_1.setBounds(278, 191, 93, 23);
		contentPane.add(button_1);
	}
}
