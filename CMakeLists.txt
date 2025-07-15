cmake_minimum_required(VERSION 3.10)
project(TesseractOCR)

find_package(PkgConfig REQUIRED)
pkg_check_modules(TESSERACT REQUIRED tesseract)
pkg_check_modules(LEPTONICA REQUIRED lept)

include_directories(${TESSERACT_INCLUDE_DIRS} ${LEPTONICA_INCLUDE_DIRS})
link_directories(${TESSERACT_LIBRARY_DIRS} ${LEPTONICA_LIBRARY_DIRS})

add_executable(ocr main.cpp)
target_link_libraries(ocr ${TESSERACT_LIBRARIES} ${LEPTONICA_LIBRARIES})