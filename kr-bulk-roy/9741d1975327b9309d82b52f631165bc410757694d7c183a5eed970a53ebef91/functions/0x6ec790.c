
void FUN_006ec790(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    do {
      uVar1 = *(uint *)(*(int *)(param_1 + 0x28) + iVar3 * 4);
      if (((*(int *)(param_3 + 0x10) == 0) || (((uVar1 != 2 && (uVar1 != 4)) && (uVar1 != 8)))) &&
         ((uVar1 == 0 || ((*(uint *)(param_2 + 0x1c) & uVar1) != 0)))) {
        iVar2 = FUN_006ed1c0();
        if (-1 < iVar2) {
          *(uint *)(*(int *)(param_3 + 0x38) + *(int *)(param_3 + 0x3c) * 4) = uVar1;
          *(int *)(param_3 + 0x3c) = *(int *)(param_3 + 0x3c) + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x2c));
  }
  return;
}

