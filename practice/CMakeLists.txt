set(CMAKE_CXX_FLAGS "-std=c++1z")

add_executable(lambda
  main.cpp 
  ast.cpp 
  eval.cpp 
  type.cpp 
)