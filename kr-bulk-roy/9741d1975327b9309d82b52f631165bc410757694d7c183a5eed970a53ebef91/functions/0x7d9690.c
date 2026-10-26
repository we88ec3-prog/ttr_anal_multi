
void FUN_007d9690(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009207ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x104) == 0) {
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_8 = 0;
      FUN_007b5430(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bce660);
    }
    local_8 = 0xffffffff;
    FUN_007b67e0(&DAT_00fd9420);
  }
  else {
    FUN_007bb350();
    iVar2 = *(int *)(in_ECX + 0x110);
    uVar1 = 0;
    if (*(int *)(in_ECX + 0x114) - iVar2 >> 2 != 0) {
      iVar3 = 0;
      do {
        if ((int)uVar1 < *(int *)(in_ECX + 0xb8)) {
          *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0xc + iVar3) =
               *(undefined4 *)(*(int *)(iVar2 + uVar1 * 4) + 4);
        }
        iVar2 = *(int *)(in_ECX + 0x110);
        uVar1 = uVar1 + 1;
        iVar3 = iVar3 + 0x14;
      } while (uVar1 < (uint)(*(int *)(in_ECX + 0x114) - iVar2 >> 2));
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

