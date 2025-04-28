#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class ValueNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Value not found in container";
		}
};

template <typename T>
void	easyfind(T &container, int value) {

	// Déclare une variable it de type itérateur du conteneur T.
	// container.begin() : Retourne un itérateur pointant vers le début du conteneur.
	// container.end() : Retourne un itérateur pointant vers la fin du conteneur.
	// std::find() : Recherche la première occurrence de value dans le conteneur,
	// si elle n'est pas trouvée, retourne un itérateur pointant vers la fin du conteneur.
	// https://cplusplus.com/reference/algorithm/find/
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw ValueNotFoundException();
	std::cout << "Value " << value << " found in container" << std::endl;
}

#endif