
void FUN_008f42c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    piVar2 = param_1 + 0xd;
    local_8 = 2;
    do {
      piVar2[-2] = 0;
      piVar2[-1] = 0;
      FUN_008b9f80(iVar1,*piVar2);
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      FUN_008b9f80(iVar1,piVar2[3]);
      piVar2[3] = 0;
      piVar2 = piVar2 + 7;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    FUN_008b9f80(iVar1,param_1[10]);
    param_1[10] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    FUN_008b9f80(iVar1,param_1[7]);
    param_1[7] = 0;
    param_1[6] = 0;
    param_1[5] = 0;
    *param_1 = 0;
  }
  return;
}

