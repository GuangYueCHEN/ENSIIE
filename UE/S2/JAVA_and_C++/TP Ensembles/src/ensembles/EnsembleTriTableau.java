package ensembles;

import java.util.Collection;
import java.util.Iterator;

import tableaux.Tableau;


public class EnsembleTriTableau<E extends Comparable<E>> extends
		EnsembleTableau<E> implements EnsembleTri<E>
{

	/**
	 * Constructeur par défaut d'un ensemble trié utilisant un {@link Tableau}
	 */
	public EnsembleTriTableau()
	{
		tableau=new Tableau<E>();
	}

	/**
	 * Constructeur de copie à partir d'un autre iterable
	 * @param elements l'itérable dont on veut copier les éléments
	 */
	public EnsembleTriTableau(Iterable<E> elements)
	{
		this();
		for(E elt:elements) {
			this.ajout(elt);
		}
	}

	/**
	 * Ajout d'un élément de manière triée dans l'ensemble utilisant un
	 * {@link Tableau}
	 * @param element l'élément à ajouter de manière triée (on considèrera que
	 * l'on ne peut pas ajouter d'élément null)
	 * @return true si l'élément n'était pas déjà présent dans l'ensemble, false
	 * sinon ou si l'on a tenté d'insérer un élément null (auquel cas il
	 * n'est pas inséré).
	 * @see ensembles.EnsembleTableau#ajout(java.lang.Object)
	 * @see tableaux.Tableau#insertElement(E, int)
	 */
	@Override
	public boolean ajout(E element)
	{
		if (element==null||this.contient(element))
			return false;
		
			tableau.insertElement(element,rang(element));
			return true;

	}

	/**
	 * Test d'égalité d'un ensemble trié. Il est nécessaire de réimplémenter la
	 * comparaison avec un autre ensemble car l'ordre des élément aura son
	 * importance dans la comparaison ce qui n'était pas le cas avec les
	 * ensembles non triés.
	 * @return true si l'objet obj est aussi un ensemble (pas forcément trié) et
	 * qu'il contient exactement les mêmes éléments dans le même ordre.
	 * @see ensembles.EnsembleGenerique#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj)
	{
		/*
		 * TODO Remplacer par ...
		 * 	1 - obj == null ? ==> false
		 * 	2 - obj == this ? ==> true
		 * 	3 - obj est une instance de Ensemble<?>
		 * 		- caster obj en Ensemble<?>
		 * 		- si obj et this ont exactement les mêmes éléments dans le
		 * 		  même ordre ==> true
		 * 		- sinon ==> false;
		 * 	  - sinon (obj n'est pas un Ensembble<?>) ==> false
		 */
		if(obj == null)
			return false;
		if(obj == this)
			return true;
		if(!(obj instanceof Ensemble<?>))
			return false;
		
		Ensemble<?> ob = (Ensemble<?>) obj;
		
		Iterator<E> it = iterator();
		Iterator<?> it_o = ob.iterator();

		while(it.hasNext()) {
			if(!it_o.hasNext())
				return false;
			if(!it.next().equals(it_o.next()))
				return false;
		}
			
		if(it_o.hasNext())
			return false;
		return true;

	}

	/**
	 * Code de hachage d'un ensemble trié. Il est nécessaire de réimplémenter le
	 * code de hachage pour les ensembles triés car on considèrera que deux
	 * ensembles contenant les même éléments mais dans des ordres différents
	 * seront eux-même différents. Il faut donc que la méthode hashCode prenne
	 * en compte l'ordre des éléments (Comme dans les autres {@link Collection}
	 * d'ailleurs).
	 * @return le code de hachage de cet ensemble trié.
	 * @see tableaux.Tableau#hashCode() pour un exemple de hashage utilisant
	 * l'ordre des éléments
	 * @see ensembles.EnsembleGenerique#hashCode()
	 */
	@Override
	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
	
		Iterator<E> it = this.iterator();
	
		
		while(it.hasNext())
			result = prime*result+it.next().hashCode();
		return result;
	}
}
