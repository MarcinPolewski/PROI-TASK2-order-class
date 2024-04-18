cmake_minimum_required(VERSION 3.11.0)
project(stack VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare( 
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

# for using main:
# set(PROJECT_SOURCES order.cpp order.h date.h date.cpp statusCodes.h product.h product.cpp orderListElement.h orderListElement.cpp address.h address.cpp main.cpp)
# add_executable(main main.cpp  ${PROJECT_SOURCES} )

#for google test:
set(PROJECT_SOURCES order.cpp order.h date.h date.cpp statusCodes.h product.h product.cpp orderListElement.h orderListElement.cpp address.h address.cpp)
add_executable(testGoogle testGoogle.cpp ${PROJECT_SOURCES})
target_link_libraries(testGoogle PUBLIC gtest_main)
