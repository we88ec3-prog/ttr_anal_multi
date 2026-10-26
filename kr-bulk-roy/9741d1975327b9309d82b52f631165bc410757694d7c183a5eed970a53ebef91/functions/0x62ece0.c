
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062ece0(void)

{
  int iVar1;
  int in_EAX;
  uint in_ECX;
  undefined2 local_8;
  undefined2 local_6;
  
  if (in_ECX < (uint)(*(int *)(in_EAX + 0x118) - *(int *)(in_EAX + 0x114) >> 2)) {
    iVar1 = *(int *)(in_EAX + 0x114);
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _local_8 = CONCAT22(**(undefined2 **)(iVar1 + in_ECX * 4),0x39);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
    }
  }
  return;
}

