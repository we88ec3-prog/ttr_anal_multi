
void FUN_00489990(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *in_ECX;
  undefined **local_8c [19];
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009253fb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_8c[0] = TiXmlDocument::vftable;
    if (0xf < local_2c) {
      FUN_0089120c(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = local_40 & 0xffffff00;
    FUN_0072e040();
    goto LAB_00489b6f;
  }
  piVar3 = (int *)FUN_0072e2e0("PATCH");
  (**(code **)(*piVar3 + 0x14))(uVar2);
  iVar4 = FUN_007300a0("MajorVersion");
  if (iVar4 == 0) {
LAB_00489a8d:
    uVar6 = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_00489a8d;
    uVar6 = FUN_008917b4(puVar5);
  }
  *param_1 = uVar6;
  piVar3 = (int *)FUN_0072e2e0("PATCH");
  (**(code **)(*piVar3 + 0x14))();
  iVar4 = FUN_007300a0("MinorVersion");
  if (iVar4 == 0) {
LAB_00489ad4:
    uVar6 = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_00489ad4;
    uVar6 = FUN_008917b4(puVar5);
  }
  *param_2 = uVar6;
  piVar3 = (int *)FUN_0072e2e0("PATCH");
  (**(code **)(*piVar3 + 0x14))();
  iVar4 = FUN_007300a0("Build");
  if (iVar4 == 0) {
LAB_00489b21:
    uVar6 = 0;
  }
  else {
    puVar5 = (undefined4 *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_00489b21;
    uVar6 = FUN_008917b4(puVar5);
  }
  local_8 = 0xffffffff;
  *in_ECX = uVar6;
  local_8c[0] = TiXmlDocument::vftable;
  if (0xf < local_2c) {
    FUN_0089120c(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_0072e040();
LAB_00489b6f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

