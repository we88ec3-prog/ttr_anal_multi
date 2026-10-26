
void FUN_00562cf0(int param_1)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ab0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = *(int *)(DAT_00fba7cc + 0x1360);
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 0;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7620 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(*DAT_00fb7620 + 0x18))();
  }
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 1;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 0x1c))((int)((float)param_1 / (float)iVar1) + iVar2);
  }
  ExceptionList = local_14;
  return;
}

