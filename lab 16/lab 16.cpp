// задание 16
#include <random>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void fill_set(std::set<int>& s)
{
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(-50, 50);
    for (int i = 0; i < 20; i++)
    {
        s.insert(uid(gen));
    }
    
}


bool erase_set(std::set<int>& s, const int& a)
{

    std::set<int>::iterator it2 = std::find(s.begin(), s.end(), a);

    if (it2 != s.end())
    {
        std::cout << "Элемент был найден!\n";
        s.erase(it2);
        return true;
    }
    else {
        //std::cout << "Элемент не был найден!\n";
        return false;

    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::set<int> s;
    fill_set(s);
    std::cout << "Исходный список элементов бинарного дерева:\n";
    for (auto r : s)
    {
        std::cout << r << " ";
    }
    auto it = std::minmax_element(s.begin(), s.end());
    std::cout << "\nНаибольший элемент в дереве: " << *it.second << std::endl;
    std::cout << "Наименьший элемент в дереве: " << *it.first << std::endl;
    
    std::cout << "Измененный список элементов бинарного дерева:\n";
    std::vector<int> vec;
    for (auto it : s)
    {
        vec.push_back(it);
    }
    std::swap(vec[0], vec[vec.size()-1]);
    for (auto it : vec)
    {
        std::cout << it << " ";
    }

    std::cout << "\n";
    std::set<int>  s2;
    
    fill_set(s2);
    for (auto it : s2)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    int a;
    std::cout << "Введите значение для удаления из дерева ";
    std::cin >> a;
    if (erase_set(s2, a))
    {
        for (auto it : s2)
        {
            std::cout << it << " ";
        }
    }
    else if (erase_set(s2, a) == false)
    {
        std::cout << "Элемент не был найден!\n";
    }


         
}

