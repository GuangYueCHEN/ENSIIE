package myMain;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.border.SoftBevelBorder;
import javax.swing.border.BevelBorder;

public class ErrorTipNotFound extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void notFound() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ErrorTipNotFound frame = new ErrorTipNotFound();
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
	public ErrorTipNotFound() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 550, 175);
		contentPane = new JPanel();
		contentPane.setBorder(new SoftBevelBorder(BevelBorder.LOWERED, null, null, null, null));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel label = new JLabel("\u6CA1\u6709\u67E5\u8BE2\u5230\u76F8\u5173\u4FE1\u606F\uFF01");
		label.setBounds(190, 57, 191, 19);
		contentPane.add(label);
	}

}
