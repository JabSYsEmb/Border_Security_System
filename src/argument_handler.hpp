#define ALL_COUNTRY "All"
#define CALC_BORDER "BORDER"

enum c_choice { ALL = 1, SINGLE_COUNTRY }; // all for all countries, Single for a single country
enum t_choice { BORDER = 1, SENSING_CABLE, UNVALID};

void c_handler(std::string* cflag, char* optarg); // c parameter handler
void t_handler(std::string* tflag, char* optarg); // t parameter handler
t_choice enum_calcType_setter(std::string str);
c_choice enum_countries_setter(std::string str);
std::string stringCapitalizer(char* str);

void notISO_A3_Argument(void);

void c_handler(std::string* cflag, char* optarg)
{
    if (optarg) cflag->assign(stringCapitalizer(optarg));

    if (cflag->length() != 3)
    {
        notISO_A3_Argument();
    }	
}

void notISO_A3_Argument(void)
{
    std::cerr << "-c argument should consist of just 3 characters, check if you've entered it correctly." << std::endl;
    return;
}

void t_handler(std::string* tflag, char* optarg)
{
    if (optarg) tflag->assign(stringCapitalizer(optarg));
    else tflag->assign((CALC_BORDER));
}

c_choice enum_countries_setter(std::string str)
{
    c_choice choice;
    if ( str == ALL_COUNTRY ) choice = ALL;
    else choice = SINGLE_COUNTRY;
    return choice;
}

t_choice enum_calcType_setter(std::string str)
{
    t_choice choice;
    if(str == "BORDER") choice = BORDER;
    else if(str == "CABLE") choice = SENSING_CABLE;
    else if(str.size() > 0 && str != "BORDER") choice = UNVALID;
    else choice = BORDER;

    return choice;
}

std::string stringCapitalizer(char* str)
{
    std::string capitalizedString{};
    while(*str != '\0')
    {
        if(*str >= 97)
            *str = *str - 32;
        capitalizedString.push_back(*str);
        ++(str);
    }
    return capitalizedString;
}