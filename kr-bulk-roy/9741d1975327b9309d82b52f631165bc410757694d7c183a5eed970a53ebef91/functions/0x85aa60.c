
undefined4 FUN_0085aa60(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (*(int **)(unaff_EDI + 0x3c) != (int *)0x0)) {
    iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x3c) + 4))();
    if (*(int *)(iVar2 + 4) == -0x5ecc0000) {
      FUN_0085aaf0(param_1,param_2);
    }
    else {
      iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x3c) + 4))();
      if (*(int *)(iVar2 + 4) == -0x5ece0000) {
        FUN_0085abc0(param_1,*(undefined4 *)(unaff_EDI + 0x3c));
      }
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 0x90);
  for (puVar3 = *(undefined4 **)(param_1 + 0x8c); puVar3 != puVar1; puVar3 = puVar3 + 3) {
    (*(code *)puVar3[2])(puVar3[1],*(undefined4 *)(param_1 + 4),*puVar3,param_2);
  }
  return 1;
}

