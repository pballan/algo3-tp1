import sys, os

os.system("g++ -std=c++11 -o main main_experiments.cpp -ggdb")

for x in range(12, 36, 3):
    os.system("./main < low-dimensional/test_" + str(x) +" >> results_3.csv" )
#os.system("./main < data_enunciado.txt")