
int FUN_008c5bb0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x1c) == -1) {
    return 0;
  }
  if ((*(char *)(param_1 + 0x18) == '\0') || (*(int *)(param_1 + 0x1c) != *param_2)) {
    iVar2 = FUN_008c5a30(param_1,param_2,1);
  }
  else {
    FUN_008c5960(param_1);
    if (*(char *)(param_1 + 0x18) == '\0') {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x20);
    iVar2 = 0;
    if (iVar1 != 0) {
      *param_2 = *(int *)(param_1 + 0x1c);
      return iVar1;
    }
  }
  return iVar2;
}

