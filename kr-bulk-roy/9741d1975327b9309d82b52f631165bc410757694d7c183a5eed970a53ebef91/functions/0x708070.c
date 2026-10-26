
undefined4 FUN_00708070(undefined4 param_1,char *param_2)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  FILE *pFVar4;
  undefined4 *puVar5;
  
  piVar1 = *(int **)(in_EAX + 0xc);
  if (((*(int **)(in_EAX + 8) <= piVar1) || (piVar1 == &DAT_00c0bfc8)) || (piVar1[2] < 1))
  goto LAB_0070815b;
  if (*(int **)(in_EAX + 8) <= piVar1) {
    piVar1 = &DAT_00c0bfc8;
  }
  if (piVar1[2] == 4) {
LAB_007080d4:
    iVar2 = *piVar1;
    if ((char *)(iVar2 + 0x10) == (char *)0x0) goto LAB_00708105;
    puVar3 = (undefined4 *)FUN_00707a00();
    pFVar4 = _fopen((char *)(iVar2 + 0x10),param_2);
    *puVar3 = pFVar4;
    if (pFVar4 == (FILE *)0x0) {
      FUN_00707850();
    }
  }
  else {
    iVar2 = FUN_006fb5d0();
    if (iVar2 != 0) {
      if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      piVar1 = *(int **)(in_EAX + 0xc);
      if (*(int **)(in_EAX + 8) <= piVar1) {
        piVar1 = &DAT_00c0bfc8;
      }
      goto LAB_007080d4;
    }
LAB_00708105:
    piVar1 = (int *)FUN_006f6140("FILE*");
    if (*piVar1 == 0) {
      FUN_006f5f30();
    }
    puVar3 = *(undefined4 **)(in_EAX + 0xc);
    puVar5 = *(undefined4 **)(in_EAX + 8);
    if (puVar5 <= puVar3) {
      puVar3 = &DAT_00c0bfc8;
    }
    *puVar5 = *puVar3;
    puVar5[1] = puVar3[1];
    puVar5[2] = puVar3[2];
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  }
  FUN_006f5870(param_1);
LAB_0070815b:
  *(undefined4 *)(in_EAX + 0x58) = *(undefined4 *)(**(int **)(*(int *)(in_EAX + 0x14) + 4) + 0xc);
  *(undefined4 *)(in_EAX + 0x60) = 5;
  puVar5 = (undefined4 *)FUN_006f9b70(param_1);
  puVar3 = *(undefined4 **)(in_EAX + 8);
  *puVar3 = *puVar5;
  puVar3[1] = puVar5[1];
  puVar3[2] = puVar5[2];
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  return 1;
}

