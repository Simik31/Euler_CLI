#include <cmath>
#include <string>

#include "Problems.h"

int64_t Problem_011::solve()
{
    int64_t data[PROBLEM_011_GRID_SIZE][PROBLEM_011_GRID_SIZE] = {
        {  8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8 },
        { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0 },
        { 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65 },
        { 52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91 },
        { 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80 },
        { 24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50 },
        { 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70 },
        { 67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21 },
        { 24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72 },
        { 21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95 },
        { 78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92 },
        { 16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57 },
        { 86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58 },
        { 19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40 },
        {  4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66 },
        { 88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69 },
        {  4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36 },
        { 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16 },
        { 20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54 },
        {  1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48 }
    };

    int64_t greatest = -1;

    for (int64_t position_y = 0; position_y < PROBLEM_011_GRID_SIZE; position_y++) {
        for (int64_t position_x = 0; position_x < PROBLEM_011_GRID_SIZE - 4; position_x++) {
            int64_t multiple = 1;

            for (int64_t offset = 0; offset < 4 && multiple != 0; offset++)
                multiple *= data[position_y][position_x + offset];

            if (multiple > greatest)
                greatest = multiple;
        }
    }

    for (int64_t position_y = 0; position_y < PROBLEM_011_GRID_SIZE - 4; position_y++) {
        for (int64_t position_x = 0; position_x < PROBLEM_011_GRID_SIZE; position_x++) {
            int64_t multiple = 1;

            for (int64_t offset = 0; offset < 4 && multiple != 0; offset++)
                multiple *= data[position_y + offset][position_x];

            if (multiple > greatest)
                greatest = multiple;
        }
    }

    for (int64_t position_y = 0; position_y < PROBLEM_011_GRID_SIZE - 4; position_y++) {
        for (int64_t position_x = 0; position_x < PROBLEM_011_GRID_SIZE - 4; position_x++) {
            int64_t multiple = 1;

            for (int64_t offset = 0; offset < 4 && multiple != 0; offset++)
                multiple *= data[position_y + offset][position_y + offset];

            if (multiple > greatest)
                greatest = multiple;
        }
    }

    for (int64_t position_y = 0; position_y < PROBLEM_011_GRID_SIZE - 4; position_y++) {
        for (int64_t position_x = PROBLEM_011_GRID_SIZE - 1; position_x - 4 >= 0; position_x--) {
            int64_t multiple = 1;

            for (int64_t offset = 0; offset < 4 && multiple != 0; offset++)
                multiple *= data[position_y + offset][position_x - offset];

            if (multiple > greatest)
                greatest = multiple;
        }
    }

    return greatest;
}

int64_t Problem_012::solve()
{
    int64_t number = 0, divisor_count = 0;

    for (int64_t add = 1; divisor_count <= 500; add++) {
        divisor_count = 0;
        number += add;

        for (int64_t i = 1; i <= std::sqrt(number); i++)
            if (number % i == 0)
                divisor_count += 2;
    }

    return number;
}

