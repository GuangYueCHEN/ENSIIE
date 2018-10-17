
package ensembles;

import java.util.Iterator;



public class EnsembleTriListe2<E extends Comparable<E>>  extends EnsembleTriGenerique<E>{


	
	public EnsembleTriListe2() {
		ensemble=new EnsembleListe<E>();
	}
	
	public EnsembleTriListe2(Iterable<E> element) {
		this();
		for(E elt: element)
			this.ajout(elt);
	}
	@Override
	protected boolean insererAuRang(E element, int rang) {
		if (element==null||this.contient(element))
			return false;
		((EnsembleListe<E>) ensemble).list.insert(element, rang);
			return true;
	}


}
