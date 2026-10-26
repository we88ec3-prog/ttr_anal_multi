
undefined4 FUN_004b4cc0(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b243;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1 = (uint)*(ushort *)(param_1 + 2);
  iVar3 = FUN_0040f060(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(iVar3 + 0xc)) && (*(int *)(in_ECX + 0x10) != 0)) {
    uVar1 = *(undefined2 *)(*(int *)(in_ECX + 0x10) + 0x88);
    if ((DAT_00fe1884 & 1) == 0) {
      DAT_00fe1884 = DAT_00fe1884 | 1;
      local_8 = 0;
      FUN_0053f0f0();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0053eda0();
      _atexit(FUN_00bce830);
      local_8 = 0xffffffff;
    }
    FUN_0053ecc0(*(undefined2 *)(iVar2 + 2),uVar1);
  }
  ExceptionList = local_10;
  return 0;
}

