# include <iostream>
# include <string>

int main(int argc, char *argv[])
{
    int i;
    int j;

    i = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (i < argc)
    {
        std::string argument = argv[i];
        j = 0;
        while (j < static_cast<int>(argument.length()))
        {
            argument[j] = std::toupper(argument[j]);
            j++;
        }
		std::cout << argument;
        if (i < argc - 1)
            std::cout << " ";
        if (i == argc - 1)
            std::cout << std::endl;
        i++;
    }
    return (0);
}  
