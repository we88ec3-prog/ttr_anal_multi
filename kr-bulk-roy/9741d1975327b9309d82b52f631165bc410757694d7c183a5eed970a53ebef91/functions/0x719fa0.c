
long FUN_00719fa0(int param_1,long param_2)

{
  undefined4 in_EAX;
  long lVar1;
  
  FUN_0071baa0(in_EAX);
  if (param_1 == 0) {
    return param_2;
  }
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    lVar1 = _strtol(*(char **)(param_1 + 8),(char **)0x0,10);
    return lVar1;
  }
  return 0;
}

