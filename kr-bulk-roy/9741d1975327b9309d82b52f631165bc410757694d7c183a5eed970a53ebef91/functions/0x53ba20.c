
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053ba20(void)

{
  undefined4 in_ECX;
  undefined3 local_8;
  undefined1 uStack_5;
  
  uStack_5 = (undefined1)((uint)in_ECX >> 0x18);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT13(uStack_5,0x5d);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,3);
  }
  return;
}

