
int FUN_00411b30(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  local_c = param_2 / 5;
  iVar3 = 0;
  local_8 = 0;
  if (0 < local_c) {
    param_2 = 0;
    do {
      FUN_007e8a90(&local_1c,*(int *)(param_1 + 0x124) + param_2);
      uVar2 = local_18 - local_1c >> 2;
      uVar1 = 0;
      if (uVar2 != 0) {
        do {
          iVar3 = *(int *)(local_1c + uVar1 * 4);
          uVar1 = uVar1 + 1;
          iVar3 = (uint)*(byte *)(iVar3 + 4) + local_8 + -1 + (uint)*(byte *)(iVar3 + 6);
          local_8 = iVar3;
        } while (uVar1 < uVar2);
      }
      if (local_1c != 0) {
        FUN_0089120c(local_1c);
      }
      param_2 = param_2 + 0x10;
      local_c = local_c + -1;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
    } while (local_c != 0);
  }
  return iVar3;
}

