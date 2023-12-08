#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <random>
#include <vector>

static void print_vector(std::vector<char*>& vec) {
	std::cout << "vec: ";
	for (auto& i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void exe_child(std::vector<char*>& vec) {
	char* const* argv = vec.data();
	execve("../PmergeMe", argv, nullptr);
	std::cerr << "execve error" << std::endl;
	exit(EXIT_FAILURE);
}

static void generate_random_value(std::mt19937& gen, const int begin, const int end, const int size) {
	std::cout << "begin: " << begin << ", end: " << end << ", size: " << size << "\n" << std::endl;
	std::uniform_int_distribution<> dis(begin, end);  // begin 부터 end 사이의 균등 분포 (char 범위)
	std::vector<char*> vec;
	std::string str;
	vec.reserve(size);

	for (int i = 0; i < size; ++i) {
		str = std::to_string(dis(gen));
		vec.emplace_back(const_cast<char*>(strdup(str.c_str())));
	}
	print_vector(vec);
	exe_child(vec);
	vec.clear();
}

static void execute_test(std::mt19937& gen, const int count) {
	std::uniform_int_distribution<> dis(0, std::numeric_limits<int>::max());
	const int end = dis(gen);
	std::uniform_int_distribution<> dis2(0, end);
	const int begin = dis2(gen);
	generate_random_value(gen, begin, end, count);
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "usage: " << av[0] << " [count]" << std::endl;
		return EXIT_FAILURE;
	}
	std::random_device rd;
	std::mt19937 gen(rd());	 // Mersenne Twister 엔진을 사용한 시드 초기화

	const int count = std::atoi(av[1]);
	for (int i = 0; i <= count; ++i) {
		std::cout << "\n------------------- test:  " << i + 1 << " -------------------\n" << std::endl;
		pid_t pid = fork();
		if (pid == -1) {
			std::cerr << "fork error" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (pid == 0) {
			execute_test(gen, i);
		} else {
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status)) {
				std::cout << "child exit status: " << WEXITSTATUS(status) << std::endl;
				if (WEXITSTATUS(status) == 42) {
					std::cout << "test: " << i + 1 << " fail" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	std::cout << "!!!!!!!!!!!!! All tests passed !!!!!!!!!!!!!!!!" << std::endl;
	return EXIT_SUCCESS;
}