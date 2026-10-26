
uint FUN_008b9b90(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_2;
  uVar1 = 0;
  *param_2 = 0;
  iVar2 = param_1[2];
  if ((uint)param_1[1] <= iVar2 + 2U) {
LAB_008b9beb:
    *puVar3 = 0x55;
    return 0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    puVar3 = (undefined4 *)(*param_1 + iVar2);
    if (puVar3 == (undefined4 *)0x0) goto LAB_008b9be3;
  }
  else {
    iVar2 = (*(code *)param_1[5])(param_1,iVar2,&param_2,3);
    if (iVar2 != 3) goto LAB_008b9beb;
    puVar3 = &param_2;
  }
  uVar1 = (uint)CONCAT21(CONCAT11(*(undefined1 *)puVar3,*(undefined1 *)((int)puVar3 + 1)),
                         *(undefined1 *)((int)puVar3 + 2));
LAB_008b9be3:
  param_1[2] = param_1[2] + 3;
  return uVar1;
}

