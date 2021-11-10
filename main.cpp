#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "nlohmann/json.hpp"

struct Film {
    std::vector<std::string> countries;
    std::string date;
    std::vector<std::string> distributed_by;
    std::vector<std::string> screenplay_by;
    std::vector<std::string> directed_by;
    std::vector<std::string> produced_by;
    std::unordered_map<std::string, std::string> character;
};

int main()
{
    Film film;
    std::ofstream file("record.json");
    nlohmann::json dict;

    std::string filmName = "Harry Potter and the Goblet of Fire";
    film.countries = {"United Kingdom", "United States"};
    film.date = "2005";

    film.distributed_by = {"Warner Bros. Pictures"};

    film.screenplay_by = {"Steve Kloves"};
    film.directed_by = {"Mike Newell"};
    film.produced_by = {"David Heyman"};

    film.character["Harry Potter"] = "Daniel Radcliffe";
    film.character["Ron Weasley"] = "Rupert Grint";
    film.character["Hermione Granger"] = "Emma Watson";
    film.character["Rubeus Hagrid"] = "Robbie Coltrane";
    film.character["Lord Voldemort"] = "Ralph Fiennes";

    dict[filmName] = {
            {"Countries", film.countries},
            {"Date", film.date},
            {"Distributed by", film.distributed_by},
            {"Screenplay by", film.screenplay_by},
            {"Directed by", film.directed_by},
            {"Produced by", film.produced_by},
            {"Starring", film.character}
    };

    file << dict;
    file.close();

    return 0;
}

