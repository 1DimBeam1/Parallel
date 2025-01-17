#include <iostream>
#include <vector>
#include "omp.h"
#include <mutex>
#include "num_threads.h"
#include <fstream>
#include "own_barrier_latch.h"
#include <thread>
#include "ExperementsRunner.h"
#include "Sums.h"
#include "RandomizeGenerator.h"

// Method to create csv file from vector that contains scalability_result objects
void to_csv(std::ostream& io, std::vector<scalability_result> v) {
	io << "N,Result,Time,Speedup,Efficiency\n";
	for (unsigned i = 0; i < v.size(); i++) {
		io << i << ',' << v.at(i).result << ',' << v.at(i).t << ',' << v.at(i).s << ',' << v.at(i).e << '\n';
	}
}

void to_csv_rand(std::ostream& io, std::vector<scalability_result> v) {
	io << "N,Time,Speedup,Efficiency\n";
	for (unsigned i = 0; i < v.size(); i++) {
		io << i + 1 << ',' << v.at(i).t << ',' << v.at(i).s << ',' << v.at(i).e << '\n';
	}
}


int main() {
	auto sr1 = run_experiment(sum, 1u, 1u<<28);
	std::ofstream os1("sum.csv", std::ios_base::out);
	if (os1.is_open()) {
		to_csv(os1, sr1);
		os1.close();
	}

	auto sr2 = run_experiment(sum_cpp_mutex, 1u, 1u << 28);
	std::ofstream os2("sum_mutex.csv", std::ios_base::out);
	if (os2.is_open()) {
		to_csv(os2, sr2);
		os2.close();
	}

	auto sr3 = run_experiment(localization_sum, 1u, 1u << 28);
	std::ofstream os3("sum_barrier.csv", std::ios_base::out);
	if (os3.is_open()) {
		to_csv(os3, sr3);
		os3.close();
	}

	auto sr4 = run_experiment(sum_omp_reduce, 1u, 1u << 28);
	std::ofstream os4("sum_reduce.csv", std::ios_base::out);
	if (os4.is_open()) {
		to_csv(os4, sr4);
		os4.close();
	}

	auto sr5 = run_experiment(sum_round_robin, 1u, 1u << 28);
	std::ofstream os5("sum_partial.csv", std::ios_base::out);
	if (os5.is_open()) {
		to_csv(os5, sr5);
		os5.close();
	}

	auto sr6 = run_experiment(sum_round_robinF, 1u, 1u << 28);
	std::ofstream os6("sum_noPartial.csv", std::ios_base::out);
	if (os6.is_open()) {
		to_csv(os6, sr6);
		os6.close();
	}

	auto sr7 = run_experiment(sum_round_robinR, 1u, 1u << 28);
	std::ofstream os7("sum_localData.csv", std::ios_base::out);
	if (os7.is_open()) {
		to_csv(os7, sr7);
		os7.close();
	}





	//randomize experiment
	//unsigned sz = 2 << 20; // 2^20 elements in array
	//unsigned* v = new unsigned[sz];
	//auto randomExp = run_experiment_rand(randomize, sz, 0, 1000, 0);
	//for (int i = 0; i < randomExp.size(); i++) {
	//	std::cout << "Cores: " << i + 1 << "\n";
	//	std::cout << "time (ms): " << randomExp.at(i).t << "\n";
	//	std::cout << "speedup: " << randomExp.at(i).s << "\n";
	//	std::cout << "efficiency: " << randomExp.at(i).e << "\n\n";
	//}
	//std::ofstream randomizerInput("randomize_experiment.csv", std::ios_base::out);
	//if (randomizerInput.is_open()) {
	//	to_csv_rand(randomizerInput, randomExp);
	//	randomizerInput.close();
	//}


}

