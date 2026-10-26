
/* WARNING: Removing unreachable block (ram,0x006688ee) */
/* WARNING: Removing unreachable block (ram,0x00668884) */
/* WARNING: Removing unreachable block (ram,0x00668922) */
/* WARNING: Removing unreachable block (ram,0x00668926) */

void FUN_006687d0(undefined4 param_1,undefined4 *param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  short *psVar7;
  undefined4 *in_ECX;
  uint uVar8;
  uint uVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092a978;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = param_2[4];
  uVar8 = 0;
  uVar9 = uVar4;
  while( true ) {
    local_8 = 0xffffffff;
    puVar5 = param_2;
    if (7 < (uint)param_2[5]) {
      puVar5 = (undefined4 *)*param_2;
    }
    iVar6 = FUN_00466df0(in_ECX,puVar5,param_2[4]);
    if (iVar6 == -1) break;
    local_8 = 0;
    puVar5 = in_ECX;
    if (7 < (uint)in_ECX[5]) {
      puVar5 = (undefined4 *)*in_ECX;
    }
    FUN_00402160((int)puVar5 + uVar8 * 2,iVar6 - uVar8);
    FUN_0049c120(uVar9);
    uVar8 = iVar6 + iVar3;
  }
  if (uVar8 < (uint)in_ECX[4]) {
    local_8 = 1;
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    psVar1 = (short *)((int)in_ECX + uVar8 * 2);
    psVar7 = psVar1;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar1,(int)psVar7 - (int)(psVar1 + 1) >> 1);
    FUN_0049c120(uVar9);
  }
  else if (in_ECX[4] == uVar8) {
    local_8 = 2;
    FUN_0049c120(uVar9);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}

