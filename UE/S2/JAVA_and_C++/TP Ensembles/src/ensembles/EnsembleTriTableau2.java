package ensembles;

import java.util.Iterator;

import tableaux.Tableau;

public class EnsembleTriTableau2<E extends Comparable<E>>  extends EnsembleTriGenerique<E>{


	
	public EnsembleTriTableau2() {
		ensemble=new EnsembleTableau<E>();
	}
	
	public EnsembleTriTableau2(Iterable<E> element) {
		this();
		for(E elt: element)
			this.ajout(elt);
	}
	@Override
	protected boolean insererAuRang(E element, int rang) {
		if (element==null||this.contient(element))
			return false;
		((EnsembleTableau<E>) ensemble).tableau.insertElement(element, rang);
			return true;
	}


}
