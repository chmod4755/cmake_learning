add_library(MyMathFunctions mysqrt.cxx)

#DESTINATION :/usr/local
install (TARGETS MyMathFunctions DESTINATION bin)
install (FILES mysqrt.h DESTINATION include)