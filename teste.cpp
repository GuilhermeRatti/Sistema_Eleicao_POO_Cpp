#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include <memory>
#include <any>
#include <exception>
#include <stdexcept>
#include <typeinfo>

#include <string>

using namespace std;

int main()
{
    std::any a(12);

    // set any value:
    a = std::string("Hello!");
    a = 16;
    // reading a value:

    // we can read it as int
    std::cout << std::any_cast<int>(a) << '\n';

    // but not as string:
    try
    {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch (const std::bad_any_cast &e)
    {
        std::cout << e.what() << '\n';
    }

    // reset and check if it contains any value:
    a.reset();
    if (!a.has_value())
    {
        std::cout << "a is empty!"
                  << "\n";
    }

    // you can use it in a container:
    std::map<std::string, std::any> m;
    m["integer"] = 10;
    m["string"] = std::string("Hello World");
    m["float"] = 1.0f;

    for (auto &[key, val] : m)
    {
        if (val.type() == typeid(int))
            std::cout << "int: " << std::any_cast<int>(val) << "\n";
        else if (val.type() == typeid(std::string))
            std::cout << "string: " << std::any_cast<std::string>(val) << "\n";
        else if (val.type() == typeid(float))
            std::cout << "float: " << std::any_cast<float>(val) << "\n";
    }

    cout << any_cast<string>(m["string"]) << endl;

    map<string, any> mapa;
    try
    {
        mapa.insert(pair<string, any>("teste", 1));
        mapa.insert(pair<string, any>("teste2", 2.2));
        mapa.insert(pair<string, any>("teste3", string("oi")));

        cout << any_cast<int>(mapa["teste"]) << endl;
        cout << any_cast<double>(mapa["teste2"]) << endl;
        cout << any_cast<std::string>(mapa["teste3"]) << endl;
    }
    

    catch (const bad_any_cast &e)
    {
        cout << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Erro desconhecido" << endl;
    }
}
