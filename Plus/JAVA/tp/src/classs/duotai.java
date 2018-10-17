package classs;
abstract class Animal{
	abstract void eat();
	
}
class Cat extends Animal{
	public void eat() {
		System.out.print("cat eat fish\n");
	}
	public void work() {
		System.out.print("cat catch mouses\n");
	}
}

class Dog extends Animal{
	public void eat() {
		System.out.print("dogs eat bones\n");
	}public void work() {
		System.out.print("dogs catch cats\n");
	}
}




public class duotai {
public static void main(String[] args) {
	show(new Cat());
	show(new Dog());
	
	Animal a = new Cat();
	a.eat();
Cat c= (Cat)a;
c.work();
	
}

public static void show(Animal a) {
	a.eat();
	if(a instanceof Cat) {
		Cat c =(Cat)a;
		c.work();
	}else if(a instanceof Dog) {
		Dog d=(Dog)a;
		d.work();
	}
	
}
}
