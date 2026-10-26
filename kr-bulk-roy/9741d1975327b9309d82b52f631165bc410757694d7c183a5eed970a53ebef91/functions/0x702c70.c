
void FUN_00702c70(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_218;
  uint *local_214;
  int local_210;
  int local_20c;
  uint local_208 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = FUN_006f6210(param_1);
  local_214 = local_208;
  uVar7 = 0;
  local_20c = param_1;
  local_210 = 0;
  if (local_218 != 0) {
    do {
      iVar5 = local_20c;
      if ((&local_8 <= local_214) && (iVar6 = (int)local_214 - (int)local_208, iVar6 != 0)) {
        if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <=
            *(uint *)(*(int *)(local_20c + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar2 = *(undefined4 **)(iVar5 + 8);
        uVar4 = FUN_006fec70(iVar5,local_208,iVar6);
        *puVar2 = uVar4;
        puVar2[2] = 4;
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 0x10;
        local_210 = local_210 + 1;
        local_214 = local_208;
        FUN_006f6b60(&local_214);
      }
      iVar5 = _tolower((uint)*(byte *)(uVar7 + iVar3));
      *(char *)local_214 = (char)iVar5;
      local_214 = (uint *)((int)local_214 + 1);
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_218);
  }
  iVar3 = local_20c;
  iVar5 = (int)local_214 - (int)local_208;
  if (iVar5 != 0) {
    if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <= *(uint *)(*(int *)(local_20c + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(iVar3 + 8);
    uVar4 = FUN_006fec70(iVar3,local_208,iVar5);
    *puVar2 = uVar4;
    puVar2[2] = 4;
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x10;
    local_214 = local_208;
    local_210 = local_210 + 1;
  }
  iVar5 = local_20c;
  iVar3 = local_210;
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
    FUN_006fc080(iVar5,iVar3,(*(int *)(iVar5 + 8) - *(int *)(iVar5 + 0xc) >> 4) + -1);
    *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + iVar3 * -0x10 + 0x10;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

