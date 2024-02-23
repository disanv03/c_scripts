#ifdef macroname
    statement1;
    statement2;
    statement3;
#endif

if **macroname** has been #defined, the block of code will be processed as
usual; otherwise not.


Making hte programs portable, to make them work on two totally different
computers.

int main() {

#ifdef INTEL
    code suitable for an INTEL PC
#else
    code suitable for a Motorola PC
#endif

    code common to both computers
}


Sometimes, instead of #ifdef, the #ifndef directive is used.
The #ifndef (which means 'if not defined') works exactly opposite to #ifdef


int main() {
    #ifndef INTEL
        code suitable for a motorola PC
    #else
        code suitable for an intel PC
    #endif

    here common code for both computers
}

#if ADAPTER == SVGA
    code for video graphics array
#else
    #if ADAPTER == SVGA
        code for super video graphics array
    #else
        code for extended graphics adapter
    #endif
#endif

#if ADAPTER == VGA
    code for video graphics array
#elif ADAPTER == SVGA
    code for super video graphics array
#else
    code for extended graphics array
#endif


