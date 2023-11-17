#ifndef BAF85EEF_93BA_446A_848B_5E9DC229331C
#define BAF85EEF_93BA_446A_848B_5E9DC229331C

#include <stdexcept>

class NotImplemented : public std::logic_error
{
public:
    NotImplemented() : std::logic_error("Function not yet implemented") { };
};

#endif /* BAF85EEF_93BA_446A_848B_5E9DC229331C */
