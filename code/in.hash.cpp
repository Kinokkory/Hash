#line 0
#include "hash.hpp"
#line 1
template<typename T>
struct A{
    private: typedef A thistype;
    static_assert(hash::is_pod<T>::value,"DOESN'T MATCH TYPE CONDITION");
    static_assert((10)<(20),"DOESN'T MATCH STATIC CONDITION");
    #line 2
    public: A(thistype* x){
    }
    #line 3
    private: virtual ~A(){
    }
    #line 4
    public: T fun(T x, T y){
        #line 5
        return (x)*(y);
    }
};
#line 6
template<typename T>
class XOO;
#line 7
namespace a{
namespace b{
#line 10
enum class X;
#line 12
enum class X :int {
    X1 = 1, X2 = 2, X3 = 4, X4 = 8
};
}
}
#line 15
int main(){
    #line 17
    if(bool x=(true)){
        #line 18
        printf("foo\n");
    }
    #line 18
    typedef int foo;
    #line 19
    ;
    #line 19
    hash::vector<int> x{
        0, 1, 2, 3
    };
    #line 20
    if((static_cast<hash::vector<int>>(x)).size()==3&&true&&true&&((static_cast<hash::vector<int>>(x)).at(2))==1){
        auto& a=((static_cast<hash::vector<int>>(x)).at(0));
        auto& q=((static_cast<hash::vector<int>>(x)).at(1));
        printf("%d", (a)+(q));
    }else if((static_cast<hash::vector<int>>(x)).size()==1&&((static_cast<hash::vector<int>>(x)).at(0))==0){
        printf("foo");
    }else if(true){
        printf("foo");
    }else{
        throw "No Match For Pattern";
    }
    #line 23
    return 0;
}
#line 25
namespace foo{
#line 27
template<typename T, int x>
int f(T y){
    return ((10)+(x))+(--(-(++(+(((((y)++)++)--)--)))));
}
#line 29
typedef int foo;
#line 30
;
}
