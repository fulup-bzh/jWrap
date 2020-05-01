#  $Header: /Master/jWrap/readline/Etc/Module.mk,v 1.4 1999/03/19 17:57:10 Fulup Exp $
#
#	Copyright(c) 97 Fridu a Free Software Company
#
# File      :   module.mk, project global definition
# Projet    : 	jTcl
# SubModule :   readline
# Auteur    :   Fulup Ar Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/19 17:57:10 $
#      Revision    : $Revision: 1.4 $
#      Source      : $Source: /Master/jWrap/readline/Etc/Module.mk,v $
#      State       : $State: Exp $
#
# Modification History
# --------------------
# 01a,19oct97, Fulup written in order supporting modules
#
  MOD_VERSION   := readline-008
  MOD_INCLUDES  :=
  MOD_DEFINES   := -DTCLREADLINE_VERSION=\"$(MOD_VERSION)\"
