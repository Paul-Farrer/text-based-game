#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout<< "Hacking into the security mainframe. Difficulty: "  << Difficulty << std::endl;
    std::cout << "Enter correct code to get through the security... \n";
}

bool PlayGame(int Difficulty)
{
     PrintIntroduction(Difficulty);

    //Declared Variables, declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Adding and multiplying the variables and assigning them to a variable name
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Prints out the variable values to the terminal with a new line (Sum, Product etc.)
    std::cout << std::endl;
    std::cout << "- There are 3 numbers here in the code \n"; 
    std::cout << "- The codes add up to: " << CodeSum << "\n";
    std::cout << "- The codes multiply to give: " << CodeProduct << std::endl;
    
    //Store player guess
    int GuessA, GuessB, GuessC;

    std::cout << "\nEnter code:" << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou have made it through!\n";
        std::cout << "Proceed onto next level\n";
        return true;
    }
    else
    {
        std::cout << "\nYou have failed!\n";
        std::cout << "Please redo the level\n";
        return false;
    }
}

int main()
{

    srand(time(NULL)); //Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop game until all levels are complete
    {
    
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //Clears any errors
    std::cin.ignore(); //Discards the buffer

    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }
    
    }

    std::cout<< "/nYou have gained access to the mainframe! Congratulations";
    return 0;   
}