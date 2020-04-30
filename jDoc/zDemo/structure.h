#assert implement(strutureDemo)


/**-------------------------------
 * This is program main doc
 */


/** doc for toto */
#define toto 1

/** doc for titi */
#define titi 1

/**-------------------------
 *  This is a Structure docc
 */
 struct totoStr {
   /** This is element doc */
   int a;

   /**  this next element doc */
   int b;
 };

/** *********************
 *  This is a Union doc
 */
 union totoUnion {
   /** This is element doc a */
   int a;

   /**  this next element doc b */
   int b;
 };

/**
 *  This is a Union doc
 */
 enum totoEnum {
   /** This is element doc a */
   a = 0,

   /**  this next element doc b */
   b,

   /**  this next element doc c*/
   c,

   /**this next element doc d */
   e,

   /**  this next element doc e */
   f
 };

