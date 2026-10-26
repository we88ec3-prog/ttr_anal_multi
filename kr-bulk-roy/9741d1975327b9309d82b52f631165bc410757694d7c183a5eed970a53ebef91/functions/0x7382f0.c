
int FUN_007382f0(void)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int unaff_EDI;
  undefined2 in_FPUControlWord;
  float local_24;
  float local_20;
  int local_1c;
  int local_18;
  float local_14;
  float local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = *(int *)(unaff_EDI + 300);
  local_10 = (float)*(int *)(unaff_EDI + 0x128) / (float)*(int *)(unaff_EDI + 0x120);
  local_14 = (float)local_8 / (float)*(int *)(unaff_EDI + 0x124);
  if (((*(int *)(unaff_EDI + 0x14) == 2) && (*(int *)(unaff_EDI + 0x118) != 0)) &&
     (local_c = 0, 0 < *(int *)(unaff_EDI + 0xc))) {
    iVar2 = local_8 / 2;
    local_1c = *(int *)(unaff_EDI + 0x128) / 2;
    pfVar3 = (float *)(unaff_EDI + 0x18);
    do {
      local_24 = *pfVar3 * local_10;
      local_8 = CONCAT22(in_FPUControlWord,(undefined2)local_8);
      local_20 = *pfVar3 * local_14;
      local_18 = (int)ROUND(pfVar3[0x20]);
      iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x118) + 0x24))
                        (local_1c,iVar2,0,&local_24,1,0,local_18 << 0x18 | 0xffffff);
      if (iVar1 < 0) {
        return iVar1;
      }
      local_c = local_c + 1;
      pfVar3 = pfVar3 + 1;
    } while (local_c < *(int *)(unaff_EDI + 0xc));
  }
  return 0;
}

