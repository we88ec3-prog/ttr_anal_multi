
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00508970(int param_1)

{
  int in_EAX;
  int iVar1;
  
  if (param_1 == -1) {
    iVar1 = *(int *)(in_EAX + 0x18);
  }
  else {
    if (*(int *)(in_EAX + 0x1c) <= param_1) {
      return;
    }
    *(int *)(in_EAX + 0x18) = param_1;
    iVar1 = param_1;
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  param_1 = CONCAT13(10,CONCAT12((char)iVar1,0x43));
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
  }
  return;
}

