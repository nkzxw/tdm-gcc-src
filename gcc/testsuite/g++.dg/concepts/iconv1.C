// PR c++/67240
// { dg-do compile { target c++17 } }
// { dg-options "-fconcepts" }

int foo(int x)
{
    return x;
}
 
template <typename T>
concept bool C1 = requires (T x) {
    {foo(x)} -> int&;
};

template <typename T>
concept bool C2 = requires (T x) {
    {foo(x)} -> void;
};
 
static_assert( C1<int> );	// { dg-error "assert" }
static_assert( C2<int> );	// { dg-error "assert" }
