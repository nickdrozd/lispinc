/* 
	This code is compiler-generated! 
	It may be ugly, but it sure is fast!
	Can you figure out how it works?
	
	https://github.com/nickdrozd/Lisp-C-Compyler
*/

#ifndef COMP_CODE_GUARD
#define COMP_CODE_GUARD

#define COMPILED_CODE_BODY \
val = parse("()\n"); \
defineVar(NAMEOBJ("nil"), val, env); \
val = COMPOBJ(_ENTRY_1, env); \
goto AFTER_LAMBDA_2; \
ENTRY_1: print_info("ENTRY_1"); \
env = COMPENVOBJ(func); \
unev = parse("s\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("s"), env); \
goto CONTINUE; \
AFTER_LAMBDA_2: print_info("AFTER_LAMBDA_2"); \
defineVar(NAMEOBJ("list"), val, env); \
val = COMPOBJ(_ENTRY_3, env); \
goto AFTER_LAMBDA_4; \
ENTRY_3: print_info("ENTRY_3"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_5, env); \
goto AFTER_LAMBDA_6; \
ENTRY_5: print_info("ENTRY_5"); \
env = COMPENVOBJ(func); \
unev = parse("(total rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_10; \
if (isCompound(func)) goto COMPOUND_11; \
COMPILED_12: print_info("COMPILED_12"); \
cont = LABELOBJ(_AFTER_CALL_13); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_11: print_info("COMPOUND_11"); \
cont = LABELOBJ(_AFTER_CALL_13); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_10: print_info("PRIMITIVE_10"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_13: print_info("AFTER_CALL_13"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_7; \
FALSE_BRANCH_8: print_info("FALSE_BRANCH_8"); \
func = lookup(NAMEOBJ("loop"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("add1"), env); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_14; \
if (isCompound(func)) goto COMPOUND_15; \
COMPILED_16: print_info("COMPILED_16"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_15: print_info("COMPOUND_15"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_14: print_info("PRIMITIVE_14"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_17: print_info("AFTER_CALL_17"); \
TRUE_BRANCH_7: print_info("TRUE_BRANCH_7"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_9: print_info("AFTER_IF_9"); \
AFTER_LAMBDA_6: print_info("AFTER_LAMBDA_6"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_18; \
if (isCompound(func)) goto COMPOUND_19; \
COMPILED_20: print_info("COMPILED_20"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_19: print_info("COMPOUND_19"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_18: print_info("PRIMITIVE_18"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_21: print_info("AFTER_CALL_21"); \
AFTER_LAMBDA_4: print_info("AFTER_LAMBDA_4"); \
defineVar(NAMEOBJ("length"), val, env); \
val = COMPOBJ(_ENTRY_22, env); \
goto AFTER_LAMBDA_23; \
ENTRY_22: print_info("ENTRY_22"); \
env = COMPENVOBJ(func); \
unev = parse("(items n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
if (isTrue(val)) goto TRUE_BRANCH_24; \
FALSE_BRANCH_25: print_info("FALSE_BRANCH_25"); \
func = lookup(NAMEOBJ("list-ref"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_27; \
if (isCompound(func)) goto COMPOUND_28; \
COMPILED_29: print_info("COMPILED_29"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_28: print_info("COMPOUND_28"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_27: print_info("PRIMITIVE_27"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_30: print_info("AFTER_CALL_30"); \
TRUE_BRANCH_24: print_info("TRUE_BRANCH_24"); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_IF_26: print_info("AFTER_IF_26"); \
AFTER_LAMBDA_23: print_info("AFTER_LAMBDA_23"); \
defineVar(NAMEOBJ("list-ref"), val, env); \
val = COMPOBJ(_ENTRY_31, env); \
goto AFTER_LAMBDA_32; \
ENTRY_31: print_info("ENTRY_31"); \
env = COMPENVOBJ(func); \
unev = parse("(list1 list2)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_36; \
if (isCompound(func)) goto COMPOUND_37; \
COMPILED_38: print_info("COMPILED_38"); \
cont = LABELOBJ(_AFTER_CALL_39); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_37: print_info("COMPOUND_37"); \
cont = LABELOBJ(_AFTER_CALL_39); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_36: print_info("PRIMITIVE_36"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_39: print_info("AFTER_CALL_39"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_33; \
FALSE_BRANCH_34: print_info("FALSE_BRANCH_34"); \
func = lookup(NAMEOBJ("cons"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("append"), env); \
save(func); \
val = lookup(NAMEOBJ("list2"), env); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_40; \
if (isCompound(func)) goto COMPOUND_41; \
COMPILED_42: print_info("COMPILED_42"); \
cont = LABELOBJ(_AFTER_CALL_43); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_41: print_info("COMPOUND_41"); \
cont = LABELOBJ(_AFTER_CALL_43); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_40: print_info("PRIMITIVE_40"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_43: print_info("AFTER_CALL_43"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
TRUE_BRANCH_33: print_info("TRUE_BRANCH_33"); \
val = lookup(NAMEOBJ("list2"), env); \
goto CONTINUE; \
AFTER_IF_35: print_info("AFTER_IF_35"); \
AFTER_LAMBDA_32: print_info("AFTER_LAMBDA_32"); \
defineVar(NAMEOBJ("append"), val, env); \
val = COMPOBJ(_ENTRY_44, env); \
goto AFTER_LAMBDA_45; \
ENTRY_44: print_info("ENTRY_44"); \
env = COMPENVOBJ(func); \
unev = parse("(items)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_46, env); \
goto AFTER_LAMBDA_47; \
ENTRY_46: print_info("ENTRY_46"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_51; \
if (isCompound(func)) goto COMPOUND_52; \
COMPILED_53: print_info("COMPILED_53"); \
cont = LABELOBJ(_AFTER_CALL_54); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_52: print_info("COMPOUND_52"); \
cont = LABELOBJ(_AFTER_CALL_54); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_51: print_info("PRIMITIVE_51"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_54: print_info("AFTER_CALL_54"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_48; \
FALSE_BRANCH_49: print_info("FALSE_BRANCH_49"); \
func = lookup(NAMEOBJ("loop"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("cons"), env); \
save(func); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_55; \
if (isCompound(func)) goto COMPOUND_56; \
COMPILED_57: print_info("COMPILED_57"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_56: print_info("COMPOUND_56"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_55: print_info("PRIMITIVE_55"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_58: print_info("AFTER_CALL_58"); \
TRUE_BRANCH_48: print_info("TRUE_BRANCH_48"); \
val = lookup(NAMEOBJ("result"), env); \
goto CONTINUE; \
AFTER_IF_50: print_info("AFTER_IF_50"); \
AFTER_LAMBDA_47: print_info("AFTER_LAMBDA_47"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("nil"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_59; \
if (isCompound(func)) goto COMPOUND_60; \
COMPILED_61: print_info("COMPILED_61"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_60: print_info("COMPOUND_60"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_59: print_info("PRIMITIVE_59"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_62: print_info("AFTER_CALL_62"); \
AFTER_LAMBDA_45: print_info("AFTER_LAMBDA_45"); \
defineVar(NAMEOBJ("reverse"), val, env); \
val = COMPOBJ(_ENTRY_63, env); \
goto AFTER_LAMBDA_64; \
ENTRY_63: print_info("ENTRY_63"); \
env = COMPENVOBJ(func); \
unev = parse("(func items)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_65, env); \
goto AFTER_LAMBDA_66; \
ENTRY_65: print_info("ENTRY_65"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_70; \
if (isCompound(func)) goto COMPOUND_71; \
COMPILED_72: print_info("COMPILED_72"); \
cont = LABELOBJ(_AFTER_CALL_73); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_71: print_info("COMPOUND_71"); \
cont = LABELOBJ(_AFTER_CALL_73); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_70: print_info("PRIMITIVE_70"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_73: print_info("AFTER_CALL_73"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_67; \
FALSE_BRANCH_68: print_info("FALSE_BRANCH_68"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("cons"), env); \
save(func); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("func"), env); \
save(func); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_78; \
if (isCompound(func)) goto COMPOUND_79; \
COMPILED_80: print_info("COMPILED_80"); \
cont = LABELOBJ(_AFTER_CALL_81); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_79: print_info("COMPOUND_79"); \
cont = LABELOBJ(_AFTER_CALL_81); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_78: print_info("PRIMITIVE_78"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_81: print_info("AFTER_CALL_81"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_82; \
if (isCompound(func)) goto COMPOUND_83; \
COMPILED_84: print_info("COMPILED_84"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_83: print_info("COMPOUND_83"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_82: print_info("PRIMITIVE_82"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_85: print_info("AFTER_CALL_85"); \
TRUE_BRANCH_67: print_info("TRUE_BRANCH_67"); \
func = lookup(NAMEOBJ("reverse"), env); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_74; \
if (isCompound(func)) goto COMPOUND_75; \
COMPILED_76: print_info("COMPILED_76"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_75: print_info("COMPOUND_75"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_74: print_info("PRIMITIVE_74"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_77: print_info("AFTER_CALL_77"); \
AFTER_IF_69: print_info("AFTER_IF_69"); \
AFTER_LAMBDA_66: print_info("AFTER_LAMBDA_66"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("nil"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_86; \
if (isCompound(func)) goto COMPOUND_87; \
COMPILED_88: print_info("COMPILED_88"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_87: print_info("COMPOUND_87"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_86: print_info("PRIMITIVE_86"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_89: print_info("AFTER_CALL_89"); \
AFTER_LAMBDA_64: print_info("AFTER_LAMBDA_64"); \
defineVar(NAMEOBJ("map"), val, env); \
val = COMPOBJ(_ENTRY_90, env); \
goto AFTER_LAMBDA_91; \
ENTRY_90: print_info("ENTRY_90"); \
env = COMPENVOBJ(func); \
unev = parse("(comb null seq)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_92, env); \
goto AFTER_LAMBDA_93; \
ENTRY_92: print_info("ENTRY_92"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_97; \
if (isCompound(func)) goto COMPOUND_98; \
COMPILED_99: print_info("COMPILED_99"); \
cont = LABELOBJ(_AFTER_CALL_100); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_98: print_info("COMPOUND_98"); \
cont = LABELOBJ(_AFTER_CALL_100); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_97: print_info("PRIMITIVE_97"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_100: print_info("AFTER_CALL_100"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_94; \
FALSE_BRANCH_95: print_info("FALSE_BRANCH_95"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("comb"), env); \
save(func); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_101; \
if (isCompound(func)) goto COMPOUND_102; \
COMPILED_103: print_info("COMPILED_103"); \
cont = LABELOBJ(_AFTER_CALL_104); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_102: print_info("COMPOUND_102"); \
cont = LABELOBJ(_AFTER_CALL_104); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_101: print_info("PRIMITIVE_101"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_104: print_info("AFTER_CALL_104"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_105; \
if (isCompound(func)) goto COMPOUND_106; \
COMPILED_107: print_info("COMPILED_107"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_106: print_info("COMPOUND_106"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_105: print_info("PRIMITIVE_105"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_108: print_info("AFTER_CALL_108"); \
TRUE_BRANCH_94: print_info("TRUE_BRANCH_94"); \
val = lookup(NAMEOBJ("result"), env); \
goto CONTINUE; \
AFTER_IF_96: print_info("AFTER_IF_96"); \
AFTER_LAMBDA_93: print_info("AFTER_LAMBDA_93"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("seq"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("null"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_109; \
if (isCompound(func)) goto COMPOUND_110; \
COMPILED_111: print_info("COMPILED_111"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_110: print_info("COMPOUND_110"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_109: print_info("PRIMITIVE_109"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_112: print_info("AFTER_CALL_112"); \
AFTER_LAMBDA_91: print_info("AFTER_LAMBDA_91"); \
defineVar(NAMEOBJ("fold-left"), val, env); \
val = COMPOBJ(_ENTRY_113, env); \
goto AFTER_LAMBDA_114; \
ENTRY_113: print_info("ENTRY_113"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-left"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("_+_"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_115; \
if (isCompound(func)) goto COMPOUND_116; \
COMPILED_117: print_info("COMPILED_117"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_116: print_info("COMPOUND_116"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_115: print_info("PRIMITIVE_115"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_118: print_info("AFTER_CALL_118"); \
AFTER_LAMBDA_114: print_info("AFTER_LAMBDA_114"); \
defineVar(NAMEOBJ("+"), val, env); \
val = COMPOBJ(_ENTRY_119, env); \
goto AFTER_LAMBDA_120; \
ENTRY_119: print_info("ENTRY_119"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-left"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(1); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("_*_"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_121; \
if (isCompound(func)) goto COMPOUND_122; \
COMPILED_123: print_info("COMPILED_123"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_122: print_info("COMPOUND_122"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_121: print_info("PRIMITIVE_121"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_124: print_info("AFTER_CALL_124"); \
AFTER_LAMBDA_120: print_info("AFTER_LAMBDA_120"); \
defineVar(NAMEOBJ("*"), val, env); \
val = COMPOBJ(_ENTRY_125, env); \
goto AFTER_LAMBDA_126; \
ENTRY_125: print_info("ENTRY_125"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
if (isTrue(val)) goto TRUE_BRANCH_127; \
FALSE_BRANCH_128: print_info("FALSE_BRANCH_128"); \
func = lookup(NAMEOBJ("_*_"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_130; \
if (isCompound(func)) goto COMPOUND_131; \
COMPILED_132: print_info("COMPILED_132"); \
cont = LABELOBJ(_AFTER_CALL_133); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_131: print_info("COMPOUND_131"); \
cont = LABELOBJ(_AFTER_CALL_133); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_130: print_info("PRIMITIVE_130"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_133: print_info("AFTER_CALL_133"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
TRUE_BRANCH_127: print_info("TRUE_BRANCH_127"); \
val = NUMOBJ(1); \
goto CONTINUE; \
AFTER_IF_129: print_info("AFTER_IF_129"); \
AFTER_LAMBDA_126: print_info("AFTER_LAMBDA_126"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_134, env); \
goto AFTER_LAMBDA_135; \
ENTRY_134: print_info("ENTRY_134"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_136, env); \
goto AFTER_LAMBDA_137; \
ENTRY_136: print_info("ENTRY_136"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
if (isTrue(val)) goto TRUE_BRANCH_138; \
FALSE_BRANCH_139: print_info("FALSE_BRANCH_139"); \
func = lookup(NAMEOBJ("loop"), env); \
save(func); \
func = lookup(NAMEOBJ("_*_"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, arglist); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_141; \
if (isCompound(func)) goto COMPOUND_142; \
COMPILED_143: print_info("COMPILED_143"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_142: print_info("COMPOUND_142"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_141: print_info("PRIMITIVE_141"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_144: print_info("AFTER_CALL_144"); \
TRUE_BRANCH_138: print_info("TRUE_BRANCH_138"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_140: print_info("AFTER_IF_140"); \
AFTER_LAMBDA_137: print_info("AFTER_LAMBDA_137"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_145; \
if (isCompound(func)) goto COMPOUND_146; \
COMPILED_147: print_info("COMPILED_147"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_146: print_info("COMPOUND_146"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_145: print_info("PRIMITIVE_145"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_148: print_info("AFTER_CALL_148"); \
AFTER_LAMBDA_135: print_info("AFTER_LAMBDA_135"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_149, env); \
goto AFTER_LAMBDA_150; \
ENTRY_149: print_info("ENTRY_149"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("<"), env); \
val = NUMOBJ(2); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
val = applyPrimitive(func, arglist); \
if (isTrue(val)) goto TRUE_BRANCH_151; \
FALSE_BRANCH_152: print_info("FALSE_BRANCH_152"); \
func = lookup(NAMEOBJ("_+_"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_fibonacci_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(2); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_158; \
if (isCompound(func)) goto COMPOUND_159; \
COMPILED_160: print_info("COMPILED_160"); \
cont = LABELOBJ(_AFTER_CALL_161); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_159: print_info("COMPOUND_159"); \
cont = LABELOBJ(_AFTER_CALL_161); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_158: print_info("PRIMITIVE_158"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_161: print_info("AFTER_CALL_161"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_fibonacci_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_154; \
if (isCompound(func)) goto COMPOUND_155; \
COMPILED_156: print_info("COMPILED_156"); \
cont = LABELOBJ(_AFTER_CALL_157); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_155: print_info("COMPOUND_155"); \
cont = LABELOBJ(_AFTER_CALL_157); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_154: print_info("PRIMITIVE_154"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_157: print_info("AFTER_CALL_157"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
TRUE_BRANCH_151: print_info("TRUE_BRANCH_151"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
AFTER_IF_153: print_info("AFTER_IF_153"); \
AFTER_LAMBDA_150: print_info("AFTER_LAMBDA_150"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_162, env); \
goto AFTER_LAMBDA_163; \
ENTRY_162: print_info("ENTRY_162"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_164, env); \
goto AFTER_LAMBDA_165; \
ENTRY_164: print_info("ENTRY_164"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
if (isTrue(val)) goto TRUE_BRANCH_166; \
FALSE_BRANCH_167: print_info("FALSE_BRANCH_167"); \
func = lookup(NAMEOBJ("loop"), env); \
save(func); \
func = lookup(NAMEOBJ("_+_"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("a"), env); \
arglist = CONS(val, arglist); \
val = applyPrimitive(func, arglist); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, arglist); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = applyPrimitive(func, arglist); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_169; \
if (isCompound(func)) goto COMPOUND_170; \
COMPILED_171: print_info("COMPILED_171"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_170: print_info("COMPOUND_170"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_169: print_info("PRIMITIVE_169"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_172: print_info("AFTER_CALL_172"); \
TRUE_BRANCH_166: print_info("TRUE_BRANCH_166"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
AFTER_IF_168: print_info("AFTER_IF_168"); \
AFTER_LAMBDA_165: print_info("AFTER_LAMBDA_165"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_173; \
if (isCompound(func)) goto COMPOUND_174; \
COMPILED_175: print_info("COMPILED_175"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_174: print_info("COMPOUND_174"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_173: print_info("PRIMITIVE_173"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_176: print_info("AFTER_CALL_176"); \
AFTER_LAMBDA_163: print_info("AFTER_LAMBDA_163"); \
defineVar(NAMEOBJ("iterative_fibonacci_compiled"), val, env); \
val = lookup(NAMEOBJ("iterative_factorial_compiled"), env); \
defineVar(NAMEOBJ("factorial"), val, env); \
val = lookup(NAMEOBJ("iterative_fibonacci_compiled"), env); \
defineVar(NAMEOBJ("fibonacci"), val, env); \
goto DONE;

#define COMP_CONT(REG) \
if (GETLABEL(REG) == _ENTRY_1) goto ENTRY_1; \
if (GETLABEL(REG) == _AFTER_LAMBDA_2) goto AFTER_LAMBDA_2; \
if (GETLABEL(REG) == _ENTRY_3) goto ENTRY_3; \
if (GETLABEL(REG) == _AFTER_LAMBDA_4) goto AFTER_LAMBDA_4; \
if (GETLABEL(REG) == _ENTRY_5) goto ENTRY_5; \
if (GETLABEL(REG) == _AFTER_LAMBDA_6) goto AFTER_LAMBDA_6; \
if (GETLABEL(REG) == _TRUE_BRANCH_7) goto TRUE_BRANCH_7; \
if (GETLABEL(REG) == _FALSE_BRANCH_8) goto FALSE_BRANCH_8; \
if (GETLABEL(REG) == _AFTER_IF_9) goto AFTER_IF_9; \
if (GETLABEL(REG) == _PRIMITIVE_10) goto PRIMITIVE_10; \
if (GETLABEL(REG) == _COMPOUND_11) goto COMPOUND_11; \
if (GETLABEL(REG) == _COMPILED_12) goto COMPILED_12; \
if (GETLABEL(REG) == _AFTER_CALL_13) goto AFTER_CALL_13; \
if (GETLABEL(REG) == _PRIMITIVE_14) goto PRIMITIVE_14; \
if (GETLABEL(REG) == _COMPOUND_15) goto COMPOUND_15; \
if (GETLABEL(REG) == _COMPILED_16) goto COMPILED_16; \
if (GETLABEL(REG) == _AFTER_CALL_17) goto AFTER_CALL_17; \
if (GETLABEL(REG) == _PRIMITIVE_18) goto PRIMITIVE_18; \
if (GETLABEL(REG) == _COMPOUND_19) goto COMPOUND_19; \
if (GETLABEL(REG) == _COMPILED_20) goto COMPILED_20; \
if (GETLABEL(REG) == _AFTER_CALL_21) goto AFTER_CALL_21; \
if (GETLABEL(REG) == _ENTRY_22) goto ENTRY_22; \
if (GETLABEL(REG) == _AFTER_LAMBDA_23) goto AFTER_LAMBDA_23; \
if (GETLABEL(REG) == _TRUE_BRANCH_24) goto TRUE_BRANCH_24; \
if (GETLABEL(REG) == _FALSE_BRANCH_25) goto FALSE_BRANCH_25; \
if (GETLABEL(REG) == _AFTER_IF_26) goto AFTER_IF_26; \
if (GETLABEL(REG) == _PRIMITIVE_27) goto PRIMITIVE_27; \
if (GETLABEL(REG) == _COMPOUND_28) goto COMPOUND_28; \
if (GETLABEL(REG) == _COMPILED_29) goto COMPILED_29; \
if (GETLABEL(REG) == _AFTER_CALL_30) goto AFTER_CALL_30; \
if (GETLABEL(REG) == _ENTRY_31) goto ENTRY_31; \
if (GETLABEL(REG) == _AFTER_LAMBDA_32) goto AFTER_LAMBDA_32; \
if (GETLABEL(REG) == _TRUE_BRANCH_33) goto TRUE_BRANCH_33; \
if (GETLABEL(REG) == _FALSE_BRANCH_34) goto FALSE_BRANCH_34; \
if (GETLABEL(REG) == _AFTER_IF_35) goto AFTER_IF_35; \
if (GETLABEL(REG) == _PRIMITIVE_36) goto PRIMITIVE_36; \
if (GETLABEL(REG) == _COMPOUND_37) goto COMPOUND_37; \
if (GETLABEL(REG) == _COMPILED_38) goto COMPILED_38; \
if (GETLABEL(REG) == _AFTER_CALL_39) goto AFTER_CALL_39; \
if (GETLABEL(REG) == _PRIMITIVE_40) goto PRIMITIVE_40; \
if (GETLABEL(REG) == _COMPOUND_41) goto COMPOUND_41; \
if (GETLABEL(REG) == _COMPILED_42) goto COMPILED_42; \
if (GETLABEL(REG) == _AFTER_CALL_43) goto AFTER_CALL_43; \
if (GETLABEL(REG) == _ENTRY_44) goto ENTRY_44; \
if (GETLABEL(REG) == _AFTER_LAMBDA_45) goto AFTER_LAMBDA_45; \
if (GETLABEL(REG) == _ENTRY_46) goto ENTRY_46; \
if (GETLABEL(REG) == _AFTER_LAMBDA_47) goto AFTER_LAMBDA_47; \
if (GETLABEL(REG) == _TRUE_BRANCH_48) goto TRUE_BRANCH_48; \
if (GETLABEL(REG) == _FALSE_BRANCH_49) goto FALSE_BRANCH_49; \
if (GETLABEL(REG) == _AFTER_IF_50) goto AFTER_IF_50; \
if (GETLABEL(REG) == _PRIMITIVE_51) goto PRIMITIVE_51; \
if (GETLABEL(REG) == _COMPOUND_52) goto COMPOUND_52; \
if (GETLABEL(REG) == _COMPILED_53) goto COMPILED_53; \
if (GETLABEL(REG) == _AFTER_CALL_54) goto AFTER_CALL_54; \
if (GETLABEL(REG) == _PRIMITIVE_55) goto PRIMITIVE_55; \
if (GETLABEL(REG) == _COMPOUND_56) goto COMPOUND_56; \
if (GETLABEL(REG) == _COMPILED_57) goto COMPILED_57; \
if (GETLABEL(REG) == _AFTER_CALL_58) goto AFTER_CALL_58; \
if (GETLABEL(REG) == _PRIMITIVE_59) goto PRIMITIVE_59; \
if (GETLABEL(REG) == _COMPOUND_60) goto COMPOUND_60; \
if (GETLABEL(REG) == _COMPILED_61) goto COMPILED_61; \
if (GETLABEL(REG) == _AFTER_CALL_62) goto AFTER_CALL_62; \
if (GETLABEL(REG) == _ENTRY_63) goto ENTRY_63; \
if (GETLABEL(REG) == _AFTER_LAMBDA_64) goto AFTER_LAMBDA_64; \
if (GETLABEL(REG) == _ENTRY_65) goto ENTRY_65; \
if (GETLABEL(REG) == _AFTER_LAMBDA_66) goto AFTER_LAMBDA_66; \
if (GETLABEL(REG) == _TRUE_BRANCH_67) goto TRUE_BRANCH_67; \
if (GETLABEL(REG) == _FALSE_BRANCH_68) goto FALSE_BRANCH_68; \
if (GETLABEL(REG) == _AFTER_IF_69) goto AFTER_IF_69; \
if (GETLABEL(REG) == _PRIMITIVE_70) goto PRIMITIVE_70; \
if (GETLABEL(REG) == _COMPOUND_71) goto COMPOUND_71; \
if (GETLABEL(REG) == _COMPILED_72) goto COMPILED_72; \
if (GETLABEL(REG) == _AFTER_CALL_73) goto AFTER_CALL_73; \
if (GETLABEL(REG) == _PRIMITIVE_74) goto PRIMITIVE_74; \
if (GETLABEL(REG) == _COMPOUND_75) goto COMPOUND_75; \
if (GETLABEL(REG) == _COMPILED_76) goto COMPILED_76; \
if (GETLABEL(REG) == _AFTER_CALL_77) goto AFTER_CALL_77; \
if (GETLABEL(REG) == _PRIMITIVE_78) goto PRIMITIVE_78; \
if (GETLABEL(REG) == _COMPOUND_79) goto COMPOUND_79; \
if (GETLABEL(REG) == _COMPILED_80) goto COMPILED_80; \
if (GETLABEL(REG) == _AFTER_CALL_81) goto AFTER_CALL_81; \
if (GETLABEL(REG) == _PRIMITIVE_82) goto PRIMITIVE_82; \
if (GETLABEL(REG) == _COMPOUND_83) goto COMPOUND_83; \
if (GETLABEL(REG) == _COMPILED_84) goto COMPILED_84; \
if (GETLABEL(REG) == _AFTER_CALL_85) goto AFTER_CALL_85; \
if (GETLABEL(REG) == _PRIMITIVE_86) goto PRIMITIVE_86; \
if (GETLABEL(REG) == _COMPOUND_87) goto COMPOUND_87; \
if (GETLABEL(REG) == _COMPILED_88) goto COMPILED_88; \
if (GETLABEL(REG) == _AFTER_CALL_89) goto AFTER_CALL_89; \
if (GETLABEL(REG) == _ENTRY_90) goto ENTRY_90; \
if (GETLABEL(REG) == _AFTER_LAMBDA_91) goto AFTER_LAMBDA_91; \
if (GETLABEL(REG) == _ENTRY_92) goto ENTRY_92; \
if (GETLABEL(REG) == _AFTER_LAMBDA_93) goto AFTER_LAMBDA_93; \
if (GETLABEL(REG) == _TRUE_BRANCH_94) goto TRUE_BRANCH_94; \
if (GETLABEL(REG) == _FALSE_BRANCH_95) goto FALSE_BRANCH_95; \
if (GETLABEL(REG) == _AFTER_IF_96) goto AFTER_IF_96; \
if (GETLABEL(REG) == _PRIMITIVE_97) goto PRIMITIVE_97; \
if (GETLABEL(REG) == _COMPOUND_98) goto COMPOUND_98; \
if (GETLABEL(REG) == _COMPILED_99) goto COMPILED_99; \
if (GETLABEL(REG) == _AFTER_CALL_100) goto AFTER_CALL_100; \
if (GETLABEL(REG) == _PRIMITIVE_101) goto PRIMITIVE_101; \
if (GETLABEL(REG) == _COMPOUND_102) goto COMPOUND_102; \
if (GETLABEL(REG) == _COMPILED_103) goto COMPILED_103; \
if (GETLABEL(REG) == _AFTER_CALL_104) goto AFTER_CALL_104; \
if (GETLABEL(REG) == _PRIMITIVE_105) goto PRIMITIVE_105; \
if (GETLABEL(REG) == _COMPOUND_106) goto COMPOUND_106; \
if (GETLABEL(REG) == _COMPILED_107) goto COMPILED_107; \
if (GETLABEL(REG) == _AFTER_CALL_108) goto AFTER_CALL_108; \
if (GETLABEL(REG) == _PRIMITIVE_109) goto PRIMITIVE_109; \
if (GETLABEL(REG) == _COMPOUND_110) goto COMPOUND_110; \
if (GETLABEL(REG) == _COMPILED_111) goto COMPILED_111; \
if (GETLABEL(REG) == _AFTER_CALL_112) goto AFTER_CALL_112; \
if (GETLABEL(REG) == _ENTRY_113) goto ENTRY_113; \
if (GETLABEL(REG) == _AFTER_LAMBDA_114) goto AFTER_LAMBDA_114; \
if (GETLABEL(REG) == _PRIMITIVE_115) goto PRIMITIVE_115; \
if (GETLABEL(REG) == _COMPOUND_116) goto COMPOUND_116; \
if (GETLABEL(REG) == _COMPILED_117) goto COMPILED_117; \
if (GETLABEL(REG) == _AFTER_CALL_118) goto AFTER_CALL_118; \
if (GETLABEL(REG) == _ENTRY_119) goto ENTRY_119; \
if (GETLABEL(REG) == _AFTER_LAMBDA_120) goto AFTER_LAMBDA_120; \
if (GETLABEL(REG) == _PRIMITIVE_121) goto PRIMITIVE_121; \
if (GETLABEL(REG) == _COMPOUND_122) goto COMPOUND_122; \
if (GETLABEL(REG) == _COMPILED_123) goto COMPILED_123; \
if (GETLABEL(REG) == _AFTER_CALL_124) goto AFTER_CALL_124; \
if (GETLABEL(REG) == _ENTRY_125) goto ENTRY_125; \
if (GETLABEL(REG) == _AFTER_LAMBDA_126) goto AFTER_LAMBDA_126; \
if (GETLABEL(REG) == _TRUE_BRANCH_127) goto TRUE_BRANCH_127; \
if (GETLABEL(REG) == _FALSE_BRANCH_128) goto FALSE_BRANCH_128; \
if (GETLABEL(REG) == _AFTER_IF_129) goto AFTER_IF_129; \
if (GETLABEL(REG) == _PRIMITIVE_130) goto PRIMITIVE_130; \
if (GETLABEL(REG) == _COMPOUND_131) goto COMPOUND_131; \
if (GETLABEL(REG) == _COMPILED_132) goto COMPILED_132; \
if (GETLABEL(REG) == _AFTER_CALL_133) goto AFTER_CALL_133; \
if (GETLABEL(REG) == _ENTRY_134) goto ENTRY_134; \
if (GETLABEL(REG) == _AFTER_LAMBDA_135) goto AFTER_LAMBDA_135; \
if (GETLABEL(REG) == _ENTRY_136) goto ENTRY_136; \
if (GETLABEL(REG) == _AFTER_LAMBDA_137) goto AFTER_LAMBDA_137; \
if (GETLABEL(REG) == _TRUE_BRANCH_138) goto TRUE_BRANCH_138; \
if (GETLABEL(REG) == _FALSE_BRANCH_139) goto FALSE_BRANCH_139; \
if (GETLABEL(REG) == _AFTER_IF_140) goto AFTER_IF_140; \
if (GETLABEL(REG) == _PRIMITIVE_141) goto PRIMITIVE_141; \
if (GETLABEL(REG) == _COMPOUND_142) goto COMPOUND_142; \
if (GETLABEL(REG) == _COMPILED_143) goto COMPILED_143; \
if (GETLABEL(REG) == _AFTER_CALL_144) goto AFTER_CALL_144; \
if (GETLABEL(REG) == _PRIMITIVE_145) goto PRIMITIVE_145; \
if (GETLABEL(REG) == _COMPOUND_146) goto COMPOUND_146; \
if (GETLABEL(REG) == _COMPILED_147) goto COMPILED_147; \
if (GETLABEL(REG) == _AFTER_CALL_148) goto AFTER_CALL_148; \
if (GETLABEL(REG) == _ENTRY_149) goto ENTRY_149; \
if (GETLABEL(REG) == _AFTER_LAMBDA_150) goto AFTER_LAMBDA_150; \
if (GETLABEL(REG) == _TRUE_BRANCH_151) goto TRUE_BRANCH_151; \
if (GETLABEL(REG) == _FALSE_BRANCH_152) goto FALSE_BRANCH_152; \
if (GETLABEL(REG) == _AFTER_IF_153) goto AFTER_IF_153; \
if (GETLABEL(REG) == _PRIMITIVE_154) goto PRIMITIVE_154; \
if (GETLABEL(REG) == _COMPOUND_155) goto COMPOUND_155; \
if (GETLABEL(REG) == _COMPILED_156) goto COMPILED_156; \
if (GETLABEL(REG) == _AFTER_CALL_157) goto AFTER_CALL_157; \
if (GETLABEL(REG) == _PRIMITIVE_158) goto PRIMITIVE_158; \
if (GETLABEL(REG) == _COMPOUND_159) goto COMPOUND_159; \
if (GETLABEL(REG) == _COMPILED_160) goto COMPILED_160; \
if (GETLABEL(REG) == _AFTER_CALL_161) goto AFTER_CALL_161; \
if (GETLABEL(REG) == _ENTRY_162) goto ENTRY_162; \
if (GETLABEL(REG) == _AFTER_LAMBDA_163) goto AFTER_LAMBDA_163; \
if (GETLABEL(REG) == _ENTRY_164) goto ENTRY_164; \
if (GETLABEL(REG) == _AFTER_LAMBDA_165) goto AFTER_LAMBDA_165; \
if (GETLABEL(REG) == _TRUE_BRANCH_166) goto TRUE_BRANCH_166; \
if (GETLABEL(REG) == _FALSE_BRANCH_167) goto FALSE_BRANCH_167; \
if (GETLABEL(REG) == _AFTER_IF_168) goto AFTER_IF_168; \
if (GETLABEL(REG) == _PRIMITIVE_169) goto PRIMITIVE_169; \
if (GETLABEL(REG) == _COMPOUND_170) goto COMPOUND_170; \
if (GETLABEL(REG) == _COMPILED_171) goto COMPILED_171; \
if (GETLABEL(REG) == _AFTER_CALL_172) goto AFTER_CALL_172; \
if (GETLABEL(REG) == _PRIMITIVE_173) goto PRIMITIVE_173; \
if (GETLABEL(REG) == _COMPOUND_174) goto COMPOUND_174; \
if (GETLABEL(REG) == _COMPILED_175) goto COMPILED_175; \
if (GETLABEL(REG) == _AFTER_CALL_176) goto AFTER_CALL_176;

#define ALL_COMPILED_LABELS \
_ENTRY_1, \
_AFTER_LAMBDA_2, \
_ENTRY_3, \
_AFTER_LAMBDA_4, \
_ENTRY_5, \
_AFTER_LAMBDA_6, \
_TRUE_BRANCH_7, \
_FALSE_BRANCH_8, \
_AFTER_IF_9, \
_PRIMITIVE_10, \
_COMPOUND_11, \
_COMPILED_12, \
_AFTER_CALL_13, \
_PRIMITIVE_14, \
_COMPOUND_15, \
_COMPILED_16, \
_AFTER_CALL_17, \
_PRIMITIVE_18, \
_COMPOUND_19, \
_COMPILED_20, \
_AFTER_CALL_21, \
_ENTRY_22, \
_AFTER_LAMBDA_23, \
_TRUE_BRANCH_24, \
_FALSE_BRANCH_25, \
_AFTER_IF_26, \
_PRIMITIVE_27, \
_COMPOUND_28, \
_COMPILED_29, \
_AFTER_CALL_30, \
_ENTRY_31, \
_AFTER_LAMBDA_32, \
_TRUE_BRANCH_33, \
_FALSE_BRANCH_34, \
_AFTER_IF_35, \
_PRIMITIVE_36, \
_COMPOUND_37, \
_COMPILED_38, \
_AFTER_CALL_39, \
_PRIMITIVE_40, \
_COMPOUND_41, \
_COMPILED_42, \
_AFTER_CALL_43, \
_ENTRY_44, \
_AFTER_LAMBDA_45, \
_ENTRY_46, \
_AFTER_LAMBDA_47, \
_TRUE_BRANCH_48, \
_FALSE_BRANCH_49, \
_AFTER_IF_50, \
_PRIMITIVE_51, \
_COMPOUND_52, \
_COMPILED_53, \
_AFTER_CALL_54, \
_PRIMITIVE_55, \
_COMPOUND_56, \
_COMPILED_57, \
_AFTER_CALL_58, \
_PRIMITIVE_59, \
_COMPOUND_60, \
_COMPILED_61, \
_AFTER_CALL_62, \
_ENTRY_63, \
_AFTER_LAMBDA_64, \
_ENTRY_65, \
_AFTER_LAMBDA_66, \
_TRUE_BRANCH_67, \
_FALSE_BRANCH_68, \
_AFTER_IF_69, \
_PRIMITIVE_70, \
_COMPOUND_71, \
_COMPILED_72, \
_AFTER_CALL_73, \
_PRIMITIVE_74, \
_COMPOUND_75, \
_COMPILED_76, \
_AFTER_CALL_77, \
_PRIMITIVE_78, \
_COMPOUND_79, \
_COMPILED_80, \
_AFTER_CALL_81, \
_PRIMITIVE_82, \
_COMPOUND_83, \
_COMPILED_84, \
_AFTER_CALL_85, \
_PRIMITIVE_86, \
_COMPOUND_87, \
_COMPILED_88, \
_AFTER_CALL_89, \
_ENTRY_90, \
_AFTER_LAMBDA_91, \
_ENTRY_92, \
_AFTER_LAMBDA_93, \
_TRUE_BRANCH_94, \
_FALSE_BRANCH_95, \
_AFTER_IF_96, \
_PRIMITIVE_97, \
_COMPOUND_98, \
_COMPILED_99, \
_AFTER_CALL_100, \
_PRIMITIVE_101, \
_COMPOUND_102, \
_COMPILED_103, \
_AFTER_CALL_104, \
_PRIMITIVE_105, \
_COMPOUND_106, \
_COMPILED_107, \
_AFTER_CALL_108, \
_PRIMITIVE_109, \
_COMPOUND_110, \
_COMPILED_111, \
_AFTER_CALL_112, \
_ENTRY_113, \
_AFTER_LAMBDA_114, \
_PRIMITIVE_115, \
_COMPOUND_116, \
_COMPILED_117, \
_AFTER_CALL_118, \
_ENTRY_119, \
_AFTER_LAMBDA_120, \
_PRIMITIVE_121, \
_COMPOUND_122, \
_COMPILED_123, \
_AFTER_CALL_124, \
_ENTRY_125, \
_AFTER_LAMBDA_126, \
_TRUE_BRANCH_127, \
_FALSE_BRANCH_128, \
_AFTER_IF_129, \
_PRIMITIVE_130, \
_COMPOUND_131, \
_COMPILED_132, \
_AFTER_CALL_133, \
_ENTRY_134, \
_AFTER_LAMBDA_135, \
_ENTRY_136, \
_AFTER_LAMBDA_137, \
_TRUE_BRANCH_138, \
_FALSE_BRANCH_139, \
_AFTER_IF_140, \
_PRIMITIVE_141, \
_COMPOUND_142, \
_COMPILED_143, \
_AFTER_CALL_144, \
_PRIMITIVE_145, \
_COMPOUND_146, \
_COMPILED_147, \
_AFTER_CALL_148, \
_ENTRY_149, \
_AFTER_LAMBDA_150, \
_TRUE_BRANCH_151, \
_FALSE_BRANCH_152, \
_AFTER_IF_153, \
_PRIMITIVE_154, \
_COMPOUND_155, \
_COMPILED_156, \
_AFTER_CALL_157, \
_PRIMITIVE_158, \
_COMPOUND_159, \
_COMPILED_160, \
_AFTER_CALL_161, \
_ENTRY_162, \
_AFTER_LAMBDA_163, \
_ENTRY_164, \
_AFTER_LAMBDA_165, \
_TRUE_BRANCH_166, \
_FALSE_BRANCH_167, \
_AFTER_IF_168, \
_PRIMITIVE_169, \
_COMPOUND_170, \
_COMPILED_171, \
_AFTER_CALL_172, \
_PRIMITIVE_173, \
_COMPOUND_174, \
_COMPILED_175, \
_AFTER_CALL_176

#endif
