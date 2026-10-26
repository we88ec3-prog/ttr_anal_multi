
void FUN_007d7600(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(in_ECX + 0xa8);
  if (iVar1 + param_1 < 0x100) {
    iVar7 = *(int *)(in_ECX + 0xac);
    iVar5 = 2;
    *(int *)(in_ECX + 0xac) = iVar7 + -2 + param_1;
    if (2 < param_1) {
      psVar3 = (short *)(in_ECX + iVar7 * 6 + 0x38b4);
      do {
        sVar2 = (short)iVar1;
        psVar3[-1] = (short)iVar5 + -1 + sVar2;
        psVar3[-2] = sVar2;
        *psVar3 = (short)iVar5 + sVar2;
        iVar5 = iVar5 + 1;
        psVar3 = psVar3 + 3;
      } while (iVar5 < param_1);
    }
    local_14 = *(undefined4 *)(in_ECX + 0x10);
    local_10 = *(undefined4 *)(in_ECX + 0x14);
    local_c = *(undefined4 *)(in_ECX + 0x18);
    D3DXVec3Normalize(&local_14,&local_14);
    iVar7 = iVar1;
    if (0 < param_1) {
      puVar6 = (undefined4 *)(iVar1 * 0x20 + 0xbc + in_ECX);
      puVar4 = (undefined4 *)(in_ECX + 0x20b0 + iVar1 * 0xc);
      param_2 = param_2 - (int)param_3;
      local_18 = param_1;
      do {
        *puVar4 = *(undefined4 *)(param_2 + (int)param_3);
        puVar4[1] = *(undefined4 *)(param_2 + 4 + (int)param_3);
        puVar4[2] = *(undefined4 *)(param_2 + 8 + (int)param_3);
        puVar6[-3] = *puVar4;
        puVar6[-2] = puVar4[1];
        puVar6[-1] = puVar4[2];
        *puVar6 = *param_3;
        puVar6[1] = param_3[1];
        puVar6[2] = param_3[2];
        puVar4 = puVar4 + 3;
        puVar6 = puVar6 + 8;
        param_3 = param_3 + 3;
        local_18 = local_18 + -1;
        iVar7 = iVar1 + param_1;
      } while (local_18 != 0);
    }
    *(int *)(in_ECX + 0xa8) = iVar7;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

