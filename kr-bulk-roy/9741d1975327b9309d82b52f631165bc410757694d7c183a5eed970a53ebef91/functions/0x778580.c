
void FUN_00778580(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  int local_18;
  int local_10;
  int *local_8;
  
  iVar2 = 0;
  iVar3 = 0;
  uVar4 = 0;
  local_8 = (int *)(in_ECX + 0x10);
  local_10 = 0;
  local_18 = 0;
  local_1c = 0;
  do {
    iVar1 = *local_8;
    if (iVar1 != 0) {
      if (uVar4 / 3 == 0) {
        if (local_18 <= *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c)) {
          local_18 = *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c);
        }
      }
      else if ((uVar4 / 3 == 2) && (local_10 <= *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c))) {
        local_10 = *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c);
      }
      iVar2 = local_1c;
      if (uVar4 % 3 == 0) {
        if (local_1c <= *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28)) {
          local_1c = *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28);
          iVar2 = local_1c;
        }
      }
      else if ((uVar4 % 3 == 2) && (iVar3 <= *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28))) {
        iVar3 = *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28);
      }
    }
    local_8 = local_8 + 0x10;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 9);
  FUN_00778660(iVar2,local_18,iVar3,local_10);
  return;
}

