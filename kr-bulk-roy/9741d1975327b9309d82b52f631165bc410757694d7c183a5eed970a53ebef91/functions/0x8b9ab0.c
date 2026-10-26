
undefined2 FUN_008b9ab0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  
  puVar2 = param_2;
  uVar3 = 0;
  *param_2 = 0;
  iVar1 = param_1[2];
  if ((uint)param_1[1] <= iVar1 + 1U) {
LAB_008b9b07:
    *puVar2 = 0x55;
    return 0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    puVar2 = (undefined4 *)(*param_1 + iVar1);
    if (puVar2 == (undefined4 *)0x0) goto LAB_008b9aff;
  }
  else {
    iVar1 = (*(code *)param_1[5])(param_1,iVar1,&param_2,2);
    if (iVar1 != 2) goto LAB_008b9b07;
    puVar2 = &param_2;
  }
  uVar3 = CONCAT11(*(undefined1 *)puVar2,*(undefined1 *)((int)puVar2 + 1));
LAB_008b9aff:
  param_1[2] = param_1[2] + 2;
  return uVar3;
}

