/* ********************************************************************
   | 
   |  Basic example show how to generate a proto from a C/C++ source
   |
   |  WARNING: This file does not compile it only test C/C++ frontend
   |
   ********************************************************************/

#assert interface (demoType)

// Check aliasing mecanism
typedef unsigned char   int8u;  /* unsigned integer 8 bits      */
typedef unsigned int    int16u; /* unsigned integer 16 bits     */
typedef unsigned long   int32u; /* unsigned integer 32 bits     */
typedef char 	 	int8s;  /* signed integer 8 bits        */
typedef int     	int16s; /* signed integer 16 bits       */
typedef long   		int32s; /* signed integer 32 bits       */
typedef struct _wtx_exchange * WTX_XID;

// Check structure
struct toto {
 int a;
 int b;
};

// type def
typedef	struct	{
	int16u	MsgForm;
	char	*add_info_ptr;
} MESG_HEADER;


// check union
typedef	struct	{
	int16u	MsgForm;
	union Ptr_or_Data
		{
		int8u		*Buffer;
		int16u		Data[2];
		}BD;
	int16u	Free_Buffer;
} MESG_HEADER2;

// typedef enum
typedef enum {
	Q931,
	TELEVERKET,
	TELENOKIA,
	UNKNOWN_PID = 0xFF	/* RL */
} toto;

// type with array 
typedef struct  {
	t_info_trans_capability	code;
	int	used;
	int	lg;
	t_byte	value[16];
} t_bc;
