set(CMAKE_CXX_FLAGS "-std=c++14")

add_executable(lambda
  main.cpp 
  ast.cpp 
  eval.cpp 
  type.cpp 
  )