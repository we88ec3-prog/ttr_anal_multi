
uint FUN_00509130(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094001e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&param_1);
  uVar2 = in_ECX;
  if ((in_ECX != DAT_00f8d91c) && (uVar2 = 0, *(int *)(in_ECX + 0x10) != 0)) {
    iVar3 = *(int *)(*(int *)(in_ECX + 0x10) + 0x68);
    uVar2 = 0;
    if (iVar3 != 0) {
      uVar1 = *(ushort *)(iVar3 + 8);
      iVar3 = FUN_00404ba0();
      iVar3 = *(int *)(iVar3 + 0x6928);
      param_1 = (uint)uVar1;
      FUN_004a4cc0(&param_1);
      uVar2 = in_ECX;
      if (((in_ECX == *(uint *)(iVar3 + 0x14)) || (uVar2 = *(uint *)(in_ECX + 0x10), uVar2 == 0)) ||
         (*(int *)(uVar2 + 0xc) == 0)) goto LAB_005091ae;
    }
    ExceptionList = local_10;
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
LAB_005091ae:
  ExceptionList = local_10;
  return uVar2 & 0xffffff00;
}

