CMakefile is an automatic build system for C/C++ based on
`make`. CMakefile is configurable by a PROJECT file. It is appropriate
for small to medium-sized C/C++ projects.

Features
--------
* Easy to use. In simple cases just copying the Makefile into your project directory suffices.
* Automatic detection of C, C++, Flex and Yacc/Bison sources based on
  file extensions.
* Automatic dependency generation.
* Automatic creation of executables based on the presence of the
  `main` function.
* Support for subdirectories.
* Support for library creation.
* Support for multiple user-defined build configurations (e.g. DEBUG,
  RELEASE).
* Configurable compiler, linker, flex and yacc executable names and
  flags.
* Configurable build and source directories.
* Extensible with arbitrary make rules read from `Makefile-include`.

Requirements
------------
* GNU make
* bash, grep, sed, find

Usage
-----

If all your sources are in a single directory, then the simplest way
to use CMakefile is to copy `Makefile` into your source
directory. Running `make` will then create executables for all files
containing definitions of `main`. If your project directory contains
the `src` subdirectory with all sources, then you can copy `Makefile`
into the project directory instead of into `src`.

Compiler flags, subdirectories, program sources, build directory and
more can be specified via project options (see below).

You can also add arbitrary make rules by putting them in
`Makefile-include`.

The [`examples/`](examples/) directory contains some examples.

Makefile targets
----------------
* `all`: Build all programs and libraries. This is the default target.
* `clean`: Remove all build files. Removes the build directory
  entirely if it is different from `.`.
* `depend`: Create the `*.d` dependency files.

Project options
---------------

The `PROJECT` file should contain project option declarations, each on
a separate line. The declarations have two forms.

1. Global declarations.
```
OPTION = VALUE
```
2. Configuration-local declarations.
```
CFG1 .. CFGn OPTION = VALUE
```

Prefixing an option with build configurations `CFG1 .. CFGn` indicates
that the declaration should be used only if the current build
configuration is one of `CFG1`,...,`CFGn`. The current build
configuration is specified by the `CONFIG` option.

For instance, the following declarations will set the `CFLAGS` option
to `-Wall -g -O0`.

```
CONFIG = DEBUG
DEBUG CFLAGS = -Wall -g -O0
RELEASE CFLAGS = -O2 -DNDEBUG
```

The idea is that the value of `CONFIG` may be easily changed affecting
multiple options at once. Typical values for `CONFIG` are `RELEASE`
and `DEBUG`, but any word can be used.

The project options may also be specified on the command line,
overriding the declarations in `PROJECT`. For example,
```
make CONFIG=DEBUG
```
sets the current build configuration to `DEBUG` overriding the
declaration of `CONFIG` in `PROJECT`.

All options are available for use as variables in `Makefile-include`.

Lines of `PROJECT` which begin with `#` are treated as comments. Note
that `#` must be the first character in the line for it to be treated
as a comment.

Aside of the `CONFIG` option which should have only one declaration,
there are two types of project options: concatenable and
replaceable. For concatenable options, when there exist both global
and local declarations of the option, their values are
concatenated. For replaceable options, the local declaration overrides
the global one.

### Concatenable options
* `PROGRAMS`: Program executables to create (paths relative to the
  source directory). Default: basenames without extension of source
  files containing definitions of `main`.
* `SUBDIRS`: Subdirectories of the source directory (`SRCDIR`)
  included in the search for sources. Default: empty.
* `RSUBDIRS`: Same as `SUBDIRS` but also recursively includes all
  subdirectories of the listed directories, the subdirectories of the
  subdirectories of the listed directories, and so on. Default: empty.
* `IGNORE`: Source files to ignore (paths are relative to the source
  directory). Default: empty.
* `CFLAGS`: C compiler flags. Default: empty.
* `CXXFLAGS`: C++ compiler flags. Default: empty.
* `CDEPFLAGS`: C flags for dependency generation. Default: `CFLAGS`.
* `CXXDEPFLAGS`: C++ flags for dependency generation. Default:
  `CXXFLAGS`.
* `YFLAGS`: Yacc flags. Default: `-d`.
* `LEXFLAGS`: Lex flags. Default: empty.
* `CCLDFLAGS`: C linker flags. Default: empty.
* `CXXLDFLAGS`: C++ linker flags. Default: empty.
* `LDFLAGS`: Linker flags common to C and C++ linkers. Default: empty.
* `LIBFLAGS`: Librarian flags. The flag `-o` must occur at the end of
  `LIBFLAGS` if `libtool` is used. For `ar` compatibility, `-o` is not
  added automatically. Default: `-static -o`.

### Replaceable options
* `SRCDIR`: Source directory. Default: `src` if it exists, current
  directory otherwise.
* `BUILDDIR`: Build directory. Default: `_build`. Warning: if
  different from `.` then the build directory is entirely removed by
  `make clean`.
* `LIB`: Library to create. Default: empty.
* `CC`: C compiler executable. Default: `gcc`.
* `CXX`: C++ compiler executable. Default: `g++`.
* `YACC`: Yacc executable. Default: `bison`.
* `LEX`: Lex executable. Default: `flex`.
* `CCLD`: C linker. Default: `CC` if there are no C++ sources, `CXX`
  otherwise.
* `CXXLD`: C++ linker. Default: `CXX`.
* `LIBTOOL`: Librarian. Default: `libtool`.

Limitations
-----------
* Source files must have recognised extensions: .c, .cpp, .cxx, .cc,
  .lex, .y.
* File names cannot contain whitespace.
* Detection of the `main` function is very crude - it is based on
  matching the regular expression `\bint[ \t]+main\b`. This may give a
  false positive if anything in your sources that is not a definition
  of `main` matches, or a false negative when, e.g., you have a
  newline between `int` and `main`.

Copyright and license
---------------------

Copyright (C) 2008-2022 by Lukasz Czajka.

Distributed under the MIT license. See [LICENSE](LICENSE).
