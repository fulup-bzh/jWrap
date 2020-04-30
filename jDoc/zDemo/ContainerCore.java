
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: -
 *   Date: Thu May 14 23:09:35 1998

 *   jWrap --javadoc ContainerCore.java

 *   Except if you really know what you are doing you should
 *   not edit this file by hand.
 *
 *   In order rebuilding it use jWrap
 + ------------------------------------------------------------ */
package jWrap.ContainerCore;

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

public class ContainerCore 
 extends ComponentCore 
 implements Layout 
  {
  // Vars sub-section

  // Methods sub-section

  // Vars sub-section

/**  The number of son for the container */
 private  int nbSon;

/**  The son's reference in an array */
 private  ComponentCore_Ptr son;

  // Methods sub-section

/** 	The getSon method, look in the container for the son (component)
	which matches the point in parameter (x,y) 
	In somecase, the component will be not lookup if:
	- it is not visible
	- it is not enable
	@param the x value to look at
	@param the y value to look at
	@return the component which match
	with the coordonates or NULL it no match is found
	*/
 private  ComponentCore_Ptr getSon (int x, int y) {};

/** 	The getSonIndice method, look in the container for the son (component)
	which matches the adress in parameter (x,y) and return it indice
	@param the component for match
	@return the found indice
	or -1 it no match is found
	*/
 private  int getSonIndice (ComponentCore_Ptr cc) {};

/** 	The drawSonObject method 
	Call each son with son::draw() method
	@return the result of draw SUCCES if ok, FAILED else
	*/
 private  int drawSonObject () {};

/** 	The draw method 
	Draw first the container, and after
	all its sons
	*/
 private  void draw () {};

/** 	The method for add a son in the container
	@param the component to add
	@return the result of add SUCCES if ok, FAILED else
	*/
 private  int add (ComponentCore_Ptr comp) {};

/** 	The method for remove a son in the container
	@param the component to remove
	@return the result of remove SUCCES if ok, FAILED else
	*/
 private  int remove (ComponentCore_Ptr comp) {};

/** 	The constructor of ContainerCore 
	The number of son is set to 0
	*/
 private   ContainerCore () {};

/** 	The destructor of ContainerCore
	@param none
	*/
 private finalize   ContainerCore () {};

  // Vars sub-section

  // Methods sub-section
}