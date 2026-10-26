
void FUN_008cd3d0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 0x10);
    iVar2 = *(int *)(param_1 + 0x34);
    if ((param_2 == iVar2 + iVar1) &&
       ((iVar3 = FUN_008ccf60(param_3,0,iVar1), iVar3 != 0 ||
        (iVar3 = FUN_008ccf60(param_3,iVar1,iVar2), iVar3 != 0)))) {
      *(int *)(param_1 + 4) = iVar3;
    }
  }
  return;
}

