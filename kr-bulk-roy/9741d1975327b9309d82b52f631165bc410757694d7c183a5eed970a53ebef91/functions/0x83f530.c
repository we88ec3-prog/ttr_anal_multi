
undefined4 * FUN_0083f530(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  
  puVar2 = param_1;
  piVar1 = *(int **)(unaff_ESI + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_0083f200(piVar1[1]);
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(undefined4 *)*(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *puVar2 = **(undefined4 **)(unaff_ESI + 4);
    return puVar2;
  }
  if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_00628740();
      FUN_0083f7b0(unaff_ESI,&param_1,piVar1);
    } while (param_2 != param_3);
  }
  *puVar2 = param_2;
  return puVar2;
}

