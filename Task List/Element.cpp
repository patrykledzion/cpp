//
// Created by patry on 17.05.2022.
//

#include "Element.h"

void Element::ShowDate() const {
    cout<<this->date.day<<"/"<<this->date.month<<"/"<<this->date.year;
}