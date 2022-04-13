#include "cities.hh"

int main(int argc, char *argv[]){
	if(argc < 2){
		std::cout << "ERROR: NO FILE TO OPTIMIZE, try again pls <3 :) \n";
		return 0;
	}
	else {

		std::ifstream is_file (argv[1], std::ifstream::in);

		std::ofstream os_file ("shortest.tsv", std::ofstream::out);

		Cities::Cities input_city(argv[1]);

		is_file >> input_city;

		unsigned city_amt = Cities::city_size();

		double best_route = input_city.total_path_distance(input_city.get_perms());

		for(i = 0; i < 1000000; i++){
			Cities::input_city.random_permutation();
			Cities::permutation_t cur_perm = input_city.get_perms();
			double path_temp = input_city.total_path_distance(cur_perm);
			if(path_temp < best_route){
				best_route = path_temp;
				Cities::input_city.reorder(cur_perm);
				std::cout << i << "\t" << best_route;
			}

		}
		os_file << input_city;
		return 0;
}