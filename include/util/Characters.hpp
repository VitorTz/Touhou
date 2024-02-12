#pragma once
#include <string>
#include <map>


namespace th {


    enum Characters {

        ReimuHakurei,
        MarisaKirisame

    };

    const std::map<th::Characters, std::string> characterNameMap = {
        {th::Characters::ReimuHakurei, "Reimu Hakurei"},
        {th::Characters::MarisaKirisame, "Marisa Kirisame"}
    };

    
} // namespace th
