
void FUN_00708580(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  FILE *in_ECX;
  int iVar5;
  uint _Count;
  undefined1 *local_21c;
  int local_218;
  int local_214;
  undefined1 local_210 [520];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_21c = local_210;
  local_214 = param_1;
  local_218 = 0;
  _Count = 0x200;
  do {
    iVar4 = local_214;
    iVar5 = (int)local_21c - (int)local_210;
    if (iVar5 != 0) {
      if (*(uint *)(*(int *)(local_214 + 0x10) + 0x40) <=
          *(uint *)(*(int *)(local_214 + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar1 = *(undefined4 **)(iVar4 + 8);
      uVar2 = FUN_006fec70(iVar4,local_210,iVar5);
      *puVar1 = uVar2;
      puVar1[2] = 4;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
      local_218 = local_218 + 1;
      local_21c = local_210;
      FUN_006f6b60(&local_21c);
    }
    if (param_2 < _Count) {
      _Count = param_2;
    }
    sVar3 = _fread(local_210,1,_Count,in_ECX);
    local_21c = local_21c + sVar3;
    param_2 = param_2 - sVar3;
  } while ((param_2 != 0) && (sVar3 == _Count));
  FUN_006f6af0();
  FUN_006f5bb0();
  local_218 = 1;
  if ((param_2 != 0) && (iVar4 = FUN_006f5460(), iVar4 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

