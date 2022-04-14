#include "cities.hh"

int main(int argc, char *argv[]){
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO OPTIMIZE, try again pls <3 :) \n";
		return 0;
	}
	else {


		std::ofstream os_file ("shortest.tsv", std::ofstream::out);

		Cities input_city(argv[1]);

		std::ifstream is_file(filename, std::ifstream::in);

		is_file >> input_city;

		Cities::permutation_t cur_perm = Cities::input_city.random_permutation();

		unsigned city_amt = Cities::city_size();

		double best_route = input_city.total_path_distance(input_city.get_perms());

		for(int i = 0; i < 1000000; i++){
			cur_perm = input_city.random_permutation();
			double path_temp = input_city.total_path_distance(cur_perm);
			if(path_temp < best_route){
				best_route = path_temp;
				input_city.reorder(cur_perm);
				std::cout << i << "\t" << best_route;
			}

		}
		os_file << input_city;
		return 0;
}