
undefined4
FUN_00857b70(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  if (iVar1 != unaff_ESI[1]) {
    iVar2 = FUN_00857b00(0,0);
    if (iVar2 != -1) {
      param_1 = param_1 * 0x14;
      iVar2 = iVar2 * 0xc;
      *param_2 = *(undefined2 *)(iVar2 + *(int *)(param_1 + iVar1));
      *param_3 = *(undefined2 *)(*(int *)(param_1 + *unaff_ESI) + 4 + iVar2);
      *param_4 = *(undefined2 *)(*(int *)(param_1 + *unaff_ESI) + 8 + iVar2);
      *param_5 = *(undefined4 *)(param_1 + 0x10 + *unaff_ESI);
      return 1;
    }
  }
  return 0;
}

