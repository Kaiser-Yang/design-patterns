#ifndef DESIGN_PATTERN_MENU_COMPONENT_H
#define DESIGN_PATTERN_MENU_COMPONENT_H

#include <memory>
#include <stdexcept>
#include <string>

class MenuComponent {
public:
    virtual ~MenuComponent() = default;

    virtual const std::string &getName() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual const std::string &getDescription() const {
        throw std::runtime_error("Unsupported operation");
    }

    virtual double getPrice() const { throw std::runtime_error("Unsupported operation"); }

    virtual bool isVegetarian() const { throw std::runtime_error("Unsupported operation"); }

    virtual void print() const { throw std::runtime_error("Unsupported operation"); }

    virtual void add(const std::shared_ptr<MenuComponent> &menuComponent) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual void remove(const std::shared_ptr<MenuComponent> &menuComponent) {
        throw std::runtime_error("Unsupported operation");
    }

    virtual std::shared_ptr<MenuComponent> getChild(size_t i) const {
        throw std::runtime_error("Unsupported operation");
    }
};

#endif
