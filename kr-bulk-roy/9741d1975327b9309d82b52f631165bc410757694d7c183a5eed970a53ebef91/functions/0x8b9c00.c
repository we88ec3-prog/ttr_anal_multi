
undefined4 FUN_008b9c00(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_2;
  uVar1 = 0;
  *param_2 = 0;
  iVar2 = param_1[2];
  if ((uint)param_1[1] <= iVar2 + 3U) {
LAB_008b9c64:
    *puVar3 = 0x55;
    return 0;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    puVar3 = (undefined4 *)(*param_1 + iVar2);
    if (puVar3 == (undefined4 *)0x0) goto LAB_008b9c5c;
  }
  else {
    iVar2 = (*(code *)param_1[5])(param_1,iVar2,&param_2,4);
    if (iVar2 != 4) goto LAB_008b9c64;
    puVar3 = &param_2;
  }
  uVar1 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)puVar3,*(undefined1 *)((int)puVar3 + 1)),
                            *(undefined1 *)((int)puVar3 + 2)),*(undefined1 *)((int)puVar3 + 3));
LAB_008b9c5c:
  param_1[2] = param_1[2] + 4;
  return uVar1;
}

