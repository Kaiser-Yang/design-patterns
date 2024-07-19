#ifndef DESIGN_PATTERN_ITERATOR_H
#define DESIGN_PATTERN_ITERATOR_H

template <class Item>
class Iterator {
public:
    virtual bool hasNext()     = 0;
    virtual Item &next()       = 0;
    virtual Iterator &remove() = 0;
};

#endif
