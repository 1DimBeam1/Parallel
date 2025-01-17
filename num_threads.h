#include <iostream>
#include <vector>
#include <iomanip>
#include "omp.h"
#include "stdlib.h"
#include <thread>
#include <chrono>
#include <mutex>
#include <ranges> 
#include <fstream>
#include <numeric>

using namespace std;

void set_num_threads(unsigned T);
unsigned get_num_threads();

//template <std::invocable <const unsigned*,size_t> F>
//std::vector<scability> run_experement(F f, unsigned v_min, unsigned v_max)
//{
//	std::vector<unsigned> v(v_max-v_min+1);
//	std::iota(v.begin(), v.end(), v_min);
//	unsigned P = get_num_threads();
//	std::vector<scability> r(P);
//
//	using namespace std::chrono;
//	for (unsigned T = 1; T <= P; ++T)
//	{
//		set_num_threads(T);
//		auto t1 = steady_clock::now();
//		r[T - 1].result = f(v.data(), v.size());
//		auto t2 = steady_clock::now();
//		r[T - 1].t = duration_cast<milliseconds>(t2 - t1).count();
//		r[T - 1].s = r[0].t / r[T - 1].t;
//		r[T - 1].e = r[T - 1].s / T;
//	}
//	return r;
//}


