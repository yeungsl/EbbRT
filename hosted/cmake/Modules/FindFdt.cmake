find_package(PkgConfig)
pkg_check_modules(PC_LIBFDT QUIET libfdt)
set(LIBFDT_DEFINITIONS ${PC_LIBFDT_CFLAGS_OTHER})

find_path(LIBFDT_INCLUDE_DIR fdt.h
  HINTS ${PC_LIBFDT_INCLUDEDIR} ${PC_LIBFDT_INCLUDE_DIRS})

find_library(LIBFDT_LIBRARY NAMES fdt
  HINTS ${PC_LIBFDT_LIBDIR} ${PC_LIBFDT_LIBRARY_DIRS})

set(LIBFDT_LIBRARIES ${LIBFDT_LIBRARY})
set(LIBFDT_INCLUDE_DIRS ${LIBFDT_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibFdt DEFAULT_MSG
  LIBFDT_LIBRARY LIBFDT_INCLUDE_DIR)

mark_as_advanced(LIBFDT_INCLUDE_DIR LIBFDT_LIBRARY)
if (NOT LIBFDT_FOUND)
if (Fdt_FIND_REQUIRED)
message(FATAL_ERROR )
endif (Fdt_FIND_REQUIRED)
endif (NOT LIBFDT_FOUND)