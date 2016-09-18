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
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_8; \
if (isCompound(func)) goto COMPOUND_9; \
COMPILED_10: print_info("COMPILED_10"); \
cont = LABELOBJ(_AFTER_CALL_11); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_9: print_info("COMPOUND_9"); \
cont = LABELOBJ(_AFTER_CALL_11); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_8: print_info("PRIMITIVE_8"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_11: print_info("AFTER_CALL_11"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_5; \
FALSE_BRANCH_6: print_info("FALSE_BRANCH_6"); \
func = lookup(NAMEOBJ("add1"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("length"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_12; \
if (isCompound(func)) goto COMPOUND_13; \
COMPILED_14: print_info("COMPILED_14"); \
cont = LABELOBJ(_AFTER_CALL_15); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_13: print_info("COMPOUND_13"); \
cont = LABELOBJ(_AFTER_CALL_15); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_12: print_info("PRIMITIVE_12"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_15: print_info("AFTER_CALL_15"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_16; \
if (isCompound(func)) goto COMPOUND_17; \
COMPILED_18: print_info("COMPILED_18"); \
cont = LABELOBJ(_AFTER_CALL_19); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_17: print_info("COMPOUND_17"); \
cont = LABELOBJ(_AFTER_CALL_19); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_16: print_info("PRIMITIVE_16"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_19: print_info("AFTER_CALL_19"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_20; \
if (isCompound(func)) goto COMPOUND_21; \
COMPILED_22: print_info("COMPILED_22"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_21: print_info("COMPOUND_21"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_20: print_info("PRIMITIVE_20"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_23: print_info("AFTER_CALL_23"); \
TRUE_BRANCH_5: print_info("TRUE_BRANCH_5"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_7: print_info("AFTER_IF_7"); \
AFTER_LAMBDA_4: print_info("AFTER_LAMBDA_4"); \
defineVar(NAMEOBJ("length"), val, env); \
val = COMPOBJ(_ENTRY_24, env); \
goto AFTER_LAMBDA_25; \
ENTRY_24: print_info("ENTRY_24"); \
env = COMPENVOBJ(func); \
unev = parse("(items n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_29; \
if (isCompound(func)) goto COMPOUND_30; \
COMPILED_31: print_info("COMPILED_31"); \
cont = LABELOBJ(_AFTER_CALL_32); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_30: print_info("COMPOUND_30"); \
cont = LABELOBJ(_AFTER_CALL_32); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_29: print_info("PRIMITIVE_29"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_32: print_info("AFTER_CALL_32"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_26; \
FALSE_BRANCH_27: print_info("FALSE_BRANCH_27"); \
func = lookup(NAMEOBJ("list-ref"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_41; \
if (isCompound(func)) goto COMPOUND_42; \
COMPILED_43: print_info("COMPILED_43"); \
cont = LABELOBJ(_AFTER_CALL_44); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_42: print_info("COMPOUND_42"); \
cont = LABELOBJ(_AFTER_CALL_44); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_41: print_info("PRIMITIVE_41"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_44: print_info("AFTER_CALL_44"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_37; \
if (isCompound(func)) goto COMPOUND_38; \
COMPILED_39: print_info("COMPILED_39"); \
cont = LABELOBJ(_AFTER_CALL_40); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_38: print_info("COMPOUND_38"); \
cont = LABELOBJ(_AFTER_CALL_40); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_37: print_info("PRIMITIVE_37"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_40: print_info("AFTER_CALL_40"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_45; \
if (isCompound(func)) goto COMPOUND_46; \
COMPILED_47: print_info("COMPILED_47"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_46: print_info("COMPOUND_46"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_45: print_info("PRIMITIVE_45"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_48: print_info("AFTER_CALL_48"); \
TRUE_BRANCH_26: print_info("TRUE_BRANCH_26"); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_33; \
if (isCompound(func)) goto COMPOUND_34; \
COMPILED_35: print_info("COMPILED_35"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_34: print_info("COMPOUND_34"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_33: print_info("PRIMITIVE_33"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_36: print_info("AFTER_CALL_36"); \
AFTER_IF_28: print_info("AFTER_IF_28"); \
AFTER_LAMBDA_25: print_info("AFTER_LAMBDA_25"); \
defineVar(NAMEOBJ("list-ref"), val, env); \
val = COMPOBJ(_ENTRY_49, env); \
goto AFTER_LAMBDA_50; \
ENTRY_49: print_info("ENTRY_49"); \
env = COMPENVOBJ(func); \
unev = parse("(list1 list2)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_54; \
if (isCompound(func)) goto COMPOUND_55; \
COMPILED_56: print_info("COMPILED_56"); \
cont = LABELOBJ(_AFTER_CALL_57); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_55: print_info("COMPOUND_55"); \
cont = LABELOBJ(_AFTER_CALL_57); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_54: print_info("PRIMITIVE_54"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_57: print_info("AFTER_CALL_57"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_51; \
FALSE_BRANCH_52: print_info("FALSE_BRANCH_52"); \
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
if (isPrimitive(func)) goto PRIMITIVE_62; \
if (isCompound(func)) goto COMPOUND_63; \
COMPILED_64: print_info("COMPILED_64"); \
cont = LABELOBJ(_AFTER_CALL_65); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_63: print_info("COMPOUND_63"); \
cont = LABELOBJ(_AFTER_CALL_65); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_62: print_info("PRIMITIVE_62"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_65: print_info("AFTER_CALL_65"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_66; \
if (isCompound(func)) goto COMPOUND_67; \
COMPILED_68: print_info("COMPILED_68"); \
cont = LABELOBJ(_AFTER_CALL_69); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_67: print_info("COMPOUND_67"); \
cont = LABELOBJ(_AFTER_CALL_69); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_66: print_info("PRIMITIVE_66"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_69: print_info("AFTER_CALL_69"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_58; \
if (isCompound(func)) goto COMPOUND_59; \
COMPILED_60: print_info("COMPILED_60"); \
cont = LABELOBJ(_AFTER_CALL_61); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_59: print_info("COMPOUND_59"); \
cont = LABELOBJ(_AFTER_CALL_61); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_58: print_info("PRIMITIVE_58"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_61: print_info("AFTER_CALL_61"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_70; \
if (isCompound(func)) goto COMPOUND_71; \
COMPILED_72: print_info("COMPILED_72"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_71: print_info("COMPOUND_71"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_70: print_info("PRIMITIVE_70"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_73: print_info("AFTER_CALL_73"); \
TRUE_BRANCH_51: print_info("TRUE_BRANCH_51"); \
val = lookup(NAMEOBJ("list2"), env); \
goto CONTINUE; \
AFTER_IF_53: print_info("AFTER_IF_53"); \
AFTER_LAMBDA_50: print_info("AFTER_LAMBDA_50"); \
defineVar(NAMEOBJ("append"), val, env); \
val = COMPOBJ(_ENTRY_74, env); \
goto AFTER_LAMBDA_75; \
ENTRY_74: print_info("ENTRY_74"); \
env = COMPENVOBJ(func); \
unev = parse("(func items)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_79; \
if (isCompound(func)) goto COMPOUND_80; \
COMPILED_81: print_info("COMPILED_81"); \
cont = LABELOBJ(_AFTER_CALL_82); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_80: print_info("COMPOUND_80"); \
cont = LABELOBJ(_AFTER_CALL_82); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_79: print_info("PRIMITIVE_79"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_82: print_info("AFTER_CALL_82"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_76; \
FALSE_BRANCH_77: print_info("FALSE_BRANCH_77"); \
func = lookup(NAMEOBJ("cons"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("map"), env); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_91; \
if (isCompound(func)) goto COMPOUND_92; \
COMPILED_93: print_info("COMPILED_93"); \
cont = LABELOBJ(_AFTER_CALL_94); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_92: print_info("COMPOUND_92"); \
cont = LABELOBJ(_AFTER_CALL_94); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_91: print_info("PRIMITIVE_91"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_94: print_info("AFTER_CALL_94"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("func"), env); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_95; \
if (isCompound(func)) goto COMPOUND_96; \
COMPILED_97: print_info("COMPILED_97"); \
cont = LABELOBJ(_AFTER_CALL_98); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_96: print_info("COMPOUND_96"); \
cont = LABELOBJ(_AFTER_CALL_98); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_95: print_info("PRIMITIVE_95"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_98: print_info("AFTER_CALL_98"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("func"), env); \
save(func); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_83; \
if (isCompound(func)) goto COMPOUND_84; \
COMPILED_85: print_info("COMPILED_85"); \
cont = LABELOBJ(_AFTER_CALL_86); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_84: print_info("COMPOUND_84"); \
cont = LABELOBJ(_AFTER_CALL_86); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_83: print_info("PRIMITIVE_83"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_86: print_info("AFTER_CALL_86"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_87; \
if (isCompound(func)) goto COMPOUND_88; \
COMPILED_89: print_info("COMPILED_89"); \
cont = LABELOBJ(_AFTER_CALL_90); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_88: print_info("COMPOUND_88"); \
cont = LABELOBJ(_AFTER_CALL_90); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_87: print_info("PRIMITIVE_87"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_90: print_info("AFTER_CALL_90"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_99; \
if (isCompound(func)) goto COMPOUND_100; \
COMPILED_101: print_info("COMPILED_101"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_100: print_info("COMPOUND_100"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_99: print_info("PRIMITIVE_99"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_102: print_info("AFTER_CALL_102"); \
TRUE_BRANCH_76: print_info("TRUE_BRANCH_76"); \
val = lookup(NAMEOBJ("nil"), env); \
goto CONTINUE; \
AFTER_IF_78: print_info("AFTER_IF_78"); \
AFTER_LAMBDA_75: print_info("AFTER_LAMBDA_75"); \
defineVar(NAMEOBJ("map"), val, env); \
val = COMPOBJ(_ENTRY_103, env); \
goto AFTER_LAMBDA_104; \
ENTRY_103: print_info("ENTRY_103"); \
env = COMPENVOBJ(func); \
unev = parse("(comb null seq)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("seq"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_108; \
if (isCompound(func)) goto COMPOUND_109; \
COMPILED_110: print_info("COMPILED_110"); \
cont = LABELOBJ(_AFTER_CALL_111); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_109: print_info("COMPOUND_109"); \
cont = LABELOBJ(_AFTER_CALL_111); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_108: print_info("PRIMITIVE_108"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_111: print_info("AFTER_CALL_111"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_105; \
FALSE_BRANCH_106: print_info("FALSE_BRANCH_106"); \
func = lookup(NAMEOBJ("comb"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("fold-right"), env); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("seq"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_116; \
if (isCompound(func)) goto COMPOUND_117; \
COMPILED_118: print_info("COMPILED_118"); \
cont = LABELOBJ(_AFTER_CALL_119); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_117: print_info("COMPOUND_117"); \
cont = LABELOBJ(_AFTER_CALL_119); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_116: print_info("PRIMITIVE_116"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_119: print_info("AFTER_CALL_119"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("null"), env); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("comb"), env); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_120; \
if (isCompound(func)) goto COMPOUND_121; \
COMPILED_122: print_info("COMPILED_122"); \
cont = LABELOBJ(_AFTER_CALL_123); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_121: print_info("COMPOUND_121"); \
cont = LABELOBJ(_AFTER_CALL_123); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_120: print_info("PRIMITIVE_120"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_123: print_info("AFTER_CALL_123"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("seq"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_112; \
if (isCompound(func)) goto COMPOUND_113; \
COMPILED_114: print_info("COMPILED_114"); \
cont = LABELOBJ(_AFTER_CALL_115); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_113: print_info("COMPOUND_113"); \
cont = LABELOBJ(_AFTER_CALL_115); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_112: print_info("PRIMITIVE_112"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_115: print_info("AFTER_CALL_115"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_124; \
if (isCompound(func)) goto COMPOUND_125; \
COMPILED_126: print_info("COMPILED_126"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_125: print_info("COMPOUND_125"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_124: print_info("PRIMITIVE_124"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_127: print_info("AFTER_CALL_127"); \
TRUE_BRANCH_105: print_info("TRUE_BRANCH_105"); \
val = lookup(NAMEOBJ("null"), env); \
goto CONTINUE; \
AFTER_IF_107: print_info("AFTER_IF_107"); \
AFTER_LAMBDA_104: print_info("AFTER_LAMBDA_104"); \
defineVar(NAMEOBJ("fold-right"), val, env); \
val = COMPOBJ(_ENTRY_128, env); \
goto AFTER_LAMBDA_129; \
ENTRY_128: print_info("ENTRY_128"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-right"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("__+__"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_130; \
if (isCompound(func)) goto COMPOUND_131; \
COMPILED_132: print_info("COMPILED_132"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_131: print_info("COMPOUND_131"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_130: print_info("PRIMITIVE_130"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_133: print_info("AFTER_CALL_133"); \
AFTER_LAMBDA_129: print_info("AFTER_LAMBDA_129"); \
defineVar(NAMEOBJ("+"), val, env); \
val = COMPOBJ(_ENTRY_134, env); \
goto AFTER_LAMBDA_135; \
ENTRY_134: print_info("ENTRY_134"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-right"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(1); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("__*__"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_136; \
if (isCompound(func)) goto COMPOUND_137; \
COMPILED_138: print_info("COMPILED_138"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_137: print_info("COMPOUND_137"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_136: print_info("PRIMITIVE_136"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_139: print_info("AFTER_CALL_139"); \
AFTER_LAMBDA_135: print_info("AFTER_LAMBDA_135"); \
defineVar(NAMEOBJ("*"), val, env); \
val = COMPOBJ(_ENTRY_140, env); \
goto AFTER_LAMBDA_141; \
ENTRY_140: print_info("ENTRY_140"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_145; \
if (isCompound(func)) goto COMPOUND_146; \
COMPILED_147: print_info("COMPILED_147"); \
cont = LABELOBJ(_AFTER_CALL_148); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_146: print_info("COMPOUND_146"); \
cont = LABELOBJ(_AFTER_CALL_148); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_145: print_info("PRIMITIVE_145"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_148: print_info("AFTER_CALL_148"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_142; \
FALSE_BRANCH_143: print_info("FALSE_BRANCH_143"); \
func = lookup(NAMEOBJ("__*__"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_149; \
if (isCompound(func)) goto COMPOUND_150; \
COMPILED_151: print_info("COMPILED_151"); \
cont = LABELOBJ(_AFTER_CALL_152); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_150: print_info("COMPOUND_150"); \
cont = LABELOBJ(_AFTER_CALL_152); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_149: print_info("PRIMITIVE_149"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_152: print_info("AFTER_CALL_152"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_153; \
if (isCompound(func)) goto COMPOUND_154; \
COMPILED_155: print_info("COMPILED_155"); \
cont = LABELOBJ(_AFTER_CALL_156); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_154: print_info("COMPOUND_154"); \
cont = LABELOBJ(_AFTER_CALL_156); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_153: print_info("PRIMITIVE_153"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_156: print_info("AFTER_CALL_156"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_157; \
if (isCompound(func)) goto COMPOUND_158; \
COMPILED_159: print_info("COMPILED_159"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_158: print_info("COMPOUND_158"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_157: print_info("PRIMITIVE_157"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_160: print_info("AFTER_CALL_160"); \
TRUE_BRANCH_142: print_info("TRUE_BRANCH_142"); \
val = NUMOBJ(1); \
goto CONTINUE; \
AFTER_IF_144: print_info("AFTER_IF_144"); \
AFTER_LAMBDA_141: print_info("AFTER_LAMBDA_141"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_161, env); \
goto AFTER_LAMBDA_162; \
ENTRY_161: print_info("ENTRY_161"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_163, env); \
goto AFTER_LAMBDA_164; \
ENTRY_163: print_info("ENTRY_163"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_168; \
if (isCompound(func)) goto COMPOUND_169; \
COMPILED_170: print_info("COMPILED_170"); \
cont = LABELOBJ(_AFTER_CALL_171); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_169: print_info("COMPOUND_169"); \
cont = LABELOBJ(_AFTER_CALL_171); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_168: print_info("PRIMITIVE_168"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_171: print_info("AFTER_CALL_171"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_165; \
FALSE_BRANCH_166: print_info("FALSE_BRANCH_166"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("__*__"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_176; \
if (isCompound(func)) goto COMPOUND_177; \
COMPILED_178: print_info("COMPILED_178"); \
cont = LABELOBJ(_AFTER_CALL_179); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_177: print_info("COMPOUND_177"); \
cont = LABELOBJ(_AFTER_CALL_179); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_176: print_info("PRIMITIVE_176"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_179: print_info("AFTER_CALL_179"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_172; \
if (isCompound(func)) goto COMPOUND_173; \
COMPILED_174: print_info("COMPILED_174"); \
cont = LABELOBJ(_AFTER_CALL_175); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_173: print_info("COMPOUND_173"); \
cont = LABELOBJ(_AFTER_CALL_175); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_172: print_info("PRIMITIVE_172"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_175: print_info("AFTER_CALL_175"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_180; \
if (isCompound(func)) goto COMPOUND_181; \
COMPILED_182: print_info("COMPILED_182"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_181: print_info("COMPOUND_181"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_180: print_info("PRIMITIVE_180"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_183: print_info("AFTER_CALL_183"); \
TRUE_BRANCH_165: print_info("TRUE_BRANCH_165"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_167: print_info("AFTER_IF_167"); \
AFTER_LAMBDA_164: print_info("AFTER_LAMBDA_164"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_184; \
if (isCompound(func)) goto COMPOUND_185; \
COMPILED_186: print_info("COMPILED_186"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_185: print_info("COMPOUND_185"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_184: print_info("PRIMITIVE_184"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_187: print_info("AFTER_CALL_187"); \
AFTER_LAMBDA_162: print_info("AFTER_LAMBDA_162"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_188, env); \
goto AFTER_LAMBDA_189; \
ENTRY_188: print_info("ENTRY_188"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("<"), env); \
val = NUMOBJ(2); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_193; \
if (isCompound(func)) goto COMPOUND_194; \
COMPILED_195: print_info("COMPILED_195"); \
cont = LABELOBJ(_AFTER_CALL_196); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_194: print_info("COMPOUND_194"); \
cont = LABELOBJ(_AFTER_CALL_196); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_193: print_info("PRIMITIVE_193"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_196: print_info("AFTER_CALL_196"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_190; \
FALSE_BRANCH_191: print_info("FALSE_BRANCH_191"); \
func = lookup(NAMEOBJ("__+__"), env); \
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
if (isPrimitive(func)) goto PRIMITIVE_205; \
if (isCompound(func)) goto COMPOUND_206; \
COMPILED_207: print_info("COMPILED_207"); \
cont = LABELOBJ(_AFTER_CALL_208); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_206: print_info("COMPOUND_206"); \
cont = LABELOBJ(_AFTER_CALL_208); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_205: print_info("PRIMITIVE_205"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_208: print_info("AFTER_CALL_208"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_209; \
if (isCompound(func)) goto COMPOUND_210; \
COMPILED_211: print_info("COMPILED_211"); \
cont = LABELOBJ(_AFTER_CALL_212); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_210: print_info("COMPOUND_210"); \
cont = LABELOBJ(_AFTER_CALL_212); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_209: print_info("PRIMITIVE_209"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_212: print_info("AFTER_CALL_212"); \
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
if (isPrimitive(func)) goto PRIMITIVE_197; \
if (isCompound(func)) goto COMPOUND_198; \
COMPILED_199: print_info("COMPILED_199"); \
cont = LABELOBJ(_AFTER_CALL_200); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_198: print_info("COMPOUND_198"); \
cont = LABELOBJ(_AFTER_CALL_200); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_197: print_info("PRIMITIVE_197"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_200: print_info("AFTER_CALL_200"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_201; \
if (isCompound(func)) goto COMPOUND_202; \
COMPILED_203: print_info("COMPILED_203"); \
cont = LABELOBJ(_AFTER_CALL_204); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_202: print_info("COMPOUND_202"); \
cont = LABELOBJ(_AFTER_CALL_204); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_201: print_info("PRIMITIVE_201"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_204: print_info("AFTER_CALL_204"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_213; \
if (isCompound(func)) goto COMPOUND_214; \
COMPILED_215: print_info("COMPILED_215"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_214: print_info("COMPOUND_214"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_213: print_info("PRIMITIVE_213"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_216: print_info("AFTER_CALL_216"); \
TRUE_BRANCH_190: print_info("TRUE_BRANCH_190"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
AFTER_IF_192: print_info("AFTER_IF_192"); \
AFTER_LAMBDA_189: print_info("AFTER_LAMBDA_189"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_217, env); \
goto AFTER_LAMBDA_218; \
ENTRY_217: print_info("ENTRY_217"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_219, env); \
goto AFTER_LAMBDA_220; \
ENTRY_219: print_info("ENTRY_219"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_224; \
if (isCompound(func)) goto COMPOUND_225; \
COMPILED_226: print_info("COMPILED_226"); \
cont = LABELOBJ(_AFTER_CALL_227); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_225: print_info("COMPOUND_225"); \
cont = LABELOBJ(_AFTER_CALL_227); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_224: print_info("PRIMITIVE_224"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_227: print_info("AFTER_CALL_227"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_221; \
FALSE_BRANCH_222: print_info("FALSE_BRANCH_222"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("__+__"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("a"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_232; \
if (isCompound(func)) goto COMPOUND_233; \
COMPILED_234: print_info("COMPILED_234"); \
cont = LABELOBJ(_AFTER_CALL_235); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_233: print_info("COMPOUND_233"); \
cont = LABELOBJ(_AFTER_CALL_235); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_232: print_info("PRIMITIVE_232"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_235: print_info("AFTER_CALL_235"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, arglist); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_228; \
if (isCompound(func)) goto COMPOUND_229; \
COMPILED_230: print_info("COMPILED_230"); \
cont = LABELOBJ(_AFTER_CALL_231); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_229: print_info("COMPOUND_229"); \
cont = LABELOBJ(_AFTER_CALL_231); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_228: print_info("PRIMITIVE_228"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_231: print_info("AFTER_CALL_231"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_236; \
if (isCompound(func)) goto COMPOUND_237; \
COMPILED_238: print_info("COMPILED_238"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_237: print_info("COMPOUND_237"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_236: print_info("PRIMITIVE_236"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_239: print_info("AFTER_CALL_239"); \
TRUE_BRANCH_221: print_info("TRUE_BRANCH_221"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
AFTER_IF_223: print_info("AFTER_IF_223"); \
AFTER_LAMBDA_220: print_info("AFTER_LAMBDA_220"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_240; \
if (isCompound(func)) goto COMPOUND_241; \
COMPILED_242: print_info("COMPILED_242"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_241: print_info("COMPOUND_241"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_240: print_info("PRIMITIVE_240"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_243: print_info("AFTER_CALL_243"); \
AFTER_LAMBDA_218: print_info("AFTER_LAMBDA_218"); \
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
if (GETLABEL(REG) == _TRUE_BRANCH_5) goto TRUE_BRANCH_5; \
if (GETLABEL(REG) == _FALSE_BRANCH_6) goto FALSE_BRANCH_6; \
if (GETLABEL(REG) == _AFTER_IF_7) goto AFTER_IF_7; \
if (GETLABEL(REG) == _PRIMITIVE_8) goto PRIMITIVE_8; \
if (GETLABEL(REG) == _COMPOUND_9) goto COMPOUND_9; \
if (GETLABEL(REG) == _COMPILED_10) goto COMPILED_10; \
if (GETLABEL(REG) == _AFTER_CALL_11) goto AFTER_CALL_11; \
if (GETLABEL(REG) == _PRIMITIVE_12) goto PRIMITIVE_12; \
if (GETLABEL(REG) == _COMPOUND_13) goto COMPOUND_13; \
if (GETLABEL(REG) == _COMPILED_14) goto COMPILED_14; \
if (GETLABEL(REG) == _AFTER_CALL_15) goto AFTER_CALL_15; \
if (GETLABEL(REG) == _PRIMITIVE_16) goto PRIMITIVE_16; \
if (GETLABEL(REG) == _COMPOUND_17) goto COMPOUND_17; \
if (GETLABEL(REG) == _COMPILED_18) goto COMPILED_18; \
if (GETLABEL(REG) == _AFTER_CALL_19) goto AFTER_CALL_19; \
if (GETLABEL(REG) == _PRIMITIVE_20) goto PRIMITIVE_20; \
if (GETLABEL(REG) == _COMPOUND_21) goto COMPOUND_21; \
if (GETLABEL(REG) == _COMPILED_22) goto COMPILED_22; \
if (GETLABEL(REG) == _AFTER_CALL_23) goto AFTER_CALL_23; \
if (GETLABEL(REG) == _ENTRY_24) goto ENTRY_24; \
if (GETLABEL(REG) == _AFTER_LAMBDA_25) goto AFTER_LAMBDA_25; \
if (GETLABEL(REG) == _TRUE_BRANCH_26) goto TRUE_BRANCH_26; \
if (GETLABEL(REG) == _FALSE_BRANCH_27) goto FALSE_BRANCH_27; \
if (GETLABEL(REG) == _AFTER_IF_28) goto AFTER_IF_28; \
if (GETLABEL(REG) == _PRIMITIVE_29) goto PRIMITIVE_29; \
if (GETLABEL(REG) == _COMPOUND_30) goto COMPOUND_30; \
if (GETLABEL(REG) == _COMPILED_31) goto COMPILED_31; \
if (GETLABEL(REG) == _AFTER_CALL_32) goto AFTER_CALL_32; \
if (GETLABEL(REG) == _PRIMITIVE_33) goto PRIMITIVE_33; \
if (GETLABEL(REG) == _COMPOUND_34) goto COMPOUND_34; \
if (GETLABEL(REG) == _COMPILED_35) goto COMPILED_35; \
if (GETLABEL(REG) == _AFTER_CALL_36) goto AFTER_CALL_36; \
if (GETLABEL(REG) == _PRIMITIVE_37) goto PRIMITIVE_37; \
if (GETLABEL(REG) == _COMPOUND_38) goto COMPOUND_38; \
if (GETLABEL(REG) == _COMPILED_39) goto COMPILED_39; \
if (GETLABEL(REG) == _AFTER_CALL_40) goto AFTER_CALL_40; \
if (GETLABEL(REG) == _PRIMITIVE_41) goto PRIMITIVE_41; \
if (GETLABEL(REG) == _COMPOUND_42) goto COMPOUND_42; \
if (GETLABEL(REG) == _COMPILED_43) goto COMPILED_43; \
if (GETLABEL(REG) == _AFTER_CALL_44) goto AFTER_CALL_44; \
if (GETLABEL(REG) == _PRIMITIVE_45) goto PRIMITIVE_45; \
if (GETLABEL(REG) == _COMPOUND_46) goto COMPOUND_46; \
if (GETLABEL(REG) == _COMPILED_47) goto COMPILED_47; \
if (GETLABEL(REG) == _AFTER_CALL_48) goto AFTER_CALL_48; \
if (GETLABEL(REG) == _ENTRY_49) goto ENTRY_49; \
if (GETLABEL(REG) == _AFTER_LAMBDA_50) goto AFTER_LAMBDA_50; \
if (GETLABEL(REG) == _TRUE_BRANCH_51) goto TRUE_BRANCH_51; \
if (GETLABEL(REG) == _FALSE_BRANCH_52) goto FALSE_BRANCH_52; \
if (GETLABEL(REG) == _AFTER_IF_53) goto AFTER_IF_53; \
if (GETLABEL(REG) == _PRIMITIVE_54) goto PRIMITIVE_54; \
if (GETLABEL(REG) == _COMPOUND_55) goto COMPOUND_55; \
if (GETLABEL(REG) == _COMPILED_56) goto COMPILED_56; \
if (GETLABEL(REG) == _AFTER_CALL_57) goto AFTER_CALL_57; \
if (GETLABEL(REG) == _PRIMITIVE_58) goto PRIMITIVE_58; \
if (GETLABEL(REG) == _COMPOUND_59) goto COMPOUND_59; \
if (GETLABEL(REG) == _COMPILED_60) goto COMPILED_60; \
if (GETLABEL(REG) == _AFTER_CALL_61) goto AFTER_CALL_61; \
if (GETLABEL(REG) == _PRIMITIVE_62) goto PRIMITIVE_62; \
if (GETLABEL(REG) == _COMPOUND_63) goto COMPOUND_63; \
if (GETLABEL(REG) == _COMPILED_64) goto COMPILED_64; \
if (GETLABEL(REG) == _AFTER_CALL_65) goto AFTER_CALL_65; \
if (GETLABEL(REG) == _PRIMITIVE_66) goto PRIMITIVE_66; \
if (GETLABEL(REG) == _COMPOUND_67) goto COMPOUND_67; \
if (GETLABEL(REG) == _COMPILED_68) goto COMPILED_68; \
if (GETLABEL(REG) == _AFTER_CALL_69) goto AFTER_CALL_69; \
if (GETLABEL(REG) == _PRIMITIVE_70) goto PRIMITIVE_70; \
if (GETLABEL(REG) == _COMPOUND_71) goto COMPOUND_71; \
if (GETLABEL(REG) == _COMPILED_72) goto COMPILED_72; \
if (GETLABEL(REG) == _AFTER_CALL_73) goto AFTER_CALL_73; \
if (GETLABEL(REG) == _ENTRY_74) goto ENTRY_74; \
if (GETLABEL(REG) == _AFTER_LAMBDA_75) goto AFTER_LAMBDA_75; \
if (GETLABEL(REG) == _TRUE_BRANCH_76) goto TRUE_BRANCH_76; \
if (GETLABEL(REG) == _FALSE_BRANCH_77) goto FALSE_BRANCH_77; \
if (GETLABEL(REG) == _AFTER_IF_78) goto AFTER_IF_78; \
if (GETLABEL(REG) == _PRIMITIVE_79) goto PRIMITIVE_79; \
if (GETLABEL(REG) == _COMPOUND_80) goto COMPOUND_80; \
if (GETLABEL(REG) == _COMPILED_81) goto COMPILED_81; \
if (GETLABEL(REG) == _AFTER_CALL_82) goto AFTER_CALL_82; \
if (GETLABEL(REG) == _PRIMITIVE_83) goto PRIMITIVE_83; \
if (GETLABEL(REG) == _COMPOUND_84) goto COMPOUND_84; \
if (GETLABEL(REG) == _COMPILED_85) goto COMPILED_85; \
if (GETLABEL(REG) == _AFTER_CALL_86) goto AFTER_CALL_86; \
if (GETLABEL(REG) == _PRIMITIVE_87) goto PRIMITIVE_87; \
if (GETLABEL(REG) == _COMPOUND_88) goto COMPOUND_88; \
if (GETLABEL(REG) == _COMPILED_89) goto COMPILED_89; \
if (GETLABEL(REG) == _AFTER_CALL_90) goto AFTER_CALL_90; \
if (GETLABEL(REG) == _PRIMITIVE_91) goto PRIMITIVE_91; \
if (GETLABEL(REG) == _COMPOUND_92) goto COMPOUND_92; \
if (GETLABEL(REG) == _COMPILED_93) goto COMPILED_93; \
if (GETLABEL(REG) == _AFTER_CALL_94) goto AFTER_CALL_94; \
if (GETLABEL(REG) == _PRIMITIVE_95) goto PRIMITIVE_95; \
if (GETLABEL(REG) == _COMPOUND_96) goto COMPOUND_96; \
if (GETLABEL(REG) == _COMPILED_97) goto COMPILED_97; \
if (GETLABEL(REG) == _AFTER_CALL_98) goto AFTER_CALL_98; \
if (GETLABEL(REG) == _PRIMITIVE_99) goto PRIMITIVE_99; \
if (GETLABEL(REG) == _COMPOUND_100) goto COMPOUND_100; \
if (GETLABEL(REG) == _COMPILED_101) goto COMPILED_101; \
if (GETLABEL(REG) == _AFTER_CALL_102) goto AFTER_CALL_102; \
if (GETLABEL(REG) == _ENTRY_103) goto ENTRY_103; \
if (GETLABEL(REG) == _AFTER_LAMBDA_104) goto AFTER_LAMBDA_104; \
if (GETLABEL(REG) == _TRUE_BRANCH_105) goto TRUE_BRANCH_105; \
if (GETLABEL(REG) == _FALSE_BRANCH_106) goto FALSE_BRANCH_106; \
if (GETLABEL(REG) == _AFTER_IF_107) goto AFTER_IF_107; \
if (GETLABEL(REG) == _PRIMITIVE_108) goto PRIMITIVE_108; \
if (GETLABEL(REG) == _COMPOUND_109) goto COMPOUND_109; \
if (GETLABEL(REG) == _COMPILED_110) goto COMPILED_110; \
if (GETLABEL(REG) == _AFTER_CALL_111) goto AFTER_CALL_111; \
if (GETLABEL(REG) == _PRIMITIVE_112) goto PRIMITIVE_112; \
if (GETLABEL(REG) == _COMPOUND_113) goto COMPOUND_113; \
if (GETLABEL(REG) == _COMPILED_114) goto COMPILED_114; \
if (GETLABEL(REG) == _AFTER_CALL_115) goto AFTER_CALL_115; \
if (GETLABEL(REG) == _PRIMITIVE_116) goto PRIMITIVE_116; \
if (GETLABEL(REG) == _COMPOUND_117) goto COMPOUND_117; \
if (GETLABEL(REG) == _COMPILED_118) goto COMPILED_118; \
if (GETLABEL(REG) == _AFTER_CALL_119) goto AFTER_CALL_119; \
if (GETLABEL(REG) == _PRIMITIVE_120) goto PRIMITIVE_120; \
if (GETLABEL(REG) == _COMPOUND_121) goto COMPOUND_121; \
if (GETLABEL(REG) == _COMPILED_122) goto COMPILED_122; \
if (GETLABEL(REG) == _AFTER_CALL_123) goto AFTER_CALL_123; \
if (GETLABEL(REG) == _PRIMITIVE_124) goto PRIMITIVE_124; \
if (GETLABEL(REG) == _COMPOUND_125) goto COMPOUND_125; \
if (GETLABEL(REG) == _COMPILED_126) goto COMPILED_126; \
if (GETLABEL(REG) == _AFTER_CALL_127) goto AFTER_CALL_127; \
if (GETLABEL(REG) == _ENTRY_128) goto ENTRY_128; \
if (GETLABEL(REG) == _AFTER_LAMBDA_129) goto AFTER_LAMBDA_129; \
if (GETLABEL(REG) == _PRIMITIVE_130) goto PRIMITIVE_130; \
if (GETLABEL(REG) == _COMPOUND_131) goto COMPOUND_131; \
if (GETLABEL(REG) == _COMPILED_132) goto COMPILED_132; \
if (GETLABEL(REG) == _AFTER_CALL_133) goto AFTER_CALL_133; \
if (GETLABEL(REG) == _ENTRY_134) goto ENTRY_134; \
if (GETLABEL(REG) == _AFTER_LAMBDA_135) goto AFTER_LAMBDA_135; \
if (GETLABEL(REG) == _PRIMITIVE_136) goto PRIMITIVE_136; \
if (GETLABEL(REG) == _COMPOUND_137) goto COMPOUND_137; \
if (GETLABEL(REG) == _COMPILED_138) goto COMPILED_138; \
if (GETLABEL(REG) == _AFTER_CALL_139) goto AFTER_CALL_139; \
if (GETLABEL(REG) == _ENTRY_140) goto ENTRY_140; \
if (GETLABEL(REG) == _AFTER_LAMBDA_141) goto AFTER_LAMBDA_141; \
if (GETLABEL(REG) == _TRUE_BRANCH_142) goto TRUE_BRANCH_142; \
if (GETLABEL(REG) == _FALSE_BRANCH_143) goto FALSE_BRANCH_143; \
if (GETLABEL(REG) == _AFTER_IF_144) goto AFTER_IF_144; \
if (GETLABEL(REG) == _PRIMITIVE_145) goto PRIMITIVE_145; \
if (GETLABEL(REG) == _COMPOUND_146) goto COMPOUND_146; \
if (GETLABEL(REG) == _COMPILED_147) goto COMPILED_147; \
if (GETLABEL(REG) == _AFTER_CALL_148) goto AFTER_CALL_148; \
if (GETLABEL(REG) == _PRIMITIVE_149) goto PRIMITIVE_149; \
if (GETLABEL(REG) == _COMPOUND_150) goto COMPOUND_150; \
if (GETLABEL(REG) == _COMPILED_151) goto COMPILED_151; \
if (GETLABEL(REG) == _AFTER_CALL_152) goto AFTER_CALL_152; \
if (GETLABEL(REG) == _PRIMITIVE_153) goto PRIMITIVE_153; \
if (GETLABEL(REG) == _COMPOUND_154) goto COMPOUND_154; \
if (GETLABEL(REG) == _COMPILED_155) goto COMPILED_155; \
if (GETLABEL(REG) == _AFTER_CALL_156) goto AFTER_CALL_156; \
if (GETLABEL(REG) == _PRIMITIVE_157) goto PRIMITIVE_157; \
if (GETLABEL(REG) == _COMPOUND_158) goto COMPOUND_158; \
if (GETLABEL(REG) == _COMPILED_159) goto COMPILED_159; \
if (GETLABEL(REG) == _AFTER_CALL_160) goto AFTER_CALL_160; \
if (GETLABEL(REG) == _ENTRY_161) goto ENTRY_161; \
if (GETLABEL(REG) == _AFTER_LAMBDA_162) goto AFTER_LAMBDA_162; \
if (GETLABEL(REG) == _ENTRY_163) goto ENTRY_163; \
if (GETLABEL(REG) == _AFTER_LAMBDA_164) goto AFTER_LAMBDA_164; \
if (GETLABEL(REG) == _TRUE_BRANCH_165) goto TRUE_BRANCH_165; \
if (GETLABEL(REG) == _FALSE_BRANCH_166) goto FALSE_BRANCH_166; \
if (GETLABEL(REG) == _AFTER_IF_167) goto AFTER_IF_167; \
if (GETLABEL(REG) == _PRIMITIVE_168) goto PRIMITIVE_168; \
if (GETLABEL(REG) == _COMPOUND_169) goto COMPOUND_169; \
if (GETLABEL(REG) == _COMPILED_170) goto COMPILED_170; \
if (GETLABEL(REG) == _AFTER_CALL_171) goto AFTER_CALL_171; \
if (GETLABEL(REG) == _PRIMITIVE_172) goto PRIMITIVE_172; \
if (GETLABEL(REG) == _COMPOUND_173) goto COMPOUND_173; \
if (GETLABEL(REG) == _COMPILED_174) goto COMPILED_174; \
if (GETLABEL(REG) == _AFTER_CALL_175) goto AFTER_CALL_175; \
if (GETLABEL(REG) == _PRIMITIVE_176) goto PRIMITIVE_176; \
if (GETLABEL(REG) == _COMPOUND_177) goto COMPOUND_177; \
if (GETLABEL(REG) == _COMPILED_178) goto COMPILED_178; \
if (GETLABEL(REG) == _AFTER_CALL_179) goto AFTER_CALL_179; \
if (GETLABEL(REG) == _PRIMITIVE_180) goto PRIMITIVE_180; \
if (GETLABEL(REG) == _COMPOUND_181) goto COMPOUND_181; \
if (GETLABEL(REG) == _COMPILED_182) goto COMPILED_182; \
if (GETLABEL(REG) == _AFTER_CALL_183) goto AFTER_CALL_183; \
if (GETLABEL(REG) == _PRIMITIVE_184) goto PRIMITIVE_184; \
if (GETLABEL(REG) == _COMPOUND_185) goto COMPOUND_185; \
if (GETLABEL(REG) == _COMPILED_186) goto COMPILED_186; \
if (GETLABEL(REG) == _AFTER_CALL_187) goto AFTER_CALL_187; \
if (GETLABEL(REG) == _ENTRY_188) goto ENTRY_188; \
if (GETLABEL(REG) == _AFTER_LAMBDA_189) goto AFTER_LAMBDA_189; \
if (GETLABEL(REG) == _TRUE_BRANCH_190) goto TRUE_BRANCH_190; \
if (GETLABEL(REG) == _FALSE_BRANCH_191) goto FALSE_BRANCH_191; \
if (GETLABEL(REG) == _AFTER_IF_192) goto AFTER_IF_192; \
if (GETLABEL(REG) == _PRIMITIVE_193) goto PRIMITIVE_193; \
if (GETLABEL(REG) == _COMPOUND_194) goto COMPOUND_194; \
if (GETLABEL(REG) == _COMPILED_195) goto COMPILED_195; \
if (GETLABEL(REG) == _AFTER_CALL_196) goto AFTER_CALL_196; \
if (GETLABEL(REG) == _PRIMITIVE_197) goto PRIMITIVE_197; \
if (GETLABEL(REG) == _COMPOUND_198) goto COMPOUND_198; \
if (GETLABEL(REG) == _COMPILED_199) goto COMPILED_199; \
if (GETLABEL(REG) == _AFTER_CALL_200) goto AFTER_CALL_200; \
if (GETLABEL(REG) == _PRIMITIVE_201) goto PRIMITIVE_201; \
if (GETLABEL(REG) == _COMPOUND_202) goto COMPOUND_202; \
if (GETLABEL(REG) == _COMPILED_203) goto COMPILED_203; \
if (GETLABEL(REG) == _AFTER_CALL_204) goto AFTER_CALL_204; \
if (GETLABEL(REG) == _PRIMITIVE_205) goto PRIMITIVE_205; \
if (GETLABEL(REG) == _COMPOUND_206) goto COMPOUND_206; \
if (GETLABEL(REG) == _COMPILED_207) goto COMPILED_207; \
if (GETLABEL(REG) == _AFTER_CALL_208) goto AFTER_CALL_208; \
if (GETLABEL(REG) == _PRIMITIVE_209) goto PRIMITIVE_209; \
if (GETLABEL(REG) == _COMPOUND_210) goto COMPOUND_210; \
if (GETLABEL(REG) == _COMPILED_211) goto COMPILED_211; \
if (GETLABEL(REG) == _AFTER_CALL_212) goto AFTER_CALL_212; \
if (GETLABEL(REG) == _PRIMITIVE_213) goto PRIMITIVE_213; \
if (GETLABEL(REG) == _COMPOUND_214) goto COMPOUND_214; \
if (GETLABEL(REG) == _COMPILED_215) goto COMPILED_215; \
if (GETLABEL(REG) == _AFTER_CALL_216) goto AFTER_CALL_216; \
if (GETLABEL(REG) == _ENTRY_217) goto ENTRY_217; \
if (GETLABEL(REG) == _AFTER_LAMBDA_218) goto AFTER_LAMBDA_218; \
if (GETLABEL(REG) == _ENTRY_219) goto ENTRY_219; \
if (GETLABEL(REG) == _AFTER_LAMBDA_220) goto AFTER_LAMBDA_220; \
if (GETLABEL(REG) == _TRUE_BRANCH_221) goto TRUE_BRANCH_221; \
if (GETLABEL(REG) == _FALSE_BRANCH_222) goto FALSE_BRANCH_222; \
if (GETLABEL(REG) == _AFTER_IF_223) goto AFTER_IF_223; \
if (GETLABEL(REG) == _PRIMITIVE_224) goto PRIMITIVE_224; \
if (GETLABEL(REG) == _COMPOUND_225) goto COMPOUND_225; \
if (GETLABEL(REG) == _COMPILED_226) goto COMPILED_226; \
if (GETLABEL(REG) == _AFTER_CALL_227) goto AFTER_CALL_227; \
if (GETLABEL(REG) == _PRIMITIVE_228) goto PRIMITIVE_228; \
if (GETLABEL(REG) == _COMPOUND_229) goto COMPOUND_229; \
if (GETLABEL(REG) == _COMPILED_230) goto COMPILED_230; \
if (GETLABEL(REG) == _AFTER_CALL_231) goto AFTER_CALL_231; \
if (GETLABEL(REG) == _PRIMITIVE_232) goto PRIMITIVE_232; \
if (GETLABEL(REG) == _COMPOUND_233) goto COMPOUND_233; \
if (GETLABEL(REG) == _COMPILED_234) goto COMPILED_234; \
if (GETLABEL(REG) == _AFTER_CALL_235) goto AFTER_CALL_235; \
if (GETLABEL(REG) == _PRIMITIVE_236) goto PRIMITIVE_236; \
if (GETLABEL(REG) == _COMPOUND_237) goto COMPOUND_237; \
if (GETLABEL(REG) == _COMPILED_238) goto COMPILED_238; \
if (GETLABEL(REG) == _AFTER_CALL_239) goto AFTER_CALL_239; \
if (GETLABEL(REG) == _PRIMITIVE_240) goto PRIMITIVE_240; \
if (GETLABEL(REG) == _COMPOUND_241) goto COMPOUND_241; \
if (GETLABEL(REG) == _COMPILED_242) goto COMPILED_242; \
if (GETLABEL(REG) == _AFTER_CALL_243) goto AFTER_CALL_243;

#define ALL_COMPILED_LABELS \
_ENTRY_1, \
_AFTER_LAMBDA_2, \
_ENTRY_3, \
_AFTER_LAMBDA_4, \
_TRUE_BRANCH_5, \
_FALSE_BRANCH_6, \
_AFTER_IF_7, \
_PRIMITIVE_8, \
_COMPOUND_9, \
_COMPILED_10, \
_AFTER_CALL_11, \
_PRIMITIVE_12, \
_COMPOUND_13, \
_COMPILED_14, \
_AFTER_CALL_15, \
_PRIMITIVE_16, \
_COMPOUND_17, \
_COMPILED_18, \
_AFTER_CALL_19, \
_PRIMITIVE_20, \
_COMPOUND_21, \
_COMPILED_22, \
_AFTER_CALL_23, \
_ENTRY_24, \
_AFTER_LAMBDA_25, \
_TRUE_BRANCH_26, \
_FALSE_BRANCH_27, \
_AFTER_IF_28, \
_PRIMITIVE_29, \
_COMPOUND_30, \
_COMPILED_31, \
_AFTER_CALL_32, \
_PRIMITIVE_33, \
_COMPOUND_34, \
_COMPILED_35, \
_AFTER_CALL_36, \
_PRIMITIVE_37, \
_COMPOUND_38, \
_COMPILED_39, \
_AFTER_CALL_40, \
_PRIMITIVE_41, \
_COMPOUND_42, \
_COMPILED_43, \
_AFTER_CALL_44, \
_PRIMITIVE_45, \
_COMPOUND_46, \
_COMPILED_47, \
_AFTER_CALL_48, \
_ENTRY_49, \
_AFTER_LAMBDA_50, \
_TRUE_BRANCH_51, \
_FALSE_BRANCH_52, \
_AFTER_IF_53, \
_PRIMITIVE_54, \
_COMPOUND_55, \
_COMPILED_56, \
_AFTER_CALL_57, \
_PRIMITIVE_58, \
_COMPOUND_59, \
_COMPILED_60, \
_AFTER_CALL_61, \
_PRIMITIVE_62, \
_COMPOUND_63, \
_COMPILED_64, \
_AFTER_CALL_65, \
_PRIMITIVE_66, \
_COMPOUND_67, \
_COMPILED_68, \
_AFTER_CALL_69, \
_PRIMITIVE_70, \
_COMPOUND_71, \
_COMPILED_72, \
_AFTER_CALL_73, \
_ENTRY_74, \
_AFTER_LAMBDA_75, \
_TRUE_BRANCH_76, \
_FALSE_BRANCH_77, \
_AFTER_IF_78, \
_PRIMITIVE_79, \
_COMPOUND_80, \
_COMPILED_81, \
_AFTER_CALL_82, \
_PRIMITIVE_83, \
_COMPOUND_84, \
_COMPILED_85, \
_AFTER_CALL_86, \
_PRIMITIVE_87, \
_COMPOUND_88, \
_COMPILED_89, \
_AFTER_CALL_90, \
_PRIMITIVE_91, \
_COMPOUND_92, \
_COMPILED_93, \
_AFTER_CALL_94, \
_PRIMITIVE_95, \
_COMPOUND_96, \
_COMPILED_97, \
_AFTER_CALL_98, \
_PRIMITIVE_99, \
_COMPOUND_100, \
_COMPILED_101, \
_AFTER_CALL_102, \
_ENTRY_103, \
_AFTER_LAMBDA_104, \
_TRUE_BRANCH_105, \
_FALSE_BRANCH_106, \
_AFTER_IF_107, \
_PRIMITIVE_108, \
_COMPOUND_109, \
_COMPILED_110, \
_AFTER_CALL_111, \
_PRIMITIVE_112, \
_COMPOUND_113, \
_COMPILED_114, \
_AFTER_CALL_115, \
_PRIMITIVE_116, \
_COMPOUND_117, \
_COMPILED_118, \
_AFTER_CALL_119, \
_PRIMITIVE_120, \
_COMPOUND_121, \
_COMPILED_122, \
_AFTER_CALL_123, \
_PRIMITIVE_124, \
_COMPOUND_125, \
_COMPILED_126, \
_AFTER_CALL_127, \
_ENTRY_128, \
_AFTER_LAMBDA_129, \
_PRIMITIVE_130, \
_COMPOUND_131, \
_COMPILED_132, \
_AFTER_CALL_133, \
_ENTRY_134, \
_AFTER_LAMBDA_135, \
_PRIMITIVE_136, \
_COMPOUND_137, \
_COMPILED_138, \
_AFTER_CALL_139, \
_ENTRY_140, \
_AFTER_LAMBDA_141, \
_TRUE_BRANCH_142, \
_FALSE_BRANCH_143, \
_AFTER_IF_144, \
_PRIMITIVE_145, \
_COMPOUND_146, \
_COMPILED_147, \
_AFTER_CALL_148, \
_PRIMITIVE_149, \
_COMPOUND_150, \
_COMPILED_151, \
_AFTER_CALL_152, \
_PRIMITIVE_153, \
_COMPOUND_154, \
_COMPILED_155, \
_AFTER_CALL_156, \
_PRIMITIVE_157, \
_COMPOUND_158, \
_COMPILED_159, \
_AFTER_CALL_160, \
_ENTRY_161, \
_AFTER_LAMBDA_162, \
_ENTRY_163, \
_AFTER_LAMBDA_164, \
_TRUE_BRANCH_165, \
_FALSE_BRANCH_166, \
_AFTER_IF_167, \
_PRIMITIVE_168, \
_COMPOUND_169, \
_COMPILED_170, \
_AFTER_CALL_171, \
_PRIMITIVE_172, \
_COMPOUND_173, \
_COMPILED_174, \
_AFTER_CALL_175, \
_PRIMITIVE_176, \
_COMPOUND_177, \
_COMPILED_178, \
_AFTER_CALL_179, \
_PRIMITIVE_180, \
_COMPOUND_181, \
_COMPILED_182, \
_AFTER_CALL_183, \
_PRIMITIVE_184, \
_COMPOUND_185, \
_COMPILED_186, \
_AFTER_CALL_187, \
_ENTRY_188, \
_AFTER_LAMBDA_189, \
_TRUE_BRANCH_190, \
_FALSE_BRANCH_191, \
_AFTER_IF_192, \
_PRIMITIVE_193, \
_COMPOUND_194, \
_COMPILED_195, \
_AFTER_CALL_196, \
_PRIMITIVE_197, \
_COMPOUND_198, \
_COMPILED_199, \
_AFTER_CALL_200, \
_PRIMITIVE_201, \
_COMPOUND_202, \
_COMPILED_203, \
_AFTER_CALL_204, \
_PRIMITIVE_205, \
_COMPOUND_206, \
_COMPILED_207, \
_AFTER_CALL_208, \
_PRIMITIVE_209, \
_COMPOUND_210, \
_COMPILED_211, \
_AFTER_CALL_212, \
_PRIMITIVE_213, \
_COMPOUND_214, \
_COMPILED_215, \
_AFTER_CALL_216, \
_ENTRY_217, \
_AFTER_LAMBDA_218, \
_ENTRY_219, \
_AFTER_LAMBDA_220, \
_TRUE_BRANCH_221, \
_FALSE_BRANCH_222, \
_AFTER_IF_223, \
_PRIMITIVE_224, \
_COMPOUND_225, \
_COMPILED_226, \
_AFTER_CALL_227, \
_PRIMITIVE_228, \
_COMPOUND_229, \
_COMPILED_230, \
_AFTER_CALL_231, \
_PRIMITIVE_232, \
_COMPOUND_233, \
_COMPILED_234, \
_AFTER_CALL_235, \
_PRIMITIVE_236, \
_COMPOUND_237, \
_COMPILED_238, \
_AFTER_CALL_239, \
_PRIMITIVE_240, \
_COMPOUND_241, \
_COMPILED_242, \
_AFTER_CALL_243

#endif
