package listes;

import java.util.AbstractCollection;
import java.util.ArrayList;
import java.util.Iterator;

public class CollectionListe<E> extends AbstractCollection<E> {
	
	
	private Liste<E> liste;
	public  CollectionListe(){
		this.liste=new Liste<E>();
	}
	public  CollectionListe(CollectionListe<E> copi){
		this.liste=new Liste<E>(copi.getList());
		
	}
	
	
	
	
	public CollectionListe(ArrayList<E> otherCollection) {
		this.liste = new Liste<E>();
		for (E e : otherCollection) {
			this.liste.add(e);
}
	}
	public Liste<E> getList(){
		return this.liste;
	}
	@Override
	public boolean add(E elt){
		try{
		if(elt==null)return false;
		this.liste.add(elt);
		}catch(Exception e){
			System.out.println("exception\n");
			return false;
		}
		System.out.println(this.liste);
		return true;
	}
	
	@Override
	public boolean equals(Object o){
		return liste.equals(o);
	}
	
	@Override
	public Iterator<E> iterator() {
		return (this.liste.iterator());
}


	@Override
	public int size() {
		return (this.liste.size());
}
	@Override
	public int hashCode(){
		return liste.hashCode();
	}

}
