#pragma once
#include <string>
#include <vector>



template <class T>
class ResourceManager
{
public:

	ResourceManager();
	~ResourceManager();

	void store(std::string &name, T& resource);
	T get(std::string &name) const;
	void remove(std::string &name);

	typename std::vector<T>::iterator begin();
	typename std::vector<T>::iterator end();
};

