package ensembles;

import java.util.Iterator;

/**
 * Ensemble Générique implémentant partiellement les opérations communes à tous
 * les ensembles quels que soit les conteneurs sous-jacents utilisés pour
 * stocker les éléments de l'ensemble. L'ensemble générique est implémenté en
 * majeure partie grâce à l'itérateur fourni par la méthode {@link #iterator()}
 *
 * @author davidroussel
 */
public abstract class EnsembleGenerique<E> implements Ensemble<E> {
	/*
	 * (non-Javadoc)
	 * @see ensembles.Ensemble#ajout(java.lang.Object)
	 */
	@Override
	public abstract boolean ajout(E element);

	/*
	 * (non-Javadoc)
	 * @see ensembles.Ensemble#union(ensembles.Ensemble)
	 */
	@Override
	public abstract Ensemble<E> union(Ensemble<E> ensemble);

	/*
	 * (non-Javadoc)
	 * @see ensembles.Ensemble#intersection(ensembles.Ensemble)
	 */
	@Override
	public abstract Ensemble<E> intersection(Ensemble<E> ensemble);

	/*
	 * (non-Javadoc)
	 * @see ensembles.Ensemble#complement(ensembles.Ensemble)
	 */
	@Override
	public abstract Ensemble<E> complement(Ensemble<E> ensemble);

	/*
	 * (non-Javadoc)
	 * @see ensembles.Ensemble#iterator()
	 */
	@Override
	public abstract Iterator<E> iterator();

	/**
	 * Test d'égalité entre deux ensembles
	 *
	 * @param o l'objet à comparer
	 * @return true si l'objet à comparer est un ensemble et qu'il contient les
	 *         mêmes éléments (pas forcément dans le même ordre). Si les deux
	 *         ensembles sont vides on considère qu'ils seront égaux quel que
	 *         soit leur type de contenu (dans la mesure où l'on ne peut pas le
	 *         déterminer avec {@link ensembles.Ensemble#typeElements()}
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		if(obj == null)
			return false;
		if(obj == this)
			return true;
		if(!(obj instanceof Ensemble<?>))
			return false;
		
		Ensemble<?> other = (Ensemble<?>) obj;
		
		if(typeElements() != other.typeElements())
			return false;
		if(typeElements() == null)
			return estVide();
		
		@SuppressWarnings("unchecked")
		Ensemble<E> other_E = (Ensemble<E>) other;
		
		return (contient(other_E) && other_E.contient(this));
	}

	/**
	 * Hashcode d'un ensemble en utilisant l'itérateur pour parcourir les
	 * éléments. Le HashCode d'un ensemble doit être calculé comme étant la
	 * somme des hashcodes de ses éléments afin de ne pas tenir compte de
	 * l'ordre des éléments dans la collection sous-jacente.
	 *
	 * @return le hashage d'un ensemble
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		Iterator<E> it = iterator();
		int result = 0;
		
		while(it.hasNext())
			result += it.next().hashCode();
		
		return result;
	}

	/**
	 * Affichage des élement de l'ensemble sous la forme : par exemple pour un
	 * ensemble de 3 elts : "[elt1, elt2, elt3]" où eltn représente le toString
	 * du nième elt.
	 *
	 * @return une chaine de caractère représentant les éléments de l'ensemble
	 *         séparé par des virgules et encadré par des crochets
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		String separator = "";
		
		sb.append("[");
		for(E elt : this) {
			sb.append(separator);
			separator = ", ";
			sb.append(elt);
		}
		sb.append("]");

		return new String(sb);
	}
}