# The Proxy Pattern
In this pattern, we can use `grpc` to implement the example, which is a little tricky. The `grpc`
is a high performance, open source, general RPC framework that puts mobile and HTTP/2 first. It is
based on many years of Google's experience in building distributed systems. It is also applicable
in last mile of distributed computing to connect devices, mobile applications and browsers to
backend services.

The proxy pattern provides a surrogate or placeholder for another object to control access to it.
Use the proxy pattern when you need to create a more sophisticated or intelligent access to an
object than simply exposing its methods. The proxy pattern is also useful when you need to control
access to the object from a remote location, add logging, or perform other tasks.

There are many variants of the proxy pattern, including the following:
* `Remote Proxy`: Controls access to an object that resides in a different address space.
* `Virtual Proxy`: Controls access to an object that is expensive to create.
* `Protection Proxy`: Controls access to an object based on access rights.
* `Cache Proxy`: Provides temporary storage for the results of expensive operations.
* `Smart Proxy`: Provides additional actions whenever an object is accessed, such as the smart
pointer in `C++`.
* `Firewall Proxy`: Protects objects from unauthorized access.
* `Synchronization Proxy`: Provides multithreaded access to an object.
* `Complexity Hiding Proxy`: Hides the complexity of the object from the client.
* `Copy-On-Write Proxy`: Delays copying an object until it is modified.
* `Logging Proxy`: Adds logging to an object.
* ...
