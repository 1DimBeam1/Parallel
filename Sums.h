#pragma once
#include <vector>
unsigned localization_sum(unsigned* v, unsigned n);//с барьерами
unsigned sum_c_mutex(unsigned* v, unsigned v_size);
unsigned sum_cpp_mutex(std::vector <unsigned> v, unsigned v_size);//мьютекс
unsigned sum(std::vector<unsigned> v, unsigned n);//обычная сумма
unsigned sum_omp_reduce(std::vector<unsigned> v, unsigned n);//редуцией
unsigned sum_round_robin(std::vector <unsigned> v, unsigned n);//с партиалом
unsigned sum_round_robinF(std::vector<unsigned> v, unsigned n);// без партиала
unsigned sum_round_robinR(std::vector <unsigned> v, unsigned n);//локальность данных
