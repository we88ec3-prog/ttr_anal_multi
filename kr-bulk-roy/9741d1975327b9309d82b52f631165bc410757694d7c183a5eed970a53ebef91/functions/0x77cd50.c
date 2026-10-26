
void FUN_0077cd50(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  if ((((*(int **)(in_ECX + 0xc) != (int *)0x0) && (**(int **)(in_ECX + 0xc) != 0)) &&
      (*(int *)(in_ECX + 8) != 0)) && (*(int *)(*(int *)(in_ECX + 8) + 0x24) != 0)) {
    if (*(char *)(in_ECX + 0x18) == '\0') {
      local_10 = *(int *)(in_ECX + 0x10);
      local_c = *(int *)(in_ECX + 0x14);
      local_24 = 1.0;
      local_20 = 1.0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8);
      local_10 = *(int *)(in_ECX + 0x10);
      local_24 = (float)(*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) / (float)local_10;
      local_c = *(int *)(in_ECX + 0x14);
      local_20 = (float)(*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) / (float)local_c;
    }
    local_14 = 0;
    local_18 = 0;
    local_1c = 0x3f800000;
    local_30 = (float)param_1;
    local_2c = (float)param_2;
    local_28 = 0;
    FUN_00750ec0(local_10,local_c,&local_18,&local_30,&local_24);
  }
  return;
}

