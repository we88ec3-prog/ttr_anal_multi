
void FUN_0069bb20(void)

{
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  float local_48;
  float local_44;
  int local_40;
  RECT local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091789e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_48;
  ExceptionList = &local_14;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_48 = DAT_00f95bac;
  local_44 = DAT_00f95bb0;
  FUN_00443da0();
  local_2c.top = FUN_008fed10();
  FUN_00443da0();
  local_2c.bottom = FUN_008fed10();
  FUN_00443da0();
  local_2c.left = FUN_008fed10();
  FUN_00443da0();
  local_2c.right = FUN_008fed10();
  BVar1 = EqualRect((RECT *)(unaff_EDI + 0x100),&local_2c);
  if (BVar1 == 0) {
    piVar2 = (int *)FUN_00443da0();
    local_40 = (piVar2[2] - *piVar2) / 2;
    *(float *)(unaff_EDI + 0xdc) = (float)local_40 * local_48;
    iVar3 = FUN_00443da0();
    local_40 = (*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 4)) / 2;
    ((RECT *)(unaff_EDI + 0x100))->left = local_2c.left;
    *(LONG *)(unaff_EDI + 0x104) = local_2c.top;
    *(LONG *)(unaff_EDI + 0x108) = local_2c.right;
    *(LONG *)(unaff_EDI + 0x10c) = local_2c.bottom;
    *(float *)(unaff_EDI + 0xe0) = (float)local_40 * local_44;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_48);
  return;
}

