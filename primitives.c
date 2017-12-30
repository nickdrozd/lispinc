#include "primitives.h"

/* PRIMITIVE FUNCTIONS DEFINED */

/* primitive type-checking */

Obj isnumber_func(Obj obj) { return BOOLOBJ(GETTAG(obj) == NUM); }

oneArgFunc isnumber_ = isnumber_func;

Obj islist_func(Obj obj) { return BOOLOBJ(GETTAG(obj) == LIST); }

oneArgFunc islist_ = islist_func;

Obj isbool_func(Obj obj) { return BOOLOBJ(GETTAG(obj) == BOOL_); }

oneArgFunc isbool_ = isbool_func;

Obj issymbol_func(Obj obj) { return BOOLOBJ(GETTAG(obj) == NAME); }

oneArgFunc issymbol_ = issymbol_func;

// null? returns false for non-list objects
Obj null_func(Obj obj) {
    bool isList = GETTAG(obj) == LIST;

    if (!isList) return FALSEOBJ;

    bool isNull = GETLIST(obj) == NULL;

    return BOOLOBJ(isNull);
}

oneArgFunc null_ = null_func;

/* primitive list functions
(not to be confused with the list
macros found in objects.h!) */

/* car and cdr both do simple error-checking */

Obj car_func(Obj obj) {
    if (!(GETTAG(obj) == LIST)) {
        print_error_message(LIST, "car");
        return ERROROBJ;
    }

    List* list = GETLIST(obj);

    if (list == NULL) {
        print_error_message(LIST, "car");
        return ERROROBJ;
    } else
        return list->car;
}

Obj cdr_func(Obj obj) {
    if (!(GETTAG(obj) == LIST)) {
        print_error_message(LIST, "cdr");
        return ERROROBJ;
    }

    List* list = GETLIST(obj);

    // cdr of empty list is empty list
    if (list == NULL)
        return NULLOBJ;
    else
        return LISTOBJ(list->cdr);
}

Obj setcar_func(Obj obj, Obj carval) {
    if (GETTAG(obj) != LIST) {
        print_error_message(LIST, "set-car!");
        return ERROROBJ;
    }

    List* list = GETLIST(obj);

    if (list == NULL) {
        print_error_message(LIST, "set-car!");
        return ERROROBJ;
    } else {
        list->car = carval;
        return LISTOBJ(list);
    }
}

Obj setcdr_func(Obj obj, Obj cdrval) {
    if (GETTAG(obj) != LIST || GETTAG(cdrval) != LIST) {
        print_error_message(LIST, "set-cdr!");
        return ERROROBJ;
    }

    List* list = GETLIST(obj);

    if (list == NULL) {
        print_error_message(LIST, "set-cdr!");
        return ERROROBJ;
    } else {
        list->cdr = GETLIST(cdrval);
        return LISTOBJ(list);
    }
}

Obj cadr_func(Obj obj) { return car_func(cdr_func(obj)); }

Obj cddr_func(Obj obj) { return cdr_func(cdr_func(obj)); }

Obj cdadr_func(Obj obj) { return cdr_func(cadr_func(obj)); }

Obj caddr_func(Obj obj) { return car_func(cddr_func(obj)); }

Obj cdddr_func(Obj obj) { return cdr_func(cddr_func(obj)); }

Obj cadddr_func(Obj obj) { return car_func(cdddr_func(obj)); }

// is there a faster way to do this?
oneArgFunc car_ = car_func;
oneArgFunc cdr_ = cdr_func;

twoArgFunc setcar_ = setcar_func;
twoArgFunc setcdr_ = setcdr_func;

oneArgFunc cadr_ = cadr_func;
oneArgFunc cddr_ = cddr_func;
oneArgFunc cdadr_ = cdadr_func;
oneArgFunc caddr_ = caddr_func;
oneArgFunc cdddr_ = cdddr_func;
oneArgFunc cadddr_ = cadddr_func;

/* second object MUST BE list. if it isn't
a list, it will be coerced to a one-item list */
Obj cons_func(Obj car, Obj cdr) {
    int isList = GETTAG(cdr) == LIST;

    if (!isList) {
        printf("%s\n", "Second arg not a list! Converting to one-item list...");
        List* listcdr = makeList(cdr, NULL);
        return LISTOBJ(makeList(car, listcdr));
    } else
        return LISTOBJ(makeList(car, GETLIST(cdr)));
}

twoArgFunc cons_ = cons_func;

/* primitive arithmetic */

Obj add_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, ADD_NAME);
        return ERROROBJ;
    }
    return NUMOBJ(GETNUM(a) + GETNUM(b));
}

Obj sub_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, "-");
        return ERROROBJ;
    }
    return NUMOBJ(GETNUM(a) - GETNUM(b));
}

Obj mul_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, MUL_NAME);
        return ERROROBJ;
    }
    return NUMOBJ(GETNUM(a) * GETNUM(b));
}

Obj div_func(Obj a, Obj b) {  // floor division
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, "/");
        return ERROROBJ;
    }
    return NUMOBJ(GETNUM(a) / GETNUM(b));
}

