#
#       Copyright(c) 97-99 FRIDU a Free Software Company (Fulup Le Foll)
#
# File      :   Build.mk Force install and non compling of Test Routines
# Projet    :   jWrap
# Module    :   Wrs ressource file
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/from-wrs/Resource/Build.mk,v $
#
#Modification History
#--------------------
#01a,10mar99,Fulup written
#

install::
	@echo installing Wrs/Ressource routines in $(RUNTIME_TCLDIR)
	mkdir -p $(RUNTIME_TCLDIR)
	cp -f *.tcl $(RUNTIME_TCLDIR)

# do not install subdirs
# ----------------------
NOT_INSTALL=1
