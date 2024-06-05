#include <iostream>

int main(int argc, char** argv, char** envp)
{
    const char* var_38 = "RUUR#!#%j Ny!aTNh!dNb!]G\"N&YxBNdB \x7fVN(Usl";
    std::cout << "Flag: ";
    int var_c = 0;
    while (var_38[var_c] != '\0')
    {
        putchar(var_38[var_c] ^ 0x11);
        var_c++;
    }
    putchar('\n');
    return 0;
}
