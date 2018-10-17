package iiens;
import javax.swing.*;
import java.awt.event.*;

public class Buttontest {

    JButton b;
    JRadioButton rb;

    public Buttontest() {
        JFrame f = new JFrame("Test");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.getContentPane().setLayout(
            new java.awt.FlowLayout());
        b = new JButton("JButton");
        rb = new JRadioButton("RadioButton");
        ActionListener a = new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                if (ae.getSource() == b) {
                    System.out.println(
                        "You clicked the JButton");
                } else {
                    System.out.println(
                        "You clicked the RadioButton");
                }
            }
        };
        b.addActionListener(a);
        rb.addActionListener(a);
        f.getContentPane().add(b);
        f.getContentPane().add(rb);
        f.pack();
        f.show();
    }
    public static void main(String[] args) {
        new Buttontest();
    }

}