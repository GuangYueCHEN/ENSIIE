package ensembles;

/**
 * Ensemble trié utilisant une {@link EnsembleVector}
 *
 * @author kevincocchi
 */
public class EnsembleTriVector2<E extends Comparable<E>> extends
	EnsembleTriGenerique<E> implements EnsembleTri<E> {
	/**
	 * Constructeur par défaut d'un ensemble trié utilisant un {@link EnsembleVector}
	 */
	public EnsembleTriVector2() {
		ensemble = new EnsembleVector<E>();
	}

	/**
	 * Constructeur de copie à partir d'un autre iterable
	 * @param elements l'itérable dont on veut copier les éléments
	 */
	public EnsembleTriVector2(Iterable<E> elements) {
		ensemble = new EnsembleVector<E>();
		for(E elt : elements)
			ajout(elt);
	}

	/**
	 * Insertion d'un nouvel élément au rang choisi en utilisant
	 * {@link #rang(E element)} pour calculer le rang d'insertion de l'élément
	 *
	 * @param element l'élément à insérer
	 * @param rang le rang où insérer cet élément
	 * @return true si l'élément a été inséré au rang choisi, false si l'élement
	 *         n'a pas pu être inséré à cause d'un rang invalide
	 * @note On remarquera que la méthode ne teste pas au préalable l'existence
	 *       de l'élément à insérer dans l'ensemble car c'est la méthode
	 *       {@link #ajout(E)} qui s'en chargera
	 */
	@Override
	protected boolean insererAuRang(E element, int rang) {
		if(rang < 0 || rang > cardinal())
			return false;
		
		((EnsembleVector<E>) ensemble).vecteur.insertElementAt(element, rang);
		return true;
	}
}
