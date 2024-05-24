find . -name "*.gcda" -delete
find . -name "*.gcno" -delete

g++ -fprofile-arcs -ftest-coverage -std=c++17 src/a.cpp -lgtest -o test

./test

gcov a.cpp

lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent

genhtml coverage.info --output-directory out --ignore-errors inconsistent 