int64_t Problem_013::solve()
{
    double data[] = {
        37107287533902102798797998220837590246510135740250.0,
        46376937677490009712648124896970078050417018260538.0,
        74324986199524741059474233309513058123726617309629.0,
        91942213363574161572522430563301811072406154908250.0,
        23067588207539346171171980310421047513778063246676.0,
        89261670696623633820136378418383684178734361726757.0,
        28112879812849979408065481931592621691275889832738.0,
        44274228917432520321923589422876796487670272189318.0,
        47451445736001306439091167216856844588711603153276.0,
        70386486105843025439939619828917593665686757934951.0,
        62176457141856560629502157223196586755079324193331.0,
        64906352462741904929101432445813822663347944758178.0,
        92575867718337217661963751590579239728245598838407.0,
        58203565325359399008402633568948830189458628227828.0,
        80181199384826282014278194139940567587151170094390.0,
        35398664372827112653829987240784473053190104293586.0,
        86515506006295864861532075273371959191420517255829.0,
        71693888707715466499115593487603532921714970056938.0,
        54370070576826684624621495650076471787294438377604.0,
        53282654108756828443191190634694037855217779295145.0,
        36123272525000296071075082563815656710885258350721.0,
        45876576172410976447339110607218265236877223636045.0,
        17423706905851860660448207621209813287860733969412.0,
        81142660418086830619328460811191061556940512689692.0,
        51934325451728388641918047049293215058642563049483.0,
        62467221648435076201727918039944693004732956340691.0,
        15732444386908125794514089057706229429197107928209.0,
        55037687525678773091862540744969844508330393682126.0,
        18336384825330154686196124348767681297534375946515.0,
        80386287592878490201521685554828717201219257766954.0,
        78182833757993103614740356856449095527097864797581.0,
        16726320100436897842553539920931837441497806860984.0,
        48403098129077791799088218795327364475675590848030.0,
        87086987551392711854517078544161852424320693150332.0,
        59959406895756536782107074926966537676326235447210.0,
        69793950679652694742597709739166693763042633987085.0,
        41052684708299085211399427365734116182760315001271.0,
        65378607361501080857009149939512557028198746004375.0,
        35829035317434717326932123578154982629742552737307.0,
        94953759765105305946966067683156574377167401875275.0,
        88902802571733229619176668713819931811048770190271.0,
        25267680276078003013678680992525463401061632866526.0,
        36270218540497705585629946580636237993140746255962.0,
        24074486908231174977792365466257246923322810917141.0,
        91430288197103288597806669760892938638285025333403.0,
        34413065578016127815921815005561868836468420090470.0,
        23053081172816430487623791969842487255036638784583.0,
        11487696932154902810424020138335124462181441773470.0,
        63783299490636259666498587618221225225512486764533.0,
        67720186971698544312419572409913959008952310058822.0,
        95548255300263520781532296796249481641953868218774.0,
        76085327132285723110424803456124867697064507995236.0,
        37774242535411291684276865538926205024910326572967.0,
        23701913275725675285653248258265463092207058596522.0,
        29798860272258331913126375147341994889534765745501.0,
        18495701454879288984856827726077713721403798879715.0,
        38298203783031473527721580348144513491373226651381.0,
        34829543829199918180278916522431027392251122869539.0,
        40957953066405232632538044100059654939159879593635.0,
        29746152185502371307642255121183693803580388584903.0,
        41698116222072977186158236678424689157993532961922.0,
        62467957194401269043877107275048102390895523597457.0,
        23189706772547915061505504953922979530901129967519.0,
        86188088225875314529584099251203829009407770775672.0,
        11306739708304724483816533873502340845647058077308.0,
        82959174767140363198008187129011875491310547126581.0,
        97623331044818386269515456334926366572897563400500.0,
        42846280183517070527831839425882145521227251250327.0,
        55121603546981200581762165212827652751691296897789.0,
        32238195734329339946437501907836945765883352399886.0,
        75506164965184775180738168837861091527357929701337.0,
        62177842752192623401942399639168044983993173312731.0,
        32924185707147349566916674687634660915035914677504.0,
        99518671430235219628894890102423325116913619626622.0,
        73267460800591547471830798392868535206946944540724.0,
        76841822524674417161514036427982273348055556214818.0,
        97142617910342598647204516893989422179826088076852.0,
        87783646182799346313767754307809363333018982642090.0,
        10848802521674670883215120185883543223812876952786.0,
        71329612474782464538636993009049310363619763878039.0,
        62184073572399794223406235393808339651327408011116.0,
        66627891981488087797941876876144230030984490851411.0,
        60661826293682836764744779239180335110989069790714.0,
        85786944089552990653640447425576083659976645795096.0,
        66024396409905389607120198219976047599490197230297.0,
        64913982680032973156037120041377903785566085089252.0,
        16730939319872750275468906903707539413042652315011.0,
        94809377245048795150954100921645863754710598436791.0,
        78639167021187492431995700641917969777599028300699.0,
        15368713711936614952811305876380278410754449733078.0,
        40789923115535562561142322423255033685442488917353.0,
        44889911501440648020369068063960672322193204149535.0,
        41503128880339536053299340368006977710650566631954.0,
        81234880673210146739058568557934581403627822703280.0,
        82616570773948327592232845941706525094512325230608.0,
        22918802058777319719839450180888072429661980811197.0,
        77158542502016545090413245809786882778948721859617.0,
        72107838435069186155435662884062257473692284509516.0,
        20849603980134001723930671666823555245252804609722.0,
        53503534226472524250874054075591789781264330331690.0
    };

    double sum = 0;

    for (double number : data)
        sum += number;

    return std::stoll(std::to_string(sum).substr(0, 10));
}

