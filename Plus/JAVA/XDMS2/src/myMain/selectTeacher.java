package myMain;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import javax.swing.plaf.basic.BasicInternalFrameTitlePane.IconifyAction;

import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.PlainDocument;

import mysqlUtil.dbUtil;

import java.sql.PreparedStatement;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.nio.channels.ScatteringByteChannel;
import java.sql.Connection;
import java.sql.ResultSet;

public class selectTeacher extends JFrame {

	/**
	 * 查询授课教师
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;
	private JTable table;
	private JScrollPane scrollPane;
	private int rows = 0;
	private JTextField textFieldReq;
	private JTextField textFieldSelect;
	private JTextField textFieldSum;
	private int requiredGrade = 0;
	private int requiredCredit = 0;
	private int selectGrade = 0;
	private int score = 0;
	private int selectCredit = 0;
	private int sumGrade = 0;
	private int sumCredit = 0;
	private int credittemp = 0;
	private String courseType = null;
	private String courseNumber = null;
	private String className = null;

	/**
	 * Launch the application.
	 */
	public static void getTeacher() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					selectTeacher frame = new selectTeacher();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public selectTeacher() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 538, 502);
		contentPane = new JPanel();
		contentPane.setBorder(new LineBorder(new Color(0, 0, 0)));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel label = new JLabel("\u59D3\u540D");
		label.setBounds(162, 61, 54, 15);
		contentPane.add(label);

		textField = new JTextField();
		textField.setBounds(246, 58, 92, 21);
		contentPane.add(textField);
		textField.setColumns(10);

		JLabel label_1 = new JLabel("\u5B66\u53F7");
		label_1.setBounds(162, 92, 54, 15);
		contentPane.add(label_1);

		textField_1 = new JTextField();
		textField_1.setBounds(246, 89, 92, 21);
		contentPane.add(textField_1);
		textField_1.setColumns(10);

		JButton button = new JButton("\u68C0\u6D4B");
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (textField.getText().length() > 0 && textField_1.getText().length() > 0) {
					scrollPane.remove(table);
					dbUtil util = new dbUtil();
					Connection connection = null;
					PreparedStatement preparedStatement = null;
					ResultSet resultSet = null;
					try {
						connection = util.getCon();
						preparedStatement = connection
								.prepareStatement("select count(*) from (select distinct sid,sname,tid,tname from student join class join class_teacher join teacher on sclass=class_teacher.class_id and teacher_id=tid where sid = ?)a");
						preparedStatement.setString(1, textField_1.getText());
						resultSet = preparedStatement.executeQuery();
						if (resultSet.next()) {
							rows = resultSet.getInt(1);
							System.out.println(rows);
						}
                 
						table = new JTable();
						table.setModel(new DefaultTableModel(new Object[rows][6],
								new String[] { "   \u8BFE\u540D", "  \u6210\u7EE9", "  \u6027\u8d28", "  \u6559\u5E08","--" }));
						table.setBorder(new LineBorder(new Color(0, 0, 0)));
						scrollPane.setViewportView(table);
						preparedStatement = connection.prepareStatement(
								"select distinct class_id,sid,sname,student_course.course_id,score,property,credit,teacher_id,tname from student join student_course join course join class_teacher join teacher on sid=student_id and student_course.course_id=cid  and sclass=class_teacher.class_id and teacher_id=tid and student_course.course_id=class_teacher.course_id where sid  =?");
						preparedStatement.setString(1, textField_1.getText());
						resultSet = preparedStatement.executeQuery();
						for (int i = 0; resultSet.next(); i++) {
							System.out.println(i);
							table.setValueAt(resultSet.getString(4), i, 0);
							table.setValueAt(resultSet.getString(5), i, 1);
							table.setValueAt(resultSet.getString(6), i, 2);
							table.setValueAt(resultSet.getString(8), i, 3);

							// System.out.println("===="+resultSet.getString(3)+"===="+resultSet.getString(3).length());
							if (resultSet.getString(4) != null) {
								//String majorDirectionTemp = null;
								
								String termTemp = null;
								//String plan = null;
								//String plancourse = null;
								//String majorTemp = null;
								//courseNumber = resultSet.getString(4);
								//preparedStatement = connection.prepareStatement(
								//		" select distinct class_id,sid,sname,student_course.course_id,score,property,credit,teacher_id,tname from student join student_course join course join class_teacher join teacher on sid=student_id and student_course.course_id=cid  and sclass=class_teacher.class_id and teacher_id=tid and student_course.course_id=class_teacher.course_id where sid  =?");
								//preparedStatement.setString(1, textField_1.getText());
								//ResultSet resultSet2 = preparedStatement.executeQuery();
							//	if (resultSet2.next()) {
									termTemp = resultSet.getString(2);
									className = resultSet.getString(1);
									credittemp = resultSet.getInt(7);
									courseType = resultSet.getString(6);
									//score =  resultSet.getString(5);
									System.out.println(termTemp );
									System.out.println(credittemp);
									System.out.println(courseType);
									System.out.println(className);
									//majorDirectionTemp = resultSet2.getString(3);
									//preparedStatement = connection
											//.prepareStatement("select majorNumber from class where className = ?");
									//preparedStatement.setString(1, className);
									//resultSet2 = preparedStatement.executeQuery();
									//if (resultSet2.next()) {

									//	majorTemp = resultSet2.getString(1);
									//}
									//preparedStatement = connection.prepareStatement(
											//"select count(*) from majorTrainingplan where majorNumber =? and courseNumber = ?");
									//preparedStatement.setString(1, majorTemp);
									//preparedStatement.setString(2, courseNumber);
									//resultSet2 = preparedStatement.executeQuery();
									//if (resultSet2.next()) {
										//if (resultSet2.getInt(1) > 0) {
										//	preparedStatement = connection.prepareStatement(
										//			"select credit,courseType from majorTrainingPlan where courseNumber = ? and majorNumber = ?");
											//preparedStatement.setString(1, courseNumber);//
											//preparedStatement.setString(2, majorTemp);//
											//resultSet2 = preparedStatement.executeQuery();
											//if (resultSet2.next()) {
											//	credittemp = resultSet2.getInt(1);
											//	courseType = resultSet2.getString(2);
											//}
									//	}
									//} else {
										//preparedStatement = connection.prepareStatement(
											//	"select credit,courseType from majorDirectionPlan where courseNumber = ? and majorDirectionNumber= ?");
										//preparedStatement.setString(1, courseNumber);//
										//preparedStatement.setString(2, majorDirectionTemp);
										//resultSet2 = preparedStatement.executeQuery();
										//if (resultSet2.next()) {
											//credittemp = resultSet2.getInt(1);
											//courseType = resultSet2.getString(2);
										//}
									//}
									System.out.println(Integer.parseInt((String) table.getValueAt(i, 1)));
									if (courseType.equals("必修")) {
										requiredCredit += credittemp;
										requiredGrade += Integer.parseInt((String) table.getValueAt(i, 1)) * credittemp;
									} else {
										selectCredit += credittemp;
										selectGrade += Integer.parseInt((String) table.getValueAt(i, 1)) * credittemp;
									}
									sumCredit += credittemp;
									sumGrade += Integer.parseInt((String) table.getValueAt(i, 1)) * credittemp;

								}
							//}*/

						}

						if (requiredCredit != 0)
							textFieldReq.setText(String.valueOf(requiredGrade / requiredCredit));
						else {
							textFieldReq.setText("null");
						}
						if (selectCredit != 0) {
							textFieldSelect.setText(String.valueOf(selectGrade / selectCredit));
						} else {
							textFieldSelect.setText("null");
						}
						if (sumCredit != 0)
							textFieldSum.setText(String.valueOf(sumGrade / sumCredit));
						else {
							textFieldSum.setText("null");
						}
						preparedStatement.close();
					} catch (Exception e1) {
						// TODO Auto-generated catch block
						ErrorTipMistake.mainErrorTipMistake();
						e1.printStackTrace();
					}

				}
			}
		});
		button.setBounds(198, 134, 93, 23);
		contentPane.add(button);

		scrollPane = new JScrollPane();
		scrollPane.setBorder(new LineBorder(new Color(130, 135, 144)));
		scrollPane.setBounds(45, 183, 445, 178);
		contentPane.add(scrollPane);

		table = new JTable();
		table.setModel(new DefaultTableModel(new Object[][] { { null, null, null,null ,null}, },
				new String[] { "   \u8BFE\u540D", "  \u6210\u7EE9", "  \u6027\u8d28", "  \u6559\u5E08","--"  }));
		table.setBorder(new LineBorder(new Color(0, 0, 0)));
		scrollPane.setViewportView(table);

		JLabel label_2 = new JLabel("\u5FC5\u4FEE\u5747\u5206");
		label_2.setBounds(88, 383, 54, 15);
		contentPane.add(label_2);

		textFieldReq = new JTextField();
		textFieldReq.setBounds(74, 419, 71, 21);
		contentPane.add(textFieldReq);
		textFieldReq.setColumns(10);

		JLabel label_3 = new JLabel("\u9009\u4FEE\u5747\u5206");
		label_3.setBounds(224, 383, 54, 15);
		contentPane.add(label_3);

		textFieldSelect = new JTextField();
		textFieldSelect.setBounds(212, 419, 79, 21);
		contentPane.add(textFieldSelect);
		textFieldSelect.setColumns(10);

		JLabel label_4 = new JLabel("\u603B\u4F53\u5747\u5206");
		label_4.setBounds(370, 383, 54, 15);
		contentPane.add(label_4);

		textFieldSum = new JTextField();
		textFieldSum.setBounds(358, 419, 71, 21);
		contentPane.add(textFieldSum);
		textFieldSum.setColumns(10);

	}
}
