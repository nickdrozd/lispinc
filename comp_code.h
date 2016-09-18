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
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_18; \
if (isCompound(func)) goto COMPOUND_19; \
COMPILED_20: print_info("COMPILED_20"); \
cont = LABELOBJ(_AFTER_CALL_21); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_19: print_info("COMPOUND_19"); \
cont = LABELOBJ(_AFTER_CALL_21); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_18: print_info("PRIMITIVE_18"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_21: print_info("AFTER_CALL_21"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("add1"), env); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_14; \
if (isCompound(func)) goto COMPOUND_15; \
COMPILED_16: print_info("COMPILED_16"); \
cont = LABELOBJ(_AFTER_CALL_17); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_15: print_info("COMPOUND_15"); \
cont = LABELOBJ(_AFTER_CALL_17); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_14: print_info("PRIMITIVE_14"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_17: print_info("AFTER_CALL_17"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_22; \
if (isCompound(func)) goto COMPOUND_23; \
COMPILED_24: print_info("COMPILED_24"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_23: print_info("COMPOUND_23"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_22: print_info("PRIMITIVE_22"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_25: print_info("AFTER_CALL_25"); \
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
if (isPrimitive(func)) goto PRIMITIVE_26; \
if (isCompound(func)) goto COMPOUND_27; \
COMPILED_28: print_info("COMPILED_28"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_27: print_info("COMPOUND_27"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_26: print_info("PRIMITIVE_26"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_29: print_info("AFTER_CALL_29"); \
AFTER_LAMBDA_4: print_info("AFTER_LAMBDA_4"); \
defineVar(NAMEOBJ("length"), val, env); \
val = COMPOBJ(_ENTRY_30, env); \
goto AFTER_LAMBDA_31; \
ENTRY_30: print_info("ENTRY_30"); \
env = COMPENVOBJ(func); \
unev = parse("(items n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_35; \
if (isCompound(func)) goto COMPOUND_36; \
COMPILED_37: print_info("COMPILED_37"); \
cont = LABELOBJ(_AFTER_CALL_38); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_36: print_info("COMPOUND_36"); \
cont = LABELOBJ(_AFTER_CALL_38); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_35: print_info("PRIMITIVE_35"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_38: print_info("AFTER_CALL_38"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_32; \
FALSE_BRANCH_33: print_info("FALSE_BRANCH_33"); \
func = lookup(NAMEOBJ("list-ref"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_47; \
if (isCompound(func)) goto COMPOUND_48; \
COMPILED_49: print_info("COMPILED_49"); \
cont = LABELOBJ(_AFTER_CALL_50); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_48: print_info("COMPOUND_48"); \
cont = LABELOBJ(_AFTER_CALL_50); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_47: print_info("PRIMITIVE_47"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_50: print_info("AFTER_CALL_50"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_43; \
if (isCompound(func)) goto COMPOUND_44; \
COMPILED_45: print_info("COMPILED_45"); \
cont = LABELOBJ(_AFTER_CALL_46); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_44: print_info("COMPOUND_44"); \
cont = LABELOBJ(_AFTER_CALL_46); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_43: print_info("PRIMITIVE_43"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_46: print_info("AFTER_CALL_46"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_51; \
if (isCompound(func)) goto COMPOUND_52; \
COMPILED_53: print_info("COMPILED_53"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_52: print_info("COMPOUND_52"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_51: print_info("PRIMITIVE_51"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_54: print_info("AFTER_CALL_54"); \
TRUE_BRANCH_32: print_info("TRUE_BRANCH_32"); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_39; \
if (isCompound(func)) goto COMPOUND_40; \
COMPILED_41: print_info("COMPILED_41"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_40: print_info("COMPOUND_40"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_39: print_info("PRIMITIVE_39"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_42: print_info("AFTER_CALL_42"); \
AFTER_IF_34: print_info("AFTER_IF_34"); \
AFTER_LAMBDA_31: print_info("AFTER_LAMBDA_31"); \
defineVar(NAMEOBJ("list-ref"), val, env); \
val = COMPOBJ(_ENTRY_55, env); \
goto AFTER_LAMBDA_56; \
ENTRY_55: print_info("ENTRY_55"); \
env = COMPENVOBJ(func); \
unev = parse("(list1 list2)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_60; \
if (isCompound(func)) goto COMPOUND_61; \
COMPILED_62: print_info("COMPILED_62"); \
cont = LABELOBJ(_AFTER_CALL_63); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_61: print_info("COMPOUND_61"); \
cont = LABELOBJ(_AFTER_CALL_63); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_60: print_info("PRIMITIVE_60"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_63: print_info("AFTER_CALL_63"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_57; \
FALSE_BRANCH_58: print_info("FALSE_BRANCH_58"); \
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
if (isPrimitive(func)) goto PRIMITIVE_68; \
if (isCompound(func)) goto COMPOUND_69; \
COMPILED_70: print_info("COMPILED_70"); \
cont = LABELOBJ(_AFTER_CALL_71); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_69: print_info("COMPOUND_69"); \
cont = LABELOBJ(_AFTER_CALL_71); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_68: print_info("PRIMITIVE_68"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_71: print_info("AFTER_CALL_71"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_72; \
if (isCompound(func)) goto COMPOUND_73; \
COMPILED_74: print_info("COMPILED_74"); \
cont = LABELOBJ(_AFTER_CALL_75); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_73: print_info("COMPOUND_73"); \
cont = LABELOBJ(_AFTER_CALL_75); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_72: print_info("PRIMITIVE_72"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_75: print_info("AFTER_CALL_75"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("list1"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_64; \
if (isCompound(func)) goto COMPOUND_65; \
COMPILED_66: print_info("COMPILED_66"); \
cont = LABELOBJ(_AFTER_CALL_67); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_65: print_info("COMPOUND_65"); \
cont = LABELOBJ(_AFTER_CALL_67); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_64: print_info("PRIMITIVE_64"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_67: print_info("AFTER_CALL_67"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_76; \
if (isCompound(func)) goto COMPOUND_77; \
COMPILED_78: print_info("COMPILED_78"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_77: print_info("COMPOUND_77"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_76: print_info("PRIMITIVE_76"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_79: print_info("AFTER_CALL_79"); \
TRUE_BRANCH_57: print_info("TRUE_BRANCH_57"); \
val = lookup(NAMEOBJ("list2"), env); \
goto CONTINUE; \
AFTER_IF_59: print_info("AFTER_IF_59"); \
AFTER_LAMBDA_56: print_info("AFTER_LAMBDA_56"); \
defineVar(NAMEOBJ("append"), val, env); \
val = COMPOBJ(_ENTRY_80, env); \
goto AFTER_LAMBDA_81; \
ENTRY_80: print_info("ENTRY_80"); \
env = COMPENVOBJ(func); \
unev = parse("(items)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_82, env); \
goto AFTER_LAMBDA_83; \
ENTRY_82: print_info("ENTRY_82"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
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
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_84; \
FALSE_BRANCH_85: print_info("FALSE_BRANCH_85"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_99; \
if (isCompound(func)) goto COMPOUND_100; \
COMPILED_101: print_info("COMPILED_101"); \
cont = LABELOBJ(_AFTER_CALL_102); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_100: print_info("COMPOUND_100"); \
cont = LABELOBJ(_AFTER_CALL_102); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_99: print_info("PRIMITIVE_99"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_102: print_info("AFTER_CALL_102"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("cons"), env); \
save(func); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, NULLOBJ); \
save(arglist); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("rest"), env); \
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
restore(arglist); \
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
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_103; \
if (isCompound(func)) goto COMPOUND_104; \
COMPILED_105: print_info("COMPILED_105"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_104: print_info("COMPOUND_104"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_103: print_info("PRIMITIVE_103"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_106: print_info("AFTER_CALL_106"); \
TRUE_BRANCH_84: print_info("TRUE_BRANCH_84"); \
val = lookup(NAMEOBJ("result"), env); \
goto CONTINUE; \
AFTER_IF_86: print_info("AFTER_IF_86"); \
AFTER_LAMBDA_83: print_info("AFTER_LAMBDA_83"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("nil"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_107; \
if (isCompound(func)) goto COMPOUND_108; \
COMPILED_109: print_info("COMPILED_109"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_108: print_info("COMPOUND_108"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_107: print_info("PRIMITIVE_107"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_110: print_info("AFTER_CALL_110"); \
AFTER_LAMBDA_81: print_info("AFTER_LAMBDA_81"); \
defineVar(NAMEOBJ("reverse"), val, env); \
val = COMPOBJ(_ENTRY_111, env); \
goto AFTER_LAMBDA_112; \
ENTRY_111: print_info("ENTRY_111"); \
env = COMPENVOBJ(func); \
unev = parse("(func items)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_113, env); \
goto AFTER_LAMBDA_114; \
ENTRY_113: print_info("ENTRY_113"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_118; \
if (isCompound(func)) goto COMPOUND_119; \
COMPILED_120: print_info("COMPILED_120"); \
cont = LABELOBJ(_AFTER_CALL_121); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_119: print_info("COMPOUND_119"); \
cont = LABELOBJ(_AFTER_CALL_121); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_118: print_info("PRIMITIVE_118"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_121: print_info("AFTER_CALL_121"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_115; \
FALSE_BRANCH_116: print_info("FALSE_BRANCH_116"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_138; \
if (isCompound(func)) goto COMPOUND_139; \
COMPILED_140: print_info("COMPILED_140"); \
cont = LABELOBJ(_AFTER_CALL_141); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_139: print_info("COMPOUND_139"); \
cont = LABELOBJ(_AFTER_CALL_141); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_138: print_info("PRIMITIVE_138"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_141: print_info("AFTER_CALL_141"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
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
if (isPrimitive(func)) goto PRIMITIVE_126; \
if (isCompound(func)) goto COMPOUND_127; \
COMPILED_128: print_info("COMPILED_128"); \
cont = LABELOBJ(_AFTER_CALL_129); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_127: print_info("COMPOUND_127"); \
cont = LABELOBJ(_AFTER_CALL_129); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_126: print_info("PRIMITIVE_126"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_129: print_info("AFTER_CALL_129"); \
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
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_134; \
if (isCompound(func)) goto COMPOUND_135; \
COMPILED_136: print_info("COMPILED_136"); \
cont = LABELOBJ(_AFTER_CALL_137); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_135: print_info("COMPOUND_135"); \
cont = LABELOBJ(_AFTER_CALL_137); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_134: print_info("PRIMITIVE_134"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_137: print_info("AFTER_CALL_137"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_142; \
if (isCompound(func)) goto COMPOUND_143; \
COMPILED_144: print_info("COMPILED_144"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_143: print_info("COMPOUND_143"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_142: print_info("PRIMITIVE_142"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_145: print_info("AFTER_CALL_145"); \
TRUE_BRANCH_115: print_info("TRUE_BRANCH_115"); \
func = lookup(NAMEOBJ("reverse"), env); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_122; \
if (isCompound(func)) goto COMPOUND_123; \
COMPILED_124: print_info("COMPILED_124"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_123: print_info("COMPOUND_123"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_122: print_info("PRIMITIVE_122"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_125: print_info("AFTER_CALL_125"); \
AFTER_IF_117: print_info("AFTER_IF_117"); \
AFTER_LAMBDA_114: print_info("AFTER_LAMBDA_114"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("items"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("nil"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_146; \
if (isCompound(func)) goto COMPOUND_147; \
COMPILED_148: print_info("COMPILED_148"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_147: print_info("COMPOUND_147"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_146: print_info("PRIMITIVE_146"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_149: print_info("AFTER_CALL_149"); \
AFTER_LAMBDA_112: print_info("AFTER_LAMBDA_112"); \
defineVar(NAMEOBJ("map"), val, env); \
val = COMPOBJ(_ENTRY_150, env); \
goto AFTER_LAMBDA_151; \
ENTRY_150: print_info("ENTRY_150"); \
env = COMPENVOBJ(func); \
unev = parse("(comb null seq)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_152, env); \
goto AFTER_LAMBDA_153; \
ENTRY_152: print_info("ENTRY_152"); \
env = COMPENVOBJ(func); \
unev = parse("(result rest)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("null?"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_157; \
if (isCompound(func)) goto COMPOUND_158; \
COMPILED_159: print_info("COMPILED_159"); \
cont = LABELOBJ(_AFTER_CALL_160); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_158: print_info("COMPOUND_158"); \
cont = LABELOBJ(_AFTER_CALL_160); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_157: print_info("PRIMITIVE_157"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_160: print_info("AFTER_CALL_160"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_154; \
FALSE_BRANCH_155: print_info("FALSE_BRANCH_155"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("cdr"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_169; \
if (isCompound(func)) goto COMPOUND_170; \
COMPILED_171: print_info("COMPILED_171"); \
cont = LABELOBJ(_AFTER_CALL_172); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_170: print_info("COMPOUND_170"); \
cont = LABELOBJ(_AFTER_CALL_172); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_169: print_info("PRIMITIVE_169"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_172: print_info("AFTER_CALL_172"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("comb"), env); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("car"), env); \
val = lookup(NAMEOBJ("rest"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_161; \
if (isCompound(func)) goto COMPOUND_162; \
COMPILED_163: print_info("COMPILED_163"); \
cont = LABELOBJ(_AFTER_CALL_164); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_162: print_info("COMPOUND_162"); \
cont = LABELOBJ(_AFTER_CALL_164); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_161: print_info("PRIMITIVE_161"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_164: print_info("AFTER_CALL_164"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("result"), env); \
arglist = CONS(val, arglist); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_165; \
if (isCompound(func)) goto COMPOUND_166; \
COMPILED_167: print_info("COMPILED_167"); \
cont = LABELOBJ(_AFTER_CALL_168); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_166: print_info("COMPOUND_166"); \
cont = LABELOBJ(_AFTER_CALL_168); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_165: print_info("PRIMITIVE_165"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_168: print_info("AFTER_CALL_168"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
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
TRUE_BRANCH_154: print_info("TRUE_BRANCH_154"); \
val = lookup(NAMEOBJ("result"), env); \
goto CONTINUE; \
AFTER_IF_156: print_info("AFTER_IF_156"); \
AFTER_LAMBDA_153: print_info("AFTER_LAMBDA_153"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = lookup(NAMEOBJ("seq"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("null"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_177; \
if (isCompound(func)) goto COMPOUND_178; \
COMPILED_179: print_info("COMPILED_179"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_178: print_info("COMPOUND_178"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_177: print_info("PRIMITIVE_177"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_180: print_info("AFTER_CALL_180"); \
AFTER_LAMBDA_151: print_info("AFTER_LAMBDA_151"); \
defineVar(NAMEOBJ("fold-left"), val, env); \
val = COMPOBJ(_ENTRY_181, env); \
goto AFTER_LAMBDA_182; \
ENTRY_181: print_info("ENTRY_181"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-left"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("__+__"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_183; \
if (isCompound(func)) goto COMPOUND_184; \
COMPILED_185: print_info("COMPILED_185"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_184: print_info("COMPOUND_184"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_183: print_info("PRIMITIVE_183"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_186: print_info("AFTER_CALL_186"); \
AFTER_LAMBDA_182: print_info("AFTER_LAMBDA_182"); \
defineVar(NAMEOBJ("+"), val, env); \
val = COMPOBJ(_ENTRY_187, env); \
goto AFTER_LAMBDA_188; \
ENTRY_187: print_info("ENTRY_187"); \
env = COMPENVOBJ(func); \
unev = parse("nums\n"); \
env = extendEnv(unev, arglist, env); \
func = lookup(NAMEOBJ("fold-left"), env); \
val = lookup(NAMEOBJ("nums"), env); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(1); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("__*__"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_189; \
if (isCompound(func)) goto COMPOUND_190; \
COMPILED_191: print_info("COMPILED_191"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_190: print_info("COMPOUND_190"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_189: print_info("PRIMITIVE_189"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_192: print_info("AFTER_CALL_192"); \
AFTER_LAMBDA_188: print_info("AFTER_LAMBDA_188"); \
defineVar(NAMEOBJ("*"), val, env); \
val = COMPOBJ(_ENTRY_193, env); \
goto AFTER_LAMBDA_194; \
ENTRY_193: print_info("ENTRY_193"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_198; \
if (isCompound(func)) goto COMPOUND_199; \
COMPILED_200: print_info("COMPILED_200"); \
cont = LABELOBJ(_AFTER_CALL_201); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_199: print_info("COMPOUND_199"); \
cont = LABELOBJ(_AFTER_CALL_201); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_198: print_info("PRIMITIVE_198"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_201: print_info("AFTER_CALL_201"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_195; \
FALSE_BRANCH_196: print_info("FALSE_BRANCH_196"); \
func = lookup(NAMEOBJ("__*__"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("recursive_factorial_compiled"), env); \
save(func); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_202; \
if (isCompound(func)) goto COMPOUND_203; \
COMPILED_204: print_info("COMPILED_204"); \
cont = LABELOBJ(_AFTER_CALL_205); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_203: print_info("COMPOUND_203"); \
cont = LABELOBJ(_AFTER_CALL_205); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_202: print_info("PRIMITIVE_202"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_205: print_info("AFTER_CALL_205"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_206; \
if (isCompound(func)) goto COMPOUND_207; \
COMPILED_208: print_info("COMPILED_208"); \
cont = LABELOBJ(_AFTER_CALL_209); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_207: print_info("COMPOUND_207"); \
cont = LABELOBJ(_AFTER_CALL_209); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_206: print_info("PRIMITIVE_206"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_209: print_info("AFTER_CALL_209"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_210; \
if (isCompound(func)) goto COMPOUND_211; \
COMPILED_212: print_info("COMPILED_212"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_211: print_info("COMPOUND_211"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_210: print_info("PRIMITIVE_210"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_213: print_info("AFTER_CALL_213"); \
TRUE_BRANCH_195: print_info("TRUE_BRANCH_195"); \
val = NUMOBJ(1); \
goto CONTINUE; \
AFTER_IF_197: print_info("AFTER_IF_197"); \
AFTER_LAMBDA_194: print_info("AFTER_LAMBDA_194"); \
defineVar(NAMEOBJ("recursive_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_214, env); \
goto AFTER_LAMBDA_215; \
ENTRY_214: print_info("ENTRY_214"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_216, env); \
goto AFTER_LAMBDA_217; \
ENTRY_216: print_info("ENTRY_216"); \
env = COMPENVOBJ(func); \
unev = parse("(count total)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_221; \
if (isCompound(func)) goto COMPOUND_222; \
COMPILED_223: print_info("COMPILED_223"); \
cont = LABELOBJ(_AFTER_CALL_224); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_222: print_info("COMPOUND_222"); \
cont = LABELOBJ(_AFTER_CALL_224); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_221: print_info("PRIMITIVE_221"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_224: print_info("AFTER_CALL_224"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_218; \
FALSE_BRANCH_219: print_info("FALSE_BRANCH_219"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("__*__"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("total"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_229; \
if (isCompound(func)) goto COMPOUND_230; \
COMPILED_231: print_info("COMPILED_231"); \
cont = LABELOBJ(_AFTER_CALL_232); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_230: print_info("COMPOUND_230"); \
cont = LABELOBJ(_AFTER_CALL_232); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_229: print_info("PRIMITIVE_229"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_232: print_info("AFTER_CALL_232"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_225; \
if (isCompound(func)) goto COMPOUND_226; \
COMPILED_227: print_info("COMPILED_227"); \
cont = LABELOBJ(_AFTER_CALL_228); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_226: print_info("COMPOUND_226"); \
cont = LABELOBJ(_AFTER_CALL_228); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_225: print_info("PRIMITIVE_225"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_228: print_info("AFTER_CALL_228"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_233; \
if (isCompound(func)) goto COMPOUND_234; \
COMPILED_235: print_info("COMPILED_235"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_234: print_info("COMPOUND_234"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_233: print_info("PRIMITIVE_233"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_236: print_info("AFTER_CALL_236"); \
TRUE_BRANCH_218: print_info("TRUE_BRANCH_218"); \
val = lookup(NAMEOBJ("total"), env); \
goto CONTINUE; \
AFTER_IF_220: print_info("AFTER_IF_220"); \
AFTER_LAMBDA_217: print_info("AFTER_LAMBDA_217"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_237; \
if (isCompound(func)) goto COMPOUND_238; \
COMPILED_239: print_info("COMPILED_239"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_238: print_info("COMPOUND_238"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_237: print_info("PRIMITIVE_237"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_240: print_info("AFTER_CALL_240"); \
AFTER_LAMBDA_215: print_info("AFTER_LAMBDA_215"); \
defineVar(NAMEOBJ("iterative_factorial_compiled"), val, env); \
val = COMPOBJ(_ENTRY_241, env); \
goto AFTER_LAMBDA_242; \
ENTRY_241: print_info("ENTRY_241"); \
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
if (isPrimitive(func)) goto PRIMITIVE_246; \
if (isCompound(func)) goto COMPOUND_247; \
COMPILED_248: print_info("COMPILED_248"); \
cont = LABELOBJ(_AFTER_CALL_249); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_247: print_info("COMPOUND_247"); \
cont = LABELOBJ(_AFTER_CALL_249); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_246: print_info("PRIMITIVE_246"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_249: print_info("AFTER_CALL_249"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_243; \
FALSE_BRANCH_244: print_info("FALSE_BRANCH_244"); \
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
if (isPrimitive(func)) goto PRIMITIVE_258; \
if (isCompound(func)) goto COMPOUND_259; \
COMPILED_260: print_info("COMPILED_260"); \
cont = LABELOBJ(_AFTER_CALL_261); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_259: print_info("COMPOUND_259"); \
cont = LABELOBJ(_AFTER_CALL_261); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_258: print_info("PRIMITIVE_258"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_261: print_info("AFTER_CALL_261"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_262; \
if (isCompound(func)) goto COMPOUND_263; \
COMPILED_264: print_info("COMPILED_264"); \
cont = LABELOBJ(_AFTER_CALL_265); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_263: print_info("COMPOUND_263"); \
cont = LABELOBJ(_AFTER_CALL_265); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_262: print_info("PRIMITIVE_262"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_265: print_info("AFTER_CALL_265"); \
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
if (isPrimitive(func)) goto PRIMITIVE_250; \
if (isCompound(func)) goto COMPOUND_251; \
COMPILED_252: print_info("COMPILED_252"); \
cont = LABELOBJ(_AFTER_CALL_253); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_251: print_info("COMPOUND_251"); \
cont = LABELOBJ(_AFTER_CALL_253); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_250: print_info("PRIMITIVE_250"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_253: print_info("AFTER_CALL_253"); \
arglist = CONS(val, NULLOBJ); \
restore(func); \
if (isPrimitive(func)) goto PRIMITIVE_254; \
if (isCompound(func)) goto COMPOUND_255; \
COMPILED_256: print_info("COMPILED_256"); \
cont = LABELOBJ(_AFTER_CALL_257); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_255: print_info("COMPOUND_255"); \
cont = LABELOBJ(_AFTER_CALL_257); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_254: print_info("PRIMITIVE_254"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_257: print_info("AFTER_CALL_257"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_266; \
if (isCompound(func)) goto COMPOUND_267; \
COMPILED_268: print_info("COMPILED_268"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_267: print_info("COMPOUND_267"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_266: print_info("PRIMITIVE_266"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_269: print_info("AFTER_CALL_269"); \
TRUE_BRANCH_243: print_info("TRUE_BRANCH_243"); \
val = lookup(NAMEOBJ("n"), env); \
goto CONTINUE; \
AFTER_IF_245: print_info("AFTER_IF_245"); \
AFTER_LAMBDA_242: print_info("AFTER_LAMBDA_242"); \
defineVar(NAMEOBJ("recursive_fibonacci_compiled"), val, env); \
val = COMPOBJ(_ENTRY_270, env); \
goto AFTER_LAMBDA_271; \
ENTRY_270: print_info("ENTRY_270"); \
env = COMPENVOBJ(func); \
unev = parse("(n)\n"); \
env = extendEnv(unev, arglist, env); \
val = COMPOBJ(_ENTRY_272, env); \
goto AFTER_LAMBDA_273; \
ENTRY_272: print_info("ENTRY_272"); \
env = COMPENVOBJ(func); \
unev = parse("(count a b)\n"); \
env = extendEnv(unev, arglist, env); \
save(cont); \
save(env); \
func = lookup(NAMEOBJ("zero?"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_277; \
if (isCompound(func)) goto COMPOUND_278; \
COMPILED_279: print_info("COMPILED_279"); \
cont = LABELOBJ(_AFTER_CALL_280); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_278: print_info("COMPOUND_278"); \
cont = LABELOBJ(_AFTER_CALL_280); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_277: print_info("PRIMITIVE_277"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_280: print_info("AFTER_CALL_280"); \
restore(env); \
restore(cont); \
if (isTrue(val)) goto TRUE_BRANCH_274; \
FALSE_BRANCH_275: print_info("FALSE_BRANCH_275"); \
func = lookup(NAMEOBJ("loop"), env); \
save(cont); \
save(func); \
save(env); \
func = lookup(NAMEOBJ("__+__"), env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, NULLOBJ); \
val = lookup(NAMEOBJ("a"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_285; \
if (isCompound(func)) goto COMPOUND_286; \
COMPILED_287: print_info("COMPILED_287"); \
cont = LABELOBJ(_AFTER_CALL_288); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_286: print_info("COMPOUND_286"); \
cont = LABELOBJ(_AFTER_CALL_288); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_285: print_info("PRIMITIVE_285"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_288: print_info("AFTER_CALL_288"); \
arglist = CONS(val, NULLOBJ); \
restore(env); \
val = lookup(NAMEOBJ("b"), env); \
arglist = CONS(val, arglist); \
save(arglist); \
func = lookup(NAMEOBJ("sub1"), env); \
val = lookup(NAMEOBJ("count"), env); \
arglist = CONS(val, NULLOBJ); \
if (isPrimitive(func)) goto PRIMITIVE_281; \
if (isCompound(func)) goto COMPOUND_282; \
COMPILED_283: print_info("COMPILED_283"); \
cont = LABELOBJ(_AFTER_CALL_284); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_282: print_info("COMPOUND_282"); \
cont = LABELOBJ(_AFTER_CALL_284); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_281: print_info("PRIMITIVE_281"); \
val = applyPrimitive(func, arglist); \
AFTER_CALL_284: print_info("AFTER_CALL_284"); \
restore(arglist); \
arglist = CONS(val, arglist); \
restore(func); \
restore(cont); \
if (isPrimitive(func)) goto PRIMITIVE_289; \
if (isCompound(func)) goto COMPOUND_290; \
COMPILED_291: print_info("COMPILED_291"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_290: print_info("COMPOUND_290"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_289: print_info("PRIMITIVE_289"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_292: print_info("AFTER_CALL_292"); \
TRUE_BRANCH_274: print_info("TRUE_BRANCH_274"); \
val = lookup(NAMEOBJ("a"), env); \
goto CONTINUE; \
AFTER_IF_276: print_info("AFTER_IF_276"); \
AFTER_LAMBDA_273: print_info("AFTER_LAMBDA_273"); \
defineVar(NAMEOBJ("loop"), val, env); \
func = lookup(NAMEOBJ("loop"), env); \
val = NUMOBJ(1); \
arglist = CONS(val, NULLOBJ); \
val = NUMOBJ(0); \
arglist = CONS(val, arglist); \
val = lookup(NAMEOBJ("n"), env); \
arglist = CONS(val, arglist); \
if (isPrimitive(func)) goto PRIMITIVE_293; \
if (isCompound(func)) goto COMPOUND_294; \
COMPILED_295: print_info("COMPILED_295"); \
val = COMPLABOBJ(func); \
goto COMP_LABEL; \
COMPOUND_294: print_info("COMPOUND_294"); \
save(cont); \
goto APPLY_COMPOUND; \
PRIMITIVE_293: print_info("PRIMITIVE_293"); \
val = applyPrimitive(func, arglist); \
goto CONTINUE; \
AFTER_CALL_296: print_info("AFTER_CALL_296"); \
AFTER_LAMBDA_271: print_info("AFTER_LAMBDA_271"); \
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
if (GETLABEL(REG) == _PRIMITIVE_22) goto PRIMITIVE_22; \
if (GETLABEL(REG) == _COMPOUND_23) goto COMPOUND_23; \
if (GETLABEL(REG) == _COMPILED_24) goto COMPILED_24; \
if (GETLABEL(REG) == _AFTER_CALL_25) goto AFTER_CALL_25; \
if (GETLABEL(REG) == _PRIMITIVE_26) goto PRIMITIVE_26; \
if (GETLABEL(REG) == _COMPOUND_27) goto COMPOUND_27; \
if (GETLABEL(REG) == _COMPILED_28) goto COMPILED_28; \
if (GETLABEL(REG) == _AFTER_CALL_29) goto AFTER_CALL_29; \
if (GETLABEL(REG) == _ENTRY_30) goto ENTRY_30; \
if (GETLABEL(REG) == _AFTER_LAMBDA_31) goto AFTER_LAMBDA_31; \
if (GETLABEL(REG) == _TRUE_BRANCH_32) goto TRUE_BRANCH_32; \
if (GETLABEL(REG) == _FALSE_BRANCH_33) goto FALSE_BRANCH_33; \
if (GETLABEL(REG) == _AFTER_IF_34) goto AFTER_IF_34; \
if (GETLABEL(REG) == _PRIMITIVE_35) goto PRIMITIVE_35; \
if (GETLABEL(REG) == _COMPOUND_36) goto COMPOUND_36; \
if (GETLABEL(REG) == _COMPILED_37) goto COMPILED_37; \
if (GETLABEL(REG) == _AFTER_CALL_38) goto AFTER_CALL_38; \
if (GETLABEL(REG) == _PRIMITIVE_39) goto PRIMITIVE_39; \
if (GETLABEL(REG) == _COMPOUND_40) goto COMPOUND_40; \
if (GETLABEL(REG) == _COMPILED_41) goto COMPILED_41; \
if (GETLABEL(REG) == _AFTER_CALL_42) goto AFTER_CALL_42; \
if (GETLABEL(REG) == _PRIMITIVE_43) goto PRIMITIVE_43; \
if (GETLABEL(REG) == _COMPOUND_44) goto COMPOUND_44; \
if (GETLABEL(REG) == _COMPILED_45) goto COMPILED_45; \
if (GETLABEL(REG) == _AFTER_CALL_46) goto AFTER_CALL_46; \
if (GETLABEL(REG) == _PRIMITIVE_47) goto PRIMITIVE_47; \
if (GETLABEL(REG) == _COMPOUND_48) goto COMPOUND_48; \
if (GETLABEL(REG) == _COMPILED_49) goto COMPILED_49; \
if (GETLABEL(REG) == _AFTER_CALL_50) goto AFTER_CALL_50; \
if (GETLABEL(REG) == _PRIMITIVE_51) goto PRIMITIVE_51; \
if (GETLABEL(REG) == _COMPOUND_52) goto COMPOUND_52; \
if (GETLABEL(REG) == _COMPILED_53) goto COMPILED_53; \
if (GETLABEL(REG) == _AFTER_CALL_54) goto AFTER_CALL_54; \
if (GETLABEL(REG) == _ENTRY_55) goto ENTRY_55; \
if (GETLABEL(REG) == _AFTER_LAMBDA_56) goto AFTER_LAMBDA_56; \
if (GETLABEL(REG) == _TRUE_BRANCH_57) goto TRUE_BRANCH_57; \
if (GETLABEL(REG) == _FALSE_BRANCH_58) goto FALSE_BRANCH_58; \
if (GETLABEL(REG) == _AFTER_IF_59) goto AFTER_IF_59; \
if (GETLABEL(REG) == _PRIMITIVE_60) goto PRIMITIVE_60; \
if (GETLABEL(REG) == _COMPOUND_61) goto COMPOUND_61; \
if (GETLABEL(REG) == _COMPILED_62) goto COMPILED_62; \
if (GETLABEL(REG) == _AFTER_CALL_63) goto AFTER_CALL_63; \
if (GETLABEL(REG) == _PRIMITIVE_64) goto PRIMITIVE_64; \
if (GETLABEL(REG) == _COMPOUND_65) goto COMPOUND_65; \
if (GETLABEL(REG) == _COMPILED_66) goto COMPILED_66; \
if (GETLABEL(REG) == _AFTER_CALL_67) goto AFTER_CALL_67; \
if (GETLABEL(REG) == _PRIMITIVE_68) goto PRIMITIVE_68; \
if (GETLABEL(REG) == _COMPOUND_69) goto COMPOUND_69; \
if (GETLABEL(REG) == _COMPILED_70) goto COMPILED_70; \
if (GETLABEL(REG) == _AFTER_CALL_71) goto AFTER_CALL_71; \
if (GETLABEL(REG) == _PRIMITIVE_72) goto PRIMITIVE_72; \
if (GETLABEL(REG) == _COMPOUND_73) goto COMPOUND_73; \
if (GETLABEL(REG) == _COMPILED_74) goto COMPILED_74; \
if (GETLABEL(REG) == _AFTER_CALL_75) goto AFTER_CALL_75; \
if (GETLABEL(REG) == _PRIMITIVE_76) goto PRIMITIVE_76; \
if (GETLABEL(REG) == _COMPOUND_77) goto COMPOUND_77; \
if (GETLABEL(REG) == _COMPILED_78) goto COMPILED_78; \
if (GETLABEL(REG) == _AFTER_CALL_79) goto AFTER_CALL_79; \
if (GETLABEL(REG) == _ENTRY_80) goto ENTRY_80; \
if (GETLABEL(REG) == _AFTER_LAMBDA_81) goto AFTER_LAMBDA_81; \
if (GETLABEL(REG) == _ENTRY_82) goto ENTRY_82; \
if (GETLABEL(REG) == _AFTER_LAMBDA_83) goto AFTER_LAMBDA_83; \
if (GETLABEL(REG) == _TRUE_BRANCH_84) goto TRUE_BRANCH_84; \
if (GETLABEL(REG) == _FALSE_BRANCH_85) goto FALSE_BRANCH_85; \
if (GETLABEL(REG) == _AFTER_IF_86) goto AFTER_IF_86; \
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
if (GETLABEL(REG) == _PRIMITIVE_103) goto PRIMITIVE_103; \
if (GETLABEL(REG) == _COMPOUND_104) goto COMPOUND_104; \
if (GETLABEL(REG) == _COMPILED_105) goto COMPILED_105; \
if (GETLABEL(REG) == _AFTER_CALL_106) goto AFTER_CALL_106; \
if (GETLABEL(REG) == _PRIMITIVE_107) goto PRIMITIVE_107; \
if (GETLABEL(REG) == _COMPOUND_108) goto COMPOUND_108; \
if (GETLABEL(REG) == _COMPILED_109) goto COMPILED_109; \
if (GETLABEL(REG) == _AFTER_CALL_110) goto AFTER_CALL_110; \
if (GETLABEL(REG) == _ENTRY_111) goto ENTRY_111; \
if (GETLABEL(REG) == _AFTER_LAMBDA_112) goto AFTER_LAMBDA_112; \
if (GETLABEL(REG) == _ENTRY_113) goto ENTRY_113; \
if (GETLABEL(REG) == _AFTER_LAMBDA_114) goto AFTER_LAMBDA_114; \
if (GETLABEL(REG) == _TRUE_BRANCH_115) goto TRUE_BRANCH_115; \
if (GETLABEL(REG) == _FALSE_BRANCH_116) goto FALSE_BRANCH_116; \
if (GETLABEL(REG) == _AFTER_IF_117) goto AFTER_IF_117; \
if (GETLABEL(REG) == _PRIMITIVE_118) goto PRIMITIVE_118; \
if (GETLABEL(REG) == _COMPOUND_119) goto COMPOUND_119; \
if (GETLABEL(REG) == _COMPILED_120) goto COMPILED_120; \
if (GETLABEL(REG) == _AFTER_CALL_121) goto AFTER_CALL_121; \
if (GETLABEL(REG) == _PRIMITIVE_122) goto PRIMITIVE_122; \
if (GETLABEL(REG) == _COMPOUND_123) goto COMPOUND_123; \
if (GETLABEL(REG) == _COMPILED_124) goto COMPILED_124; \
if (GETLABEL(REG) == _AFTER_CALL_125) goto AFTER_CALL_125; \
if (GETLABEL(REG) == _PRIMITIVE_126) goto PRIMITIVE_126; \
if (GETLABEL(REG) == _COMPOUND_127) goto COMPOUND_127; \
if (GETLABEL(REG) == _COMPILED_128) goto COMPILED_128; \
if (GETLABEL(REG) == _AFTER_CALL_129) goto AFTER_CALL_129; \
if (GETLABEL(REG) == _PRIMITIVE_130) goto PRIMITIVE_130; \
if (GETLABEL(REG) == _COMPOUND_131) goto COMPOUND_131; \
if (GETLABEL(REG) == _COMPILED_132) goto COMPILED_132; \
if (GETLABEL(REG) == _AFTER_CALL_133) goto AFTER_CALL_133; \
if (GETLABEL(REG) == _PRIMITIVE_134) goto PRIMITIVE_134; \
if (GETLABEL(REG) == _COMPOUND_135) goto COMPOUND_135; \
if (GETLABEL(REG) == _COMPILED_136) goto COMPILED_136; \
if (GETLABEL(REG) == _AFTER_CALL_137) goto AFTER_CALL_137; \
if (GETLABEL(REG) == _PRIMITIVE_138) goto PRIMITIVE_138; \
if (GETLABEL(REG) == _COMPOUND_139) goto COMPOUND_139; \
if (GETLABEL(REG) == _COMPILED_140) goto COMPILED_140; \
if (GETLABEL(REG) == _AFTER_CALL_141) goto AFTER_CALL_141; \
if (GETLABEL(REG) == _PRIMITIVE_142) goto PRIMITIVE_142; \
if (GETLABEL(REG) == _COMPOUND_143) goto COMPOUND_143; \
if (GETLABEL(REG) == _COMPILED_144) goto COMPILED_144; \
if (GETLABEL(REG) == _AFTER_CALL_145) goto AFTER_CALL_145; \
if (GETLABEL(REG) == _PRIMITIVE_146) goto PRIMITIVE_146; \
if (GETLABEL(REG) == _COMPOUND_147) goto COMPOUND_147; \
if (GETLABEL(REG) == _COMPILED_148) goto COMPILED_148; \
if (GETLABEL(REG) == _AFTER_CALL_149) goto AFTER_CALL_149; \
if (GETLABEL(REG) == _ENTRY_150) goto ENTRY_150; \
if (GETLABEL(REG) == _AFTER_LAMBDA_151) goto AFTER_LAMBDA_151; \
if (GETLABEL(REG) == _ENTRY_152) goto ENTRY_152; \
if (GETLABEL(REG) == _AFTER_LAMBDA_153) goto AFTER_LAMBDA_153; \
if (GETLABEL(REG) == _TRUE_BRANCH_154) goto TRUE_BRANCH_154; \
if (GETLABEL(REG) == _FALSE_BRANCH_155) goto FALSE_BRANCH_155; \
if (GETLABEL(REG) == _AFTER_IF_156) goto AFTER_IF_156; \
if (GETLABEL(REG) == _PRIMITIVE_157) goto PRIMITIVE_157; \
if (GETLABEL(REG) == _COMPOUND_158) goto COMPOUND_158; \
if (GETLABEL(REG) == _COMPILED_159) goto COMPILED_159; \
if (GETLABEL(REG) == _AFTER_CALL_160) goto AFTER_CALL_160; \
if (GETLABEL(REG) == _PRIMITIVE_161) goto PRIMITIVE_161; \
if (GETLABEL(REG) == _COMPOUND_162) goto COMPOUND_162; \
if (GETLABEL(REG) == _COMPILED_163) goto COMPILED_163; \
if (GETLABEL(REG) == _AFTER_CALL_164) goto AFTER_CALL_164; \
if (GETLABEL(REG) == _PRIMITIVE_165) goto PRIMITIVE_165; \
if (GETLABEL(REG) == _COMPOUND_166) goto COMPOUND_166; \
if (GETLABEL(REG) == _COMPILED_167) goto COMPILED_167; \
if (GETLABEL(REG) == _AFTER_CALL_168) goto AFTER_CALL_168; \
if (GETLABEL(REG) == _PRIMITIVE_169) goto PRIMITIVE_169; \
if (GETLABEL(REG) == _COMPOUND_170) goto COMPOUND_170; \
if (GETLABEL(REG) == _COMPILED_171) goto COMPILED_171; \
if (GETLABEL(REG) == _AFTER_CALL_172) goto AFTER_CALL_172; \
if (GETLABEL(REG) == _PRIMITIVE_173) goto PRIMITIVE_173; \
if (GETLABEL(REG) == _COMPOUND_174) goto COMPOUND_174; \
if (GETLABEL(REG) == _COMPILED_175) goto COMPILED_175; \
if (GETLABEL(REG) == _AFTER_CALL_176) goto AFTER_CALL_176; \
if (GETLABEL(REG) == _PRIMITIVE_177) goto PRIMITIVE_177; \
if (GETLABEL(REG) == _COMPOUND_178) goto COMPOUND_178; \
if (GETLABEL(REG) == _COMPILED_179) goto COMPILED_179; \
if (GETLABEL(REG) == _AFTER_CALL_180) goto AFTER_CALL_180; \
if (GETLABEL(REG) == _ENTRY_181) goto ENTRY_181; \
if (GETLABEL(REG) == _AFTER_LAMBDA_182) goto AFTER_LAMBDA_182; \
if (GETLABEL(REG) == _PRIMITIVE_183) goto PRIMITIVE_183; \
if (GETLABEL(REG) == _COMPOUND_184) goto COMPOUND_184; \
if (GETLABEL(REG) == _COMPILED_185) goto COMPILED_185; \
if (GETLABEL(REG) == _AFTER_CALL_186) goto AFTER_CALL_186; \
if (GETLABEL(REG) == _ENTRY_187) goto ENTRY_187; \
if (GETLABEL(REG) == _AFTER_LAMBDA_188) goto AFTER_LAMBDA_188; \
if (GETLABEL(REG) == _PRIMITIVE_189) goto PRIMITIVE_189; \
if (GETLABEL(REG) == _COMPOUND_190) goto COMPOUND_190; \
if (GETLABEL(REG) == _COMPILED_191) goto COMPILED_191; \
if (GETLABEL(REG) == _AFTER_CALL_192) goto AFTER_CALL_192; \
if (GETLABEL(REG) == _ENTRY_193) goto ENTRY_193; \
if (GETLABEL(REG) == _AFTER_LAMBDA_194) goto AFTER_LAMBDA_194; \
if (GETLABEL(REG) == _TRUE_BRANCH_195) goto TRUE_BRANCH_195; \
if (GETLABEL(REG) == _FALSE_BRANCH_196) goto FALSE_BRANCH_196; \
if (GETLABEL(REG) == _AFTER_IF_197) goto AFTER_IF_197; \
if (GETLABEL(REG) == _PRIMITIVE_198) goto PRIMITIVE_198; \
if (GETLABEL(REG) == _COMPOUND_199) goto COMPOUND_199; \
if (GETLABEL(REG) == _COMPILED_200) goto COMPILED_200; \
if (GETLABEL(REG) == _AFTER_CALL_201) goto AFTER_CALL_201; \
if (GETLABEL(REG) == _PRIMITIVE_202) goto PRIMITIVE_202; \
if (GETLABEL(REG) == _COMPOUND_203) goto COMPOUND_203; \
if (GETLABEL(REG) == _COMPILED_204) goto COMPILED_204; \
if (GETLABEL(REG) == _AFTER_CALL_205) goto AFTER_CALL_205; \
if (GETLABEL(REG) == _PRIMITIVE_206) goto PRIMITIVE_206; \
if (GETLABEL(REG) == _COMPOUND_207) goto COMPOUND_207; \
if (GETLABEL(REG) == _COMPILED_208) goto COMPILED_208; \
if (GETLABEL(REG) == _AFTER_CALL_209) goto AFTER_CALL_209; \
if (GETLABEL(REG) == _PRIMITIVE_210) goto PRIMITIVE_210; \
if (GETLABEL(REG) == _COMPOUND_211) goto COMPOUND_211; \
if (GETLABEL(REG) == _COMPILED_212) goto COMPILED_212; \
if (GETLABEL(REG) == _AFTER_CALL_213) goto AFTER_CALL_213; \
if (GETLABEL(REG) == _ENTRY_214) goto ENTRY_214; \
if (GETLABEL(REG) == _AFTER_LAMBDA_215) goto AFTER_LAMBDA_215; \
if (GETLABEL(REG) == _ENTRY_216) goto ENTRY_216; \
if (GETLABEL(REG) == _AFTER_LAMBDA_217) goto AFTER_LAMBDA_217; \
if (GETLABEL(REG) == _TRUE_BRANCH_218) goto TRUE_BRANCH_218; \
if (GETLABEL(REG) == _FALSE_BRANCH_219) goto FALSE_BRANCH_219; \
if (GETLABEL(REG) == _AFTER_IF_220) goto AFTER_IF_220; \
if (GETLABEL(REG) == _PRIMITIVE_221) goto PRIMITIVE_221; \
if (GETLABEL(REG) == _COMPOUND_222) goto COMPOUND_222; \
if (GETLABEL(REG) == _COMPILED_223) goto COMPILED_223; \
if (GETLABEL(REG) == _AFTER_CALL_224) goto AFTER_CALL_224; \
if (GETLABEL(REG) == _PRIMITIVE_225) goto PRIMITIVE_225; \
if (GETLABEL(REG) == _COMPOUND_226) goto COMPOUND_226; \
if (GETLABEL(REG) == _COMPILED_227) goto COMPILED_227; \
if (GETLABEL(REG) == _AFTER_CALL_228) goto AFTER_CALL_228; \
if (GETLABEL(REG) == _PRIMITIVE_229) goto PRIMITIVE_229; \
if (GETLABEL(REG) == _COMPOUND_230) goto COMPOUND_230; \
if (GETLABEL(REG) == _COMPILED_231) goto COMPILED_231; \
if (GETLABEL(REG) == _AFTER_CALL_232) goto AFTER_CALL_232; \
if (GETLABEL(REG) == _PRIMITIVE_233) goto PRIMITIVE_233; \
if (GETLABEL(REG) == _COMPOUND_234) goto COMPOUND_234; \
if (GETLABEL(REG) == _COMPILED_235) goto COMPILED_235; \
if (GETLABEL(REG) == _AFTER_CALL_236) goto AFTER_CALL_236; \
if (GETLABEL(REG) == _PRIMITIVE_237) goto PRIMITIVE_237; \
if (GETLABEL(REG) == _COMPOUND_238) goto COMPOUND_238; \
if (GETLABEL(REG) == _COMPILED_239) goto COMPILED_239; \
if (GETLABEL(REG) == _AFTER_CALL_240) goto AFTER_CALL_240; \
if (GETLABEL(REG) == _ENTRY_241) goto ENTRY_241; \
if (GETLABEL(REG) == _AFTER_LAMBDA_242) goto AFTER_LAMBDA_242; \
if (GETLABEL(REG) == _TRUE_BRANCH_243) goto TRUE_BRANCH_243; \
if (GETLABEL(REG) == _FALSE_BRANCH_244) goto FALSE_BRANCH_244; \
if (GETLABEL(REG) == _AFTER_IF_245) goto AFTER_IF_245; \
if (GETLABEL(REG) == _PRIMITIVE_246) goto PRIMITIVE_246; \
if (GETLABEL(REG) == _COMPOUND_247) goto COMPOUND_247; \
if (GETLABEL(REG) == _COMPILED_248) goto COMPILED_248; \
if (GETLABEL(REG) == _AFTER_CALL_249) goto AFTER_CALL_249; \
if (GETLABEL(REG) == _PRIMITIVE_250) goto PRIMITIVE_250; \
if (GETLABEL(REG) == _COMPOUND_251) goto COMPOUND_251; \
if (GETLABEL(REG) == _COMPILED_252) goto COMPILED_252; \
if (GETLABEL(REG) == _AFTER_CALL_253) goto AFTER_CALL_253; \
if (GETLABEL(REG) == _PRIMITIVE_254) goto PRIMITIVE_254; \
if (GETLABEL(REG) == _COMPOUND_255) goto COMPOUND_255; \
if (GETLABEL(REG) == _COMPILED_256) goto COMPILED_256; \
if (GETLABEL(REG) == _AFTER_CALL_257) goto AFTER_CALL_257; \
if (GETLABEL(REG) == _PRIMITIVE_258) goto PRIMITIVE_258; \
if (GETLABEL(REG) == _COMPOUND_259) goto COMPOUND_259; \
if (GETLABEL(REG) == _COMPILED_260) goto COMPILED_260; \
if (GETLABEL(REG) == _AFTER_CALL_261) goto AFTER_CALL_261; \
if (GETLABEL(REG) == _PRIMITIVE_262) goto PRIMITIVE_262; \
if (GETLABEL(REG) == _COMPOUND_263) goto COMPOUND_263; \
if (GETLABEL(REG) == _COMPILED_264) goto COMPILED_264; \
if (GETLABEL(REG) == _AFTER_CALL_265) goto AFTER_CALL_265; \
if (GETLABEL(REG) == _PRIMITIVE_266) goto PRIMITIVE_266; \
if (GETLABEL(REG) == _COMPOUND_267) goto COMPOUND_267; \
if (GETLABEL(REG) == _COMPILED_268) goto COMPILED_268; \
if (GETLABEL(REG) == _AFTER_CALL_269) goto AFTER_CALL_269; \
if (GETLABEL(REG) == _ENTRY_270) goto ENTRY_270; \
if (GETLABEL(REG) == _AFTER_LAMBDA_271) goto AFTER_LAMBDA_271; \
if (GETLABEL(REG) == _ENTRY_272) goto ENTRY_272; \
if (GETLABEL(REG) == _AFTER_LAMBDA_273) goto AFTER_LAMBDA_273; \
if (GETLABEL(REG) == _TRUE_BRANCH_274) goto TRUE_BRANCH_274; \
if (GETLABEL(REG) == _FALSE_BRANCH_275) goto FALSE_BRANCH_275; \
if (GETLABEL(REG) == _AFTER_IF_276) goto AFTER_IF_276; \
if (GETLABEL(REG) == _PRIMITIVE_277) goto PRIMITIVE_277; \
if (GETLABEL(REG) == _COMPOUND_278) goto COMPOUND_278; \
if (GETLABEL(REG) == _COMPILED_279) goto COMPILED_279; \
if (GETLABEL(REG) == _AFTER_CALL_280) goto AFTER_CALL_280; \
if (GETLABEL(REG) == _PRIMITIVE_281) goto PRIMITIVE_281; \
if (GETLABEL(REG) == _COMPOUND_282) goto COMPOUND_282; \
if (GETLABEL(REG) == _COMPILED_283) goto COMPILED_283; \
if (GETLABEL(REG) == _AFTER_CALL_284) goto AFTER_CALL_284; \
if (GETLABEL(REG) == _PRIMITIVE_285) goto PRIMITIVE_285; \
if (GETLABEL(REG) == _COMPOUND_286) goto COMPOUND_286; \
if (GETLABEL(REG) == _COMPILED_287) goto COMPILED_287; \
if (GETLABEL(REG) == _AFTER_CALL_288) goto AFTER_CALL_288; \
if (GETLABEL(REG) == _PRIMITIVE_289) goto PRIMITIVE_289; \
if (GETLABEL(REG) == _COMPOUND_290) goto COMPOUND_290; \
if (GETLABEL(REG) == _COMPILED_291) goto COMPILED_291; \
if (GETLABEL(REG) == _AFTER_CALL_292) goto AFTER_CALL_292; \
if (GETLABEL(REG) == _PRIMITIVE_293) goto PRIMITIVE_293; \
if (GETLABEL(REG) == _COMPOUND_294) goto COMPOUND_294; \
if (GETLABEL(REG) == _COMPILED_295) goto COMPILED_295; \
if (GETLABEL(REG) == _AFTER_CALL_296) goto AFTER_CALL_296;

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
_PRIMITIVE_22, \
_COMPOUND_23, \
_COMPILED_24, \
_AFTER_CALL_25, \
_PRIMITIVE_26, \
_COMPOUND_27, \
_COMPILED_28, \
_AFTER_CALL_29, \
_ENTRY_30, \
_AFTER_LAMBDA_31, \
_TRUE_BRANCH_32, \
_FALSE_BRANCH_33, \
_AFTER_IF_34, \
_PRIMITIVE_35, \
_COMPOUND_36, \
_COMPILED_37, \
_AFTER_CALL_38, \
_PRIMITIVE_39, \
_COMPOUND_40, \
_COMPILED_41, \
_AFTER_CALL_42, \
_PRIMITIVE_43, \
_COMPOUND_44, \
_COMPILED_45, \
_AFTER_CALL_46, \
_PRIMITIVE_47, \
_COMPOUND_48, \
_COMPILED_49, \
_AFTER_CALL_50, \
_PRIMITIVE_51, \
_COMPOUND_52, \
_COMPILED_53, \
_AFTER_CALL_54, \
_ENTRY_55, \
_AFTER_LAMBDA_56, \
_TRUE_BRANCH_57, \
_FALSE_BRANCH_58, \
_AFTER_IF_59, \
_PRIMITIVE_60, \
_COMPOUND_61, \
_COMPILED_62, \
_AFTER_CALL_63, \
_PRIMITIVE_64, \
_COMPOUND_65, \
_COMPILED_66, \
_AFTER_CALL_67, \
_PRIMITIVE_68, \
_COMPOUND_69, \
_COMPILED_70, \
_AFTER_CALL_71, \
_PRIMITIVE_72, \
_COMPOUND_73, \
_COMPILED_74, \
_AFTER_CALL_75, \
_PRIMITIVE_76, \
_COMPOUND_77, \
_COMPILED_78, \
_AFTER_CALL_79, \
_ENTRY_80, \
_AFTER_LAMBDA_81, \
_ENTRY_82, \
_AFTER_LAMBDA_83, \
_TRUE_BRANCH_84, \
_FALSE_BRANCH_85, \
_AFTER_IF_86, \
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
_PRIMITIVE_103, \
_COMPOUND_104, \
_COMPILED_105, \
_AFTER_CALL_106, \
_PRIMITIVE_107, \
_COMPOUND_108, \
_COMPILED_109, \
_AFTER_CALL_110, \
_ENTRY_111, \
_AFTER_LAMBDA_112, \
_ENTRY_113, \
_AFTER_LAMBDA_114, \
_TRUE_BRANCH_115, \
_FALSE_BRANCH_116, \
_AFTER_IF_117, \
_PRIMITIVE_118, \
_COMPOUND_119, \
_COMPILED_120, \
_AFTER_CALL_121, \
_PRIMITIVE_122, \
_COMPOUND_123, \
_COMPILED_124, \
_AFTER_CALL_125, \
_PRIMITIVE_126, \
_COMPOUND_127, \
_COMPILED_128, \
_AFTER_CALL_129, \
_PRIMITIVE_130, \
_COMPOUND_131, \
_COMPILED_132, \
_AFTER_CALL_133, \
_PRIMITIVE_134, \
_COMPOUND_135, \
_COMPILED_136, \
_AFTER_CALL_137, \
_PRIMITIVE_138, \
_COMPOUND_139, \
_COMPILED_140, \
_AFTER_CALL_141, \
_PRIMITIVE_142, \
_COMPOUND_143, \
_COMPILED_144, \
_AFTER_CALL_145, \
_PRIMITIVE_146, \
_COMPOUND_147, \
_COMPILED_148, \
_AFTER_CALL_149, \
_ENTRY_150, \
_AFTER_LAMBDA_151, \
_ENTRY_152, \
_AFTER_LAMBDA_153, \
_TRUE_BRANCH_154, \
_FALSE_BRANCH_155, \
_AFTER_IF_156, \
_PRIMITIVE_157, \
_COMPOUND_158, \
_COMPILED_159, \
_AFTER_CALL_160, \
_PRIMITIVE_161, \
_COMPOUND_162, \
_COMPILED_163, \
_AFTER_CALL_164, \
_PRIMITIVE_165, \
_COMPOUND_166, \
_COMPILED_167, \
_AFTER_CALL_168, \
_PRIMITIVE_169, \
_COMPOUND_170, \
_COMPILED_171, \
_AFTER_CALL_172, \
_PRIMITIVE_173, \
_COMPOUND_174, \
_COMPILED_175, \
_AFTER_CALL_176, \
_PRIMITIVE_177, \
_COMPOUND_178, \
_COMPILED_179, \
_AFTER_CALL_180, \
_ENTRY_181, \
_AFTER_LAMBDA_182, \
_PRIMITIVE_183, \
_COMPOUND_184, \
_COMPILED_185, \
_AFTER_CALL_186, \
_ENTRY_187, \
_AFTER_LAMBDA_188, \
_PRIMITIVE_189, \
_COMPOUND_190, \
_COMPILED_191, \
_AFTER_CALL_192, \
_ENTRY_193, \
_AFTER_LAMBDA_194, \
_TRUE_BRANCH_195, \
_FALSE_BRANCH_196, \
_AFTER_IF_197, \
_PRIMITIVE_198, \
_COMPOUND_199, \
_COMPILED_200, \
_AFTER_CALL_201, \
_PRIMITIVE_202, \
_COMPOUND_203, \
_COMPILED_204, \
_AFTER_CALL_205, \
_PRIMITIVE_206, \
_COMPOUND_207, \
_COMPILED_208, \
_AFTER_CALL_209, \
_PRIMITIVE_210, \
_COMPOUND_211, \
_COMPILED_212, \
_AFTER_CALL_213, \
_ENTRY_214, \
_AFTER_LAMBDA_215, \
_ENTRY_216, \
_AFTER_LAMBDA_217, \
_TRUE_BRANCH_218, \
_FALSE_BRANCH_219, \
_AFTER_IF_220, \
_PRIMITIVE_221, \
_COMPOUND_222, \
_COMPILED_223, \
_AFTER_CALL_224, \
_PRIMITIVE_225, \
_COMPOUND_226, \
_COMPILED_227, \
_AFTER_CALL_228, \
_PRIMITIVE_229, \
_COMPOUND_230, \
_COMPILED_231, \
_AFTER_CALL_232, \
_PRIMITIVE_233, \
_COMPOUND_234, \
_COMPILED_235, \
_AFTER_CALL_236, \
_PRIMITIVE_237, \
_COMPOUND_238, \
_COMPILED_239, \
_AFTER_CALL_240, \
_ENTRY_241, \
_AFTER_LAMBDA_242, \
_TRUE_BRANCH_243, \
_FALSE_BRANCH_244, \
_AFTER_IF_245, \
_PRIMITIVE_246, \
_COMPOUND_247, \
_COMPILED_248, \
_AFTER_CALL_249, \
_PRIMITIVE_250, \
_COMPOUND_251, \
_COMPILED_252, \
_AFTER_CALL_253, \
_PRIMITIVE_254, \
_COMPOUND_255, \
_COMPILED_256, \
_AFTER_CALL_257, \
_PRIMITIVE_258, \
_COMPOUND_259, \
_COMPILED_260, \
_AFTER_CALL_261, \
_PRIMITIVE_262, \
_COMPOUND_263, \
_COMPILED_264, \
_AFTER_CALL_265, \
_PRIMITIVE_266, \
_COMPOUND_267, \
_COMPILED_268, \
_AFTER_CALL_269, \
_ENTRY_270, \
_AFTER_LAMBDA_271, \
_ENTRY_272, \
_AFTER_LAMBDA_273, \
_TRUE_BRANCH_274, \
_FALSE_BRANCH_275, \
_AFTER_IF_276, \
_PRIMITIVE_277, \
_COMPOUND_278, \
_COMPILED_279, \
_AFTER_CALL_280, \
_PRIMITIVE_281, \
_COMPOUND_282, \
_COMPILED_283, \
_AFTER_CALL_284, \
_PRIMITIVE_285, \
_COMPOUND_286, \
_COMPILED_287, \
_AFTER_CALL_288, \
_PRIMITIVE_289, \
_COMPOUND_290, \
_COMPILED_291, \
_AFTER_CALL_292, \
_PRIMITIVE_293, \
_COMPOUND_294, \
_COMPILED_295, \
_AFTER_CALL_296

#endif
