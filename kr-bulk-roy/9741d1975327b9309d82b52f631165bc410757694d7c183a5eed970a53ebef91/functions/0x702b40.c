
void FUN_00702b40(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_218;
  uint *local_214;
  int local_210;
  int local_20c;
  uint local_208 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_006f6210(param_1);
  local_214 = local_208;
  local_210 = 0;
  while (local_20c = param_1, local_218 != 0) {
    local_218 = local_218 + -1;
    if ((&local_8 <= local_214) && (iVar4 = (int)local_214 - (int)local_208, iVar4 != 0)) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      puVar1 = *(undefined4 **)(param_1 + 8);
      uVar3 = FUN_006fec70(param_1,local_208,iVar4);
      *puVar1 = uVar3;
      puVar1[2] = 4;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      local_210 = local_210 + 1;
      local_214 = local_208;
      FUN_006f6b60(&local_214);
    }
    *(undefined1 *)local_214 = *(undefined1 *)(local_218 + iVar2);
    local_214 = (uint *)((int)local_214 + 1);
    param_1 = local_20c;
  }
  FUN_006f6af0();
  FUN_006f5bb0();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