int64_t Problem_014::solve()
{
    int64_t length, longest = -1, longest_start = -1;
    
    for (int64_t start = 1; start < 1000000; start += 2) {
        length = 0;

        for (int64_t number = start; number != 1; length++)
            number = (number % 2 == 0) ? number / 2 : number * 3 + 1;

        if (length > longest) {
            longest = length;
            longest_start = start;
        }
    }

    return longest_start;
}

int64_t Problem_015::solve()
{
    int64_t paths = 1;

    for (int64_t i = 0; i < 20; i++)
        paths = (paths * (40 - i)) / (i + 1);

    return paths;
}

int64_t Problem_016::solve()
{
    int64_t sum = 0;

    std::string number = std::to_string(std::pow(2, 1000));
    number = number.substr(0, number.find('.'));

    for (char ch : number)
        sum += (int64_t) ch - '0';

    return sum;
}

int64_t Problem_017::solve()
{
    std::string words[] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred",
        "thousand", "and" 
    };

    std::string out;

    for (int64_t number = 1; number <= 1000; number++) {
        int64_t i = number, hundreds = 0, tens = 0;

        if (i == 1000) {
            out.append(words[0]).append(words[28]);
            continue;
        }

        if (i > 99 && i < 1000) {
            while (i > 99) {
                hundreds++;
                i -= 100;
            }

            out.append(words[hundreds - 1]).append(words[27]);

            if (i > 0)
                out.append(words[29]);
        }

        if (i > 19 && i < 100) {
            while (i > 19) {
                tens++;
                i -= 10;
            }

            out.append(words[tens + 18]);
            i -= 10;
        }

        if (i > 10 && i < 20)
            out.append(words[i - 1]);

        if (i == 10)
            out.append(words[9]);

        if (i > 0 && i < 10)
            out.append(words[i - 1]);
    }

    return out.length();
}

int64_t Problem_018::solve()
{
    int64_t triangle[PROBLEM_018_TRIANGLE_SIZE][PROBLEM_018_TRIANGLE_SIZE] = {
        { 75 },
        { 95, 64 },
        { 17, 47, 82 },
        { 18, 35, 87, 10 },
        { 20,  4, 82, 47, 65 },
        { 19,  1, 23, 75,  3, 34 }, 
        { 88,  2, 77, 73,  7, 63, 67 },
        { 99, 65,  4, 28,  6, 16, 70, 92 }, 
        { 41, 41, 26, 56, 83, 40, 80, 70, 33 },
        { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 },
        { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 },
        { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 },
        { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 },
        { 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 },
        {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 24 }
    };

    for (int64_t row = PROBLEM_018_TRIANGLE_SIZE - 2; row >= 0; row--)
        for (int64_t column = 0; column <= row; column++)
            triangle[row][column] += std::max(triangle[row + 1][column], triangle[row + 1][column + 1]);

    return triangle[0][0];
}

int64_t Problem_019::solve()
{
    int64_t days_in_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int64_t sundays = 0, days_passed = 0;

    for (int64_t year = 1901; year <= 2000; year++)
    {
        for (int64_t month = 0; month < 12; month++)
        {
            if (days_passed % 7 == 0)
                sundays++;

            days_passed += days_in_months[month];

            if (month == 1 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
                days_passed++;
        }
    }

    return sundays;
}