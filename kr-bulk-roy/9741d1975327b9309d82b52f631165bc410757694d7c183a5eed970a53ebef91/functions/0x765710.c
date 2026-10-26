
void FUN_00765710(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x24) != 0)) {
    local_10 = (float)param_1;
    local_18 = *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8);
    local_c = (float)param_2;
    local_14 = *(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc);
    local_8 = 0;
    local_20 = 0;
    local_1c = 0;
    FUN_00750bf0(&local_20,*(undefined4 *)(in_ECX + 0xc));
  }
  return;
}

