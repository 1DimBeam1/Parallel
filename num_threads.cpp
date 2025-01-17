#include "num_threads.h"

static unsigned thread_no = std::thread::hardware_concurrency();

void set_num_threads(unsigned T)
{
	thread_no = !T ? thread::hardware_concurrency()
		: T > thread::hardware_concurrency() ? thread::hardware_concurrency()
		: T;
	omp_set_num_threads(T);
}

unsigned get_num_threads()
{
	return thread_no;
}

