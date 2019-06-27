cmake_minimum_required (VERSION 2.6)
project (Tutorial)

#define version code
set (PROJECT_NAME \"Tutorial\")
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

#make library optional
option (USE_MYMATH "Use Tutorial provided math implementation" ON)

#check function exist
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)
#test have
check_function_exists (wangs HAVE_TEST_WANG)

#pass some settings to source code by configure a header file
#this header file(.h) are produced by configure file(.h.conf)
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.conf"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

#add the binary tree to the search path for include files
#so can find Tutorial.h
include_directories("${PROJECT_BINARY_DIR}")


#add library
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory (MathFunctions)
    set(EXTRA_LIBS MyMathFunctions)
endif (USE_MYMATH)

#add the executable
add_executable(Tutorial tutorial.cxx)
target_link_libraries (Tutorial ${EXTRA_LIBS})


#MyMathFunctions安装的类型为Library，Tutorial 安装的类型为Runtime
#路径 DESTINATION : /usr/local
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

#build an installer
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)