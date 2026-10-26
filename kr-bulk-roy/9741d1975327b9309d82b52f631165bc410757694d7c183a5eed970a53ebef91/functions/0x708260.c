
undefined4 FUN_00708260(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *_Filename;
  undefined4 *puVar3;
  FILE *pFVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar3 < *(undefined4 **)(param_1 + 8)) && (puVar3 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar3[2])) {
    _Filename = (char *)FUN_006f6210(param_1);
    puVar3 = (undefined4 *)FUN_00707a00();
    pFVar4 = _fopen(_Filename,"r");
    *puVar3 = pFVar4;
    if (pFVar4 == (FILE *)0x0) {
      FUN_00707850(param_1,_Filename);
    }
    puVar1 = (undefined4 *)FUN_006f50f0();
    puVar3 = *(undefined4 **)(param_1 + 8);
    *puVar3 = *puVar1;
    puVar3[1] = puVar1[1];
    puVar3[2] = puVar1[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar3 = *(undefined4 **)(param_1 + 8);
    *puVar3 = 1;
    puVar3[2] = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f55b0(FUN_00708980,2);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  *(undefined4 *)(param_1 + 0x60) = 5;
  puVar1 = (undefined4 *)FUN_006f9b70(1);
  puVar3 = *(undefined4 **)(param_1 + 8);
  *puVar3 = *puVar1;
  puVar3[1] = puVar1[1];
  puVar3[2] = puVar1[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  uVar2 = FUN_007081e0(param_1);
  return uVar2;
}

