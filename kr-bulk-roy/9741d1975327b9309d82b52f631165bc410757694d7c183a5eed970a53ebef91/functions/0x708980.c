
undefined4 FUN_00708980(int param_1)

{
  FILE *_File;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  iVar3 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  if (*(char *)(iVar3 + 7) == '\0') {
    piVar1 = &DAT_00c0bfc8;
  }
  else {
    piVar1 = (int *)(iVar3 + 0x18);
  }
  if (piVar1[2] == 2) {
    puVar2 = (undefined4 *)*piVar1;
  }
  else if (piVar1[2] == 7) {
    puVar2 = (undefined4 *)(*piVar1 + 0x18);
  }
  else {
    puVar2 = (undefined4 *)0x0;
  }
  _File = (FILE *)*puVar2;
  if (_File == (FILE *)0x0) {
    FUN_006f5f30(param_1,"file is already closed");
  }
  iVar3 = FUN_007083f0(param_1);
  iVar4 = _ferror(_File);
  if (iVar4 == 0) {
    if (iVar3 == 0) {
      iVar3 = **(int **)(*(int *)(param_1 + 0x14) + 4);
      piVar1 = (int *)(iVar3 + 0x28);
      if (*(byte *)(iVar3 + 7) < 2) {
        piVar1 = &DAT_00c0bfc8;
      }
      if ((piVar1[2] != 0) && ((piVar1[2] != 1 || (*piVar1 != 0)))) {
        if (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0xc)) {
          do {
            *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
            *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
          } while (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0xc));
        }
        puVar2 = *(undefined4 **)(param_1 + 0xc);
        *(undefined4 **)(param_1 + 8) = puVar2;
        iVar3 = **(int **)(*(int *)(param_1 + 0x14) + 4);
        if (*(char *)(iVar3 + 7) == '\0') {
          puVar6 = &DAT_00c0bfc8;
        }
        else {
          puVar6 = (undefined4 *)(iVar3 + 0x18);
        }
        *puVar2 = *puVar6;
        puVar2[1] = puVar6[1];
        puVar2[2] = puVar6[2];
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        FUN_00707ca0();
      }
      return 0;
    }
    return 1;
  }
  piVar1 = __errno();
  uVar5 = FUN_00898466(*piVar1);
  uVar5 = FUN_006f5f30(param_1,&DAT_00bfc638,uVar5);
  return uVar5;
}

