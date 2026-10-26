
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063c8a0(void)

{
  uint uVar1;
  int in_ECX;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  *(uint *)(in_ECX + 0x108) = (uint)DAT_00f9436a;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  *(uint *)(in_ECX + 0x104) = (uint)DAT_00f9436d;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_1a = *(undefined1 *)(in_ECX + 0x108);
  local_19 = *(undefined1 *)(in_ECX + 0x104);
  local_1c = 0xcf;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,4);
  }
  FUN_0075cd30(*(undefined4 *)(in_ECX + 0x100));
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0xa0))((*(byte *)(in_ECX + 0x104) & 1) != 0);
  FUN_00749920(*(undefined4 *)(in_ECX + 0x100));
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  ExceptionList = pvStack_18;
  return;
}

