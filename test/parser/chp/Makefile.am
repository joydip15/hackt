# "test/parser/chp/Makefile.am"
#	$Id: Makefile.am,v 1.31 2011/02/25 23:19:39 fang Exp $

include $(top_srcdir)/test/Make.test-head

HACO_FLAGS += -f case-collision=ignore

HACKT_PARSE_TEST_FAILURES = \
	001 004 006 007 008 009 \
	010 011 012 013 014 016 018 019b \
	023 \
	030 031 035 037 038 \
	046 047 048 \
	050 051 055 056 059 \
	061b 062 067 068 \
	071 072 073 076 \
	095 096 \
	107 \
	119 \
	120 124 \
	131 132 133 \
	wrong-source \
	wrong-sink wrong-sink-02 \
	dataless-02 dataless-04 dataless-05 \
	bad-selection-01 \
	send-array-01 receive-array-01 probe-array-01

# deprecated, no longer relevant:
#	log-01

# TODO: add support for null lvalues in channel receive fields
# affects: dataless-02

# TODO: 133.hac -- nonmeta-member references yet unsupported

HACKT_PARSE_TEST_PASSES = \
	000 002 003 005 \
	015 017 019 \
	020 021 022 024 025 026 027 028 029 \
	032 033 034 036 039 \
	040 041 042 043 044 045 049 \
	052 053 054 057 058 \
	060 061 063 064 065 066 069 \
	070 074 075 077 078 079 \
	080 081 082 083 084 085 086 087 088 089 \
	090 091 092 093 094 097 098 099 \
	100 102 104 105 106 108 109 \
	110 111 112 113 114 115 116 117 118 \
	121 122 123 125 126 127 128 129 \
	130 \
	top-level-01 top-level-02 top-level-03 \
	bool-source bool-sink bool-sink-alt \
	source-sink-01 \
	source-sink-02 \
	bool-source-delay \
	source-sink-delay-01 \
	dataless-01 dataless-03 \
	string-01 string-02 string-03 \
	buf-01 buf-02 buf-03 buf-03b buf-04 \
	ACX-PR-6885

HACKT_PARSE_TEST_WARNINGS = \
	101 103

HACKT_CREATE_TEST_PASSES = \
	003 \
	064 \
	074 075 077 078 079 \
	080 081 082 083 084 085 086 087 088 089 \
	090 091 092 093 094 097 098 099 \
	100 101 102 103 104 105 106 108 109 \
	110 111 112 113 114 115 116 117 118 \
	123 125 126 127 128 129 130 \
	top-level-01 top-level-02 top-level-03 \
	bool-source bool-sink \
	source-sink-01 \
	source-sink-02 \
	bool-source-delay \
	source-sink-delay-01 \
	dataless-01 dataless-03 \
	string-01 string-02 string-03 \
	buf-01 buf-02 buf-03 buf-03b buf-04 \
	ACX-PR-6885

# TODO:
# 091 094: diagnostic improvement -- 
# print template arguments for definition qualifiers

HACKT_CREATE_TEST_FAILURES = \
	121 122

# TODO: alloc phase
# several tests are not ready because we haven't defined
# footprint frames for built-in channel types yet.  
# They result in an assertion failure on the frame pointer.  
HACKT_ALLOC_TEST_PASSES = $(HACKT_CREATE_TEST_PASSES)

# eventually update to use ALLOC_TEST_PASSES
HACKT_CHPSIM_ALLOC_TEST_SUBJECTS = $(HACKT_ALLOC_TEST_PASSES)

HACKT_CHPSIMRC_TEST_SCRIPTS_PASSES = \
	064-a \
	075-a \
	080-a 083-a 086-a 087-a \
	097-a 098-a 099-a \
	104-a \
	114-a 116-a 117-a 118-a \
	126 127 128 129 \
	dataless-01-a \
	source-sink-delay-01-a \
	top-level-02-a

# more output expectation files for when bison is used
BISON_OUTPUTS += 001 004 019b \
	035 055 056 059 062 107

srcdir_EXTRA_DIST += log-01.hac

include $(top_srcdir)/test/Make.test-tail

