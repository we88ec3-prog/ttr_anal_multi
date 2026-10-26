
void FUN_007ed4c0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  char ****ppppcVar9;
  char *pcVar10;
  char ****ppppcVar11;
  undefined4 uVar12;
  int local_34;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a43;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0072e2e0("LightSystem");
  iVar2 = FUN_0072e2e0("FogList");
  FUN_0072e2e0("CameraList");
  iVar3 = FUN_0072e2e0("Skybox");
  iVar4 = FUN_0072e2e0("ParticleList");
  iVar5 = FUN_007300a0("EnvIndex");
  if (iVar5 != 0) {
    puVar6 = (undefined4 *)(iVar5 + 0x30);
    if (0xf < *(uint *)(iVar5 + 0x44)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    if (puVar6 != (undefined4 *)0x0) {
      local_34 = FUN_008917b4(puVar6);
      goto LAB_007ed570;
    }
  }
  local_34 = 1;
LAB_007ed570:
  iVar5 = FUN_007300a0("Description");
  if (iVar5 == 0) {
    pcVar10 = (char *)0x0;
  }
  else {
    pcVar10 = (char *)(iVar5 + 0x30);
    if (0xf < *(uint *)(iVar5 + 0x44)) {
      pcVar10 = *(char **)pcVar10;
    }
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  pcVar7 = pcVar10;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar10,(int)pcVar7 - (int)(pcVar10 + 1));
  local_8 = 0;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x54);
  if (*(int *)(iVar5 + 0xc + local_34 * 4) == 0) {
    iVar8 = FUN_00891268(0x30);
    local_8._0_1_ = 1;
    if (iVar8 == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = FUN_007f3ba0(*(undefined4 *)(iVar5 + 0xc));
    }
    local_8 = (uint)local_8._1_3_ << 8;
    *(undefined4 *)(iVar5 + 0xc + local_34 * 4) = uVar12;
  }
  else {
    uVar12 = 0;
  }
  ppppcVar11 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar11 = local_30;
  }
  ppppcVar9 = ppppcVar11;
  do {
    cVar1 = *(char *)ppppcVar9;
    ppppcVar9 = (char ****)((int)ppppcVar9 + 1);
  } while (cVar1 != '\0');
  FUN_00402a70(ppppcVar11,(int)ppppcVar9 - (int)((int)ppppcVar11 + 1));
  FUN_007eb530(param_1);
  if (iVar2 != 0) {
    FUN_007ebe30(uVar12);
  }
  FUN_007ec080(param_1);
  if (iVar3 != 0) {
    FUN_007ec3a0(iVar3,uVar12);
  }
  if (iVar4 != 0) {
    FUN_007ec9f0(iVar4);
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

