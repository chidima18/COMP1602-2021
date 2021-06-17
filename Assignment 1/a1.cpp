#include <iostream>

using namespace std;

// 1 b [3 marks]
struct PokemonStat
{
    int hp;
    int attack;
    int defence;
    int specialAttack;
    int specialDefence;
    int speed;
};

// 1 a [4 marks]
struct Pokemon
{
    int id;
    char type;
    float catchRate;
    float height;
    float weight;
    PokemonStat stats;
};

bool isWeakTo(char type1, char type2);
bool isResistantTo(char type1, char type2);
Pokemon makePokemon(int id, char type, float catchRate, float height, float weight, PokemonStat stats);
PokemonStat makePokemonStat(int hp, int attack, int defence, int specialAttack, int specialDefence, int speed);
void printPokemon(Pokemon pokemon);
void printPokemonStat(Pokemon pokemon);
void findPokemonById(Pokemon pokemons[], int count, int id);
void findPokemonByType(Pokemon pokemons[], int count, char type);
void findPokemonByWeakness(Pokemon pokemons[], int count, char type);
void findPokemonByResistance(Pokemon pokemons[], int count, char type);

int main()
{
    Pokemon pokemons[150];
    int count = 0;
    char type;
    int choice = 1, id;
    float catchRate, height, weight;
    int hp, attack, defence, specialAttack, specialDefence, speed;

    while (choice != 0)
    {
        cout << "\nSelect an Option" << endl;
        cout << "1. Add Pokémon information" << endl;
        cout << "2. Search Pokémon by ID" << endl;
        cout << "3. Search Pokémon by Type" << endl;
        cout << "4. Search Pokémon by Weaknesses" << endl;
        cout << "5. Search Pokémon by Resistances" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        // 4 a [4 marks]
        if (choice == 1)
        {
            cout << "Enter your pokemon's information (id, type, catchRate, height, weight): " << endl;
            cin >> id >> type >> catchRate >> height >> weight;
            cout << "Enter your pokemon's stats (hp, attack, defence, specialAttack, specialDefence, speed): " << endl;
            cin >> hp >> attack >> defence >> specialAttack >> specialDefence >> speed;

            PokemonStat stats = makePokemonStat(hp, attack, defence, specialAttack, specialDefence, speed);
            pokemons[count] = makePokemon(id, type, catchRate, height, weight, stats);
            count++;
        }
        // 4 b [3 marks]
        if (choice == 2)
        {
            cout << "Enter the pokemon's id: ";
            cin >> id;
            findPokemonById(pokemons, count, id);
        }
        // 4 c [3 marks]
        if (choice == 3)
        {
            cout << "Enter the pokemon's type: ";
            cin >> type;
            findPokemonByType(pokemons, count, type);
        }
        // 4 d [3 marks]
        if (choice == 4)
        {
            cout << "Enter the pokemon's weakness: ";
            cin >> type;
            findPokemonByWeakness(pokemons, count, type);
        }
        // 4 e [3 marks]
        if (choice == 5)
        {
            cout << "Enter the pokemon's resistance: ";
            cin >> type;
            findPokemonByResistance(pokemons, count, type);
        }
    }

    return 0;
}

// 2 a [3 marks]
bool isWeakTo(char type1, char type2)
{
    if ((type1 == 'W' && type2 == 'G') ||
        (type1 == 'G' && type2 == 'F') ||
        (type1 == 'F' && type2 == 'W'))
        return true;
    return false;
}

// 2 b [3 marks]
bool isResistantTo(char type1, char type2)
{
    if ((type1 == 'W' && type2 == 'F') ||
        (type1 == 'G' && type2 == 'W') ||
        (type1 == 'F' && type2 == 'G'))
        return true;
    return false;
}

// 3 a [3 marks]
Pokemon makePokemon(int id, char type, float catchRate, float height, float weight, PokemonStat stats)
{
    Pokemon pokemon = {id, type, catchRate, height, weight, stats};
    return pokemon;
}

// 3 b [3 marks]
PokemonStat makePokemonStat(int hp, int attack, int defence, int specialAttack, int specialDefence, int speed)
{
    PokemonStat stat = {hp, attack, defence, specialAttack, specialDefence, speed};
    return stat;
}

// 3 c [3 marks]
void printPokemon(Pokemon pokemon)
{
    cout << "ID\tType\tCatch Rate\tHeight\tWeight\tStats" << endl;
    cout << pokemon.id << "\t" << pokemon.type << "\t" << pokemon.catchRate << "\t" << pokemon.height << "\t" << pokemon.weight << endl;
}

// 3 d [3 marks]
void printPokemonStat(Pokemon pokemon)
{
    cout << "ID\tHP\tAttack\tDefence\tSp.Atk\tSp.Def\tSpeed" << endl;
    cout << pokemon.id << "\t" << pokemon.stats.hp << "\t" << pokemon.stats.attack << "\t" << pokemon.stats.defence << "\t" << pokemon.stats.specialAttack << "\t" << pokemon.stats.specialDefence << "\t" << pokemon.stats.speed << endl;
}

// 3 e [3 marks]
void findPokemonById(Pokemon pokemons[], int count, int id)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (pokemons[i].id == id)
        {
            printPokemon(pokemons[i]);
            printPokemonStat(pokemons[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No data exists for that Pokémon" << endl;
}

// 3 f [3 marks]
void findPokemonByType(Pokemon pokemons[], int count, char type)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (pokemons[i].type == type)
        {
            printPokemon(pokemons[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Pokemon exists for that type" << endl;
    }
}

// 3 g [3 marks]
void findPokemonByWeakness(Pokemon pokemons[], int count, char type)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        bool weak = isWeakTo(pokemons[i].type, type);
        if (weak)
        {
            printPokemon(pokemons[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Pokemon exists that are weak to that type" << endl;
    }
}

// 3 h [3 marks]
void findPokemonByResistance(Pokemon pokemons[], int count, char type)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (isResistantTo(pokemons[i].type, type))
        {
            printPokemon(pokemons[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Pokemon exists that are resistant to that type" << endl;
    }
}