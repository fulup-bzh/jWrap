# Small example to show javadoc extraction
#
#Modification History
#--------------------
#011,20feb98,Fulup written from jIc
#

# Where to find jWrap
# -------------------
  override PATH:=../../bin:$(TOP)/Fridu/Exe/$(ARCH_OS)/bin:$(PATH)

all:: doc
clean:
	@echo "cleaning java & html file"
	rm -f *.java *.html
	rm images

doc: httpdTcp_global.java ContainerCore_global.java structure_global.java
	@echo Building Html files with Javadoc [ignoring errors]
	javadoc *.java >/dev/null || exit 0
	ln -fs $(JAVA_HOME)/docs/api/images .
	@echo Doc Done 

httpdTcp_global.java:  httpdTcp.jTcl 
	@echo Generating Java equivalent doc from $<
	jWrap --javadoc --outdir=.  --verbose $<


ContainerCore_global.java: ContainerCore.h
	@echo Generating Java equivalent doc from $<   
	jWrap --javadoc --outdir=.  --verbose $<

structure_global.java: structure.h
	@echo Generating Java equivalent doc from $<   
	jWrap --javadoc --outdir=.  --verbose $<
