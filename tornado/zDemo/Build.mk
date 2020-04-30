#
#       Copyright(c) 97-98 FRIDU a Free Software Company (Fulup Le Foll)
#
# File      :   Build.mk Force install and non compling of Test Routines
# Projet    :   jWrap
# Module    :   Test
# Auteur    :   Fulup Le Foll (Fulup@iu-vannes.fr)
#
# Last
#      Author      : $Author: Fulup $
#      Date        : $Date: 1999/03/11 12:49:31 $
#      Revision    : $Revision: 1.3.0.1 $
#      Source      : $Source: /Master/jWrap/tornado/zDemo/Build.mk,v $
#      State       : $State: Exp $
#
#Modification History
#--------------------
#01a,10mar99,Fulup written from jIc 
#

install::
	@echo installing Test/Demos routines in $(INSTALL_DIR)
	mkdir -p $(INSTALL_DIR)/examples/$(MODULE)
	clean.sh
	tar -cf - . | (cd $(INSTALL_DIR)/examples/$(MODULE); tar -xf -)

install::
	@echo force install easyc.h
	mkdir -p $(RUNTIME_INCDIR)
	cp -r $(TOP)/Common/Config/Include/* $(RUNTIME_INCDIR)

# do not install subdirs
# ----------------------
NOT_INSTALL=1
