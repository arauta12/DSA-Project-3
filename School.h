#include <iostream>
#include <string>
#include <vector>
#pragma once

struct School{
    std::string x, y, objid, ncessch, yr, stabr, leaid, stid, lea_name, schname, street, street2, city, state, zip, zip4,
            phone, charter, virt, gslo, gshi, level, status, schtype, schstat, towntype, county, totfrlunch, freelunch, reducedlunch,
            directcert, pk, k, first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth, eleventh, twelfth, thirteenth,
            ug, ae, totmen, totfem, stupop, member, fulltime, stutofratio, amalm, amalf, am, asalm, asalf, as, blalm, blalf, bl,
            hpalm, hpalf, hp, hialm, hialf, hi, tralm, tralf, tr, whalm, whalf, wh, lat, lon;

    int population;
    float freereducedlunch, studentfacratio;

    //Important string values are schname, street, city, state, level
    //Important float values are population, freereducedlunch, and studentfacratio
    School(std::vector<std::string> values){
        int i = 0;
        x = values[i++]; y = values[i++]; objid = values[i++]; ncessch = values[i++]; yr = values[i++];
        stabr = values[i++]; leaid = values[i++]; stid = values[i++]; lea_name = values[i++]; schname = values[i++];
        street = values[i++]; street2 = values[i++]; city = values[i++]; state = values[i++]; zip = values[i++];
        zip4 = values[i++]; phone = values[i++]; charter = values[i++]; virt = values[i++]; gslo = values[i++];
        gshi = values[i++]; level = values[i++]; status = values[i++]; schtype = values[i++]; schstat = values[i++];
        towntype = values[i++]; county = values[i++]; totfrlunch = values[i++]; freelunch = values[i++]; reducedlunch = values[i++];
        directcert = values[i++]; pk = values[i++]; k = values[i++]; first = values[i++]; second = values[i++];
        third = values[i++]; fourth = values[i++]; fifth = values[i++]; sixth = values[i++]; seventh = values[i++];
        eighth = values[i++]; ninth = values[i++]; tenth = values[i++]; eleventh = values[i++]; twelfth = values[i++];
        thirteenth = values[i++]; ug = values[i++]; ae = values[i++]; totmen = values[i++]; totfem = values[i++]; stupop = values[i++];
        member = values[i++]; fulltime = values[i++]; stutofratio = values[i++]; amalm = values[i++]; amalf = values[i++];
        am = values[i++]; asalm = values[i++]; asalf = values[i++]; as = values[i++]; blalm = values[i++]; blalf = values[i++];
        bl = values[i++]; hpalm = values[i++]; hpalf = values[i++]; hp = values[i++]; hialm = values[i++]; hialf = values[i++];
        hi = values[i++]; tralm = values[i++]; tralf = values[i++]; tr = values[i++]; whalm = values[i++]; whalf = values[i++];
        wh = values[i++]; lat = values[i++]; lon = values[i++];

        if(stupop != "")
            population = stoi(stupop);
        if(totfrlunch != "")
            freereducedlunch = stof(totfrlunch);
        if(stutofratio != "")
            studentfacratio = stof(stutofratio);
    }
};