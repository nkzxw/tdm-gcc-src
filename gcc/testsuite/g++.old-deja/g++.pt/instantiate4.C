// { dg-do link }
// { dg-options "-frepo" }
// { dg-require-host-local "" }
// { dg-skip-if "dkms are not final links" { vxworks_kernel } }
// { dg-warning "is deprecated and will be removed in a future release" "" { target *-*-* } 0 }


// Submitted by Melissa O'Neill <oneill@cs.sfu.ca>
// the vtable of Foo<int> wouldn't be generated

template <typename A>
struct Foo {
   virtual void foo() {}
};

template <typename A>
struct Bar {   
   void bar();
};

template <typename A> 
void Bar<A>::bar() {
   Foo<A> oof;
}

int main () {
    Bar<int> rab;
    
    rab.bar();
}

// { dg-final { cleanup-repo-files } }
