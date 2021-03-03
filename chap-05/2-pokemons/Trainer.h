#pragma once

#include "Pokemon.h"

#include <algorithm>
#include <array>
#include <string>
#include <string_view>

class Trainer
{
public:
    Trainer(std::string_view name)
        : _name { name }
    {
    }

    ~Trainer()
    {
        for (auto* pokemon : _team)
        {
            delete pokemon;
        }
    }

    int get_level() const
    {
        const auto* pokemon = get_first_pokemon();
        return pokemon ? pokemon->get_level() : 0;
    }

    std::vector<Pokemon*> get_pokemons() const
    {
        std::vector<Pokemon*> pokemons;

        for (auto* t : _team)
        {
            if (t != nullptr)
            {
                pokemons.emplace_back(t);
            }
        }

        return pokemons;
    }
    
    Pokemon* get_first_pokemon() const
    {
        for (auto& t : _team)
        {
            if (t != nullptr)
            {
                return t.get();
            }
        }

        return nullptr;
    }

    [[nodiscard]] std::vector<std::unique_ptr<Pokemon>> give_pokemons()
    {
        std::vector<std::unique_ptr<Pokemon>> pokemons;
        for (auto& t : _team)
        {
            if (t != nullptr)
            {
                auto& ptr = pokemons.emplace_back();
                std::swap(t, ptr);
            }
        }
        return pokemons;
    }

    void collect(Pokemon* pokemon) { collect(std::unique_ptr<Pokemon> { pokemon }); }

    void collect(std::unique_ptr<Pokemon> pokemon)
    {
        if (auto* fighter = get_first_pokemon())
        {
            fighter->level_up();
        }

        _pokedex.add(*pokemon);

        if (!add_to_team(pokemon))
        {
            _pc.transfer(std::move(pokemon));
        }
    }

    bool add_to_team(std::unique_ptr<Pokemon>& pokemon)
    {
        for (auto& t : _team)
        {
            if (t == nullptr)
            {
                std::swap(t, pokemon);
                return true;
            }
        }

        return false;
    }

    void remove(const Pokemon& pokemon)
    {
        _pokedex.remove(pokemon);

        if (!remove_from_team(pokemon))
        {
            _pc.remove(pokemon);
        }
    }

    bool remove_from_team(const Pokemon& pokemon)
    {
        auto it = std::find_if(_team.begin(), _team.end(), [&pokemon](const auto& p) { return p.get() == &pokemon; });
        if (it != _team.end())
        {
            it->reset();
            return true;
        }

        return false;
    }

    void transfer_team_to_pc()
    {
        for (auto& pokemon : give_pokemons())
        {
            _pc.transfer(std::move(pokemon));
        }
    }

    void release_duplicates()
    {
        auto duplicated = _pokedex.get_duplicated();
        for (auto* pokemon : duplicated)
        {
            // remove already delegates to all the right components (team / pc / pokedex).
            remove(*pokemon);
        }
    }

    const Pokedex& get_pokedex() const { return _pokedex; }

private:
    const std::string _name;
    
    std::array<std::unique_ptr<Pokemon>, 6> _team;
    PC      _pc;
    Pokedex _pokedex;
};
