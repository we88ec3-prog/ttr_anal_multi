
undefined4 FUN_0083dfa0(int param_1,short *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  iVar3 = (int)param_2;
  if (*(int *)(param_1 + 0xec) == 0) {
    return 0;
  }
  piVar2 = *(int **)(param_1 + 0x44c);
  puVar1 = (undefined4 *)(param_1 + 0x44c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *puVar1 = 0;
    *(undefined4 *)(param_1 + 0x450) = 0;
  }
  iVar5 = (**(code **)(**(int **)(param_1 + 0xec) + 0x6c))
                    (*(int **)(param_1 + 0xec),iVar3 * 0xc,8,0x65,0,puVar1,0);
  if (-1 < iVar5) {
    param_2 = (short *)0x0;
    iVar5 = (**(code **)(*(int *)*puVar1 + 0x2c))((int *)*puVar1,0,0,&param_2,0);
    if ((-1 < iVar5) && (iVar5 = 0, 0 < iVar3)) {
      do {
        sVar4 = (short)iVar5 * 4;
        *param_2 = sVar4;
        param_2[1] = sVar4 + 2;
        param_2[2] = sVar4 + 1;
        param_2[3] = sVar4 + 3;
        param_2[4] = sVar4 + 1;
        param_2[5] = sVar4 + 2;
        param_2 = param_2 + 6;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    (**(code **)(**(int **)(param_1 + 0x44c) + 0x30))(*(int **)(param_1 + 0x44c));
    *(int *)(param_1 + 0x450) = iVar3;
    return 1;
  }
  return 0;
}

