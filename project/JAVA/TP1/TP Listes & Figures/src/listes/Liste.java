package listes;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Liste<E> implements IListe<E> {
	private static class Maillon<E> {
		private E data;
		private Maillon<E> next;

		public Maillon(E x) {
			data = x;
			next = null;
		}

		public E getData() {
			return data;
		}

		public Maillon<E> getNext() {
			return next;
		}

		public void setNext(Maillon<E> next) {
			this.next = next;
		}

	}

	private Maillon<E> head;
	public Liste() {
	this.head=null;	
	}
	public Liste(Liste<E> l) {
		head=null;
		Iterator<E> it = l.iterator();
		while(it.hasNext()) {
			add(it.next());
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	   private class ListeIterator<F> implements Iterator<F>{
			private Maillon<F> current;
			private Maillon<F> last;
			private Maillon<F> penultimate;
			private F element;
			private boolean nextCalled;
			
			public  ListeIterator() {
				current = (Maillon<F>) head;
				element = null;
				last = null;
				nextCalled = false;
				penultimate = null;
			}
			
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return current != null;
		}

		@Override
		public F next() throws NoSuchElementException {
			if (current == null) {
				throw new NoSuchElementException("ListIterator:next()");

			} else {
				penultimate = last;
				last = current;
				element = current.getData();
				current = current.getNext();
				nextCalled = true;
				return element;
			}

		}
		@SuppressWarnings("unchecked")
		public void remove() throws IllegalStateException {

			if (nextCalled == false) {

				throw new IllegalStateException("ListIterator:remove()");
			} else {
		            if(last==(Maillon<F>) head){

		              head=(Maillon<E>) current;
		               last=null;
		            } else{
					last = penultimate;
					penultimate=null;
					last.setNext(current);
		            }
					nextCalled = false;
			
			}
		}

		   
	   }
	   
	   
	   


@Override
public void add(E elt) throws NullPointerException {
	if(elt==null) {
		throw new NullPointerException("add(null)");
		
	}else {
		if (head==null) {
			head = new Maillon<E>(elt);
		} else {
			Maillon<E> current = head;

			while (current.getNext() != null) {
				current = current.getNext();
			}
			current.setNext(new Maillon<E>(elt));
		}
	}
	
}

@Override
public void insert(E elt) throws NullPointerException {
	if (elt != null) {
		Maillon<E> first = new Maillon<E>(elt);
		first.setNext(head);
		head = first;

	} else {
		throw new NullPointerException("insert:error");
	}

}


@Override
public boolean insert(E elt, int index) {
	if (elt == null)
		return false;
	else {

		Maillon<E> insert = new Maillon<E>(elt);
		Maillon<E> current = head;
		
		if(index==0 ){
			insert(elt);

			return true;
		}
		while(index>1&&current!=null){
			index--;
			current=current.getNext();
		}
         
		if(current==null)return false;
		insert.setNext(current.getNext());
		current.setNext(insert);

		return true;
	}
}

/**
 * Test d'égalité au sens du contenu de la liste
 * @param o la liste dont on doit tester le contenu
 * @return true si o est une liste, que tous les maillons des deux listes
 * sont identiques (au sens du equals de chacun des maillons), dans
 * le même ordre, et que les deux listes ont la même longueur. false
 * sinon
 * @note On serait tenté d'en faire une "default method" dans la mesure où
 * l'on peut n'utiliser que l'itérateur pour parcourir les éléments de
 * la liste MAIS les méthodes par défaut n'ont pas le droit de
 * surcharger les méthodes de la superclasse Object.
 */

@Override
public boolean equals(Object o) {
	if (o == this) {
		return (true);
	}
	if (o instanceof Iterable) {
		Iterable<?> l = (Iterable<?>) o;
		Iterator<E> it = iterator();
		Iterator<?> it_l = l.iterator();
		while (it.hasNext()) {
			if (!it_l.hasNext())
				return false;
			if (!it.next().equals(it_l.next()))
				return false;
		}
		if (it_l.hasNext())
			return false;
		return true;

	} else {
		return false;
	}
}

/**
 * HashCode d'une liste
 * 
 * @return le hashCode de la liste
 * @note On serait tenté d'en faire une "default method" dans la mesure où
 *       l'on peut n'utiliser que l'itérateur pour parcourir les éléments de
 *       la liste MAIS les méthodes par défaut n'ont pas le droit de
 *       surcharger les méthodes de la superclasse Object.
 */
@Override
public int hashCode() {
	int res = 1;
	Iterator<E> it = iterator();
	while (it.hasNext()) {
		res = 31 * res + it.next().hashCode();
	}
	return res;

}

/**
 * Représentation de la chaine sous forme de chaine de caractère.
 * 
 * @return une chaine de caractère représentant la liste chainée
 * @note On serait tenté d'en faire une "default method" dans la mesure où
 *       l'on peut n'utiliser que l'itérateur pour parcourir les éléments de
 *       la liste MAIS les méthodes par défaut n'ont pas le droit de
 *       surcharger les méthodes de la superclasse Object.
 */
@Override
public String toString() {
	
	if(head==null) return "null";
	StringBuilder sb = new StringBuilder();
	sb.append("[");
	Iterator<E> it = iterator();
	while (true) {

		sb.append(it.next());
		if (!it.hasNext())
			break;
		sb.append("->");
	}
	sb.append("]");
	return sb.toString();

}


/**
 * Obtention d'un itérateur pour parcourir la liste : <code>
 * Liste<Type> l = new Liste<Type>();
 * ...
 * for (Iterator<Type> it = l.iterator(); it.hasNext(); )
 * {
 * 		... it.next() ...
 * }
 * ou bien
 * for (Type elt : l)
 * {
 * 		... elt ...
 * }
 * </code>
 * @return un nouvel itérateur sur la liste
 * @see {@link Iterable#iterator()}
 */

@Override
public Iterator<E> iterator() {
	// TODO Auto-generated method stub
	return new ListeIterator<E>();
}

}