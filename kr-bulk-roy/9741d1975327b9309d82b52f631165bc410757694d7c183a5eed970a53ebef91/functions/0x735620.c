
undefined4 FUN_00735620(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar7 = param_4;
  uVar6 = param_3;
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915a2b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00735280(param_1,&param_1,param_3,param_2,param_4);
  if (param_1 == *(int *)(iVar1 + 0x28)) {
    param_1 = FUN_00891268(0x38,uVar2);
    local_8 = 0;
    if (param_1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00734e90(param_2,uVar7,*(undefined4 *)(iVar1 + 0x40));
      uVar7 = param_4;
    }
    local_8 = 0xffffffff;
    iVar4 = FUN_00735350(iVar1);
    if (iVar4 == 0) {
      FUN_00735530();
      iVar4 = FUN_00735350(iVar1);
      uVar7 = param_4;
      if (iVar4 == 0) {
        if (iVar3 == 0) {
          ExceptionList = local_10;
          return 0;
        }
        FUN_007355e0();
        ExceptionList = local_10;
        return 0;
      }
    }
    piVar5 = (int *)FUN_00735280(iVar1,&param_4,param_3,param_2,uVar7);
    iVar3 = *piVar5;
    *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x34) = *(undefined4 *)(iVar1 + 0x40);
    param_4 = *(undefined4 *)(iVar3 + 0xc);
    FUN_004ca200(iVar1 + 0x24,&param_1,iVar3);
    FUN_00736400(local_18,&param_4);
    uVar6 = param_3;
  }
  piVar5 = (int *)FUN_00735280(iVar1,&param_3,uVar6,param_2,uVar7);
  if (*piVar5 == *(int *)(iVar1 + 0x28)) {
    ExceptionList = local_10;
    return 0;
  }
  ExceptionList = local_10;
  return *(undefined4 *)(*piVar5 + 0xc);
}

