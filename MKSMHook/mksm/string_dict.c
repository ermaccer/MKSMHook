#include "string_dict.h"

const char* get_string(int id)
{
    return 	((const char*(*)(int))0x1E6EF0)(id);
}

const char* get_character_name(int id)
{
    return get_string(id + CHARACTER_STRING_START);
}
