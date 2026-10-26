
void FUN_00713740(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  byte *pbVar6;
  bool bVar7;
  undefined4 local_198;
  int local_194;
  undefined1 local_190 [12];
  byte local_184 [364];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f40d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_00715270(local_190);
  local_8 = 0;
  local_198 = 1;
  iVar3 = FUN_00715620(1);
  if (iVar3 != 0) {
    local_8 = 0xffffffff;
    FUN_00715380(local_190);
    goto LAB_007138c3;
  }
  FUN_007187c0(uVar2);
  pbVar6 = local_184;
  pcVar4 = "Master0z";
  do {
    bVar1 = *pcVar4;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_007137f6:
      iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_007137fb;
    }
    if (bVar1 == 0) break;
    bVar1 = pcVar4[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_007137f6;
    pcVar4 = pcVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_007137fb:
  if (iVar3 != 0) {
    local_8 = 0xffffffff;
    FUN_00715380(local_190);
    goto LAB_007138c3;
  }
  piVar5 = (int *)FUN_00717410("EncSetting");
  if (piVar5 == (int *)0x0) {
LAB_00713870:
    local_194 = 0;
    FUN_007135b0(local_190,param_1 + 4,local_198,&local_194);
    FUN_00715b00();
    local_8 = 0xffffffff;
    if (local_194 == 0) {
      FUN_00715380(local_190);
      goto LAB_007138c3;
    }
  }
  else {
    iVar3 = (**(code **)(*piVar5 + 0x20))();
    uVar2 = -(uint)(iVar3 != 0) & (uint)piVar5;
    if (uVar2 == 0) goto LAB_00713870;
    iVar3 = *(int *)(uVar2 + 0x118);
    if (*(int *)(iVar3 + 0x4c) == 4) {
      local_198 = **(undefined4 **)(iVar3 + 0x48);
      goto LAB_00713870;
    }
  }
  local_8 = 0xffffffff;
  FUN_00715380(local_190);
LAB_007138c3:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

