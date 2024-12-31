AUTOMAKE_OPTIONS = foreign

#
# Build a shared library "libcalovalid.la" containing CaloValid and CaloFittingQA
#
lib_LTLIBRARIES = \
    libcalovalid.la

#
# Add paths for linking
#
AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  -L$(OFFLINE_MAIN)/lib64

#
# Add include paths for headers
#
AM_CPPFLAGS = \
  -I$(includedir) \
  -isystem$(OFFLINE_MAIN)/include \
  -isystem$(ROOTSYS)/include

#
# Headers installed by this package
#
pkginclude_HEADERS = \
  CaloValid.h \
  CaloFittingQA.h

#
# Source files to be built into "libcalovalid.la"
#
libcalovalid_la_SOURCES = \
  CaloValid.cc \
  CaloFittingQA.cc

#
# Libraries we link against; NOTE the addition of -lcalotrigger here.
#
libcalovalid_la_LIBADD = \
  -lcalo_io \
  -lcalotrigger \
  -lCLHEP \
  -lfun4all \
  -lglobalvertex_io \
  -lmbd_io \
  -lzdcinfo_io \
  -lphool \
  -lSubsysReco \
  -lffarawobjects \
  -lffamodules \
  -lcdbobjects \
  -lqautils

################################################
# Linking a simple test executable named 'testexternals'
# that exercises the newly built library
################################################

noinst_PROGRAMS = \
  testexternals

testexternals_SOURCES = testexternals.C
testexternals_LDADD = libcalovalid.la

# Generate a trivial testexternals.C at build time
testexternals.C:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

################################################
# Example rule for generating a dictionary with rootcint (if needed)
################################################
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

clean-local:
	rm -f $(BUILT_SOURCES)

