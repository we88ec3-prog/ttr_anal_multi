
void FUN_0077cfb0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  
  if ((((*(int **)(in_ECX + 0xc) != (int *)0x0) && (**(int **)(in_ECX + 0xc) != 0)) &&
      (iVar1 = *(int *)(in_ECX + 8), iVar1 != 0)) && (*(int *)(iVar1 + 0x24) != 0)) {
    if (*(char *)(in_ECX + 0x18) == '\0') {
      pfVar6 = &local_24;
      local_24 = 1.0;
      local_20 = 1.0;
      pfVar5 = &local_30;
      local_1c = 0;
      local_30 = (float)param_1;
      local_2c = (float)param_2;
      local_28 = 0;
      uVar2 = FUN_0077d0f0(pfVar5,pfVar6);
      iVar3 = *(int *)(in_ECX + 0x10);
      iVar4 = *(int *)(in_ECX + 0x14);
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
      local_24 = (float)(*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) / (float)iVar3;
      iVar4 = *(int *)(in_ECX + 0x14);
      pfVar6 = &local_24;
      pfVar5 = &local_30;
      local_20 = (float)(*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) / (float)iVar4;
      local_1c = 0;
      local_30 = (float)param_1;
      local_2c = (float)param_2;
      local_28 = 0;
      uVar2 = FUN_0077d0f0(pfVar5,pfVar6);
    }
    FUN_00750ec0(iVar3,iVar4,uVar2,pfVar5,pfVar6);
    if (((*(float *)(in_ECX + 0x1c) <= *(float *)(in_ECX + 0x24)) ||
        (*(char *)(in_ECX + 0x20) != '\0')) && (*(char *)(in_ECX + 0x3c) == '\0')) {
      FUN_0074e480(in_ECX);
    }
  }
  return;
}

