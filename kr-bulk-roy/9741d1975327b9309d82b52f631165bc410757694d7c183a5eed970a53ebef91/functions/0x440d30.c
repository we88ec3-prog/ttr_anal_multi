
/* WARNING: Removing unreachable block (ram,0x00440e44) */
/* WARNING: Removing unreachable block (ram,0x00440de0) */
/* WARNING: Removing unreachable block (ram,0x00440e76) */
/* WARNING: Removing unreachable block (ram,0x00440e7a) */

void FUN_00440d30(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *in_ECX;
  uint uVar8;
  uint uVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092a1d8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = param_2[4];
  uVar8 = 0;
  uVar9 = uVar4;
  while( true ) {
    local_8 = 0xffffffff;
    puVar5 = param_2;
    if (0xf < (uint)param_2[5]) {
      puVar5 = (undefined4 *)*param_2;
    }
    iVar6 = FUN_00440930(in_ECX,puVar5,param_2[4]);
    if (iVar6 == -1) break;
    local_8 = 0;
    puVar5 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      puVar5 = (undefined4 *)*in_ECX;
    }
    FUN_00402a70((int)puVar5 + uVar8,iVar6 - uVar8);
    FUN_00440c60(uVar9);
    uVar8 = iVar6 + iVar3;
  }
  if (uVar8 < (uint)in_ECX[4]) {
    local_8 = 1;
    if (0xf < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    pcVar1 = (char *)((int)in_ECX + uVar8);
    pcVar7 = pcVar1;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(pcVar1,(int)pcVar7 - (int)(pcVar1 + 1));
    FUN_00440c60(uVar9);
  }
  else if (in_ECX[4] == uVar8) {
    local_8 = 2;
    FUN_00440c60(uVar9);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}

