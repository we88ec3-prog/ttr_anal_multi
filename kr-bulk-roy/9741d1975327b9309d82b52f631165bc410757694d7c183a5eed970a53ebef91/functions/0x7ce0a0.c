
void FUN_007ce0a0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *in_ECX;
  undefined1 auStack_c4 [4];
  int local_c0;
  int local_bc;
  int local_b8;
  uint local_b4 [4];
  undefined4 local_a4;
  uint local_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009265f6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_c4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff30;
  ExceptionList = &local_14;
  local_c0 = param_2;
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4[0] = local_b4[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_c = 0;
  local_bc = FUN_007b6f30(local_b4);
  if ((local_bc == *(int *)(param_1 + 0x14)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_b8 = *(int *)(param_1 + 0x14);
    piVar4 = &local_b8;
  }
  else {
    piVar4 = &local_bc;
  }
  iVar5 = *piVar4;
  local_c = 0xffffffff;
  if (0xf < local_a0) {
    FUN_0089120c(local_b4[0]);
  }
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4[0] = local_b4[0] & 0xffffff00;
  if (iVar5 == *(int *)(param_1 + 0x14)) {
    FUN_0072ee30(local_98);
    local_c = 1;
    cVar1 = FUN_0072f110(0);
    if (cVar1 == '\0') {
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      local_c0 = FUN_0072e2e0("ParticleSystem");
      if (local_c0 == 0) {
        local_c = 0xffffffff;
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
        FUN_007ee480(local_c0);
        FUN_007cf2f0(iVar5);
        *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
        local_c = 0xffffffff;
        FUN_00407fb0();
      }
    }
  }
  else {
    piVar4 = (int *)(*(int *)(iVar5 + 0x28) + 4);
    *piVar4 = *piVar4 + 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_c4);
  return;
}

