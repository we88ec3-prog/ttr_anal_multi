
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064b090(void)

{
  undefined4 in_ECX;
  undefined2 local_8;
  undefined2 uStack_6;
  
  uStack_6 = (undefined2)((uint)in_ECX >> 0x10);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT22(uStack_6,0x59);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,2);
  }
  return;
}

