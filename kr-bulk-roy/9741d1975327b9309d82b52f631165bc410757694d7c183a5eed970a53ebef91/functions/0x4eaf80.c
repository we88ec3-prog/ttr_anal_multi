
undefined4 FUN_004eaf80(int param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fcb6;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 2) == 0) {
    ExceptionList = &local_10;
    *(int *)(in_ECX + 0x5ed8) = *(int *)(in_ECX + 0x5ed8) + *(int *)(param_1 + 10);
    iVar4 = FUN_00404ba0();
    iVar4 = *(int *)(iVar4 + 0x6868);
    iVar1 = *(int *)(param_1 + 0xe);
    iVar5 = FUN_00404ba0();
    uVar3 = DAT_00faadd4 & 1;
    *(int *)(iVar5 + 0x6868) = iVar1 + iVar4;
    if (uVar3 == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar7 = (*pcVar2)();
      return uVar7;
    }
    puVar6 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0040e460(puVar6);
  }
  else {
    if (*(int *)(param_1 + 2) != 1) {
      return 0;
    }
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_0058aad0();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 6;
    iVar4 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar7 = (*pcVar2)();
      return uVar7;
    }
    FUN_0040aff0();
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return 0;
}

