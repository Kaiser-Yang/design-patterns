# The Singleton Pattern
The single pattern is a easy one, so there is no executable code in this directory.

I'll discuss some differences and similarities between the Singleton Pattern of `C++` and `Java`.

## Single Thread
In single thread, the Singleton Pattern is very simple. The only thing you need to do is to make the constructor private, and provide a static method to get the instance of the class. There is nothing different between `C++` and `Java`.

The `C++` code is like this:

```cpp
class Singleton {
public:
    static std::shared_ptr<Singleton> getInstance() {
        if (instance == nullptr) {
            instance = std::make_shared<Singleton>();
        }
        return instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton(Singleton&&) = default;
    static std::shared_ptr<Singleton> instance;
};
```

But I think you can let the return value's type be a reference. The code is shown below:

```cpp
static Singleton & getInstance() {
    if (instance == nullptr) {
        instance = std::make_shared<Singleton>();
    }
    return *instance;
}
```

## Multi Thread
There are many types of implementations of multi-thread. Let me explain them one by one.

The first one is to use `mutex`. The code is shown below:

```cpp
class Singleton {
public:
    static Singleton & getInstance() {
        std::lock_guard<std::mutex> lock(mu);
        if (instance == nullptr) {
            instance = std::make_shared<Singleton>();
        }
        return *instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton(Singleton&&) = default;
    static std::shared_ptr<Singleton> instance;
    static std::mutex mu;
};
std::mutex Singleton::mu;
std::shared_ptr<Singleton> Singleton::instance;
```

This `mutex` is similar with `Java`. This method will get lock every time you call the `getInstance` method. So it is not efficient.

The second one is to use `double check`. The code is shown below (wrong version):

```cpp
class Singleton {
public:
    static Singleton & getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = std::make_shared<Singleton>();
            }
        }
        return *instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton(Singleton&&) = default;
    static std::shared_ptr<Singleton> instance;
    static std::mutex mutex;
};
std::mutex Singleton::mu;
std::shared_ptr<Singleton> Singleton::instance;
```

This version may be wrong, because the code sequence can be changed by the compiler or the CPU. When creating a variable by the `new` keyword, the sequence is like this:
* Allocate memory
* Call the construction
* Return the pointer

But the compiler or the CPU may change the sequence to:
* Allocate memory
* Return the pointer
* Call the construction

The conversion is OK in single thread, but it is not OK in multi thread. This conversion can let another thread get the pointer not null but have not been constructed. In `Java` (after `Java 5`), you can solve this by adding `volatile` keyword for `instance` variable. But the `volatile` keyword in `C++` is little different with `Java`. The `volatile` keyword in `C++` is used to tell the compiler that the variable may be changed by other threads, so the compiler should not optimize the variable. In `C++`, a volatile-qualified variable will be read from memory every time it is accessed, and written to memory every time it is modified (this keyword is an implementation-dependent modifier, and most implementations do this). But in `Java`, there is something more that the `volatile` keyword insures. The `volatile` keyword in `Java` insures that all the write operations happens before the read operations. In this case, the `volatile` keyword in `Java` will insure that the construction happens before the return operation. But in `C++`, the `volatile` keyword can not insure that. The right way to solve this problem is to use `std::atomic`:

```cpp
class Singleton {
public:
    static Singleton & getInstance() {
        if (instance.load(std::memory_order_relaxed) == nullptr) {
            std::lock_guard<std::mutex> lock(mu);
            if (instance.load() == nullptr) {
                instance.store(new Singleton(), std::memory_order_relaxed);
            }
        }
        return *instance.load(std::memory_order_relaxed);
    }

private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton(Singleton&&) = default;
    ~Singleton() { delete instance.load(std::memory_order_relaxed); }
    static std::atomic<Singleton *> instance;
    static std::mutex mu;
};
std::mutex Singleton::mu;
std::atomic<Singleton *> Singleton::instance;
```

The `std::atomic` make the creation of the instance atomic. The `std::atomic` not only can be used to make the operation atomic, but also can be used to insure the order of the operations. In this case we only need to insure the atomicity of the operation, so we use `std::memory_order_relaxed`, which means we don't care about the memory order.

NOTE: The `std::memory_order_relaxed` is used to tell the compiler that the order of the operations is not important. The `std::memory_order_relaxed` is the most efficient one. If you want to insure the order of the operations, you can use `std::memory_order_acquire` and `std::memory_order_release`. The `std::memory_order_acquire` is used to insure that the operations before the `std::memory_order_acquire` will be executed before the `std::memory_order_acquire`. The `std::memory_order_release` is used to insure that the operations after the `std::memory_order_release` will be executed after the `std::memory_order_release`.

A little tricky, right? There is a simple one from `C++ 11`:

```cop
class Singleton {
public:
    static Singleton & getInstance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton&) = default;
    Singleton(Singleton&&) = default;
};
```

From `C++ 11` the creation of a static local variable is thread safe. The `instance` will be created only once, and the `instance` will be destroyed when the program ends.
