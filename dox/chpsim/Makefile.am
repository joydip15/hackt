# "dox/chpsim/Makefile.am"
#	$Id: Makefile.am,v 1.21 2010/04/02 22:17:25 fang Exp $

include $(top_srcdir)/dox/Make.dox-head

PDFS = hacchpsim.pdf
DVIS = $(PDFS:.pdf=.dvi)
PSS = $(PDFS:.pdf=.ps)
.NOTPARALLEL: hacchpsim.dvi hacchpsim.pdf

################### texinfo documentation #####################################

info_TEXINFOS += hacchpsim.texi
INFOS = $(TEXINFOS:.texi=.info)

AM_MAKEINFOFLAGS = -I$(srcdir)/../common -I../common
hacmacros.texi: $(srcdir)/../common/hacmacros.texi
	$(LN_SF) $< $@

CLEANFILES += hacmacros.texi

# install doesn't know how to handle generated html *directory* :(
# html_DATA = hacchpsim.html
HTML_HOOKS += hacchpsim.html

hacchpsim_INCLUDES = \
	hacmacros.texi \
	intro.texi \
	usage.texi \
	tutorial.texi \
	commands.texi \
	extending.texi \
	execution.texi \
	stdchpfn.texi

# HACCHPSIM_OPTIONS_TEXI = ...
# HACCHPSIM_COMMANDS_TEXI = ...
# HACCHPSIM_FUNCTIONS_TEXI = ...
# source-extracted texinfo files: (can we deduce this automatically? done.)
$(srcdir)/options.mk: usage.texi
	{ $(PRINTF) "HACCHPSIM_OPTIONS_TEXI = " ; \
	$(CAT) $< | $(EXTRACT_TEXI_INCLUDES) ; \
	$(ECHO) "" ; \
	$(ECHO) "" ;} > $@

$(srcdir)/commands.mk: commands.texi
	{ $(PRINTF) "HACCHPSIM_COMMANDS_TEXI = " ; \
	$(CAT) $< | $(EXTRACT_TEXI_INCLUDES) ; \
	$(ECHO) "" ; \
	$(ECHO) "" ;} > $@

$(srcdir)/functions.mk: stdchpfn.texi
	{ $(PRINTF) "HACCHPSIM_FUNCTIONS_TEXI = " ; \
	$(CAT) $< | $(EXTRACT_TEXI_INCLUDES) ; \
	$(ECHO) "" ; \
	$(ECHO) "" ;} > $@

# These are typically only built by the maintainer, since they are distributed.
# Don't depend on Makefile, because that is configure-generated,
# which would cause the following to be rebuilt by the user (not desired).
$(srcdir)/options.mk: Makefile.in
$(srcdir)/commands.mk: Makefile.in
$(srcdir)/functions.mk: Makefile.in

-include $(srcdir)/options.mk
-include $(srcdir)/commands.mk
-include $(srcdir)/functions.mk
AUTO_TEXINFO_DEPS += options.mk commands.mk functions.mk
# these could be CVS cleaned too...

# NOTE: these auto-generated .texi files are emitted in the maintainer's
# $(srcdir), however, they are distributed as part of $(srcdir).  
$(HACCHPSIM_OPTIONS_TEXI): $(top_srcdir)/src/main/chpsim.cc
	$(EXTRACT_TEXINFO_SRCDIR_BATCH_SCRIPT)
#	$(EXTRACT_TEXINFO) $<

$(HACCHPSIM_COMMANDS_TEXI): $(top_srcdir)/src/sim/chpsim/Command.cc
	$(EXTRACT_TEXINFO_SRCDIR_BATCH_SCRIPT)
#	$(EXTRACT_TEXINFO) $<

CHPFN_SRCDIR = $(top_srcdir)/lib/libchpfn
# should be synchronized with list of all sources files in lib/libchpfn/
STDCHPFN_SRCS = \
	$(CHPFN_SRCDIR)/assert.cc \
	$(CHPFN_SRCDIR)/bitmanip.cc \
	$(CHPFN_SRCDIR)/conditional.cc \
	$(CHPFN_SRCDIR)/io.cc \
	$(CHPFN_SRCDIR)/OS.cc \
	$(CHPFN_SRCDIR)/string.cc

# just re-generate all of them when any one changes...
# NOTE: this is a many-to-many dependence, which means that
# there are some false dependencies which may not be resolvable.
# If you find make keeps re-running texinfo programs, run "make clean-texi"
# once first to force-regenerate all dependent texis.  
$(HACCHPSIM_FUNCTIONS_TEXI): $(STDCHPFN_SRCS)
	$(EXTRACT_TEXINFO_SRCDIR_BATCH_SCRIPT)

