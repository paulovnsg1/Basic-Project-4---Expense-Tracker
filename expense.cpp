#include "expense.h"

Expense::Expense(int id, std::string description, double amount, std::string category) {

    this->id = id;
    this->description = description;
    this->amount = amount;
    this->category = category;
}

int Expense::getId() const{
    return id;
}

std::string Expense::getDescription() const{
    return description;
}

double Expense::getAmount() const{
    return amount;
}

std::string Expense::getCategory() const{
    return category;
}


/*
Expense::Expense(int id, string description, double amount, string category) : id(id), description(description), amount(amount), category(category){}
*/