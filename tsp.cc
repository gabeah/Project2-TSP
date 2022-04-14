#include "cities.hh"

int main(int argc, char *argv[]){
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO OPTIMIZE, try again pls <3 :) \n";
		return 0;
	}
	else {


		std::ofstream os_file ("shortest.tsv", std::ofstream::out);

		Cities input_city;

		std::ifstream is_file(argv[1], std::ifstream::in);

		is_file >> input_city;

		unsigned city_amt = input_city.city_size();

		Cities::permutation_t cur_perm = input_city.random_permutation(city_amt);

		double best_route = input_city.total_path_distance(cur_perm);

		for(int i = 0; i < 1000000; i++){
			cur_perm = input_city.random_permutation(city_amt);
			double path_temp = input_city.total_path_distance(cur_perm);
			if(path_temp < best_route){
				best_route = path_temp;
				input_city.reorder(cur_perm);
				std::cout << i << "\t" << best_route << std::endl;
			}

		}
		os_file << input_city;
		return 0;
	}
}
