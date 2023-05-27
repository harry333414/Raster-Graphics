#pragma once

#include "../Misc/IPrintable/IPrintable.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Description : public IPrintable {

    private:

        vector<string> lines;

    public:

        Description();
        Description(size_t size);
        Description(string line);
        Description(vector<string> lines);

        Description(const Description& other);
        Description& operator = (const Description& other);

        bool operator == (const Description& other);

        vector<string> getDescription() const;

        void setDescription(const vector<string> description);

        void addToDescription(const string& line);
        
        bool with_description() const;

        const string toString() const override final;

        string& operator [] (size_t index); 
        const string& operator [] (size_t index) const; 

        void print() const override final;

        ~Description() = default;

};