
void FUN_008cd370(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 0x34);
    if ((param_3 == iVar1 + *(int *)(param_1 + 0x10)) &&
       ((iVar2 = FUN_008ccf60(param_4,iVar1,*(int *)(param_1 + 0x10)), iVar2 != 0 ||
        (iVar2 = FUN_008ccf60(param_4,0,iVar1), iVar2 != 0)))) {
      *(int *)(param_1 + 4) = iVar2;
    }
  }
  return;
}

