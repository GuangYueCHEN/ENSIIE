package myMain;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;

public class ErrorTipLog extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void mainErrorTipLog() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ErrorTipLog frame = new ErrorTipLog();
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
	public ErrorTipLog() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 463, 158);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel label = new JLabel(
				"\u7528\u6237\u540D\u6216\u5BC6\u7801\u9519\u8BEF\uFF0C\u767B\u5F55\u5931\u8D25\uFF01");
		label.setFont(new Font("����", Font.PLAIN, 16));
		label.setBounds(118, 44, 224, 26);
		contentPane.add(label);
	}

}
