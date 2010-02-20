AC_INIT(skeleton, 0.1)

AM_INIT_AUTOMAKE

AC_PROG_LIBTOOL
AC_PROG_CC

AM_CONFIG_HEADER(config.h)

PKG_CHECK_MODULES(SKELETON, [gtk+-2.0 > 2.0 ])

PKG_CHECK_MODULES(HILDON, [ hildon-1 ], have_hildon=yes, have_hildon=no)

AM_CONDITIONAL(HAVE_HILDON, test "x$have_hildon" = "xyes")

if test "$have_hildon" = "yes"; then
	AC_DEFINE(HAVE_HILDON, 1, [ Have Maemo platform ])
fi

AC_SUBST(SKELETON_CFLAGS)
AC_SUBST(SKELETON_LIBS)

AC_OUTPUT([
	Makefile
	src/Makefile
])

