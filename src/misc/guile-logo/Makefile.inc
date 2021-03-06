# "misc/guile-logo/Makefile.inc"
#	$Id: Makefile.inc,v 1.6 2007/09/27 02:03:43 fang Exp $
#	vim: ft=automake
# play-testing guile functionality

GUILE_LOGO_DIR = misc/guile-logo

if WANT_LIBMISCFUN
if HAVE_LIBGUILE
if HAVE_X11
FUNPROGRAMS += misc/guile-logo/demo1 misc/guile-logo/guile-logo
FUNLIBS += misc/guile-logo/libtortoise.la \
	misc/guile-logo/libtortoise-guile.la
endif
endif
endif

misc_guile_logo_libtortoise_la_SOURCES = \
	misc/guile-logo/tortoise.cc \
	misc/guile-logo/tortoise.hh

GUILE_LOGO_CPPFLAGS = -I$(srcdir)/$(GUILE_LOGO_DIR)
# GUILE_WARN_FLAGS defined in util/Makefile.inc

misc_guile_logo_libtortoise_la_CPPFLAGS = \
	$(AM_CPPFLAGS) $(GUILE_LOGO_CPPFLAGS) $(X11_INCLUDE)
misc_guile_logo_libtortoise_la_CXXFLAGS = $(AM_CXXFLAGS) -Wno-old-style-cast
misc_guile_logo_libtortoise_la_LDFLAGS = $(X11_LDPATH)
misc_guile_logo_libtortoise_la_LIBADD = -lX11

misc_guile_logo_demo1_SOURCES = misc/guile-logo/demo1.cc
misc_guile_logo_demo1_CPPFLAGS = $(AM_CPPFLAGS) $(GUILE_LOGO_CPPFLAGS)
misc_guile_logo_demo1_LDADD = misc/guile-logo/libtortoise.la

misc_guile_logo_libtortoise_guile_la_SOURCES = \
	misc/guile-logo/tortoise-wrap.cc \
	misc/guile-logo/tortoise-wrap.hh

misc_guile_logo_libtortoise_guile_la_CPPFLAGS = \
	$(AM_CPPFLAGS) $(GUILE_LOGO_CPPFLAGS) $(GUILE_CPPFLAGS)
misc_guile_logo_libtortoise_guile_la_CXXFLAGS = \
	$(GUILE_WARN_FLAGS) -Wno-old-style-cast
misc_guile_logo_libtortoise_guile_la_LDFLAGS = $(GUILE_LDFLAGS)
misc_guile_logo_libtortoise_guile_la_LIBADD = \
	misc/guile-logo/libtortoise.la -lguile

misc_guile_logo_guile_logo_SOURCES = \
	misc/guile-logo/logo_main.cc

# NOTE: swig-wrapped sources are now deprecated
# yes, distribute this built-source too
# BUILT_SOURCES += misc/guile-logo/tortoise_wrap.cxx

misc_guile_logo_guile_logo_CPPFLAGS = \
	$(AM_CPPFLAGS) $(GUILE_LOGO_CPPFLAGS) $(GUILE_CPPFLAGS)
misc_guile_logo_guile_logo_CXXFLAGS = \
	$(misc_guile_logo_libtortoise_guile_la_CXXFLAGS)
#	$(AM_CXXFLAGS) -Wno-long-long -Wno-unused -Wno-error
# misc_guile_logo_guile_logo_LDFLAGS = $(GUILE_LDFLAGS)
misc_guile_logo_guile_logo_LDADD = misc/guile-logo/libtortoise-guile.la

# NOTE: using swig is deprecated, we now maintain wrappers by hand
# We don't distribute it, but nevertheless we leave it in CVS for history
# alternative is to distribute without requiring user to have SWIG
# misc/guile-logo/tortoise_wrap.cxx: misc/guile-logo/tortoise.swig
# if HAVE_SWIG
#	$(SWIG) -Wall -Werror -c++ -guile -scm -o $@ $<
# else
#	@$(ECHO) "No swig found in path, cannot regenerate $@" ; exit 1
# endif

if WANT_LIBMISCFUN
if HAVE_LIBGUILE
ALL_CXX_HEADER_FILES += \
	misc/guile-logo/tortoise.hh \
	misc/guile-logo/tortoise-wrap.hh
endif
endif

TORTOISE_WRAP_HCHK_FLAGS = \
	$(LIBGUILE_HCHK_FLAGS)
#	$(misc_guile_logo_libtortoise_guile_la_CPPFLAGS) \
#	$(misc_guile_logo_libtortoise_guile_la_CXXFLAGS)

# overriding default header check
misc/guile-logo/tortoise-wrap.hchk: misc/guile-logo/tortoise-wrap.h
	@$(ECHO) "Validating $< ... " ; \
	more_hchk_flags="$(TORTOISE_WRAP_HCHK_FLAGS)" ; \
	$(H_CHECK_TEST_SCRIPT)

EXTRA_DIST += misc/guile-logo/README \
	misc/guile-logo/hex-test.scm

#	misc/guile-logo/tortoise_wrap.cxx
#	misc/guile-logo/tortoise.swig

