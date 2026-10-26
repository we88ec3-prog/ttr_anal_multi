
void FUN_00808940(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_EDX;
  int local_94;
  undefined **local_90 [17];
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926349;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_0072ee30(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if ((local_4c != '\0') || (piVar2 = (int *)FUN_0072e2e0(&DAT_00c0fc30), piVar2 == (int *)0x0)) {
    local_90[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_30) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
    goto LAB_00808ba6;
  }
  (**(code **)(*piVar2 + 0x14))(uVar1);
  iVar3 = FUN_007300a0(&DAT_00bfaf5c);
  if (iVar3 == 0) {
LAB_00808a59:
    iVar3 = -1;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_00808a59;
    iVar3 = FUN_008917b4(puVar4);
  }
  if (*in_EDX == -1) {
    if (iVar3 != -1) {
      *in_EDX = iVar3;
      goto LAB_00808a84;
    }
  }
  else {
LAB_00808a84:
    FUN_008438c0(in_EDX);
    if (local_94 == *(int *)(param_1 + 8)) {
      iVar3 = FUN_00891268(0x10);
      local_8._0_1_ = 1;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00808150();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      iVar5 = FUN_0072e2e0("STATE");
      while (iVar5 != 0) {
        iVar5 = FUN_00808db0(param_1,iVar3);
        if (iVar5 == 0) {
          if (iVar3 != 0) {
            FUN_008081c0(iVar3);
            FUN_0089120c(iVar3);
          }
          goto LAB_00808b64;
        }
        iVar5 = FUN_0072e320("STATE");
      }
      uVar6 = FUN_0057ef20();
      FUN_0057e850(param_1 + 4,uVar6);
LAB_00808b64:
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_30 = 0xf;
      local_34 = 0;
      local_44 = local_44 & 0xffffff00;
      FUN_0072e040();
      goto LAB_00808ba6;
    }
  }
  local_8 = 0xffffffff;
  FUN_00407fb0();
LAB_00808ba6:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

