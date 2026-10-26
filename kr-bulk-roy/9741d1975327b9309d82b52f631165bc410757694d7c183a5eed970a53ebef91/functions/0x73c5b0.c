
/* WARNING: Removing unreachable block (ram,0x0073c6bb) */

void FUN_0073c5b0(undefined4 param_1,wchar_t *param_2)

{
  char cVar1;
  wchar_t wVar2;
  bool bVar3;
  uint uVar4;
  wchar_t *pwVar5;
  char ****ppppcVar6;
  int iVar7;
  int in_ECX;
  char ****ppppcVar8;
  char ***local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined1 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091f313;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8 = 0;
  pwVar5 = param_2;
  do {
    wVar2 = *pwVar5;
    pwVar5 = pwVar5 + 1;
  } while (wVar2 != L'\0');
  local_14 = uVar4;
  FUN_00402160(param_2,(int)pwVar5 - (int)(param_2 + 1) >> 1);
  local_58 = 0xf;
  local_5c = 0;
  local_6c[0] = (char ***)((uint)local_6c[0] & 0xffffff00);
  local_8._0_1_ = 2;
  FUN_00429710(uVar4);
  local_8 = CONCAT31(local_8._1_3_,3);
  ppppcVar8 = (char ****)local_6c[0];
  if (local_58 < 0x10) {
    ppppcVar8 = local_6c;
  }
  ppppcVar6 = ppppcVar8;
  do {
    cVar1 = *(char *)ppppcVar6;
    ppppcVar6 = (char ****)((int)ppppcVar6 + 1);
  } while (cVar1 != '\0');
  FUN_00402a70(ppppcVar8,(int)ppppcVar6 - (int)((int)ppppcVar8 + 1));
  if (0xf < local_58) {
    FUN_0089120c(local_6c[0]);
  }
  local_8 = local_8 & 0xffffff00;
  local_6c[0] = (char ***)((uint)local_6c[0] & 0xffffff00);
  local_58 = 0xf;
  local_5c = 0;
  local_34 = *(undefined4 *)(param_2 + 0x20);
  local_30 = *(uint *)(param_2 + 0x22);
  if (*(int *)(param_2 + 0x24) < 8) {
    local_18 = (uint)(6 < *(int *)(param_2 + 0x24));
  }
  else {
    local_18 = 2;
  }
  iVar7 = __wcsicmp(param_2,L"simsun");
  if (iVar7 == 0) {
    local_2c = 1;
    local_1c = 2;
    local_20 = 1;
  }
  else {
    bVar3 = 0xc < (int)((local_30 ^ (int)local_30 >> 0x1f) - ((int)local_30 >> 0x1f));
    if (bVar3) {
      local_2c = 0;
    }
    else {
      local_2c = 2;
    }
    local_24 = (uint)bVar3;
    local_1c = 1;
    local_20 = 0;
  }
  FUN_0073d530(in_ECX + 0xc);
  FUN_005719b0();
  if (0xf < local_3c) {
    FUN_0089120c(local_50);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

