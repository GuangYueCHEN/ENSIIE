package ensembles;

import java.util.Iterator;
import java.util.Vector;

public class EnsembleVector<E> extends EnsembleGenerique<E> {
	protected Vector<E> vector;
	public EnsembleVector() {
		vector=new Vector<E>();
	}
	public EnsembleVector(Iterable<E> ensemble) {
		vector=new Vector<E>();
		Iterator<E> it = ensemble.iterator();
		while(it.hasNext()) {
			this.ajout(it.next());
		}
	}

	@Override
	public boolean ajout(E element) {
		if (element==null||this.contient(element))
			return false;
		return	vector.add(element);
		
	}

	@Override
	public Ensemble<E> union(Ensemble<E> ensemble) {
		Ensemble<E>res = new EnsembleVector<E>();
		Ensemble.union(this, ensemble, res);
		
		return res;
	}

	@Override
	public Ensemble<E> intersection(Ensemble<E> ensemble) {
		// TODO Auto-generated method stub
		Ensemble<E>res = new EnsembleVector<E>();
		Ensemble.intersection(this, ensemble, res);
		
		return res;
	
	}

	@Override
	public Ensemble<E> complement(Ensemble<E> ensemble) {
		// TODO Auto-generated method stub
		Ensemble<E>res = new EnsembleVector<E>();
		Ensemble.complement(this, ensemble, res);
		
		return res;

	}

	@Override
	public Iterator<E> iterator() {
		// TODO Auto-generated method stub
		return vector.iterator();
	}


}
