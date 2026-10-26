
void FUN_007032b0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_218;
  uint *local_214;
  int local_210;
  int local_20c;
  uint local_208 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar7 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
  local_214 = local_208;
  local_20c = param_1;
  local_210 = 0;
  local_218 = 1;
  if (0 < iVar7) {
    do {
      uVar3 = FUN_006f6370(param_1,local_218);
      if ((uVar3 & 0xff) != uVar3) {
        FUN_006f5da0(local_218);
      }
      iVar6 = local_20c;
      if ((&local_8 <= local_214) && (iVar5 = (int)local_214 - (int)local_208, iVar5 != 0)) {
        if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <=
            *(uint *)(*(int *)(local_20c + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar2 = *(undefined4 **)(iVar6 + 8);
        uVar4 = FUN_006fec70(iVar6,local_208,iVar5);
        *puVar2 = uVar4;
        puVar2[2] = 4;
        *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 0x10;
        local_210 = local_210 + 1;
        local_214 = local_208;
        FUN_006f6b60(&local_214);
      }
      *(char *)local_214 = (char)uVar3;
      local_218 = local_218 + 1;
      local_214 = (uint *)((int)local_214 + 1);
    } while (local_218 <= iVar7);
  }
  iVar7 = local_20c;
  iVar6 = (int)local_214 - (int)local_208;
  if (iVar6 != 0) {
    if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <= *(uint *)(*(int *)(local_20c + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(iVar7 + 8);
    uVar4 = FUN_006fec70(iVar7,local_208,iVar6);
    *puVar2 = uVar4;
    puVar2[2] = 4;
    *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 0x10;
    local_214 = local_208;
    local_210 = local_210 + 1;
  }
  iVar6 = local_20c;
  iVar7 = local_210;
  if (local_210 < 2) {
    if (local_210 == 0) {
      puVar2 = *(undefined4 **)(local_20c + 8);
      piVar1 = (int *)(local_20c + 8);
      uVar4 = FUN_006fec70(local_20c,&DAT_00bf2375,0);
      *puVar2 = uVar4;
      puVar2[2] = 4;
      *piVar1 = *piVar1 + 0x10;
    }
  }
  else {
    if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <= *(uint *)(*(int *)(local_20c + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    FUN_006fc080(iVar6,iVar7,(*(int *)(iVar6 + 8) - *(int *)(iVar6 + 0xc) >> 4) + -1);
    *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + iVar7 * -0x10 + 0x10;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

