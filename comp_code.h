/* 
	This code is compiler-generated! 
	It may be ugly, but it sure is fast!
	Can you figure out how it works?
	
	https://github.com/nickdrozd/Lisp-C-Compyler
*/

#ifndef COMP_CODE_GUARD
#define COMP_CODE_GUARD

#define COMPILED_CODE_BODY \
val = COMPOBJ(_ENTRY_1, env); \
goto AFTER_LAMBDA_2; \
ENTRY_1: print_info("ENTRY_1"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_6; \
COMPILED_7: print_info("COMPILED_7"); \
cont = LABELOBJ(_AFTER_CALL_8); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_6: print_info("PRIMITIVE_6"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_8: print_info("AFTER_CALL_8"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_3; \
FALSE_BRANCH_4: print_info("FALSE_BRANCH_4"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_9; \
COMPILED_10: print_info("COMPILED_10"); \
cont = LABELOBJ(_AFTER_CALL_11); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_9: print_info("PRIMITIVE_9"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_11: print_info("AFTER_CALL_11"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_12; \
COMPILED_13: print_info("COMPILED_13"); \
cont = LABELOBJ(_AFTER_CALL_14); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_12: print_info("PRIMITIVE_12"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_14: print_info("AFTER_CALL_14"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_15; \
COMPILED_16: print_info("COMPILED_16"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_15: print_info("PRIMITIVE_15"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_17: print_info("AFTER_CALL_17"); \
TRUE_BRANCH_3: print_info("TRUE_BRANCH_3"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_5: print_info("AFTER_IF_5"); \
AFTER_LAMBDA_2: print_info("AFTER_LAMBDA_2"); \
defineVar(NAMEOBJ("recursive_triangular_compiled"), val, env); \
val = COMPOBJ(_ENTRY_18, env); \
goto AFTER_LAMBDA_19; \
ENTRY_18: print_info("ENTRY_18"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_23; \
COMPILED_24: print_info("COMPILED_24"); \
cont = LABELOBJ(_AFTER_CALL_25); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_23: print_info("PRIMITIVE_23"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_25: print_info("AFTER_CALL_25"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_20; \
FALSE_BRANCH_21: print_info("FALSE_BRANCH_21"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_29; \
COMPILED_30: print_info("COMPILED_30"); \
cont = LABELOBJ(_AFTER_CALL_31); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_29: print_info("PRIMITIVE_29"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_31: print_info("AFTER_CALL_31"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_32; \
COMPILED_33: print_info("COMPILED_33"); \
cont = LABELOBJ(_AFTER_CALL_34); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_32: print_info("PRIMITIVE_32"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_34: print_info("AFTER_CALL_34"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_26; \
COMPILED_27: print_info("COMPILED_27"); \
cont = LABELOBJ(_AFTER_CALL_28); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_26: print_info("PRIMITIVE_26"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_28: print_info("AFTER_CALL_28"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_35; \
COMPILED_36: print_info("COMPILED_36"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_35: print_info("PRIMITIVE_35"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_37: print_info("AFTER_CALL_37"); \
TRUE_BRANCH_20: print_info("TRUE_BRANCH_20"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_22: print_info("AFTER_IF_22"); \
AFTER_LAMBDA_19: print_info("AFTER_LAMBDA_19"); \
defineVar(NAMEOBJ("recursive_tetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_38, env); \
goto AFTER_LAMBDA_39; \
ENTRY_38: print_info("ENTRY_38"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_43; \
COMPILED_44: print_info("COMPILED_44"); \
cont = LABELOBJ(_AFTER_CALL_45); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_43: print_info("PRIMITIVE_43"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_45: print_info("AFTER_CALL_45"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_40; \
FALSE_BRANCH_41: print_info("FALSE_BRANCH_41"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_supertetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_49; \
COMPILED_50: print_info("COMPILED_50"); \
cont = LABELOBJ(_AFTER_CALL_51); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_49: print_info("PRIMITIVE_49"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_51: print_info("AFTER_CALL_51"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_52; \
COMPILED_53: print_info("COMPILED_53"); \
cont = LABELOBJ(_AFTER_CALL_54); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_52: print_info("PRIMITIVE_52"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_54: print_info("AFTER_CALL_54"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_46; \
COMPILED_47: print_info("COMPILED_47"); \
cont = LABELOBJ(_AFTER_CALL_48); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_46: print_info("PRIMITIVE_46"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_48: print_info("AFTER_CALL_48"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_55; \
COMPILED_56: print_info("COMPILED_56"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_55: print_info("PRIMITIVE_55"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_57: print_info("AFTER_CALL_57"); \
TRUE_BRANCH_40: print_info("TRUE_BRANCH_40"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_42: print_info("AFTER_IF_42"); \
AFTER_LAMBDA_39: print_info("AFTER_LAMBDA_39"); \
defineVar(NAMEOBJ("recursive_supertetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_58, env); \
goto AFTER_LAMBDA_59; \
ENTRY_58: print_info("ENTRY_58"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_63; \
COMPILED_64: print_info("COMPILED_64"); \
cont = LABELOBJ(_AFTER_CALL_65); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_63: print_info("PRIMITIVE_63"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_65: print_info("AFTER_CALL_65"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_60; \
FALSE_BRANCH_61: print_info("FALSE_BRANCH_61"); \
func = lookup(NAMEOBJ("*"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_66; \
COMPILED_67: print_info("COMPILED_67"); \
cont = LABELOBJ(_AFTER_CALL_68); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_66: print_info("PRIMITIVE_66"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_68: print_info("AFTER_CALL_68"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_69; \
COMPILED_70: print_info("COMPILED_70"); \
cont = LABELOBJ(_AFTER_CALL_71); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_69: print_info("PRIMITIVE_69"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_71: print_info("AFTER_CALL_71"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_72; \
COMPILED_73: print_info("COMPILED_73"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_72: print_info("PRIMITIVE_72"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_74: print_info("AFTER_CALL_74"); \
TRUE_BRANCH_60: print_info("TRUE_BRANCH_60"); \
val = NUMOBJ(1); \
goto CONTINUE; \
AFTER_IF_62: print_info("AFTER_IF_62"); \
AFTER_LAMBDA_59: print_info("AFTER_LAMBDA_59"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_75, env); \
goto AFTER_LAMBDA_76; \
ENTRY_75: print_info("ENTRY_75"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_77, env); \
goto AFTER_LAMBDA_78; \
ENTRY_77: print_info("ENTRY_77"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_82; \
COMPILED_83: print_info("COMPILED_83"); \
cont = LABELOBJ(_AFTER_CALL_84); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_82: print_info("PRIMITIVE_82"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_84: print_info("AFTER_CALL_84"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_79; \
FALSE_BRANCH_80: print_info("FALSE_BRANCH_80"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("*"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_88; \
COMPILED_89: print_info("COMPILED_89"); \
cont = LABELOBJ(_AFTER_CALL_90); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_88: print_info("PRIMITIVE_88"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_90: print_info("AFTER_CALL_90"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_85; \
COMPILED_86: print_info("COMPILED_86"); \
cont = LABELOBJ(_AFTER_CALL_87); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_85: print_info("PRIMITIVE_85"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_87: print_info("AFTER_CALL_87"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_91; \
COMPILED_92: print_info("COMPILED_92"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_91: print_info("PRIMITIVE_91"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_93: print_info("AFTER_CALL_93"); \
TRUE_BRANCH_79: print_info("TRUE_BRANCH_79"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_81: print_info("AFTER_IF_81"); \
AFTER_LAMBDA_78: print_info("AFTER_LAMBDA_78"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_94; \
COMPILED_95: print_info("COMPILED_95"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_94: print_info("PRIMITIVE_94"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_96: print_info("AFTER_CALL_96"); \
AFTER_LAMBDA_76: print_info("AFTER_LAMBDA_76"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_97, env); \
goto AFTER_LAMBDA_98; \
ENTRY_97: print_info("ENTRY_97"); \
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
if (isPrimitive(func)) goto PRIMITIVE_102; \
COMPILED_103: print_info("COMPILED_103"); \
cont = LABELOBJ(_AFTER_CALL_104); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_102: print_info("PRIMITIVE_102"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_104: print_info("AFTER_CALL_104"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_99; \
FALSE_BRANCH_100: print_info("FALSE_BRANCH_100"); \
func = lookup(NAMEOBJ("+"), env); \
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
if (isPrimitive(func)) goto PRIMITIVE_111; \
COMPILED_112: print_info("COMPILED_112"); \
cont = LABELOBJ(_AFTER_CALL_113); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_111: print_info("PRIMITIVE_111"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_113: print_info("AFTER_CALL_113"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_114; \
COMPILED_115: print_info("COMPILED_115"); \
cont = LABELOBJ(_AFTER_CALL_116); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_114: print_info("PRIMITIVE_114"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_116: print_info("AFTER_CALL_116"); \
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
if (isPrimitive(func)) goto PRIMITIVE_105; \
COMPILED_106: print_info("COMPILED_106"); \
cont = LABELOBJ(_AFTER_CALL_107); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_105: print_info("PRIMITIVE_105"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_107: print_info("AFTER_CALL_107"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_108; \
COMPILED_109: print_info("COMPILED_109"); \
cont = LABELOBJ(_AFTER_CALL_110); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_108: print_info("PRIMITIVE_108"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_110: print_info("AFTER_CALL_110"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_117; \
COMPILED_118: print_info("COMPILED_118"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_117: print_info("PRIMITIVE_117"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_119: print_info("AFTER_CALL_119"); \
TRUE_BRANCH_99: print_info("TRUE_BRANCH_99"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
AFTER_IF_101: print_info("AFTER_IF_101"); \
AFTER_LAMBDA_98: print_info("AFTER_LAMBDA_98"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_120, env); \
goto AFTER_LAMBDA_121; \
ENTRY_120: print_info("ENTRY_120"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_122, env); \
goto AFTER_LAMBDA_123; \
ENTRY_122: print_info("ENTRY_122"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_127; \
COMPILED_128: print_info("COMPILED_128"); \
cont = LABELOBJ(_AFTER_CALL_129); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_127: print_info("PRIMITIVE_127"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_129: print_info("AFTER_CALL_129"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_124; \
FALSE_BRANCH_125: print_info("FALSE_BRANCH_125"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("+"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("a"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_133; \
COMPILED_134: print_info("COMPILED_134"); \
cont = LABELOBJ(_AFTER_CALL_135); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_133: print_info("PRIMITIVE_133"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_135: print_info("AFTER_CALL_135"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, arglist); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_130; \
COMPILED_131: print_info("COMPILED_131"); \
cont = LABELOBJ(_AFTER_CALL_132); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_130: print_info("PRIMITIVE_130"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_132: print_info("AFTER_CALL_132"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_136; \
COMPILED_137: print_info("COMPILED_137"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_136: print_info("PRIMITIVE_136"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_138: print_info("AFTER_CALL_138"); \
TRUE_BRANCH_124: print_info("TRUE_BRANCH_124"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
AFTER_IF_126: print_info("AFTER_IF_126"); \
AFTER_LAMBDA_123: print_info("AFTER_LAMBDA_123"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_139; \
COMPILED_140: print_info("COMPILED_140"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_139: print_info("PRIMITIVE_139"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_141: print_info("AFTER_CALL_141"); \
AFTER_LAMBDA_121: print_info("AFTER_LAMBDA_121"); \
defineVar(NAMEOBJ("iterative_fibonacci_compiled"), val, env); \
val = lookup(NAMEOBJ("iterative_factorial_compiled"), env); \
defineVar(NAMEOBJ("factorial"), val, env); \
val = lookup(NAMEOBJ("iterative_fibonacci_compiled"), env); \
defineVar(NAMEOBJ("fibonacci"), val, env); \
val = COMPOBJ(_ENTRY_142, env); \
goto AFTER_LAMBDA_143; \
ENTRY_142: print_info("ENTRY_142"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_144, env); \
goto CONTINUE; \
ENTRY_144: print_info("ENTRY_144"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("s"), env); \
val = lookup(NAMEOBJ("y"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("x"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_146; \
COMPILED_147: print_info("COMPILED_147"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_146: print_info("PRIMITIVE_146"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_148: print_info("AFTER_CALL_148"); \
AFTER_LAMBDA_145: print_info("AFTER_LAMBDA_145"); \
AFTER_LAMBDA_143: print_info("AFTER_LAMBDA_143"); \
defineVar(NAMEOBJ("church_cons"), val, env); \
val = COMPOBJ(_ENTRY_149, env); \
goto AFTER_LAMBDA_150; \
ENTRY_149: print_info("ENTRY_149"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_151, env); \
goto AFTER_LAMBDA_152; \
ENTRY_151: print_info("ENTRY_151"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("x"), env); \
goto CONTINUE; \
AFTER_LAMBDA_152: print_info("AFTER_LAMBDA_152"); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_153; \
COMPILED_154: print_info("COMPILED_154"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_153: print_info("PRIMITIVE_153"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_155: print_info("AFTER_CALL_155"); \
AFTER_LAMBDA_150: print_info("AFTER_LAMBDA_150"); \
defineVar(NAMEOBJ("church_car"), val, env); \
val = COMPOBJ(_ENTRY_156, env); \
goto AFTER_LAMBDA_157; \
ENTRY_156: print_info("ENTRY_156"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_158, env); \
goto AFTER_LAMBDA_159; \
ENTRY_158: print_info("ENTRY_158"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("y"), env); \
goto CONTINUE; \
AFTER_LAMBDA_159: print_info("AFTER_LAMBDA_159"); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_160; \
COMPILED_161: print_info("COMPILED_161"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_160: print_info("PRIMITIVE_160"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_162: print_info("AFTER_CALL_162"); \
AFTER_LAMBDA_157: print_info("AFTER_LAMBDA_157"); \
defineVar(NAMEOBJ("church_cdr"), val, env); \
val = parse("()\n"); \
defineVar(NAMEOBJ("nil"), val, env); \
val = COMPOBJ(_ENTRY_163, env); \
goto AFTER_LAMBDA_164; \
ENTRY_163: print_info("ENTRY_163"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_168; \
COMPILED_169: print_info("COMPILED_169"); \
cont = LABELOBJ(_AFTER_CALL_170); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_168: print_info("PRIMITIVE_168"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_170: print_info("AFTER_CALL_170"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_165; \
FALSE_BRANCH_166: print_info("FALSE_BRANCH_166"); \
func = lookup(NAMEOBJ("add1"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("length"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_171; \
COMPILED_172: print_info("COMPILED_172"); \
cont = LABELOBJ(_AFTER_CALL_173); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_171: print_info("PRIMITIVE_171"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_173: print_info("AFTER_CALL_173"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_174; \
COMPILED_175: print_info("COMPILED_175"); \
cont = LABELOBJ(_AFTER_CALL_176); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_174: print_info("PRIMITIVE_174"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_176: print_info("AFTER_CALL_176"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_177; \
COMPILED_178: print_info("COMPILED_178"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_177: print_info("PRIMITIVE_177"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_179: print_info("AFTER_CALL_179"); \
TRUE_BRANCH_165: print_info("TRUE_BRANCH_165"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_167: print_info("AFTER_IF_167"); \
AFTER_LAMBDA_164: print_info("AFTER_LAMBDA_164"); \
defineVar(NAMEOBJ("length"), val, env); \
goto DONE;

#define COMP_CONT(REG) \
if (GETLABEL(REG) == _ENTRY_1) goto ENTRY_1; \
if (GETLABEL(REG) == _AFTER_LAMBDA_2) goto AFTER_LAMBDA_2; \
if (GETLABEL(REG) == _TRUE_BRANCH_3) goto TRUE_BRANCH_3; \
if (GETLABEL(REG) == _FALSE_BRANCH_4) goto FALSE_BRANCH_4; \
if (GETLABEL(REG) == _AFTER_IF_5) goto AFTER_IF_5; \
if (GETLABEL(REG) == _PRIMITIVE_6) goto PRIMITIVE_6; \
if (GETLABEL(REG) == _COMPILED_7) goto COMPILED_7; \
if (GETLABEL(REG) == _AFTER_CALL_8) goto AFTER_CALL_8; \
if (GETLABEL(REG) == _PRIMITIVE_9) goto PRIMITIVE_9; \
if (GETLABEL(REG) == _COMPILED_10) goto COMPILED_10; \
if (GETLABEL(REG) == _AFTER_CALL_11) goto AFTER_CALL_11; \
if (GETLABEL(REG) == _PRIMITIVE_12) goto PRIMITIVE_12; \
if (GETLABEL(REG) == _COMPILED_13) goto COMPILED_13; \
if (GETLABEL(REG) == _AFTER_CALL_14) goto AFTER_CALL_14; \
if (GETLABEL(REG) == _PRIMITIVE_15) goto PRIMITIVE_15; \
if (GETLABEL(REG) == _COMPILED_16) goto COMPILED_16; \
if (GETLABEL(REG) == _AFTER_CALL_17) goto AFTER_CALL_17; \
if (GETLABEL(REG) == _ENTRY_18) goto ENTRY_18; \
if (GETLABEL(REG) == _AFTER_LAMBDA_19) goto AFTER_LAMBDA_19; \
if (GETLABEL(REG) == _TRUE_BRANCH_20) goto TRUE_BRANCH_20; \
if (GETLABEL(REG) == _FALSE_BRANCH_21) goto FALSE_BRANCH_21; \
if (GETLABEL(REG) == _AFTER_IF_22) goto AFTER_IF_22; \
if (GETLABEL(REG) == _PRIMITIVE_23) goto PRIMITIVE_23; \
if (GETLABEL(REG) == _COMPILED_24) goto COMPILED_24; \
if (GETLABEL(REG) == _AFTER_CALL_25) goto AFTER_CALL_25; \
if (GETLABEL(REG) == _PRIMITIVE_26) goto PRIMITIVE_26; \
if (GETLABEL(REG) == _COMPILED_27) goto COMPILED_27; \
if (GETLABEL(REG) == _AFTER_CALL_28) goto AFTER_CALL_28; \
if (GETLABEL(REG) == _PRIMITIVE_29) goto PRIMITIVE_29; \
if (GETLABEL(REG) == _COMPILED_30) goto COMPILED_30; \
if (GETLABEL(REG) == _AFTER_CALL_31) goto AFTER_CALL_31; \
if (GETLABEL(REG) == _PRIMITIVE_32) goto PRIMITIVE_32; \
if (GETLABEL(REG) == _COMPILED_33) goto COMPILED_33; \
if (GETLABEL(REG) == _AFTER_CALL_34) goto AFTER_CALL_34; \
if (GETLABEL(REG) == _PRIMITIVE_35) goto PRIMITIVE_35; \
if (GETLABEL(REG) == _COMPILED_36) goto COMPILED_36; \
if (GETLABEL(REG) == _AFTER_CALL_37) goto AFTER_CALL_37; \
if (GETLABEL(REG) == _ENTRY_38) goto ENTRY_38; \
if (GETLABEL(REG) == _AFTER_LAMBDA_39) goto AFTER_LAMBDA_39; \
if (GETLABEL(REG) == _TRUE_BRANCH_40) goto TRUE_BRANCH_40; \
if (GETLABEL(REG) == _FALSE_BRANCH_41) goto FALSE_BRANCH_41; \
if (GETLABEL(REG) == _AFTER_IF_42) goto AFTER_IF_42; \
if (GETLABEL(REG) == _PRIMITIVE_43) goto PRIMITIVE_43; \
if (GETLABEL(REG) == _COMPILED_44) goto COMPILED_44; \
if (GETLABEL(REG) == _AFTER_CALL_45) goto AFTER_CALL_45; \
if (GETLABEL(REG) == _PRIMITIVE_46) goto PRIMITIVE_46; \
if (GETLABEL(REG) == _COMPILED_47) goto COMPILED_47; \
if (GETLABEL(REG) == _AFTER_CALL_48) goto AFTER_CALL_48; \
if (GETLABEL(REG) == _PRIMITIVE_49) goto PRIMITIVE_49; \
if (GETLABEL(REG) == _COMPILED_50) goto COMPILED_50; \
if (GETLABEL(REG) == _AFTER_CALL_51) goto AFTER_CALL_51; \
if (GETLABEL(REG) == _PRIMITIVE_52) goto PRIMITIVE_52; \
if (GETLABEL(REG) == _COMPILED_53) goto COMPILED_53; \
if (GETLABEL(REG) == _AFTER_CALL_54) goto AFTER_CALL_54; \
if (GETLABEL(REG) == _PRIMITIVE_55) goto PRIMITIVE_55; \
if (GETLABEL(REG) == _COMPILED_56) goto COMPILED_56; \
if (GETLABEL(REG) == _AFTER_CALL_57) goto AFTER_CALL_57; \
if (GETLABEL(REG) == _ENTRY_58) goto ENTRY_58; \
if (GETLABEL(REG) == _AFTER_LAMBDA_59) goto AFTER_LAMBDA_59; \
if (GETLABEL(REG) == _TRUE_BRANCH_60) goto TRUE_BRANCH_60; \
if (GETLABEL(REG) == _FALSE_BRANCH_61) goto FALSE_BRANCH_61; \
if (GETLABEL(REG) == _AFTER_IF_62) goto AFTER_IF_62; \
if (GETLABEL(REG) == _PRIMITIVE_63) goto PRIMITIVE_63; \
if (GETLABEL(REG) == _COMPILED_64) goto COMPILED_64; \
if (GETLABEL(REG) == _AFTER_CALL_65) goto AFTER_CALL_65; \
if (GETLABEL(REG) == _PRIMITIVE_66) goto PRIMITIVE_66; \
if (GETLABEL(REG) == _COMPILED_67) goto COMPILED_67; \
if (GETLABEL(REG) == _AFTER_CALL_68) goto AFTER_CALL_68; \
if (GETLABEL(REG) == _PRIMITIVE_69) goto PRIMITIVE_69; \
if (GETLABEL(REG) == _COMPILED_70) goto COMPILED_70; \
if (GETLABEL(REG) == _AFTER_CALL_71) goto AFTER_CALL_71; \
if (GETLABEL(REG) == _PRIMITIVE_72) goto PRIMITIVE_72; \
if (GETLABEL(REG) == _COMPILED_73) goto COMPILED_73; \
if (GETLABEL(REG) == _AFTER_CALL_74) goto AFTER_CALL_74; \
if (GETLABEL(REG) == _ENTRY_75) goto ENTRY_75; \
if (GETLABEL(REG) == _AFTER_LAMBDA_76) goto AFTER_LAMBDA_76; \
if (GETLABEL(REG) == _ENTRY_77) goto ENTRY_77; \
if (GETLABEL(REG) == _AFTER_LAMBDA_78) goto AFTER_LAMBDA_78; \
if (GETLABEL(REG) == _TRUE_BRANCH_79) goto TRUE_BRANCH_79; \
if (GETLABEL(REG) == _FALSE_BRANCH_80) goto FALSE_BRANCH_80; \
if (GETLABEL(REG) == _AFTER_IF_81) goto AFTER_IF_81; \
if (GETLABEL(REG) == _PRIMITIVE_82) goto PRIMITIVE_82; \
if (GETLABEL(REG) == _COMPILED_83) goto COMPILED_83; \
if (GETLABEL(REG) == _AFTER_CALL_84) goto AFTER_CALL_84; \
if (GETLABEL(REG) == _PRIMITIVE_85) goto PRIMITIVE_85; \
if (GETLABEL(REG) == _COMPILED_86) goto COMPILED_86; \
if (GETLABEL(REG) == _AFTER_CALL_87) goto AFTER_CALL_87; \
if (GETLABEL(REG) == _PRIMITIVE_88) goto PRIMITIVE_88; \
if (GETLABEL(REG) == _COMPILED_89) goto COMPILED_89; \
if (GETLABEL(REG) == _AFTER_CALL_90) goto AFTER_CALL_90; \
if (GETLABEL(REG) == _PRIMITIVE_91) goto PRIMITIVE_91; \
if (GETLABEL(REG) == _COMPILED_92) goto COMPILED_92; \
if (GETLABEL(REG) == _AFTER_CALL_93) goto AFTER_CALL_93; \
if (GETLABEL(REG) == _PRIMITIVE_94) goto PRIMITIVE_94; \
if (GETLABEL(REG) == _COMPILED_95) goto COMPILED_95; \
if (GETLABEL(REG) == _AFTER_CALL_96) goto AFTER_CALL_96; \
if (GETLABEL(REG) == _ENTRY_97) goto ENTRY_97; \
if (GETLABEL(REG) == _AFTER_LAMBDA_98) goto AFTER_LAMBDA_98; \
if (GETLABEL(REG) == _TRUE_BRANCH_99) goto TRUE_BRANCH_99; \
if (GETLABEL(REG) == _FALSE_BRANCH_100) goto FALSE_BRANCH_100; \
if (GETLABEL(REG) == _AFTER_IF_101) goto AFTER_IF_101; \
if (GETLABEL(REG) == _PRIMITIVE_102) goto PRIMITIVE_102; \
if (GETLABEL(REG) == _COMPILED_103) goto COMPILED_103; \
if (GETLABEL(REG) == _AFTER_CALL_104) goto AFTER_CALL_104; \
if (GETLABEL(REG) == _PRIMITIVE_105) goto PRIMITIVE_105; \
if (GETLABEL(REG) == _COMPILED_106) goto COMPILED_106; \
if (GETLABEL(REG) == _AFTER_CALL_107) goto AFTER_CALL_107; \
if (GETLABEL(REG) == _PRIMITIVE_108) goto PRIMITIVE_108; \
if (GETLABEL(REG) == _COMPILED_109) goto COMPILED_109; \
if (GETLABEL(REG) == _AFTER_CALL_110) goto AFTER_CALL_110; \
if (GETLABEL(REG) == _PRIMITIVE_111) goto PRIMITIVE_111; \
if (GETLABEL(REG) == _COMPILED_112) goto COMPILED_112; \
if (GETLABEL(REG) == _AFTER_CALL_113) goto AFTER_CALL_113; \
if (GETLABEL(REG) == _PRIMITIVE_114) goto PRIMITIVE_114; \
if (GETLABEL(REG) == _COMPILED_115) goto COMPILED_115; \
if (GETLABEL(REG) == _AFTER_CALL_116) goto AFTER_CALL_116; \
if (GETLABEL(REG) == _PRIMITIVE_117) goto PRIMITIVE_117; \
if (GETLABEL(REG) == _COMPILED_118) goto COMPILED_118; \
if (GETLABEL(REG) == _AFTER_CALL_119) goto AFTER_CALL_119; \
if (GETLABEL(REG) == _ENTRY_120) goto ENTRY_120; \
if (GETLABEL(REG) == _AFTER_LAMBDA_121) goto AFTER_LAMBDA_121; \
if (GETLABEL(REG) == _ENTRY_122) goto ENTRY_122; \
if (GETLABEL(REG) == _AFTER_LAMBDA_123) goto AFTER_LAMBDA_123; \
if (GETLABEL(REG) == _TRUE_BRANCH_124) goto TRUE_BRANCH_124; \
if (GETLABEL(REG) == _FALSE_BRANCH_125) goto FALSE_BRANCH_125; \
if (GETLABEL(REG) == _AFTER_IF_126) goto AFTER_IF_126; \
if (GETLABEL(REG) == _PRIMITIVE_127) goto PRIMITIVE_127; \
if (GETLABEL(REG) == _COMPILED_128) goto COMPILED_128; \
if (GETLABEL(REG) == _AFTER_CALL_129) goto AFTER_CALL_129; \
if (GETLABEL(REG) == _PRIMITIVE_130) goto PRIMITIVE_130; \
if (GETLABEL(REG) == _COMPILED_131) goto COMPILED_131; \
if (GETLABEL(REG) == _AFTER_CALL_132) goto AFTER_CALL_132; \
if (GETLABEL(REG) == _PRIMITIVE_133) goto PRIMITIVE_133; \
if (GETLABEL(REG) == _COMPILED_134) goto COMPILED_134; \
if (GETLABEL(REG) == _AFTER_CALL_135) goto AFTER_CALL_135; \
if (GETLABEL(REG) == _PRIMITIVE_136) goto PRIMITIVE_136; \
if (GETLABEL(REG) == _COMPILED_137) goto COMPILED_137; \
if (GETLABEL(REG) == _AFTER_CALL_138) goto AFTER_CALL_138; \
if (GETLABEL(REG) == _PRIMITIVE_139) goto PRIMITIVE_139; \
if (GETLABEL(REG) == _COMPILED_140) goto COMPILED_140; \
if (GETLABEL(REG) == _AFTER_CALL_141) goto AFTER_CALL_141; \
if (GETLABEL(REG) == _ENTRY_142) goto ENTRY_142; \
if (GETLABEL(REG) == _AFTER_LAMBDA_143) goto AFTER_LAMBDA_143; \
if (GETLABEL(REG) == _ENTRY_144) goto ENTRY_144; \
if (GETLABEL(REG) == _AFTER_LAMBDA_145) goto AFTER_LAMBDA_145; \
if (GETLABEL(REG) == _PRIMITIVE_146) goto PRIMITIVE_146; \
if (GETLABEL(REG) == _COMPILED_147) goto COMPILED_147; \
if (GETLABEL(REG) == _AFTER_CALL_148) goto AFTER_CALL_148; \
if (GETLABEL(REG) == _ENTRY_149) goto ENTRY_149; \
if (GETLABEL(REG) == _AFTER_LAMBDA_150) goto AFTER_LAMBDA_150; \
if (GETLABEL(REG) == _ENTRY_151) goto ENTRY_151; \
if (GETLABEL(REG) == _AFTER_LAMBDA_152) goto AFTER_LAMBDA_152; \
if (GETLABEL(REG) == _PRIMITIVE_153) goto PRIMITIVE_153; \
if (GETLABEL(REG) == _COMPILED_154) goto COMPILED_154; \
if (GETLABEL(REG) == _AFTER_CALL_155) goto AFTER_CALL_155; \
if (GETLABEL(REG) == _ENTRY_156) goto ENTRY_156; \
if (GETLABEL(REG) == _AFTER_LAMBDA_157) goto AFTER_LAMBDA_157; \
if (GETLABEL(REG) == _ENTRY_158) goto ENTRY_158; \
if (GETLABEL(REG) == _AFTER_LAMBDA_159) goto AFTER_LAMBDA_159; \
if (GETLABEL(REG) == _PRIMITIVE_160) goto PRIMITIVE_160; \
if (GETLABEL(REG) == _COMPILED_161) goto COMPILED_161; \
if (GETLABEL(REG) == _AFTER_CALL_162) goto AFTER_CALL_162; \
if (GETLABEL(REG) == _ENTRY_163) goto ENTRY_163; \
if (GETLABEL(REG) == _AFTER_LAMBDA_164) goto AFTER_LAMBDA_164; \
if (GETLABEL(REG) == _TRUE_BRANCH_165) goto TRUE_BRANCH_165; \
if (GETLABEL(REG) == _FALSE_BRANCH_166) goto FALSE_BRANCH_166; \
if (GETLABEL(REG) == _AFTER_IF_167) goto AFTER_IF_167; \
if (GETLABEL(REG) == _PRIMITIVE_168) goto PRIMITIVE_168; \
if (GETLABEL(REG) == _COMPILED_169) goto COMPILED_169; \
if (GETLABEL(REG) == _AFTER_CALL_170) goto AFTER_CALL_170; \
if (GETLABEL(REG) == _PRIMITIVE_171) goto PRIMITIVE_171; \
if (GETLABEL(REG) == _COMPILED_172) goto COMPILED_172; \
if (GETLABEL(REG) == _AFTER_CALL_173) goto AFTER_CALL_173; \
if (GETLABEL(REG) == _PRIMITIVE_174) goto PRIMITIVE_174; \
if (GETLABEL(REG) == _COMPILED_175) goto COMPILED_175; \
if (GETLABEL(REG) == _AFTER_CALL_176) goto AFTER_CALL_176; \
if (GETLABEL(REG) == _PRIMITIVE_177) goto PRIMITIVE_177; \
if (GETLABEL(REG) == _COMPILED_178) goto COMPILED_178; \
if (GETLABEL(REG) == _AFTER_CALL_179) goto AFTER_CALL_179;

#define ALL_COMPILED_LABELS \
_ENTRY_1, \
_AFTER_LAMBDA_2, \
_TRUE_BRANCH_3, \
_FALSE_BRANCH_4, \
_AFTER_IF_5, \
_PRIMITIVE_6, \
_COMPILED_7, \
_AFTER_CALL_8, \
_PRIMITIVE_9, \
_COMPILED_10, \
_AFTER_CALL_11, \
_PRIMITIVE_12, \
_COMPILED_13, \
_AFTER_CALL_14, \
_PRIMITIVE_15, \
_COMPILED_16, \
_AFTER_CALL_17, \
_ENTRY_18, \
_AFTER_LAMBDA_19, \
_TRUE_BRANCH_20, \
_FALSE_BRANCH_21, \
_AFTER_IF_22, \
_PRIMITIVE_23, \
_COMPILED_24, \
_AFTER_CALL_25, \
_PRIMITIVE_26, \
_COMPILED_27, \
_AFTER_CALL_28, \
_PRIMITIVE_29, \
_COMPILED_30, \
_AFTER_CALL_31, \
_PRIMITIVE_32, \
_COMPILED_33, \
_AFTER_CALL_34, \
_PRIMITIVE_35, \
_COMPILED_36, \
_AFTER_CALL_37, \
_ENTRY_38, \
_AFTER_LAMBDA_39, \
_TRUE_BRANCH_40, \
_FALSE_BRANCH_41, \
_AFTER_IF_42, \
_PRIMITIVE_43, \
_COMPILED_44, \
_AFTER_CALL_45, \
_PRIMITIVE_46, \
_COMPILED_47, \
_AFTER_CALL_48, \
_PRIMITIVE_49, \
_COMPILED_50, \
_AFTER_CALL_51, \
_PRIMITIVE_52, \
_COMPILED_53, \
_AFTER_CALL_54, \
_PRIMITIVE_55, \
_COMPILED_56, \
_AFTER_CALL_57, \
_ENTRY_58, \
_AFTER_LAMBDA_59, \
_TRUE_BRANCH_60, \
_FALSE_BRANCH_61, \
_AFTER_IF_62, \
_PRIMITIVE_63, \
_COMPILED_64, \
_AFTER_CALL_65, \
_PRIMITIVE_66, \
_COMPILED_67, \
_AFTER_CALL_68, \
_PRIMITIVE_69, \
_COMPILED_70, \
_AFTER_CALL_71, \
_PRIMITIVE_72, \
_COMPILED_73, \
_AFTER_CALL_74, \
_ENTRY_75, \
_AFTER_LAMBDA_76, \
_ENTRY_77, \
_AFTER_LAMBDA_78, \
_TRUE_BRANCH_79, \
_FALSE_BRANCH_80, \
_AFTER_IF_81, \
_PRIMITIVE_82, \
_COMPILED_83, \
_AFTER_CALL_84, \
_PRIMITIVE_85, \
_COMPILED_86, \
_AFTER_CALL_87, \
_PRIMITIVE_88, \
_COMPILED_89, \
_AFTER_CALL_90, \
_PRIMITIVE_91, \
_COMPILED_92, \
_AFTER_CALL_93, \
_PRIMITIVE_94, \
_COMPILED_95, \
_AFTER_CALL_96, \
_ENTRY_97, \
_AFTER_LAMBDA_98, \
_TRUE_BRANCH_99, \
_FALSE_BRANCH_100, \
_AFTER_IF_101, \
_PRIMITIVE_102, \
_COMPILED_103, \
_AFTER_CALL_104, \
_PRIMITIVE_105, \
_COMPILED_106, \
_AFTER_CALL_107, \
_PRIMITIVE_108, \
_COMPILED_109, \
_AFTER_CALL_110, \
_PRIMITIVE_111, \
_COMPILED_112, \
_AFTER_CALL_113, \
_PRIMITIVE_114, \
_COMPILED_115, \
_AFTER_CALL_116, \
_PRIMITIVE_117, \
_COMPILED_118, \
_AFTER_CALL_119, \
_ENTRY_120, \
_AFTER_LAMBDA_121, \
_ENTRY_122, \
_AFTER_LAMBDA_123, \
_TRUE_BRANCH_124, \
_FALSE_BRANCH_125, \
_AFTER_IF_126, \
_PRIMITIVE_127, \
_COMPILED_128, \
_AFTER_CALL_129, \
_PRIMITIVE_130, \
_COMPILED_131, \
_AFTER_CALL_132, \
_PRIMITIVE_133, \
_COMPILED_134, \
_AFTER_CALL_135, \
_PRIMITIVE_136, \
_COMPILED_137, \
_AFTER_CALL_138, \
_PRIMITIVE_139, \
_COMPILED_140, \
_AFTER_CALL_141, \
_ENTRY_142, \
_AFTER_LAMBDA_143, \
_ENTRY_144, \
_AFTER_LAMBDA_145, \
_PRIMITIVE_146, \
_COMPILED_147, \
_AFTER_CALL_148, \
_ENTRY_149, \
_AFTER_LAMBDA_150, \
_ENTRY_151, \
_AFTER_LAMBDA_152, \
_PRIMITIVE_153, \
_COMPILED_154, \
_AFTER_CALL_155, \
_ENTRY_156, \
_AFTER_LAMBDA_157, \
_ENTRY_158, \
_AFTER_LAMBDA_159, \
_PRIMITIVE_160, \
_COMPILED_161, \
_AFTER_CALL_162, \
_ENTRY_163, \
_AFTER_LAMBDA_164, \
_TRUE_BRANCH_165, \
_FALSE_BRANCH_166, \
_AFTER_IF_167, \
_PRIMITIVE_168, \
_COMPILED_169, \
_AFTER_CALL_170, \
_PRIMITIVE_171, \
_COMPILED_172, \
_AFTER_CALL_173, \
_PRIMITIVE_174, \
_COMPILED_175, \
_AFTER_CALL_176, \
_PRIMITIVE_177, \
_COMPILED_178, \
_AFTER_CALL_179

#endif
