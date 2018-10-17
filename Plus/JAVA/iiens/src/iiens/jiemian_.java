package iiens;
import java.awt.FlowLayout;
import javax.swing.JButton;
public class jiemian_ {
	jiemian_(){
		
		//shezhichuangkou
		javax.swing.JFrame jf =new javax.swing.JFrame();
		jf.setTitle("一个简单的小窗口");
		
		jf.setSize(300,300);
		FlowLayout layout =new FlowLayout(1);
		//设置流式布局并且给予窗口
		jf.setLayout(layout);
		
		
		 jf.setLocation(666, 300);
		//biaoqian
		javax.swing.JLabel la1 = new javax.swing.JLabel("账号");
		jf.add(la1);
		
		//wen ben kuang
		javax.swing.JTextField tf1=new javax.swing.JTextField(20);
		jf.add(tf1);
		
		javax.swing.JLabel la2 = new javax.swing.JLabel("密码"); 
		jf.add(la2); 
		javax.swing.JTextField tf2 = new javax.swing.JTextField(20); 
		jf.add(tf2); 
		
		//button
		javax.swing.JButton bu =new javax.swing.JButton("登陆");
		jf.add(bu);
		//关闭方式
		jf.setDefaultCloseOperation(3);
		//kejian
		jf.setVisible(true);
		
		
		
	}
public static void main(String[] args) {
	
	jiemian_ jv= new jiemian_();
	
	
	
}
	
}
