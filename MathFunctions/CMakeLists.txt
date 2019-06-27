add_executable(MakeTable MakeTable.cxx)

add_custom_command (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

#add output table.h to library
add_library(MyMathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

#DESTINATION :/usr/local
install (TARGETS MyMathFunctions DESTINATION bin)
install (FILES MyMathFunctions.h DESTINATION include)