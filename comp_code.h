#define COMPILED_CODE_BODY \
val = COMPOBJ(_ENTRY_1, env); \
goto AFTER_LAMBDA_2; \
ENTRY_1: \
if (INFO) print_info("ENTRY_1"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(0); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_3; \
COMPILED_4: \
if (INFO) print_info("COMPILED_4"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_3: \
if (INFO) print_info("PRIMITIVE_3"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_5: \
if (INFO) print_info("AFTER_CALL_5"); \
AFTER_LAMBDA_2: \
if (INFO) print_info("AFTER_LAMBDA_2"); \
defineVar(NAMEOBJ("zero?"), val, env); \
val = COMPOBJ(_ENTRY_6, env); \
goto AFTER_LAMBDA_7; \
ENTRY_6: \
if (INFO) print_info("ENTRY_6"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("+"), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_8; \
COMPILED_9: \
if (INFO) print_info("COMPILED_9"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_8: \
if (INFO) print_info("PRIMITIVE_8"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_10: \
if (INFO) print_info("AFTER_CALL_10"); \
AFTER_LAMBDA_7: \
if (INFO) print_info("AFTER_LAMBDA_7"); \
defineVar(NAMEOBJ("add1"), val, env); \
val = COMPOBJ(_ENTRY_11, env); \
goto AFTER_LAMBDA_12; \
ENTRY_11: \
if (INFO) print_info("ENTRY_11"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_13; \
COMPILED_14: \
if (INFO) print_info("COMPILED_14"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_13: \
if (INFO) print_info("PRIMITIVE_13"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_15: \
if (INFO) print_info("AFTER_CALL_15"); \
AFTER_LAMBDA_12: \
if (INFO) print_info("AFTER_LAMBDA_12"); \
defineVar(NAMEOBJ("sub1"), val, env); \
val = COMPOBJ(_ENTRY_16, env); \
goto AFTER_LAMBDA_17; \
ENTRY_16: \
if (INFO) print_info("ENTRY_16"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_21; \
COMPILED_22: \
if (INFO) print_info("COMPILED_22"); \
cont = LABELOBJ(_AFTER_CALL_23); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_21: \
if (INFO) print_info("PRIMITIVE_21"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_23: \
if (INFO) print_info("AFTER_CALL_23"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_18; \
goto FALSE_BRANCH_19; \
TRUE_BRANCH_18: \
if (INFO) print_info("TRUE_BRANCH_18"); \
val = NUMOBJ(0); \
goto CONTINUE; \
FALSE_BRANCH_19: \
if (INFO) print_info("FALSE_BRANCH_19"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_24; \
COMPILED_25: \
if (INFO) print_info("COMPILED_25"); \
cont = LABELOBJ(_AFTER_CALL_26); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_24: \
if (INFO) print_info("PRIMITIVE_24"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_26: \
if (INFO) print_info("AFTER_CALL_26"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_27; \
COMPILED_28: \
if (INFO) print_info("COMPILED_28"); \
cont = LABELOBJ(_AFTER_CALL_29); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_27: \
if (INFO) print_info("PRIMITIVE_27"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_29: \
if (INFO) print_info("AFTER_CALL_29"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_30; \
COMPILED_31: \
if (INFO) print_info("COMPILED_31"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_30: \
if (INFO) print_info("PRIMITIVE_30"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_32: \
if (INFO) print_info("AFTER_CALL_32"); \
AFTER_IF_20: \
if (INFO) print_info("AFTER_IF_20"); \
AFTER_LAMBDA_17: \
if (INFO) print_info("AFTER_LAMBDA_17"); \
defineVar(NAMEOBJ("recursive_triangular_compiled"), val, env); \
val = COMPOBJ(_ENTRY_33, env); \
goto AFTER_LAMBDA_34; \
ENTRY_33: \
if (INFO) print_info("ENTRY_33"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_38; \
COMPILED_39: \
if (INFO) print_info("COMPILED_39"); \
cont = LABELOBJ(_AFTER_CALL_40); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_38: \
if (INFO) print_info("PRIMITIVE_38"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_40: \
if (INFO) print_info("AFTER_CALL_40"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_35; \
goto FALSE_BRANCH_36; \
TRUE_BRANCH_35: \
if (INFO) print_info("TRUE_BRANCH_35"); \
val = NUMOBJ(0); \
goto CONTINUE; \
FALSE_BRANCH_36: \
if (INFO) print_info("FALSE_BRANCH_36"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_44; \
COMPILED_45: \
if (INFO) print_info("COMPILED_45"); \
cont = LABELOBJ(_AFTER_CALL_46); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_44: \
if (INFO) print_info("PRIMITIVE_44"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_46: \
if (INFO) print_info("AFTER_CALL_46"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_47; \
COMPILED_48: \
if (INFO) print_info("COMPILED_48"); \
cont = LABELOBJ(_AFTER_CALL_49); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_47: \
if (INFO) print_info("PRIMITIVE_47"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_49: \
if (INFO) print_info("AFTER_CALL_49"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_triangular_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_41; \
COMPILED_42: \
if (INFO) print_info("COMPILED_42"); \
cont = LABELOBJ(_AFTER_CALL_43); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_41: \
if (INFO) print_info("PRIMITIVE_41"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_43: \
if (INFO) print_info("AFTER_CALL_43"); \
restore(arglist); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_50; \
COMPILED_51: \
if (INFO) print_info("COMPILED_51"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_50: \
if (INFO) print_info("PRIMITIVE_50"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_52: \
if (INFO) print_info("AFTER_CALL_52"); \
AFTER_IF_37: \
if (INFO) print_info("AFTER_IF_37"); \
AFTER_LAMBDA_34: \
if (INFO) print_info("AFTER_LAMBDA_34"); \
defineVar(NAMEOBJ("recursive_tetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_53, env); \
goto AFTER_LAMBDA_54; \
ENTRY_53: \
if (INFO) print_info("ENTRY_53"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_58; \
COMPILED_59: \
if (INFO) print_info("COMPILED_59"); \
cont = LABELOBJ(_AFTER_CALL_60); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_58: \
if (INFO) print_info("PRIMITIVE_58"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_60: \
if (INFO) print_info("AFTER_CALL_60"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_55; \
goto FALSE_BRANCH_56; \
TRUE_BRANCH_55: \
if (INFO) print_info("TRUE_BRANCH_55"); \
val = NUMOBJ(0); \
goto CONTINUE; \
FALSE_BRANCH_56: \
if (INFO) print_info("FALSE_BRANCH_56"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_supertetrahedral_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_64; \
COMPILED_65: \
if (INFO) print_info("COMPILED_65"); \
cont = LABELOBJ(_AFTER_CALL_66); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_64: \
if (INFO) print_info("PRIMITIVE_64"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_66: \
if (INFO) print_info("AFTER_CALL_66"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_67; \
COMPILED_68: \
if (INFO) print_info("COMPILED_68"); \
cont = LABELOBJ(_AFTER_CALL_69); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_67: \
if (INFO) print_info("PRIMITIVE_67"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_69: \
if (INFO) print_info("AFTER_CALL_69"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_tetrahedral_compiled"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_61; \
COMPILED_62: \
if (INFO) print_info("COMPILED_62"); \
cont = LABELOBJ(_AFTER_CALL_63); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_61: \
if (INFO) print_info("PRIMITIVE_61"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_63: \
if (INFO) print_info("AFTER_CALL_63"); \
restore(arglist); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_70; \
COMPILED_71: \
if (INFO) print_info("COMPILED_71"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_70: \
if (INFO) print_info("PRIMITIVE_70"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_72: \
if (INFO) print_info("AFTER_CALL_72"); \
AFTER_IF_57: \
if (INFO) print_info("AFTER_IF_57"); \
AFTER_LAMBDA_54: \
if (INFO) print_info("AFTER_LAMBDA_54"); \
defineVar(NAMEOBJ("recursive_supertetrahedral_compiled"), val, env); \
val = COMPOBJ(_ENTRY_73, env); \
goto AFTER_LAMBDA_74; \
ENTRY_73: \
if (INFO) print_info("ENTRY_73"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_78; \
COMPILED_79: \
if (INFO) print_info("COMPILED_79"); \
cont = LABELOBJ(_AFTER_CALL_80); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_78: \
if (INFO) print_info("PRIMITIVE_78"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_80: \
if (INFO) print_info("AFTER_CALL_80"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_75; \
goto FALSE_BRANCH_76; \
TRUE_BRANCH_75: \
if (INFO) print_info("TRUE_BRANCH_75"); \
val = NUMOBJ(1); \
goto CONTINUE; \
FALSE_BRANCH_76: \
if (INFO) print_info("FALSE_BRANCH_76"); \
func = lookup(NAMEOBJ("*"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_81; \
COMPILED_82: \
if (INFO) print_info("COMPILED_82"); \
cont = LABELOBJ(_AFTER_CALL_83); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_81: \
if (INFO) print_info("PRIMITIVE_81"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_83: \
if (INFO) print_info("AFTER_CALL_83"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_84; \
COMPILED_85: \
if (INFO) print_info("COMPILED_85"); \
cont = LABELOBJ(_AFTER_CALL_86); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_84: \
if (INFO) print_info("PRIMITIVE_84"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_86: \
if (INFO) print_info("AFTER_CALL_86"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_87; \
COMPILED_88: \
if (INFO) print_info("COMPILED_88"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_87: \
if (INFO) print_info("PRIMITIVE_87"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_89: \
if (INFO) print_info("AFTER_CALL_89"); \
AFTER_IF_77: \
if (INFO) print_info("AFTER_IF_77"); \
AFTER_LAMBDA_74: \
if (INFO) print_info("AFTER_LAMBDA_74"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_90, env); \
goto AFTER_LAMBDA_91; \
ENTRY_90: \
if (INFO) print_info("ENTRY_90"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_92, env); \
goto AFTER_LAMBDA_93; \
ENTRY_92: \
if (INFO) print_info("ENTRY_92"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_97; \
COMPILED_98: \
if (INFO) print_info("COMPILED_98"); \
cont = LABELOBJ(_AFTER_CALL_99); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_97: \
if (INFO) print_info("PRIMITIVE_97"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_99: \
if (INFO) print_info("AFTER_CALL_99"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_94; \
goto FALSE_BRANCH_95; \
TRUE_BRANCH_94: \
if (INFO) print_info("TRUE_BRANCH_94"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
FALSE_BRANCH_95: \
if (INFO) print_info("FALSE_BRANCH_95"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("*"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("total"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_103; \
COMPILED_104: \
if (INFO) print_info("COMPILED_104"); \
cont = LABELOBJ(_AFTER_CALL_105); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_103: \
if (INFO) print_info("PRIMITIVE_103"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_105: \
if (INFO) print_info("AFTER_CALL_105"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_100; \
COMPILED_101: \
if (INFO) print_info("COMPILED_101"); \
cont = LABELOBJ(_AFTER_CALL_102); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_100: \
if (INFO) print_info("PRIMITIVE_100"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_102: \
if (INFO) print_info("AFTER_CALL_102"); \
restore(arglist); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_106; \
COMPILED_107: \
if (INFO) print_info("COMPILED_107"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_106: \
if (INFO) print_info("PRIMITIVE_106"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_108: \
if (INFO) print_info("AFTER_CALL_108"); \
AFTER_IF_96: \
if (INFO) print_info("AFTER_IF_96"); \
AFTER_LAMBDA_93: \
if (INFO) print_info("AFTER_LAMBDA_93"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_109; \
COMPILED_110: \
if (INFO) print_info("COMPILED_110"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_109: \
if (INFO) print_info("PRIMITIVE_109"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_111: \
if (INFO) print_info("AFTER_CALL_111"); \
AFTER_LAMBDA_91: \
if (INFO) print_info("AFTER_LAMBDA_91"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_112, env); \
goto AFTER_LAMBDA_113; \
ENTRY_112: \
if (INFO) print_info("ENTRY_112"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
save(env); \
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(0); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_120; \
COMPILED_121: \
if (INFO) print_info("COMPILED_121"); \
cont = LABELOBJ(_AFTER_CALL_122); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_120: \
if (INFO) print_info("PRIMITIVE_120"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_122: \
if (INFO) print_info("AFTER_CALL_122"); \
restore(env); \
if (isTrue(val)) \
goto TRUE_BRANCH_117; \
goto FALSE_BRANCH_118; \
TRUE_BRANCH_117: \
if (INFO) print_info("TRUE_BRANCH_117"); \
val = NUMOBJ(1); \
goto AFTER_IF_119; \
FALSE_BRANCH_118: \
if (INFO) print_info("FALSE_BRANCH_118"); \
func = lookup(NAMEOBJ("="), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_126; \
COMPILED_127: \
if (INFO) print_info("COMPILED_127"); \
cont = LABELOBJ(_AFTER_CALL_128); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_126: \
if (INFO) print_info("PRIMITIVE_126"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_128: \
if (INFO) print_info("AFTER_CALL_128"); \
if (isTrue(val)) \
goto TRUE_BRANCH_123; \
goto FALSE_BRANCH_124; \
TRUE_BRANCH_123: \
if (INFO) print_info("TRUE_BRANCH_123"); \
val = NUMOBJ(1); \
goto AFTER_IF_125; \
FALSE_BRANCH_124: \
if (INFO) print_info("FALSE_BRANCH_124"); \
val = NUMOBJ(0); \
AFTER_IF_125: \
if (INFO) print_info("AFTER_IF_125"); \
AFTER_IF_119: \
if (INFO) print_info("AFTER_IF_119"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_114; \
goto FALSE_BRANCH_115; \
TRUE_BRANCH_114: \
if (INFO) print_info("TRUE_BRANCH_114"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
FALSE_BRANCH_115: \
if (INFO) print_info("FALSE_BRANCH_115"); \
func = lookup(NAMEOBJ("+"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_fibonacci_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(2); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_135; \
COMPILED_136: \
if (INFO) print_info("COMPILED_136"); \
cont = LABELOBJ(_AFTER_CALL_137); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_135: \
if (INFO) print_info("PRIMITIVE_135"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_137: \
if (INFO) print_info("AFTER_CALL_137"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_138; \
COMPILED_139: \
if (INFO) print_info("COMPILED_139"); \
cont = LABELOBJ(_AFTER_CALL_140); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_138: \
if (INFO) print_info("PRIMITIVE_138"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_140: \
if (INFO) print_info("AFTER_CALL_140"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("recursive_fibonacci_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("-"), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_129; \
COMPILED_130: \
if (INFO) print_info("COMPILED_130"); \
cont = LABELOBJ(_AFTER_CALL_131); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_129: \
if (INFO) print_info("PRIMITIVE_129"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_131: \
if (INFO) print_info("AFTER_CALL_131"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_132; \
COMPILED_133: \
if (INFO) print_info("COMPILED_133"); \
cont = LABELOBJ(_AFTER_CALL_134); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_132: \
if (INFO) print_info("PRIMITIVE_132"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_134: \
if (INFO) print_info("AFTER_CALL_134"); \
restore(arglist); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_141; \
COMPILED_142: \
if (INFO) print_info("COMPILED_142"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_141: \
if (INFO) print_info("PRIMITIVE_141"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_143: \
if (INFO) print_info("AFTER_CALL_143"); \
AFTER_IF_116: \
if (INFO) print_info("AFTER_IF_116"); \
AFTER_LAMBDA_113: \
if (INFO) print_info("AFTER_LAMBDA_113"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_144, env); \
goto AFTER_LAMBDA_145; \
ENTRY_144: \
if (INFO) print_info("ENTRY_144"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_146, env); \
goto AFTER_LAMBDA_147; \
ENTRY_146: \
if (INFO) print_info("ENTRY_146"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_151; \
COMPILED_152: \
if (INFO) print_info("COMPILED_152"); \
cont = LABELOBJ(_AFTER_CALL_153); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_151: \
if (INFO) print_info("PRIMITIVE_151"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_153: \
if (INFO) print_info("AFTER_CALL_153"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_148; \
goto FALSE_BRANCH_149; \
TRUE_BRANCH_148: \
if (INFO) print_info("TRUE_BRANCH_148"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
FALSE_BRANCH_149: \
if (INFO) print_info("FALSE_BRANCH_149"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("+"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("a"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_157; \
COMPILED_158: \
if (INFO) print_info("COMPILED_158"); \
cont = LABELOBJ(_AFTER_CALL_159); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_157: \
if (INFO) print_info("PRIMITIVE_157"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_159: \
if (INFO) print_info("AFTER_CALL_159"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_154; \
COMPILED_155: \
if (INFO) print_info("COMPILED_155"); \
cont = LABELOBJ(_AFTER_CALL_156); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_154: \
if (INFO) print_info("PRIMITIVE_154"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_156: \
if (INFO) print_info("AFTER_CALL_156"); \
restore(arglist); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_160; \
COMPILED_161: \
if (INFO) print_info("COMPILED_161"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_160: \
if (INFO) print_info("PRIMITIVE_160"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_162: \
if (INFO) print_info("AFTER_CALL_162"); \
AFTER_IF_150: \
if (INFO) print_info("AFTER_IF_150"); \
AFTER_LAMBDA_147: \
if (INFO) print_info("AFTER_LAMBDA_147"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = NUMOBJ(0); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
val = lookup(NAMEOBJ("n"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_163; \
COMPILED_164: \
if (INFO) print_info("COMPILED_164"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_163: \
if (INFO) print_info("PRIMITIVE_163"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_165: \
if (INFO) print_info("AFTER_CALL_165"); \
AFTER_LAMBDA_145: \
if (INFO) print_info("AFTER_LAMBDA_145"); \
defineVar(NAMEOBJ("iterative_fibonacci_compiled"), val, env); \
val = lookup(NAMEOBJ("iterative_factorial_compiled"), env); \
defineVar(NAMEOBJ("factorial"), val, env); \
val = lookup(NAMEOBJ("iterative_fibonacci_compiled"), env); \
defineVar(NAMEOBJ("fibonacci"), val, env); \
val = COMPOBJ(_ENTRY_166, env); \
goto AFTER_LAMBDA_167; \
ENTRY_166: \
if (INFO) print_info("ENTRY_166"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_168, env); \
goto CONTINUE; \
ENTRY_168: \
if (INFO) print_info("ENTRY_168"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("s"), env); \
val = lookup(NAMEOBJ("y"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
val = lookup(NAMEOBJ("x"), env); \
arglist = LISTOBJ(makeList(val, GETLIST(arglist))); \
if (isPrimitive(func)) \
goto PRIMITIVE_170; \
COMPILED_171: \
if (INFO) print_info("COMPILED_171"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_170: \
if (INFO) print_info("PRIMITIVE_170"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_172: \
if (INFO) print_info("AFTER_CALL_172"); \
AFTER_LAMBDA_169: \
if (INFO) print_info("AFTER_LAMBDA_169"); \
AFTER_LAMBDA_167: \
if (INFO) print_info("AFTER_LAMBDA_167"); \
defineVar(NAMEOBJ("cons"), val, env); \
val = COMPOBJ(_ENTRY_173, env); \
goto AFTER_LAMBDA_174; \
ENTRY_173: \
if (INFO) print_info("ENTRY_173"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_175, env); \
goto AFTER_LAMBDA_176; \
ENTRY_175: \
if (INFO) print_info("ENTRY_175"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("x"), env); \
goto CONTINUE; \
AFTER_LAMBDA_176: \
if (INFO) print_info("AFTER_LAMBDA_176"); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_177; \
COMPILED_178: \
if (INFO) print_info("COMPILED_178"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_177: \
if (INFO) print_info("PRIMITIVE_177"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_179: \
if (INFO) print_info("AFTER_CALL_179"); \
AFTER_LAMBDA_174: \
if (INFO) print_info("AFTER_LAMBDA_174"); \
defineVar(NAMEOBJ("car"), val, env); \
val = COMPOBJ(_ENTRY_180, env); \
goto AFTER_LAMBDA_181; \
ENTRY_180: \
if (INFO) print_info("ENTRY_180"); \
env = COMPENVOBJ(func); \
unev = parse("(p)\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("p"), env); \
val = COMPOBJ(_ENTRY_182, env); \
goto AFTER_LAMBDA_183; \
ENTRY_182: \
if (INFO) print_info("ENTRY_182"); \
env = COMPENVOBJ(func); \
unev = parse("(x y)\n"); \
env = extendEnv(unev, arglist, env); \
val = lookup(NAMEOBJ("y"), env); \
goto CONTINUE; \
AFTER_LAMBDA_183: \
if (INFO) print_info("AFTER_LAMBDA_183"); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_184; \
COMPILED_185: \
if (INFO) print_info("COMPILED_185"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_184: \
if (INFO) print_info("PRIMITIVE_184"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_186: \
if (INFO) print_info("AFTER_CALL_186"); \
AFTER_LAMBDA_181: \
if (INFO) print_info("AFTER_LAMBDA_181"); \
defineVar(NAMEOBJ("cdr"), val, env); \
unev = parse("()\n"); \
val = unev; \
defineVar(NAMEOBJ("nil"), val, env); \
val = COMPOBJ(_ENTRY_187, env); \
goto AFTER_LAMBDA_188; \
ENTRY_187: \
if (INFO) print_info("ENTRY_187"); \
env = COMPENVOBJ(func); \
unev = parse("(s)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_192; \
COMPILED_193: \
if (INFO) print_info("COMPILED_193"); \
cont = LABELOBJ(_AFTER_CALL_194); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_192: \
if (INFO) print_info("PRIMITIVE_192"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_194: \
if (INFO) print_info("AFTER_CALL_194"); \
restore(env); \
restore(cont); \
if (isTrue(val)) \
goto TRUE_BRANCH_189; \
goto FALSE_BRANCH_190; \
TRUE_BRANCH_189: \
if (INFO) print_info("TRUE_BRANCH_189"); \
val = NUMOBJ(0); \
goto CONTINUE; \
FALSE_BRANCH_190: \
if (INFO) print_info("FALSE_BRANCH_190"); \
func = lookup(NAMEOBJ("add1"), env); \
save(cont); \
save(func); \
func = lookup(NAMEOBJ("length"), env); \
save(func); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("s"), env); \
arglist = LISTOBJ(makeList(val, NULL)); \
if (isPrimitive(func)) \
goto PRIMITIVE_195; \
COMPILED_196: \
if (INFO) print_info("COMPILED_196"); \
cont = LABELOBJ(_AFTER_CALL_197); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_195: \
if (INFO) print_info("PRIMITIVE_195"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_197: \
if (INFO) print_info("AFTER_CALL_197"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
if (isPrimitive(func)) \
goto PRIMITIVE_198; \
COMPILED_199: \
if (INFO) print_info("COMPILED_199"); \
cont = LABELOBJ(_AFTER_CALL_200); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_198: \
if (INFO) print_info("PRIMITIVE_198"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_200: \
if (INFO) print_info("AFTER_CALL_200"); \
arglist = LISTOBJ(makeList(val, NULL)); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) \
goto PRIMITIVE_201; \
COMPILED_202: \
if (INFO) print_info("COMPILED_202"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
PRIMITIVE_201: \
if (INFO) print_info("PRIMITIVE_201"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_203: \
if (INFO) print_info("AFTER_CALL_203"); \
AFTER_IF_191: \
if (INFO) print_info("AFTER_IF_191"); \
AFTER_LAMBDA_188: \
if (INFO) print_info("AFTER_LAMBDA_188"); \
defineVar(NAMEOBJ("length"), val, env); \
goto DONE; 
