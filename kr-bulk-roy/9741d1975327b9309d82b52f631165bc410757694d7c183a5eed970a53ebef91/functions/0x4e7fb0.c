
ulonglong FUN_004e7fb0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == *(int *)(param_2 + 8)) {
    return CONCAT44(param_1,CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),
                                     *(int *)(param_2 + 4) < *(int *)(param_1 + 4)));
  }
  return (ulonglong)CONCAT31((int3)((uint)iVar1 >> 8),*(int *)(param_2 + 8) < iVar1);
}

