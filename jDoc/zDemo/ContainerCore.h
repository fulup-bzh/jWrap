#ifndef CONTAINERH
#define CONTAINERH

#assert interface (ContainerCore)

#include <easyc.h>

#include "ComponentCore.h"
#include "Layout.h"

/**
 * A ContainerCore component
 * <p>
 * In a container, you can add
 * and remove component
 *
 * @author korry
 * @version 1.03, 4 Mar 1998
 * @see object.ContainerCore
 * @since jTix1.0
 */

class ContainerCore:	public ComponentCore,
			public Layout
{
	public:

	/* Property */

	/** The number of son for the container */
	int nbSon;

	/** The son's reference in an array */
	ComponentCore *son[16];

	/* Method */

	/**	The getSon method, look in the container for the son (component)
			which matches the point in parameter (x,y) 
			In somecase, the component will be not lookup if:
			- it is not visible
			- it is not enable
			@param the x value to look at
			@param the y value to look at
			@return the component which match
			with the coordonates or NULL it no match is found
	*/
	ComponentCore *getSon(int x,int y);

	/**	The getSonIndice method, look in the container for the son (component)
			which matches the adress in parameter (x,y) and return it indice
			@param the component for match
			@return the found indice
			or -1 it no match is found
	*/
	int getSonIndice(ComponentCore* cc);

	/**	The drawSonObject method 
			Call each son with son::draw() method
			@return the result of draw SUCCES if ok, FAILED else
	*/
	int drawSonObject();

	/**	The draw method 
			Draw first the container, and after
			all its sons
	*/
	virtual void draw();

	/**	The method for add a son in the container
			@param the component to add
			@return the result of add SUCCES if ok, FAILED else
	*/
	int add(ComponentCore *comp);

	/**	The method for remove a son in the container
			@param the component to remove
			@return the result of remove SUCCES if ok, FAILED else
	*/
	int remove(ComponentCore *comp);

	/**	The constructor of ContainerCore 
			The number of son is set to 0
	*/
	ContainerCore();

	/**	The destructor of ContainerCore
			@param none
	*/
	virtual ~ContainerCore(){}
};
#endif // CONTAINERH
