package iiens;

import java.awt.FlowLayout;
	import java.awt.event.ActionEvent;
	import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
	import javax.swing.JFrame;

	public class jiemiantiaozhuan extends JFrame implements ActionListener{

	    /**
	     * @param args
	     */
		
	    private JButton jb;
	    public jiemiantiaozhuan ()
	    {
	   
	   // 	FlowLayout layout =new FlowLayout(2);
	    	//this.setLayout(layout);
	    	
	    	
	        this.setSize(300, 300);
	       this.setLocation(666, 300);
	     
	       ImageIcon icon=new ImageIcon("/users/pingguo/wtf/images/tp.jpg");
	       // JButton jb=new JButton("跳转"); 不知道为什么这样声明跳转会失败
			jb=new JButton("跳转",icon);
	        this.add(jb);
	        jb.addActionListener(this);//加入事件监听
	        this.setVisible(true);
	        
	    }
	    public static void main(String[] args) {
	        // TODO Auto-generated method stub
	    	jiemiantiaozhuan  frame=new jiemiantiaozhuan ();
	           
	    }
	    @Override
	    public void actionPerformed(ActionEvent e) {
	        // TODO Auto-generated method stub
	        if(e.getSource()==jb)
	        {
	            this.dispose();//点击按钮时frame1销毁,new一个frame2
	            new jiemian_();
	        }
	    }
	}
