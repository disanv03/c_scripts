/* define a macro swap(t,x,y) that interchanges two arguments of type t. */o

#define swap(t, x, y) { t _z;   \
                        _z = y; \
                        y = x;  \
                        x = _z; }

/* _z is a local variable of type t that help swap the two arguments */
/* the assumption is that _z will not be used as a variable name */
