package ensembles;

public class EnsembleTriVector2<E extends Comparable<E>>  extends EnsembleTriGenerique<E> {
	public EnsembleTriVector2() {
		ensemble=new EnsembleVector<E>();
	}
	public EnsembleTriVector2(Iterable<E> element) {
		ensemble=new EnsembleVector<E>();
		for(E elt : element)
			this.ajout(elt);
	}
	
	@Override
	protected boolean insererAuRang(E element, int rang) {
		if (element==null||this.contient(element))
			return false;
		((EnsembleVector<E>) ensemble).vector.add(rang,element);
			return true;
	}

}
