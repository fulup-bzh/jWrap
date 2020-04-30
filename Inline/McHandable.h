/***************************************************************
 *     $Id: McHandable.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *     $Log: McHandable.h,v $
 *     Revision 1.3.0.1  1999/03/11 12:49:29  Fulup
 *     First Running version
 *
 *     Revision 1.3.0.1  1999/03/11 12:08:21  Fulup
 *     First Running version
 *
 *     Revision 1.3.0.1  1999/03/10 19:45:11  Fulup
 *     First TornadoSh Alpha
 *
 *     Revision 1.1.1.1  1999/02/17 13:20:59  Fulup
 *     new standalone version
 *
 *     Revision 3.0.3.1  1998/06/08 08:26:36  Fulup
 *     First WTX version
 *
 *     Revision 3.0.3.1  1998/06/02 14:22:30  Fulup
 *     frist W05 version
 *
 *     Revision 3.0.3.1  1998/06/02 13:37:59  Fulup
 *     First W95 version
 *
 *     Revision 3.0.3.1  1998/05/30 11:33:30  Fulup
 *     First W95 working version
 *
 *     Revision 3.0.2.1  1998/03/19 21:39:50  Fulup
 *     New 3.0.2 tree
 *
 *     Revision 1.1.1.1  1998/03/03 22:37:44  Fulup
 *     first jWrap working version
 *
 *     Revision 1.1  1998/03/03 22:49:28  Fulup
 *     first jWrap working version
 *
 *     Revision 3.0  1997/02/04 17:48:56  bzfzoeck
 *     released Version 3.0
 *
 *     Revision 1.3  1996/12/16 10:44:49  bzfzoeck
 *     now really
 *
 * Revision 1.1  1996/06/25  08:53:32  bzfzoeck
 * .
 *
 * Revision 1.2  1996/06/07  15:05:43  bzfzoeck
 * Smart pointers are implemented.
 *
 * Revision 1.1.1.1  1996/06/05  15:33:18  bzfstall
 * McLib initial repository
 *
****************************************************************/
#ifndef MC_HANDABLE_H
#define MC_HANDABLE_H

#include <assert.h>
#include <stdio.h>


/// Base class for ref-counted objects.
class McHandable
{
  protected:

    /// Destructor is protected. Use unref() instead.
    virtual ~McHandable() { 
      assert(refcount==0);
    }

    /// Reference count.
    int refcount;

  public:
    /// Constructor.
    McHandable() : refcount(0) { }

    /// Adds a reference to an instance.
    void ref() {
	//printf("Ref\n");
	refcount++;
    }

    /*/ Removes a reference from an instance. Calls delete this, if
      this was the last ref.*/
    void unref() {
	//printf("unref\n");
	assert(refcount>0);
	if (--refcount==0)
	    delete this;
    }

    /// Removes a reference but doesn't destroy object.
    void unrefNoDelete() {
	assert(refcount>0);
	--refcount;
    }


};

#endif
