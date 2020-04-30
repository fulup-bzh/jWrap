#       Copyright(c) 96-99 FRIDU a Free Software Company (Fulup Le Foll)
#
# File      :   Build.mk
# Projet    :   jWrap
# SubModule :   WTX VxWorks Tornado interface
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:30 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/backend/Build.mk,v $
#
#Modification History 
#--------------------
#01c,16feb99,Fulup,remanced modulefrom WPR to Tornado
#01b,18apr98,Fulup moved to new tree
#01a,06feb98,Fulup written
#

# Only compile this directory if tornado is defined
# -------------------------------------------------
ifdef TORNADO_BASE

# Do not install in production tree
# ---------------------------------
  NOT_INSTALL=1

# Define init modules
# ------------------------
  LIB_SRCXXS = functionBackendCc2Tornado.cxx programBackendCc2Tornado.cxx \
               typeBackendCc2Tornado.cxx     miscBackendCc2Tornado.cxx
  LIB_OBJS = $(LIB_SRCXXS:%.cxx=${OBJDIR}/%${OBJ_SFX})

  SRCXXS    = ${LIB_SRCXXS}

# define meta rules
# ------------------
  LIBS    :=  libBackendCc2Tornado

# define some extra option for TK
# --------------------------------
  MK_DEFINES  = 
  MK_INCLUDES =  

# set proto if any .i changed
# ----------------------------------------
${INCDIR}/libBackendCc2Tornado.i: $(LIB_SRCXXS:%.cxx=${DEPDIR}/%.i) 
	${protoRule} 

# Set library & subLib name and give source depending files
# ----------------------------------------------------------
${LIBDIR}/libBackendCc2Tornado${LIB_SFX}: ${LIB_OBJS}
	${libRule}

endif
