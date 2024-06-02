/*
 ApproxMC
 
 
 Copyright (c) 2019, Mate Soos and Kuldeep S. Meel. All rights reserved
 Copyright (c) 2009-2018, Mate Soos. All rights reserved.
 Copyright (c) 2015, Supratik Chakraborty, Daniel J. Fremont,
 Kuldeep S. Meel, Sanjit A. Seshia, Moshe Y. Vardi
 Copyright (c) 2014, Supratik Chakraborty, Kuldeep S. Meel, Moshe Y. Vardi

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#include "appmc_constants.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using namespace AppMCInt;

Constants::Constants() {
    //So if you have 50 hashes, then between 1-6, use 0.5 prob, between 7-8 use 0.49, between 9-10 0.48
    sparseprobvalues = {{
        "header,0.5,0.49,0.48,0.47,0.45,0.44,0.43,0.42,0.41,0.39,0.38,0.37,0.36,0.35,0.33,0.32,0.31,0.3,0.29,0.27,0.26,0.25,0.24,0.22,0.21,0.19,0.18,0.16,0.15,0.13,0.12,0.1,0.09,0.07,0.06,0.04,0.03,",
        "50,1,7,9,11,14,15,17,18,19,21,23,24,25,26,29,30,31,32,33,36,37,38,39,41,42,44,45,47,48,50,",
        "100,1,7,9,12,17,19,22,23,26,29,31,33,34,36,40,42,44,46,48,53,55,58,60,65,68,74,76,82,85,90,92,95,97,",
        "150,1,7,10,13,18,20,23,25,28,34,36,38,40,42,47,50,52,55,57,63,66,69,72,79,83,91,96,105,110,121,126,136,140,145,148,",
        "200,1,8,10,13,18,20,23,25,28,37,39,42,44,47,52,55,58,61,63,70,74,77,81,89,94,104,109,121,128,142,150,167,175,190,194,",
        "250,1,8,10,13,18,20,24,26,28,40,42,45,47,50,56,59,62,65,68,76,79,84,88,97,103,114,120,134,141,158,168,190,202,227,238,247,",
        "300,1,8,10,14,18,20,24,26,29,42,44,48,50,53,59,62,66,70,72,80,84,89,94,104,109,122,129,144,152,172,183,209,224,257,274,294,299,",
        "350,1,8,10,14,19,21,24,27,29,44,46,50,52,55,61,65,69,73,76,84,88,93,99,109,115,129,136,152,162,183,195,225,242,282,305,342,347,",
        "400,1,8,11,14,19,21,25,27,30,46,48,51,54,57,64,67,72,76,79,87,92,97,103,114,120,135,142,160,170,193,206,238,257,303,330,385,395,",
        "450,1,8,11,14,19,21,25,27,30,47,49,53,56,59,66,70,74,78,82,90,95,101,107,118,124,140,147,166,177,202,215,250,271,322,353,423,443,",
        "500,1,8,11,15,19,21,25,27,30,48,50,55,57,61,68,72,76,81,84,93,98,105,110,123,128,144,152,172,183,209,224,261,283,338,373,456,490,",
        "600,1,8,11,15,20,22,26,28,44,51,53,57,60,63,71,75,80,84,89,98,103,110,115,129,135,152,161,181,194,222,239,279,304,367,407,513,572,",
        "700,1,9,11,15,20,22,26,28,46,52,55,59,63,66,74,78,83,88,93,102,109,114,120,134,141,158,168,190,203,233,251,294,322,391,436,560,639,",
        "800,1,9,11,16,21,22,27,29,47,54,56,61,65,68,76,80,85,91,96,106,112,118,124,139,146,164,174,197,211,243,262,308,337,411,461,601,697,",
        "900,1,9,12,16,21,23,27,29,49,56,58,62,68,70,78,82,88,93,99,110,116,121,127,143,150,169,179,204,219,251,271,320,350,429,483,636,747,",
        "1000,1,9,12,16,21,23,28,30,50,57,59,64,69,71,81,84,90,95,101,112,118,124,131,146,154,173,184,210,225,258,279,331,362,446,502,667,791,",
        "1200,1,9,12,17,22,23,29,30,52,59,62,66,72,74,85,88,93,99,105,117,123,130,136,153,162,181,193,221,236,272,293,348,382,474,535,721,867,",
        "1400,1,9,12,17,22,24,29,48,53,61,64,68,74,76,88,90,96,102,108,121,127,134,141,158,169,188,201,229,245,284,306,363,401,497,564,766,930,",
        "1600,1,9,12,17,22,24,29,49,55,62,65,70,76,78,90,93,99,105,111,124,131,138,145,163,174,194,208,236,253,294,317,377,416,517,588,805,984,",
        "1800,1,10,13,18,23,24,30,50,56,64,67,72,78,80,93,95,101,107,114,127,134,141,148,167,178,199,214,243,260,302,327,388,429,536,609,839,1031,",
        "2000,1,10,13,18,23,25,30,51,57,65,68,73,80,82,94,97,103,110,116,130,137,144,152,170,182,204,219,248,266,309,335,399,440,552,629,870,1074,",
        "2400,1,10,13,18,23,25,50,53,59,67,71,76,82,85,98,101,107,113,120,135,142,149,157,177,189,214,227,258,277,322,350,418,461,579,662,922,1147,",
        "2800,1,10,13,19,24,26,52,54,60,69,73,78,85,87,100,103,110,117,124,138,146,154,162,182,195,221,234,267,286,333,362,433,478,602,689,966,1209,",
        "3200,1,10,13,19,24,26,53,56,62,71,78,80,87,89,103,106,112,119,127,142,149,157,166,187,199,226,240,274,294,342,372,446,495,624,714,1004,1261,",
        "3600,1,11,13,20,25,26,54,57,63,72,79,81,88,91,105,108,115,122,129,145,153,161,170,191,204,231,246,280,301,351,381,458,508,641,736,1039,1308,",
    }};

    readInSparseValues();
}

void Constants::readInSparseValues()
{
    assert(index_var_maps.empty());
    for (uint32_t i = 0; i < sparseprobvalues.size(); i++)
    {
        std::stringstream ss(sparseprobvalues[i]);
        string value;
        std::getline(ss, value, ',');
        if (value == "header") {
            while(std::getline(ss, value, ',')) {
                probval.push_back(std::stod(value.c_str()));
            }
            continue;
        }

        //non-header
        uint32_t numvars = std::stoul(value.c_str());
        vector<uint32_t> index_var_map;
        while(std::getline(ss, value, ',')) {
            index_var_map.push_back(std::stoul(value.c_str()));
        }
        assert(index_var_map.size() <= probval.size());
        VarMap vmap(numvars, index_var_map);
        index_var_maps.push_back(vmap);
    }
}