Obj addone_func(Obj a) { return add_func(a, ONEOBJ); }

Obj subone_func(Obj a) { return sub_func(a, ONEOBJ); }

twoArgFunc add_ = add_func;
twoArgFunc sub_ = sub_func;
twoArgFunc mul_ = mul_func;
twoArgFunc div_ = div_func;
oneArgFunc addone_ = addone_func;
oneArgFunc subone_ = subone_func;

/* boolean functions */

// (not 0) and (not '()) return #t -- desirable?
Obj not_func(Obj expr) {
    if (GETBOOL(expr) != 0)
        return FALSEOBJ;
    else
        return TRUEOBJ;
}

Obj eq_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, "=");
        return ERROROBJ;
    }
    return BOOLOBJ(GETNUM(a) == GETNUM(b));
}

Obj lt_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, "<");
        return ERROROBJ;
    }
    return BOOLOBJ(GETNUM(a) < GETNUM(b));
}

Obj gt_func(Obj a, Obj b) {
    if (!are_both_nums(a, b)) {
        print_error_message(NUM, ">");
        return ERROROBJ;
    }
    return BOOLOBJ(GETNUM(a) > GETNUM(b));
}

Obj iszero_func(Obj a) { return eq_func(a, ZEROOBJ); }

Obj isone_func(Obj a) { return eq_func(a, ONEOBJ); }

Obj geneq_func(Obj a, Obj b) {
    Tag tag_a = GETTAG(a);
    Tag tag_b = GETTAG(b);

    if (tag_a != tag_b) return FALSEOBJ;

    // else if a and be have the same type
    switch (tag_a) {
        case NUM:
            return eq_func(a, b);
        case NAME:
            return BOOLOBJ(streq(GETNAME(a), GETNAME(b)));
        case BOOL_:
            return BOOLOBJ(GETBOOL(a) == GETBOOL(b));
        case LIST:
            // pointers to the same list
            return BOOLOBJ(GETLIST(a) == GETLIST(b));
        default:
            return FALSEOBJ;
    }
}

oneArgFunc not_ = not_func;
twoArgFunc eq_ = eq_func;
twoArgFunc lt_ = lt_func;
twoArgFunc gt_ = gt_func;
oneArgFunc iszero_ = iszero_func;
oneArgFunc isone_ = isone_func;
twoArgFunc geneq_ = geneq_func;

/* I/O */

Obj read_func(void) {
    // printf("%s\n", "READ: ");
    get_input();

    if (isIrregular(code)) {
        if (badSyntax(code)) printf("Bad syntax! Try again!\n");
        read_func();
    }

    return parse(code);
}

nilArgFunc read_ = read_func;

Obj display_func(Obj obj) {
    // printf("DISPLAY: ");
    print_obj(obj);
    if (INFO) getchar();

    return obj;
}

oneArgFunc display_ = display_func;

Obj newline_func(void) {
    printf("\n");
    return DUMMYOBJ;
}

nilArgFunc newline_ = newline_func;

Obj error_func(void) {
    printf("Error? Uh-oh!\n");
    return ERROROBJ;
}

nilArgFunc error_ = error_func;

/* error-checking */

// error-checking helper
bool are_both_nums(Obj a, Obj b) {
    return GETTAG(a) == NUM && GETTAG(b) == NUM;
}

void print_error_message(Tag tag, char* source) {
    char* operation_type;

    switch (tag) {
        case NUM:
            operation_type = "Arithmetic";
            break;
        case LIST:
            operation_type = "List";
            break;
        default:
            operation_type = "???";
            break;
    }

    printf("%s operation error from *%s*! Oops!\n", operation_type, source);
}

/* primitive application */

/* if new primitives are added, applyPrimitive
can be extended in an obvious way */
Obj applyPrimitive(Obj func, Obj arglist) {
    Prim prim = func.val.prim;

    primFunc primfunc = prim.func;
    argCount argcount = prim.count;

    if (argcount == NIL) {
        nilArgFunc nilfunc = primfunc.nil;
        return nilfunc();
    }

    Obj arg1 = CAR(arglist);

    if (argcount == ONE) {
        oneArgFunc onefunc = primfunc.one;
        return onefunc(arg1);
    }

    Obj arg2 = CADR(arglist);

    if (argcount == TWO) {
        twoArgFunc twofunc = primfunc.two;
        return twofunc(arg1, arg2);
    }

    return DUMMYOBJ;
}

Obj apply_nil_func(Obj func, Obj arglist) {
    return applyPrimitive(func, arglist);
}

twoArgFunc apply_nil_ = apply_nil_func;

Obj apply_one_func(Obj func, Obj arglist) {
    return applyPrimitive(func, arglist);
}

twoArgFunc apply_one_ = apply_one_func;

Obj apply_two_func(Obj func, Obj arglist) {
    return applyPrimitive(func, arglist);
}

twoArgFunc apply_two_ = apply_two_func;
