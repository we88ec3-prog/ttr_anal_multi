
void FUN_007ce2e0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *in_ECX;
  int local_b8;
  int local_b4;
  int local_b0;
  undefined **local_ac [19];
  uint local_60;
  undefined4 local_50;
  uint local_4c;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009265b3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b0 = param_2;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  local_b8 = FUN_007b6f30(local_30);
  if ((local_b8 == *(int *)(param_1 + 0x14)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_b4 = *(int *)(param_1 + 0x14);
    piVar4 = &local_b4;
  }
  else {
    piVar4 = &local_b8;
  }
  iVar5 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar5 == *(int *)(param_1 + 0x14)) {
    FUN_0072ee30(local_ac);
    local_8 = 1;
    cVar1 = FUN_0072f110(0);
    if (cVar1 == '\0') {
      local_8 = 0xffffffff;
      local_ac[0] = TiXmlDocument::vftable;
      if (0xf < local_4c) {
        FUN_0089120c(local_60);
      }
      local_4c = 0xf;
      local_50 = 0;
      local_60 = local_60 & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_b0 = FUN_0072e2e0("ParticleSystem");
      if (local_b0 == 0) {
        local_8 = 0xffffffff;
        FUN_00407fb0();
      }
      else {
        iVar5 = FUN_00891268(0x4c);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_007ee0d0();
        }
        FUN_007ee480(local_b0);
        FUN_007cf2f0(iVar5);
        if ((0 < *(int *)(param_1 + 0x30)) && (FUN_007ee110(), 1 < *(int *)(param_1 + 0x30))) {
          FUN_007ee200();
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
        local_8 = 0xffffffff;
        FUN_00407fb0();
      }
    }
  }
  else {
    piVar4 = (int *)(*(int *)(iVar5 + 0x28) + 4);
    *piVar4 = *piVar4 + 1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

