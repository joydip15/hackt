# "test/net/Makefile.am"
#	$Id: Makefile.am,v 1.1.2.10 2009/08/15 01:52:41 fang Exp $
# Test auto-Makefile for hacknet.  

include $(top_srcdir)/test/Make.test-head

# SUBDIRS =

# .hac inputs
HACKNET_TEST_SCRIPTS_PASSES = \
	inv-00 inv-01 inv-02 inv-03 inv-04 inv-05 inv-06 inv-07 \
	inv-08 inv-09 inv-10 inv-11 inv-12 \
	nand-01 nand-02 nand-03 \
	celem-01 celem-02 celem-03 celem-04 celem-05 celem-06 \
	port-alias-01 port-alias-02 port-alias-03 port-alias-04 port-alias-05 \
	unused-port-01 \
	unconnected-01 unconnected-02 \
	internal-00 internal-05 internal-06 internal-07 internal-08
# TODO: promote these to real tests
EXTRA_DIST_HAC = \
	subckt-01 subckt-02 \
	internal-01 internal-02 internal-03 internal-04 \
	non-CMOS-01 non-CMOS-02 non-CMOS-03 \
	process-port-01 process-port-02
# internal-01..04 need subcircuits first

EXTRA_DIST += $(EXTRA_DIST_HAC:=.hac)

HACKT_PARSE_TEST_PASSES =

HACKTNET_TEST_SCRIPTS_PASSES =

CLEANFILES +=
AUTO_IGNORE +=
EXTRA_DIST +=

HACKT_CREATE_TEST_PASSES =
HACKT_CREATE_TEST_FAILURES =
HACKT_CFLAT_TEST_SUBJECTS =

HACKNET_TEST_SCRIPTS_FAILURES =

srcdir_EXTRA_DIST +=

include $(top_srcdir)/test/Make.test-tail
