
int FUN_008b8e90(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = iVar1;
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x94);
    if (param_3 != (int *)0x0) {
      if (*param_3 != 0) {
        iVar3 = *(int *)(*param_3 + 4);
      }
      *param_3 = 0;
    }
    if (iVar3 != 0) {
      while (iVar2 = *(int *)(iVar3 + 8), *(int *)(iVar2 + 0x10) != param_2) {
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          return iVar1;
        }
      }
      if (param_3 != (int *)0x0) {
        *param_3 = iVar3;
      }
    }
  }
  return iVar2;
}