auto_hacchpsim_info_DEPS = \
	$(HACCHPSIM_OPTIONS_TEXI) \
	$(HACCHPSIM_COMMANDS_TEXI) \
	$(HACCHPSIM_FUNCTIONS_TEXI)

hacchpsim_info_DEPS = \
	$(hacchpsim_INCLUDES) \
	$(auto_hacchpsim_info_DEPS)

# these auto-generated and distributed files should not be cleaned by the user
# they should only be explicitly cleaned by the maintainer.  
TEXI_CLEANFILES += $(auto_hacchpsim_info_DEPS)

# For a srcdir target like the .info to be distributed, 
# its dependencies are best distributed along with to keep 
# the user's build from trying to regenerate the .info.
# This can occur during a distcheck if auto-generated .texi dependencies
# are not shipped with the distribution.  
EXTRA_DIST += $(hacchpsim_info_DEPS)

# not bothering with more sophisticated dependency tracking
hacchpsim.dvi hacchpsim.pdf hacchpsim.html $(srcdir)/hacchpsim.info: \
	$(hacchpsim_info_DEPS)

# Q: do figures need to be installed?

# AM_MAKEINFOFLAGS =
# hack: since the options, fn, cmd directories are created during make dist,
# their time stamps will be newer than the files contained in those 
# directories, which will cause the user to unnecessarily rebuild 
# the dependent .info files.  Thus, we coercively touch the files
# in dependency order, to guarantee this doesn't occur.
# Unfortunately, not enough, because unpacking creates directories newer...
# We've permanently added the source dirs to remove dependencies on them.
# dist-hook:
# 	(cd $(distdir) && \
# 	for d in '$(BUILT_DIRS)' ; do \
# 	  $(TOUCH) $$d/*.texi ; \
# 	done && \
# 	test -z "$(INFOS)" || $(TOUCH) $(INFOS) \
# 	)

################# documentation figures #######################################
SOURCE_FIGS =
SOURCE_DOTS = \
	figs/chpsim_event_cycle.dot \
	figs/chpsim_event_algo.dot
BUILT_FIGS = $(SOURCE_DOTS:.dot=.fig)
XFIG_FIGURES = $(SOURCE_FIGS) $(BUILT_FIGS)
XFIG_TEX = $(XFIG_FIGURES:.fig=.figtex)
XFIG_PSTEX = $(XFIG_FIGURES:.fig=.ps)
XFIG_PSTEX_T = $(XFIG_FIGURES:.fig=.pstex_t)
XFIG_PDFTEX = $(XFIG_FIGURES:.fig=.pdf)
XFIG_PDFTEX_T = $(XFIG_FIGURES:.fig=.pdftex_t)
XFIG_EPS = $(XFIG_FIGURES:.fig=.eps)
XFIG_PNG = $(XFIG_FIGURES:.fig=.png)

all-figs: $(BUILT_FIGS)

# distribute to remove burden from user to build dox
EXTRA_DIST += $(XFIG_FIGURES) $(SOURCE_DOTS) $(XFIG_PNG) \
	$(XFIG_EPS) $(XFIG_PDFTEX)
# PNGs and built .figs too because distributed .info depends on them
# (don't want user to have to rebuild .info)

AUTO_IGNORE += \
	chpsim_event_cycle.fig \
	chpsim_event_algo.fig

CLEANFILES += $(BUILT_FIGS)

# COMMON_DEPS = $(srcdir)/../common/hac.bib $(XFIG_TEX)

# all-figs named so automake doesn't think we're overriding the targets' rule
# LIMITATION: choosing not to try to include the .pdftex_t for now
built-figs hacchpsim.dvi: $(XFIG_EPS)
built-figs hacchpsim.pdf hacchpsim.html: $(XFIG_PDFTEX)
built-figs hacchpsim.html: $(XFIG_PNG)
built-figs $(srcdir)/hacchpsim.info: $(XFIG_PNG)
# still not sure why html looks for .eps figures...

.PHONY: built-figs


$(srcdir)/figs/.cvsignore: $(srcdir)/.cvsignore
	$(CP) $< $@

$(srcdir)/cmd/.gitignore: $(srcdir)/cmd/.cvsignore
	$(GITIGNORE_TEXI_SCRIPT)
$(srcdir)/fn/.gitignore: $(srcdir)/fn/.cvsignore
	$(GITIGNORE_TEXI_SCRIPT)
$(srcdir)/options/.gitignore: $(srcdir)/options/.cvsignore
	$(GITIGNORE_TEXI_SCRIPT)

cvsignore-local: \
	$(srcdir)/cmd/.gitignore \
	$(srcdir)/fn/.gitignore \
	$(srcdir)/options/.gitignore

include $(top_srcdir)/dox/Make.dox-tail

