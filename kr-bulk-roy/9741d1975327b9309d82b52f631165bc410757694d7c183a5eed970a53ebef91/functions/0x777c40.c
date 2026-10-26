
void FUN_00777c40(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (*(int *)(iVar1 + 0x24) != 0) {
    iVar2 = *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8);
    iVar1 = *(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc);
    local_18 = 0;
    local_14 = 0;
    local_10 = iVar2;
    local_c = iVar1;
    FUN_00750bf0(&local_18,*(undefined4 *)(in_ECX + 0xc));
    local_10 = *(undefined4 *)(in_ECX + 0x14);
    local_18 = 0;
    local_14 = 0;
    local_c = iVar1;
    FUN_00750bf0(&local_18,*(undefined4 *)(in_ECX + 0x10));
    local_18 = iVar2 - *(int *)(in_ECX + 0x14);
    local_14 = 0;
    local_10 = iVar2;
    local_c = iVar1;
    FUN_00750bf0(&local_18,*(undefined4 *)(in_ECX + 0x10));
    local_18 = *(int *)(in_ECX + 0x14);
    local_10 = iVar2 - local_18;
    local_14 = 0;
    local_c = local_18;
    FUN_00750bf0(&local_18,*(undefined4 *)(in_ECX + 0x10));
    local_18 = *(int *)(in_ECX + 0x14);
    local_10 = iVar2 - local_18;
    local_14 = iVar1 - local_18;
    local_c = iVar1;
    FUN_00750bf0(&local_18,*(undefined4 *)(in_ECX + 0x10));
  }
  return;
}

