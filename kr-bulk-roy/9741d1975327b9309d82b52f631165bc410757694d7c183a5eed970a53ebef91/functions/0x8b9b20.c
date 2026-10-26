
undefined2 FUN_008b9b20(int *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_2;
  uVar1 = 0;
  *param_2 = 0;
  iVar2 = param_1[2];
  if ((uint)param_1[1] <= iVar2 + 1U) {
LAB_008b9b77:
    *puVar3 = 0x55;
    return 0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    puVar3 = (undefined4 *)(*param_1 + iVar2);
    if (puVar3 == (undefined4 *)0x0) goto LAB_008b9b6f;
  }
  else {
    iVar2 = (*(code *)param_1[5])(param_1,iVar2,&param_2,2);
    if (iVar2 != 2) goto LAB_008b9b77;
    puVar3 = &param_2;
  }
  uVar1 = *(undefined2 *)puVar3;
LAB_008b9b6f:
  param_1[2] = param_1[2] + 2;
  return uVar1;
}

