#pragma once

#include "../Type/Type.hpp"

class TypeConverter {

    private:
    
        Type type;

    public:

        TypeConverter();
        TypeConverter(Type type);

        const Type& getType() const;
        
        void setType(Type type);

        const string typeWriteType() const;

        const string typeGetExtension() const;

        ~TypeConverter() = default;

};