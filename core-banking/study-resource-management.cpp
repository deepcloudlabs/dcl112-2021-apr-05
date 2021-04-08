#include <memory>

int fun(){
    int *p = new int(42); // Heap,File,Socket,Connection,... -> Resource
    // doing something important
    // gun() fails -> throws an exception
    delete p;
    return 1; // ✔
}
// Idiom: RAII (Resource Acquisition Is Initialization)
// Resource -> Class -> encapsulates/wraps Resource Life-cycle Management
// C+11 -> shared_ptr -> wraps a pointer
int fun2(){
    // instead of "int *p = new int(42);" // Heap,File,Socket,Connection,... -> Resource
    std::shared_ptr<int> p = std::make_shared<int>(42);
    // doing something important
    // gun() fails -> throws an exception
    return 1; // ✔
}
// fun2() -> 1) return -> success ✔ stack object: ~p() -> delete
//           2) throw -> fails ✘ stack object: ~p() -> delete
