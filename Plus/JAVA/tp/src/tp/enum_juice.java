package tp;
class Juice {
	enum Size { SMALL , MID ,LARGE }
	Size size;
}
public class enum_juice {
public static void main(String []args) {
	Juice orange = new Juice();
	orange.size = Juice.Size.MID;
	System.out.println(orange.size);
	
}
}
