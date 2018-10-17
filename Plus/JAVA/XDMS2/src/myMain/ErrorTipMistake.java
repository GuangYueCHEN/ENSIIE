package myMain;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;

public class ErrorTipMistake extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void mainErrorTipMistake() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ErrorTipMistake frame = new ErrorTipMistake();
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
	public ErrorTipMistake() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 450, 175);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel label = new JLabel(
				"\u7CFB\u7EDF\u53D1\u751F\u4E86\u4E0D\u77E5\u540D\u7684\u9519\u8BEF\uFF0C\u5EFA\u8BAE\u91CD\u542F\u7CFB\u7EDF\uFF01");
		label.setBounds(100, 49, 261, 29);
		contentPane.add(label);
	}

}
