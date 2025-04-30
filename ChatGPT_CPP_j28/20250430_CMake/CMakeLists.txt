cmake_minimum_required(VERSION 3.14)
project(FmtExample)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Встроенный механизм CMake для загрузки внешних зависимостей
include(FetchContent)

# Загружаем и подключаем fmt
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        10.2.1  # последняя стабильная версия на момент написания
)

FetchContent_MakeAvailable(fmt)

# Создаём исполняемый файл и связываем с fmt
add_executable(main main.cpp)
target_link_libraries(main PRIVATE fmt::fmt)
