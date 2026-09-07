#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
    public:
        Expense(int id, std::string description, double amount, std::string category);  

        int getId() const;
        std::string getDescription() const;
        std::string getCategory() const;
        double getAmount() const;
    
    private:
        int id;
        std::string description;
        double amount;
        std::string category;
};

#endif
