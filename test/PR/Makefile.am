# "test/prsim/Makefile.am"
#	$Id: Makefile.am,v 1.2 2011/05/03 19:21:54 fang Exp $
# Test auto-Makefile for prsim.  

include $(top_srcdir)/test/Make.test-head

# SUBDIRS = .

HACKT_IPPLERC_TEST_SCRIPTS_PASSES = \
	001 002 003 003b 004 004b 004c 005 005b 005c 006 006b 007 008 008b 009 \
	010 011 012 013 014 015 015b 016 016b 017 017a 017b 017c 017d 017e \
	018 018a 018b 019 019a 019b 019c 019d 019e 019f 019g 019h \
	020

# random tests have non-zero temperature for randomness
if RANDOM_TESTS
else
006.ipltest: 006.iplrc
	$(SKIP_TEST_SCRIPT)
006b.ipltest: 006b.iplrc
	$(SKIP_TEST_SCRIPT)
020.ipltest: 020.iplrc
	$(SKIP_TEST_SCRIPT)
endif

# also any tests that use the 'scatter' function as a random seed belong here
# these override the default suffix rules
if RANDOM_TESTS
else
011.ipltest: 011.iplrc
	$(SKIP_TEST_SCRIPT)
012.ipltest: 012.iplrc
	$(SKIP_TEST_SCRIPT)
013.ipltest: 013.iplrc
	$(SKIP_TEST_SCRIPT)
014.ipltest: 014.iplrc
	$(SKIP_TEST_SCRIPT)
015.ipltest: 015.iplrc
	$(SKIP_TEST_SCRIPT)
015b.ipltest: 015b.iplrc
	$(SKIP_TEST_SCRIPT)
016.ipltest: 016.iplrc
	$(SKIP_TEST_SCRIPT)
016b.ipltest: 016b.iplrc
	$(SKIP_TEST_SCRIPT)
endif

HACKT_IPPLE_CKPT_TEST_SCRIPTS_BASES = $(HACKT_IPPLERC_TEST_SCRIPTS_PASSES)

include $(top_srcdir)/test/Make.test-tail

