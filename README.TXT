Daniel Kryzhanovsky and Gabe Howland

1/2.With the first 2 projects, we started off by defning the x and y coordinates of each city, going through the list of the cities and getting the coordinates. The output operator then goes the list compile in the istream and initializes it within the ostream.

3.Total path distance goes the list of the cities and initliazes the current 2 cities values to caluclate the distance of the two points. After the loop ends, it goes through the process again to find the diatcne of the last point in the list and the first point in the list.

4. To reorder, Cities::reorder is able to take a random ordering of the list and redifine each new ordered point based on the new position they are given by the permuation through the loop. It then pushes the new order to nu_ord to get the new order of the cities.

5.In order to get random integers to use for the program, we make sure to declare a list of order cities incase one wasn't made through the first for loop, we then shuffle all the cities starting from the first and ending in the last in order to get the current order of cities. 

6.We start off by checking if the file is being initialized or not, if so, we then intiailize the is_file and istreams and ostreams to get the program running. We then make sure to use the city size and city distance to initalize the total amount of cities and the "best route" for the list of cities. We then use best city to allow for the permutaion of the new random cities to be accounted for when creating the new shortest path, which allows all of the random permutations to be set. Through the for loop, we start from the beginning until we reach 1 million, which then generates a new list of cities, caculates the distance, reorders them, and then finally initalizes the cities within the new cities object. It then saves these files to the file called "shortest.tsv".
