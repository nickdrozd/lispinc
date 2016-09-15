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
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(0); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_3; \
COMPILED_4: print_info("COMPILED_4"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_3: print_info("PRIMITIVE_3"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_5: print_info("AFTER_CALL_5"); \
AFTER_LAMBDA_2: print_info("AFTER_LAMBDA_2"); \
defineVar(NAMEOBJ("zero?"), val, env); \
val = COMPOBJ(_ENTRY_6, env); \
goto AFTER_LAMBDA_7; \
ENTRY_6: print_info("ENTRY_6"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("+"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_8; \
COMPILED_9: print_info("COMPILED_9"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_8: print_info("PRIMITIVE_8"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_10: print_info("AFTER_CALL_10"); \
AFTER_LAMBDA_7: print_info("AFTER_LAMBDA_7"); \
defineVar(NAMEOBJ("add1"), val, env); \
val = COMPOBJ(_ENTRY_11, env); \
goto AFTER_LAMBDA_12; \
ENTRY_11: print_info("ENTRY_11"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_13; \
COMPILED_14: print_info("COMPILED_14"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_13: print_info("PRIMITIVE_13"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_15: print_info("AFTER_CALL_15"); \
AFTER_LAMBDA_12: print_info("AFTER_LAMBDA_12"); \
defineVar(NAMEOBJ("sub1"), val, env); \
val = COMPOBJ(_ENTRY_16, env); \
goto AFTER_LAMBDA_17; \
ENTRY_16: print_info("ENTRY_16"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_21; \
COMPILED_22: print_info("COMPILED_22"); \
cont = LABELOBJ(_AFTER_CALL_23); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_21: print_info("PRIMITIVE_21"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_23: print_info("AFTER_CALL_23"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_18; \
FALSE_BRANCH_19: print_info("FALSE_BRANCH_19"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_24; \
COMPILED_25: print_info("COMPILED_25"); \
cont = LABELOBJ(_AFTER_CALL_26); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_24: print_info("PRIMITIVE_24"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_26: print_info("AFTER_CALL_26"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_27; \
COMPILED_28: print_info("COMPILED_28"); \
cont = LABELOBJ(_AFTER_CALL_29); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_27: print_info("PRIMITIVE_27"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_29: print_info("AFTER_CALL_29"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_30; \
COMPILED_31: print_info("COMPILED_31"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_30: print_info("PRIMITIVE_30"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_32: print_info("AFTER_CALL_32"); \
TRUE_BRANCH_18: print_info("TRUE_BRANCH_18"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_20: print_info("AFTER_IF_20"); \
AFTER_LAMBDA_17: print_info("AFTER_LAMBDA_17"); \
defineVar(NAMEOBJ("recursive_triangular_compiled"), val, env); \
val = COMPOBJ(_ENTRY_33, env); \
goto AFTER_LAMBDA_34; \
ENTRY_33: print_info("ENTRY_33"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_38; \
COMPILED_39: print_info("COMPILED_39"); \
cont = LABELOBJ(_AFTER_CALL_40); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_38: print_info("PRIMITIVE_38"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_40: print_info("AFTER_CALL_40"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_35; \
FALSE_BRANCH_36: print_info("FALSE_BRANCH_36"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_44; \
COMPILED_45: print_info("COMPILED_45"); \
cont = LABELOBJ(_AFTER_CALL_46); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_44: print_info("PRIMITIVE_44"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_46: print_info("AFTER_CALL_46"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_47; \
COMPILED_48: print_info("COMPILED_48"); \
cont = LABELOBJ(_AFTER_CALL_49); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_47: print_info("PRIMITIVE_47"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_49: print_info("AFTER_CALL_49"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_41; \
COMPILED_42: print_info("COMPILED_42"); \
cont = LABELOBJ(_AFTER_CALL_43); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_41: print_info("PRIMITIVE_41"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_43: print_info("AFTER_CALL_43"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_50; \
COMPILED_51: print_info("COMPILED_51"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_50: print_info("PRIMITIVE_50"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_52: print_info("AFTER_CALL_52"); \
TRUE_BRANCH_35: print_info("TRUE_BRANCH_35"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_37: print_info("AFTER_IF_37"); \
AFTER_LAMBDA_34: print_info("AFTER_LAMBDA_34"); \
defineVar(NAMEOBJ("recursive_tetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_53, env); \
goto AFTER_LAMBDA_54; \
ENTRY_53: print_info("ENTRY_53"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_58; \
COMPILED_59: print_info("COMPILED_59"); \
cont = LABELOBJ(_AFTER_CALL_60); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_58: print_info("PRIMITIVE_58"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_60: print_info("AFTER_CALL_60"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_55; \
FALSE_BRANCH_56: print_info("FALSE_BRANCH_56"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_supertetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_64; \
COMPILED_65: print_info("COMPILED_65"); \
cont = LABELOBJ(_AFTER_CALL_66); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_64: print_info("PRIMITIVE_64"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_66: print_info("AFTER_CALL_66"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_67; \
COMPILED_68: print_info("COMPILED_68"); \
cont = LABELOBJ(_AFTER_CALL_69); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_67: print_info("PRIMITIVE_67"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_69: print_info("AFTER_CALL_69"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_61; \
COMPILED_62: print_info("COMPILED_62"); \
cont = LABELOBJ(_AFTER_CALL_63); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_61: print_info("PRIMITIVE_61"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_63: print_info("AFTER_CALL_63"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_70; \
COMPILED_71: print_info("COMPILED_71"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_70: print_info("PRIMITIVE_70"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_72: print_info("AFTER_CALL_72"); \
TRUE_BRANCH_55: print_info("TRUE_BRANCH_55"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_57: print_info("AFTER_IF_57"); \
AFTER_LAMBDA_54: print_info("AFTER_LAMBDA_54"); \
defineVar(NAMEOBJ("recursive_supertetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_73, env); \
goto AFTER_LAMBDA_74; \
ENTRY_73: print_info("ENTRY_73"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_78; \
COMPILED_79: print_info("COMPILED_79"); \
cont = LABELOBJ(_AFTER_CALL_80); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_78: print_info("PRIMITIVE_78"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_80: print_info("AFTER_CALL_80"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_75; \
FALSE_BRANCH_76: print_info("FALSE_BRANCH_76"); \
func = lookup(NAMEOBJ("*"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_81; \
COMPILED_82: print_info("COMPILED_82"); \
cont = LABELOBJ(_AFTER_CALL_83); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_81: print_info("PRIMITIVE_81"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_83: print_info("AFTER_CALL_83"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_84; \
COMPILED_85: print_info("COMPILED_85"); \
cont = LABELOBJ(_AFTER_CALL_86); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_84: print_info("PRIMITIVE_84"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_86: print_info("AFTER_CALL_86"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_87; \
COMPILED_88: print_info("COMPILED_88"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_87: print_info("PRIMITIVE_87"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_89: print_info("AFTER_CALL_89"); \
TRUE_BRANCH_75: print_info("TRUE_BRANCH_75"); \
val = NUMOBJ(1); \
goto CONTINUE; \
AFTER_IF_77: print_info("AFTER_IF_77"); \
AFTER_LAMBDA_74: print_info("AFTER_LAMBDA_74"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_90, env); \
goto AFTER_LAMBDA_91; \
ENTRY_90: print_info("ENTRY_90"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_92, env); \
goto AFTER_LAMBDA_93; \
ENTRY_92: print_info("ENTRY_92"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_97; \
COMPILED_98: print_info("COMPILED_98"); \
cont = LABELOBJ(_AFTER_CALL_99); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_97: print_info("PRIMITIVE_97"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_99: print_info("AFTER_CALL_99"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_94; \
FALSE_BRANCH_95: print_info("FALSE_BRANCH_95"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("*"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_103; \
COMPILED_104: print_info("COMPILED_104"); \
cont = LABELOBJ(_AFTER_CALL_105); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_103: print_info("PRIMITIVE_103"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_105: print_info("AFTER_CALL_105"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_100; \
COMPILED_101: print_info("COMPILED_101"); \
cont = LABELOBJ(_AFTER_CALL_102); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_100: print_info("PRIMITIVE_100"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_102: print_info("AFTER_CALL_102"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_106; \
COMPILED_107: print_info("COMPILED_107"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_106: print_info("PRIMITIVE_106"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_108: print_info("AFTER_CALL_108"); \
TRUE_BRANCH_94: print_info("TRUE_BRANCH_94"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_96: print_info("AFTER_IF_96"); \
AFTER_LAMBDA_93: print_info("AFTER_LAMBDA_93"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_109; \
COMPILED_110: print_info("COMPILED_110"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_109: print_info("PRIMITIVE_109"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_111: print_info("AFTER_CALL_111"); \
AFTER_LAMBDA_91: print_info("AFTER_LAMBDA_91"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_112, env); \
goto AFTER_LAMBDA_113; \
ENTRY_112: print_info("ENTRY_112"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
save(env); \
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(0); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_120; \
COMPILED_121: print_info("COMPILED_121"); \
cont = LABELOBJ(_AFTER_CALL_122); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_120: print_info("PRIMITIVE_120"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_122: print_info("AFTER_CALL_122"); \
restore(env); \
if (isTrue(val)) goto TRUE_BRANCH_117; \
FALSE_BRANCH_118: print_info("FALSE_BRANCH_118"); \
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_126; \
COMPILED_127: print_info("COMPILED_127"); \
cont = LABELOBJ(_AFTER_CALL_128); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_126: print_info("PRIMITIVE_126"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_128: print_info("AFTER_CALL_128"); \
if (isTrue(val)) goto TRUE_BRANCH_123; \
FALSE_BRANCH_124: print_info("FALSE_BRANCH_124"); \
val = NUMOBJ(0); \
goto AFTER_IF_119; \
TRUE_BRANCH_123: print_info("TRUE_BRANCH_123"); \
val = NUMOBJ(1); \
goto AFTER_IF_119; \
AFTER_IF_125: print_info("AFTER_IF_125"); \
TRUE_BRANCH_117: print_info("TRUE_BRANCH_117"); \
val = NUMOBJ(1); \
AFTER_IF_119: print_info("AFTER_IF_119"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_114; \
FALSE_BRANCH_115: print_info("FALSE_BRANCH_115"); \
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
if (isPrimitive(func)) goto PRIMITIVE_135; \
COMPILED_136: print_info("COMPILED_136"); \
cont = LABELOBJ(_AFTER_CALL_137); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_135: print_info("PRIMITIVE_135"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_137: print_info("AFTER_CALL_137"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_138; \
COMPILED_139: print_info("COMPILED_139"); \
cont = LABELOBJ(_AFTER_CALL_140); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_138: print_info("PRIMITIVE_138"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_140: print_info("AFTER_CALL_140"); \
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
if (isPrimitive(func)) goto PRIMITIVE_129; \
COMPILED_130: print_info("COMPILED_130"); \
cont = LABELOBJ(_AFTER_CALL_131); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_129: print_info("PRIMITIVE_129"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_131: print_info("AFTER_CALL_131"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_132; \
COMPILED_133: print_info("COMPILED_133"); \
cont = LABELOBJ(_AFTER_CALL_134); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_132: print_info("PRIMITIVE_132"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_134: print_info("AFTER_CALL_134"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_141; \
COMPILED_142: print_info("COMPILED_142"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_141: print_info("PRIMITIVE_141"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_143: print_info("AFTER_CALL_143"); \
TRUE_BRANCH_114: print_info("TRUE_BRANCH_114"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
AFTER_IF_116: print_info("AFTER_IF_116"); \
AFTER_LAMBDA_113: print_info("AFTER_LAMBDA_113"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_144, env); \
goto AFTER_LAMBDA_145; \
ENTRY_144: print_info("ENTRY_144"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_146, env); \
goto AFTER_LAMBDA_147; \
ENTRY_146: print_info("ENTRY_146"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_151; \
COMPILED_152: print_info("COMPILED_152"); \
cont = LABELOBJ(_AFTER_CALL_153); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_151: print_info("PRIMITIVE_151"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_153: print_info("AFTER_CALL_153"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_148; \
FALSE_BRANCH_149: print_info("FALSE_BRANCH_149"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("+"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("a"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_157; \
COMPILED_158: print_info("COMPILED_158"); \
cont = LABELOBJ(_AFTER_CALL_159); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_157: print_info("PRIMITIVE_157"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_159: print_info("AFTER_CALL_159"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, arglist); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_154; \
COMPILED_155: print_info("COMPILED_155"); \
cont = LABELOBJ(_AFTER_CALL_156); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_154: print_info("PRIMITIVE_154"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_156: print_info("AFTER_CALL_156"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_160; \
COMPILED_161: print_info("COMPILED_161"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_160: print_info("PRIMITIVE_160"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_162: print_info("AFTER_CALL_162"); \
TRUE_BRANCH_148: print_info("TRUE_BRANCH_148"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
AFTER_IF_150: print_info("AFTER_IF_150"); \
AFTER_LAMBDA_147: print_info("AFTER_LAMBDA_147"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_163; \
COMPILED_164: print_info("COMPILED_164"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_163: print_info("PRIMITIVE_163"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_165: print_info("AFTER_CALL_165"); \
AFTER_LAMBDA_145: print_info("AFTER_LAMBDA_145"); \
defineVar(NAMEOBJ("iterative_fibonacci_compiled"), val, env); \
val = lookup(NAMEOBJ("iterative_factorial_compiled"), env); \
defineVar(NAMEOBJ("factorial"), val, env); \
val = lookup(NAMEOBJ("iterative_fibonacci_compiled"), env); \
defineVar(NAMEOBJ("fibonacci"), val, env); \
val = COMPOBJ(_ENTRY_166, env); \
goto AFTER_LAMBDA_167; \
ENTRY_166: print_info("ENTRY_166"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_168, env); \
goto CONTINUE; \
ENTRY_168: print_info("ENTRY_168"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("s"), env); \
val = lookup(NAMEOBJ("y"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("x"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_170; \
COMPILED_171: print_info("COMPILED_171"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_170: print_info("PRIMITIVE_170"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_172: print_info("AFTER_CALL_172"); \
AFTER_LAMBDA_169: print_info("AFTER_LAMBDA_169"); \
AFTER_LAMBDA_167: print_info("AFTER_LAMBDA_167"); \
defineVar(NAMEOBJ("cons"), val, env); \
val = COMPOBJ(_ENTRY_173, env); \
goto AFTER_LAMBDA_174; \
ENTRY_173: print_info("ENTRY_173"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_175, env); \
goto AFTER_LAMBDA_176; \
ENTRY_175: print_info("ENTRY_175"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("x"), env); \
goto CONTINUE; \
AFTER_LAMBDA_176: print_info("AFTER_LAMBDA_176"); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_177; \
COMPILED_178: print_info("COMPILED_178"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_177: print_info("PRIMITIVE_177"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_179: print_info("AFTER_CALL_179"); \
AFTER_LAMBDA_174: print_info("AFTER_LAMBDA_174"); \
defineVar(NAMEOBJ("car"), val, env); \
val = COMPOBJ(_ENTRY_180, env); \
goto AFTER_LAMBDA_181; \
ENTRY_180: print_info("ENTRY_180"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_182, env); \
goto AFTER_LAMBDA_183; \
ENTRY_182: print_info("ENTRY_182"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("y"), env); \
goto CONTINUE; \
AFTER_LAMBDA_183: print_info("AFTER_LAMBDA_183"); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_184; \
COMPILED_185: print_info("COMPILED_185"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_184: print_info("PRIMITIVE_184"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_186: print_info("AFTER_CALL_186"); \
AFTER_LAMBDA_181: print_info("AFTER_LAMBDA_181"); \
defineVar(NAMEOBJ("cdr"), val, env); \
val = parse("()\n"); \
defineVar(NAMEOBJ("nil"), val, env); \
val = COMPOBJ(_ENTRY_187, env); \
goto AFTER_LAMBDA_188; \
ENTRY_187: print_info("ENTRY_187"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_192; \
COMPILED_193: print_info("COMPILED_193"); \
cont = LABELOBJ(_AFTER_CALL_194); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_192: print_info("PRIMITIVE_192"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_194: print_info("AFTER_CALL_194"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_189; \
FALSE_BRANCH_190: print_info("FALSE_BRANCH_190"); \
func = lookup(NAMEOBJ("add1"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("length"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_195; \
COMPILED_196: print_info("COMPILED_196"); \
cont = LABELOBJ(_AFTER_CALL_197); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_195: print_info("PRIMITIVE_195"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_197: print_info("AFTER_CALL_197"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_198; \
COMPILED_199: print_info("COMPILED_199"); \
cont = LABELOBJ(_AFTER_CALL_200); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_198: print_info("PRIMITIVE_198"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_200: print_info("AFTER_CALL_200"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_201; \
COMPILED_202: print_info("COMPILED_202"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_201: print_info("PRIMITIVE_201"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_203: print_info("AFTER_CALL_203"); \
TRUE_BRANCH_189: print_info("TRUE_BRANCH_189"); \
val = NUMOBJ(0); \
goto CONTINUE; \
AFTER_IF_191: print_info("AFTER_IF_191"); \
AFTER_LAMBDA_188: print_info("AFTER_LAMBDA_188"); \
defineVar(NAMEOBJ("length"), val, env); \
goto DONE;

#define COMP_CONT(REG) \
if (GETLABEL(REG) == _ENTRY_1) goto ENTRY_1; \
if (GETLABEL(REG) == _AFTER_LAMBDA_2) goto AFTER_LAMBDA_2; \
if (GETLABEL(REG) == _PRIMITIVE_3) goto PRIMITIVE_3; \
if (GETLABEL(REG) == _COMPILED_4) goto COMPILED_4; \
if (GETLABEL(REG) == _AFTER_CALL_5) goto AFTER_CALL_5; \
if (GETLABEL(REG) == _ENTRY_6) goto ENTRY_6; \
if (GETLABEL(REG) == _AFTER_LAMBDA_7) goto AFTER_LAMBDA_7; \
if (GETLABEL(REG) == _PRIMITIVE_8) goto PRIMITIVE_8; \
if (GETLABEL(REG) == _COMPILED_9) goto COMPILED_9; \
if (GETLABEL(REG) == _AFTER_CALL_10) goto AFTER_CALL_10; \
if (GETLABEL(REG) == _ENTRY_11) goto ENTRY_11; \
if (GETLABEL(REG) == _AFTER_LAMBDA_12) goto AFTER_LAMBDA_12; \
if (GETLABEL(REG) == _PRIMITIVE_13) goto PRIMITIVE_13; \
if (GETLABEL(REG) == _COMPILED_14) goto COMPILED_14; \
if (GETLABEL(REG) == _AFTER_CALL_15) goto AFTER_CALL_15; \
if (GETLABEL(REG) == _ENTRY_16) goto ENTRY_16; \
if (GETLABEL(REG) == _AFTER_LAMBDA_17) goto AFTER_LAMBDA_17; \
if (GETLABEL(REG) == _TRUE_BRANCH_18) goto TRUE_BRANCH_18; \
if (GETLABEL(REG) == _FALSE_BRANCH_19) goto FALSE_BRANCH_19; \
if (GETLABEL(REG) == _AFTER_IF_20) goto AFTER_IF_20; \
if (GETLABEL(REG) == _PRIMITIVE_21) goto PRIMITIVE_21; \
if (GETLABEL(REG) == _COMPILED_22) goto COMPILED_22; \
if (GETLABEL(REG) == _AFTER_CALL_23) goto AFTER_CALL_23; \
if (GETLABEL(REG) == _PRIMITIVE_24) goto PRIMITIVE_24; \
if (GETLABEL(REG) == _COMPILED_25) goto COMPILED_25; \
if (GETLABEL(REG) == _AFTER_CALL_26) goto AFTER_CALL_26; \
if (GETLABEL(REG) == _PRIMITIVE_27) goto PRIMITIVE_27; \
if (GETLABEL(REG) == _COMPILED_28) goto COMPILED_28; \
if (GETLABEL(REG) == _AFTER_CALL_29) goto AFTER_CALL_29; \
if (GETLABEL(REG) == _PRIMITIVE_30) goto PRIMITIVE_30; \
if (GETLABEL(REG) == _COMPILED_31) goto COMPILED_31; \
if (GETLABEL(REG) == _AFTER_CALL_32) goto AFTER_CALL_32; \
if (GETLABEL(REG) == _ENTRY_33) goto ENTRY_33; \
if (GETLABEL(REG) == _AFTER_LAMBDA_34) goto AFTER_LAMBDA_34; \
if (GETLABEL(REG) == _TRUE_BRANCH_35) goto TRUE_BRANCH_35; \
if (GETLABEL(REG) == _FALSE_BRANCH_36) goto FALSE_BRANCH_36; \
if (GETLABEL(REG) == _AFTER_IF_37) goto AFTER_IF_37; \
if (GETLABEL(REG) == _PRIMITIVE_38) goto PRIMITIVE_38; \
if (GETLABEL(REG) == _COMPILED_39) goto COMPILED_39; \
if (GETLABEL(REG) == _AFTER_CALL_40) goto AFTER_CALL_40; \
if (GETLABEL(REG) == _PRIMITIVE_41) goto PRIMITIVE_41; \
if (GETLABEL(REG) == _COMPILED_42) goto COMPILED_42; \
if (GETLABEL(REG) == _AFTER_CALL_43) goto AFTER_CALL_43; \
if (GETLABEL(REG) == _PRIMITIVE_44) goto PRIMITIVE_44; \
if (GETLABEL(REG) == _COMPILED_45) goto COMPILED_45; \
if (GETLABEL(REG) == _AFTER_CALL_46) goto AFTER_CALL_46; \
if (GETLABEL(REG) == _PRIMITIVE_47) goto PRIMITIVE_47; \
if (GETLABEL(REG) == _COMPILED_48) goto COMPILED_48; \
if (GETLABEL(REG) == _AFTER_CALL_49) goto AFTER_CALL_49; \
if (GETLABEL(REG) == _PRIMITIVE_50) goto PRIMITIVE_50; \
if (GETLABEL(REG) == _COMPILED_51) goto COMPILED_51; \
if (GETLABEL(REG) == _AFTER_CALL_52) goto AFTER_CALL_52; \
if (GETLABEL(REG) == _ENTRY_53) goto ENTRY_53; \
if (GETLABEL(REG) == _AFTER_LAMBDA_54) goto AFTER_LAMBDA_54; \
if (GETLABEL(REG) == _TRUE_BRANCH_55) goto TRUE_BRANCH_55; \
if (GETLABEL(REG) == _FALSE_BRANCH_56) goto FALSE_BRANCH_56; \
if (GETLABEL(REG) == _AFTER_IF_57) goto AFTER_IF_57; \
if (GETLABEL(REG) == _PRIMITIVE_58) goto PRIMITIVE_58; \
if (GETLABEL(REG) == _COMPILED_59) goto COMPILED_59; \
if (GETLABEL(REG) == _AFTER_CALL_60) goto AFTER_CALL_60; \
if (GETLABEL(REG) == _PRIMITIVE_61) goto PRIMITIVE_61; \
if (GETLABEL(REG) == _COMPILED_62) goto COMPILED_62; \
if (GETLABEL(REG) == _AFTER_CALL_63) goto AFTER_CALL_63; \
if (GETLABEL(REG) == _PRIMITIVE_64) goto PRIMITIVE_64; \
if (GETLABEL(REG) == _COMPILED_65) goto COMPILED_65; \
if (GETLABEL(REG) == _AFTER_CALL_66) goto AFTER_CALL_66; \
if (GETLABEL(REG) == _PRIMITIVE_67) goto PRIMITIVE_67; \
if (GETLABEL(REG) == _COMPILED_68) goto COMPILED_68; \
if (GETLABEL(REG) == _AFTER_CALL_69) goto AFTER_CALL_69; \
if (GETLABEL(REG) == _PRIMITIVE_70) goto PRIMITIVE_70; \
if (GETLABEL(REG) == _COMPILED_71) goto COMPILED_71; \
if (GETLABEL(REG) == _AFTER_CALL_72) goto AFTER_CALL_72; \
if (GETLABEL(REG) == _ENTRY_73) goto ENTRY_73; \
if (GETLABEL(REG) == _AFTER_LAMBDA_74) goto AFTER_LAMBDA_74; \
if (GETLABEL(REG) == _TRUE_BRANCH_75) goto TRUE_BRANCH_75; \
if (GETLABEL(REG) == _FALSE_BRANCH_76) goto FALSE_BRANCH_76; \
if (GETLABEL(REG) == _AFTER_IF_77) goto AFTER_IF_77; \
if (GETLABEL(REG) == _PRIMITIVE_78) goto PRIMITIVE_78; \
if (GETLABEL(REG) == _COMPILED_79) goto COMPILED_79; \
if (GETLABEL(REG) == _AFTER_CALL_80) goto AFTER_CALL_80; \
if (GETLABEL(REG) == _PRIMITIVE_81) goto PRIMITIVE_81; \
if (GETLABEL(REG) == _COMPILED_82) goto COMPILED_82; \
if (GETLABEL(REG) == _AFTER_CALL_83) goto AFTER_CALL_83; \
if (GETLABEL(REG) == _PRIMITIVE_84) goto PRIMITIVE_84; \
if (GETLABEL(REG) == _COMPILED_85) goto COMPILED_85; \
if (GETLABEL(REG) == _AFTER_CALL_86) goto AFTER_CALL_86; \
if (GETLABEL(REG) == _PRIMITIVE_87) goto PRIMITIVE_87; \
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
if (GETLABEL(REG) == _COMPILED_98) goto COMPILED_98; \
if (GETLABEL(REG) == _AFTER_CALL_99) goto AFTER_CALL_99; \
if (GETLABEL(REG) == _PRIMITIVE_100) goto PRIMITIVE_100; \
if (GETLABEL(REG) == _COMPILED_101) goto COMPILED_101; \
if (GETLABEL(REG) == _AFTER_CALL_102) goto AFTER_CALL_102; \
if (GETLABEL(REG) == _PRIMITIVE_103) goto PRIMITIVE_103; \
if (GETLABEL(REG) == _COMPILED_104) goto COMPILED_104; \
if (GETLABEL(REG) == _AFTER_CALL_105) goto AFTER_CALL_105; \
if (GETLABEL(REG) == _PRIMITIVE_106) goto PRIMITIVE_106; \
if (GETLABEL(REG) == _COMPILED_107) goto COMPILED_107; \
if (GETLABEL(REG) == _AFTER_CALL_108) goto AFTER_CALL_108; \
if (GETLABEL(REG) == _PRIMITIVE_109) goto PRIMITIVE_109; \
if (GETLABEL(REG) == _COMPILED_110) goto COMPILED_110; \
if (GETLABEL(REG) == _AFTER_CALL_111) goto AFTER_CALL_111; \
if (GETLABEL(REG) == _ENTRY_112) goto ENTRY_112; \
if (GETLABEL(REG) == _AFTER_LAMBDA_113) goto AFTER_LAMBDA_113; \
if (GETLABEL(REG) == _TRUE_BRANCH_114) goto TRUE_BRANCH_114; \
if (GETLABEL(REG) == _FALSE_BRANCH_115) goto FALSE_BRANCH_115; \
if (GETLABEL(REG) == _AFTER_IF_116) goto AFTER_IF_116; \
if (GETLABEL(REG) == _TRUE_BRANCH_117) goto TRUE_BRANCH_117; \
if (GETLABEL(REG) == _FALSE_BRANCH_118) goto FALSE_BRANCH_118; \
if (GETLABEL(REG) == _AFTER_IF_119) goto AFTER_IF_119; \
if (GETLABEL(REG) == _PRIMITIVE_120) goto PRIMITIVE_120; \
if (GETLABEL(REG) == _COMPILED_121) goto COMPILED_121; \
if (GETLABEL(REG) == _AFTER_CALL_122) goto AFTER_CALL_122; \
if (GETLABEL(REG) == _TRUE_BRANCH_123) goto TRUE_BRANCH_123; \
if (GETLABEL(REG) == _FALSE_BRANCH_124) goto FALSE_BRANCH_124; \
if (GETLABEL(REG) == _AFTER_IF_125) goto AFTER_IF_125; \
if (GETLABEL(REG) == _PRIMITIVE_126) goto PRIMITIVE_126; \
if (GETLABEL(REG) == _COMPILED_127) goto COMPILED_127; \
if (GETLABEL(REG) == _AFTER_CALL_128) goto AFTER_CALL_128; \
if (GETLABEL(REG) == _PRIMITIVE_129) goto PRIMITIVE_129; \
if (GETLABEL(REG) == _COMPILED_130) goto COMPILED_130; \
if (GETLABEL(REG) == _AFTER_CALL_131) goto AFTER_CALL_131; \
if (GETLABEL(REG) == _PRIMITIVE_132) goto PRIMITIVE_132; \
if (GETLABEL(REG) == _COMPILED_133) goto COMPILED_133; \
if (GETLABEL(REG) == _AFTER_CALL_134) goto AFTER_CALL_134; \
if (GETLABEL(REG) == _PRIMITIVE_135) goto PRIMITIVE_135; \
if (GETLABEL(REG) == _COMPILED_136) goto COMPILED_136; \
if (GETLABEL(REG) == _AFTER_CALL_137) goto AFTER_CALL_137; \
if (GETLABEL(REG) == _PRIMITIVE_138) goto PRIMITIVE_138; \
if (GETLABEL(REG) == _COMPILED_139) goto COMPILED_139; \
if (GETLABEL(REG) == _AFTER_CALL_140) goto AFTER_CALL_140; \
if (GETLABEL(REG) == _PRIMITIVE_141) goto PRIMITIVE_141; \
if (GETLABEL(REG) == _COMPILED_142) goto COMPILED_142; \
if (GETLABEL(REG) == _AFTER_CALL_143) goto AFTER_CALL_143; \
if (GETLABEL(REG) == _ENTRY_144) goto ENTRY_144; \
if (GETLABEL(REG) == _AFTER_LAMBDA_145) goto AFTER_LAMBDA_145; \
if (GETLABEL(REG) == _ENTRY_146) goto ENTRY_146; \
if (GETLABEL(REG) == _AFTER_LAMBDA_147) goto AFTER_LAMBDA_147; \
if (GETLABEL(REG) == _TRUE_BRANCH_148) goto TRUE_BRANCH_148; \
if (GETLABEL(REG) == _FALSE_BRANCH_149) goto FALSE_BRANCH_149; \
if (GETLABEL(REG) == _AFTER_IF_150) goto AFTER_IF_150; \
if (GETLABEL(REG) == _PRIMITIVE_151) goto PRIMITIVE_151; \
if (GETLABEL(REG) == _COMPILED_152) goto COMPILED_152; \
if (GETLABEL(REG) == _AFTER_CALL_153) goto AFTER_CALL_153; \
if (GETLABEL(REG) == _PRIMITIVE_154) goto PRIMITIVE_154; \
if (GETLABEL(REG) == _COMPILED_155) goto COMPILED_155; \
if (GETLABEL(REG) == _AFTER_CALL_156) goto AFTER_CALL_156; \
if (GETLABEL(REG) == _PRIMITIVE_157) goto PRIMITIVE_157; \
if (GETLABEL(REG) == _COMPILED_158) goto COMPILED_158; \
if (GETLABEL(REG) == _AFTER_CALL_159) goto AFTER_CALL_159; \
if (GETLABEL(REG) == _PRIMITIVE_160) goto PRIMITIVE_160; \
if (GETLABEL(REG) == _COMPILED_161) goto COMPILED_161; \
if (GETLABEL(REG) == _AFTER_CALL_162) goto AFTER_CALL_162; \
if (GETLABEL(REG) == _PRIMITIVE_163) goto PRIMITIVE_163; \
if (GETLABEL(REG) == _COMPILED_164) goto COMPILED_164; \
if (GETLABEL(REG) == _AFTER_CALL_165) goto AFTER_CALL_165; \
if (GETLABEL(REG) == _ENTRY_166) goto ENTRY_166; \
if (GETLABEL(REG) == _AFTER_LAMBDA_167) goto AFTER_LAMBDA_167; \
if (GETLABEL(REG) == _ENTRY_168) goto ENTRY_168; \
if (GETLABEL(REG) == _AFTER_LAMBDA_169) goto AFTER_LAMBDA_169; \
if (GETLABEL(REG) == _PRIMITIVE_170) goto PRIMITIVE_170; \
if (GETLABEL(REG) == _COMPILED_171) goto COMPILED_171; \
if (GETLABEL(REG) == _AFTER_CALL_172) goto AFTER_CALL_172; \
if (GETLABEL(REG) == _ENTRY_173) goto ENTRY_173; \
if (GETLABEL(REG) == _AFTER_LAMBDA_174) goto AFTER_LAMBDA_174; \
if (GETLABEL(REG) == _ENTRY_175) goto ENTRY_175; \
if (GETLABEL(REG) == _AFTER_LAMBDA_176) goto AFTER_LAMBDA_176; \
if (GETLABEL(REG) == _PRIMITIVE_177) goto PRIMITIVE_177; \
if (GETLABEL(REG) == _COMPILED_178) goto COMPILED_178; \
if (GETLABEL(REG) == _AFTER_CALL_179) goto AFTER_CALL_179; \
if (GETLABEL(REG) == _ENTRY_180) goto ENTRY_180; \
if (GETLABEL(REG) == _AFTER_LAMBDA_181) goto AFTER_LAMBDA_181; \
if (GETLABEL(REG) == _ENTRY_182) goto ENTRY_182; \
if (GETLABEL(REG) == _AFTER_LAMBDA_183) goto AFTER_LAMBDA_183; \
if (GETLABEL(REG) == _PRIMITIVE_184) goto PRIMITIVE_184; \
if (GETLABEL(REG) == _COMPILED_185) goto COMPILED_185; \
if (GETLABEL(REG) == _AFTER_CALL_186) goto AFTER_CALL_186; \
if (GETLABEL(REG) == _ENTRY_187) goto ENTRY_187; \
if (GETLABEL(REG) == _AFTER_LAMBDA_188) goto AFTER_LAMBDA_188; \
if (GETLABEL(REG) == _TRUE_BRANCH_189) goto TRUE_BRANCH_189; \
if (GETLABEL(REG) == _FALSE_BRANCH_190) goto FALSE_BRANCH_190; \
if (GETLABEL(REG) == _AFTER_IF_191) goto AFTER_IF_191; \
if (GETLABEL(REG) == _PRIMITIVE_192) goto PRIMITIVE_192; \
if (GETLABEL(REG) == _COMPILED_193) goto COMPILED_193; \
if (GETLABEL(REG) == _AFTER_CALL_194) goto AFTER_CALL_194; \
if (GETLABEL(REG) == _PRIMITIVE_195) goto PRIMITIVE_195; \
if (GETLABEL(REG) == _COMPILED_196) goto COMPILED_196; \
if (GETLABEL(REG) == _AFTER_CALL_197) goto AFTER_CALL_197; \
if (GETLABEL(REG) == _PRIMITIVE_198) goto PRIMITIVE_198; \
if (GETLABEL(REG) == _COMPILED_199) goto COMPILED_199; \
if (GETLABEL(REG) == _AFTER_CALL_200) goto AFTER_CALL_200; \
if (GETLABEL(REG) == _PRIMITIVE_201) goto PRIMITIVE_201; \
if (GETLABEL(REG) == _COMPILED_202) goto COMPILED_202; \
if (GETLABEL(REG) == _AFTER_CALL_203) goto AFTER_CALL_203;

#define ALL_COMPILED_LABELS \
_ENTRY_1, \
_AFTER_LAMBDA_2, \
_PRIMITIVE_3, \
_COMPILED_4, \
_AFTER_CALL_5, \
_ENTRY_6, \
_AFTER_LAMBDA_7, \
_PRIMITIVE_8, \
_COMPILED_9, \
_AFTER_CALL_10, \
_ENTRY_11, \
_AFTER_LAMBDA_12, \
_PRIMITIVE_13, \
_COMPILED_14, \
_AFTER_CALL_15, \
_ENTRY_16, \
_AFTER_LAMBDA_17, \
_TRUE_BRANCH_18, \
_FALSE_BRANCH_19, \
_AFTER_IF_20, \
_PRIMITIVE_21, \
_COMPILED_22, \
_AFTER_CALL_23, \
_PRIMITIVE_24, \
_COMPILED_25, \
_AFTER_CALL_26, \
_PRIMITIVE_27, \
_COMPILED_28, \
_AFTER_CALL_29, \
_PRIMITIVE_30, \
_COMPILED_31, \
_AFTER_CALL_32, \
_ENTRY_33, \
_AFTER_LAMBDA_34, \
_TRUE_BRANCH_35, \
_FALSE_BRANCH_36, \
_AFTER_IF_37, \
_PRIMITIVE_38, \
_COMPILED_39, \
_AFTER_CALL_40, \
_PRIMITIVE_41, \
_COMPILED_42, \
_AFTER_CALL_43, \
_PRIMITIVE_44, \
_COMPILED_45, \
_AFTER_CALL_46, \
_PRIMITIVE_47, \
_COMPILED_48, \
_AFTER_CALL_49, \
_PRIMITIVE_50, \
_COMPILED_51, \
_AFTER_CALL_52, \
_ENTRY_53, \
_AFTER_LAMBDA_54, \
_TRUE_BRANCH_55, \
_FALSE_BRANCH_56, \
_AFTER_IF_57, \
_PRIMITIVE_58, \
_COMPILED_59, \
_AFTER_CALL_60, \
_PRIMITIVE_61, \
_COMPILED_62, \
_AFTER_CALL_63, \
_PRIMITIVE_64, \
_COMPILED_65, \
_AFTER_CALL_66, \
_PRIMITIVE_67, \
_COMPILED_68, \
_AFTER_CALL_69, \
_PRIMITIVE_70, \
_COMPILED_71, \
_AFTER_CALL_72, \
_ENTRY_73, \
_AFTER_LAMBDA_74, \
_TRUE_BRANCH_75, \
_FALSE_BRANCH_76, \
_AFTER_IF_77, \
_PRIMITIVE_78, \
_COMPILED_79, \
_AFTER_CALL_80, \
_PRIMITIVE_81, \
_COMPILED_82, \
_AFTER_CALL_83, \
_PRIMITIVE_84, \
_COMPILED_85, \
_AFTER_CALL_86, \
_PRIMITIVE_87, \
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
_COMPILED_98, \
_AFTER_CALL_99, \
_PRIMITIVE_100, \
_COMPILED_101, \
_AFTER_CALL_102, \
_PRIMITIVE_103, \
_COMPILED_104, \
_AFTER_CALL_105, \
_PRIMITIVE_106, \
_COMPILED_107, \
_AFTER_CALL_108, \
_PRIMITIVE_109, \
_COMPILED_110, \
_AFTER_CALL_111, \
_ENTRY_112, \
_AFTER_LAMBDA_113, \
_TRUE_BRANCH_114, \
_FALSE_BRANCH_115, \
_AFTER_IF_116, \
_TRUE_BRANCH_117, \
_FALSE_BRANCH_118, \
_AFTER_IF_119, \
_PRIMITIVE_120, \
_COMPILED_121, \
_AFTER_CALL_122, \
_TRUE_BRANCH_123, \
_FALSE_BRANCH_124, \
_AFTER_IF_125, \
_PRIMITIVE_126, \
_COMPILED_127, \
_AFTER_CALL_128, \
_PRIMITIVE_129, \
_COMPILED_130, \
_AFTER_CALL_131, \
_PRIMITIVE_132, \
_COMPILED_133, \
_AFTER_CALL_134, \
_PRIMITIVE_135, \
_COMPILED_136, \
_AFTER_CALL_137, \
_PRIMITIVE_138, \
_COMPILED_139, \
_AFTER_CALL_140, \
_PRIMITIVE_141, \
_COMPILED_142, \
_AFTER_CALL_143, \
_ENTRY_144, \
_AFTER_LAMBDA_145, \
_ENTRY_146, \
_AFTER_LAMBDA_147, \
_TRUE_BRANCH_148, \
_FALSE_BRANCH_149, \
_AFTER_IF_150, \
_PRIMITIVE_151, \
_COMPILED_152, \
_AFTER_CALL_153, \
_PRIMITIVE_154, \
_COMPILED_155, \
_AFTER_CALL_156, \
_PRIMITIVE_157, \
_COMPILED_158, \
_AFTER_CALL_159, \
_PRIMITIVE_160, \
_COMPILED_161, \
_AFTER_CALL_162, \
_PRIMITIVE_163, \
_COMPILED_164, \
_AFTER_CALL_165, \
_ENTRY_166, \
_AFTER_LAMBDA_167, \
_ENTRY_168, \
_AFTER_LAMBDA_169, \
_PRIMITIVE_170, \
_COMPILED_171, \
_AFTER_CALL_172, \
_ENTRY_173, \
_AFTER_LAMBDA_174, \
_ENTRY_175, \
_AFTER_LAMBDA_176, \
_PRIMITIVE_177, \
_COMPILED_178, \
_AFTER_CALL_179, \
_ENTRY_180, \
_AFTER_LAMBDA_181, \
_ENTRY_182, \
_AFTER_LAMBDA_183, \
_PRIMITIVE_184, \
_COMPILED_185, \
_AFTER_CALL_186, \
_ENTRY_187, \
_AFTER_LAMBDA_188, \
_TRUE_BRANCH_189, \
_FALSE_BRANCH_190, \
_AFTER_IF_191, \
_PRIMITIVE_192, \
_COMPILED_193, \
_AFTER_CALL_194, \
_PRIMITIVE_195, \
_COMPILED_196, \
_AFTER_CALL_197, \
_PRIMITIVE_198, \
_COMPILED_199, \
_AFTER_CALL_200, \
_PRIMITIVE_201, \
_COMPILED_202, \
_AFTER_CALL_203

#endif
