
void FUN_007ed180(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  undefined1 auStack_fc [4];
  char *pcStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  uint local_ec;
  undefined4 local_dc;
  uint local_d8;
  undefined **local_d0 [19];
  uint uStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00938dca;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_fc;
  ExceptionList = &local_14;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    iVar2 = in_ECX + 8;
  }
  else {
    iVar2 = *(int *)(in_ECX + 8);
  }
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_c = 0;
    FUN_00716be0(DAT_00d61f20 ^ (uint)&stack0xfffffef8);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
  }
  local_c = 0xffffffff;
  iVar2 = FUN_00716740(iVar2);
  if (iVar2 != 0) {
    FUN_0079c590();
    local_c = 1;
    FUN_0072ee30(local_d0);
    local_c._0_1_ = 3;
    if (0xf < local_d8) {
      FUN_0089120c(local_ec);
    }
    local_d8 = 0xf;
    local_dc = 0;
    local_ec = local_ec & 0xffffff00;
    if (*(uint *)(iVar2 + 0x30) < 0x10) {
      iVar2 = iVar2 + 0x1c;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x1c);
    }
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_c._0_1_ = 4;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_c._0_1_ = 3;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(auStack_54,iVar2);
      local_c._0_1_ = 5;
      FUN_007edcd0();
      local_c._0_1_ = 3;
      FUN_007ee080();
    }
    cVar1 = FUN_0072f110(0);
    if ((cVar1 == '\0') || (iVar2 = FUN_0072e2e0(&DAT_00c508d4), iVar2 == 0)) {
      local_c = 0xffffffff;
      local_d0[0] = TiXmlDocument::vftable;
      if (0xf < uStack_70) {
        FUN_0089120c(uStack_84);
      }
      uStack_70 = 0xf;
      uStack_74 = 0;
      uStack_84 = uStack_84 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      FUN_007b9ab0(*(undefined4 *)(in_ECX + 4));
      FUN_00402a70(&DAT_00c0cec8,4);
      pcVar5 = (char *)(in_ECX + 8);
      if (0xf < *(uint *)(in_ECX + 0x1c)) {
        pcVar5 = *(char **)pcVar5;
      }
      pcStack_f8 = pcVar5 + 1;
      pcVar3 = pcVar5;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar5,(int)pcVar3 - (int)pcStack_f8);
      uVar4 = FUN_0072e2e0("Field");
      pcStack_f8 = (char *)FUN_0072e2e0("Object");
      uStack_f0 = FUN_0072e2e0("Environment");
      uStack_f4 = FUN_0072e2e0("Stamp");
      FUN_007ea0d0(in_ECX,uVar4);
      FUN_007eab90(in_ECX);
      FUN_007eb440(in_ECX);
      FUN_007eb0e0(in_ECX);
      FUN_007e27b0();
      (**(code **)(**(int **)(in_ECX + 4) + 8))();
      (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
      local_c = 0xffffffff;
      FUN_00407fb0();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_fc);
  return;
}

