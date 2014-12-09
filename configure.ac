#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([CppSTLStudy], [0.0.0.0], [cbpark@gmail.com])
AC_CONFIG_SRCDIR([src/Makefile.am])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config/config.h])
AC_CONFIG_MACRO_DIR([m4])
# m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CXX([clang++ llvm-g++ g++])
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11(noext,mandatory)
AC_PROG_INSTALL
AM_PROG_AR
LT_INIT

# Adds flags for clang.
if test "$CXX" = "clang++"; then
   CXXFLAGS="${CXXFLAGS} -stdlib=libc++"
   LDFLAGS="${LDFLAGS} -stdlib=libc++"
fi

# Checks for header files.
AC_CHECK_HEADERS([algorithm complex functional iterator memory numeric string tuple vector])

# Checks for libraries.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/lang/Makefile
                 src/util/Makefile
                 src/stl/Makefile])
AC_OUTPUT
