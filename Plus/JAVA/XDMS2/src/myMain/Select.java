package myMain;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.Color;
import javax.swing.border.LineBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

import mysqlUtil.dbUtil;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Select extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textFieldName;
	private JTextField textFieldNumber;
	private JTextField textFieldMajor;
	private JTable table;
	private dbUtil util = null;
	private Connection connection = null;
	private PreparedStatement preparedStatement = null;
	private ResultSet resultSet = null;
	private String sql = null;
	private int rows = 0;
	private JScrollPane scrollPane;

	/**
	 * Launch the application.
	 */
	public static void select() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Select frame = new Select();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * 
	 * @throws Exception
	 */
	public Select() throws Exception {
		setResizable(false);

		// 设置关闭按键
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 799, 496);
		contentPane = new JPanel();
		contentPane.setBorder(new LineBorder(new Color(0, 0, 0)));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		// 连接数据库
		util = new dbUtil();
		connection = util.getCon();

		JLabel labelName = new JLabel("\u59D3\u540D");
		labelName.setBounds(298, 32, 54, 15);
		contentPane.add(labelName);

		JLabel labelNumber = new JLabel("\u5B66\u53F7");
		labelNumber.setBounds(298, 57, 54, 15);
		contentPane.add(labelNumber);
		JLabel labelMajor = new JLabel("\u4E13\u4E1A");
		labelMajor.setBounds(298, 80, 54, 15);
		contentPane.add(labelMajor);
//检测
		JButton button = new JButton("\u68C0\u6D4B");
		button.addMouseListener(new MouseAdapter() {
			@Override
			//鼠标点击按钮后 如果输入名字就保存名字 如果是学好保存学好 
			public void mouseClicked(MouseEvent e) {
				scrollPane.remove(table);

				String temp = null;
				String temp1 = null;
				if (textFieldName.getText().length() > 0 && textFieldNumber.getText().length() == 0) {
					temp = textFieldName.getText();
					temp1 = "sname";
				} else if (textFieldNumber.getText().length() > 0) {
					temp = textFieldNumber.getText();
					temp1 = "sid";
				}else if (textFieldMajor.getText().length() > 0) {
					temp = textFieldMajor.getText();
					temp1 = "mname";
				} 
//下面是各种的查询
				try {
					//挑选的sql语句，根据查询的不同后期可惊醒修改
					preparedStatement = connection
							.prepareStatement("select sid,sname,ssex,sbirthday,sclass,mname from student  join class join major on student.sclass=class.class_id and  class.major_id=major.mid  where " + temp1 + " = ?");
					preparedStatement.setString(1, temp);
					resultSet = preparedStatement.executeQuery();
					//执行
					if (resultSet.next()) {
						rows = resultSet.getInt(1);
					}
					if (rows == 0) {
						ErrorTipNotFound.notFound();
					} else {
						table.setRowHeight(24);
						table.setModel(new DefaultTableModel(new Object[rows][9], new String[] { " 学号", "  姓名",
								" 性别", "  生日", "    班级","专业","---"}));
						table.getColumnModel().getColumn(1).setPreferredWidth(85);
						table.getColumnModel().getColumn(2).setPreferredWidth(35);
						table.getColumnModel().getColumn(3).setPreferredWidth(60);
						table.getColumnModel().getColumn(4).setPreferredWidth(100);
						table.getColumnModel().getColumn(5).setPreferredWidth(90);
						table.getColumnModel().getColumn(6).setPreferredWidth(35);
						//table.getColumnModel().getColumn(8).setPreferredWidth(80);
						table.setBorder(new LineBorder(new Color(0, 0, 0)));
						scrollPane.setViewportView(table);
						preparedStatement = connection
								.prepareStatement("select sid,sname,ssex,sbirthday,sclass,mname from student  join class join major on student.sclass=class.class_id and  class.major_id=major.mid  where " + temp1 + " = ?");
						preparedStatement.setString(1, temp);
						resultSet = preparedStatement.executeQuery();
						for (int i = 0; resultSet.next(); i++) {
							table.setValueAt(resultSet.getString(1), i, 0);
							table.setValueAt(resultSet.getString(2), i, 1);
							table.setValueAt(resultSet.getString(3), i, 2);
							table.setValueAt(resultSet.getString(4), i, 3);
							table.setValueAt(resultSet.getString(5), i, 4);
							table.setValueAt(resultSet.getString(6), i, 5);
							//table.setValueAt(resultSet.getString(7), i, 6);
							//table.setValueAt(resultSet.getString(8), i, 7);//
							//table.setValueAt(resultSet.getString(9), i, 8);
						}
					}

					preparedStatement.close();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		button.setBounds(318, 102, 93, 23);
		contentPane.add(button);

		textFieldName = new JTextField();
		textFieldName.setBounds(382, 29, 100, 21);
		contentPane.add(textFieldName);
		textFieldName.setColumns(10);

		textFieldNumber = new JTextField();
		textFieldNumber.setBounds(382, 54, 100, 21);
		contentPane.add(textFieldNumber);
		textFieldNumber.setColumns(10);
		
		textFieldMajor = new JTextField();
		textFieldMajor.setBounds(382, 78, 100, 21);
		contentPane.add(textFieldMajor);
		textFieldMajor.setColumns(10);
		
		scrollPane = new JScrollPane();
		scrollPane.setBorder(new LineBorder(new Color(130, 135, 144)));
		scrollPane.setBounds(10, 135, 763, 312);
		contentPane.add(scrollPane);

		sql = "select count(*) from student ";
		preparedStatement = connection.prepareStatement(sql);
		resultSet = preparedStatement.executeQuery();
		if (resultSet.next())
			rows = resultSet.getInt(1);
		table = new JTable();
		table.setRowHeight(24);
		table.setModel(new DefaultTableModel(new Object[rows][9],
				new String[] { " 学号", "  姓名", "性别", "  生日", "    ר班级","专业","---"}));
		table.getColumnModel().getColumn(1).setPreferredWidth(85);
		table.getColumnModel().getColumn(2).setPreferredWidth(35);
		table.getColumnModel().getColumn(3).setPreferredWidth(60);
		table.getColumnModel().getColumn(4).setPreferredWidth(100);
		table.getColumnModel().getColumn(5).setPreferredWidth(90);
		table.getColumnModel().getColumn(6).setPreferredWidth(35);
		//table.getColumnModel().getColumn(8).setPreferredWidth(80);
		//table.setBorder(new LineBorder(new Color(0, 0, 0)));

		preparedStatement = connection.prepareStatement("select sid,sname,ssex,sbirthday,sclass,mname from student  join class join major on student.sclass=class.class_id and  class.major_id=major.mid  ;");
		resultSet = preparedStatement.executeQuery();
		for (int i = 0; resultSet.next(); i++) {
			table.setValueAt(resultSet.getString(1), i, 0);
			table.setValueAt(resultSet.getString(2), i, 1);
			table.setValueAt(resultSet.getString(3), i, 2);
			table.setValueAt(resultSet.getString(4), i, 3);
			table.setValueAt(resultSet.getString(5), i, 4);
			table.setValueAt(resultSet.getString(6), i, 5);
			//table.setValueAt(resultSet.getString(7), i, 6);
			//table.setValueAt(resultSet.getString(8), i, 7);
			//table.setValueAt(resultSet.getString(9), i, 8);
		}

		scrollPane.setViewportView(table);
	}
}