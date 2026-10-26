
undefined4 FUN_0070b920(int param_1)

{
  undefined *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar3 == &DAT_00c0bfc8) || (puVar3[2] != 5)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar3) ||
         ((puVar3 == &DAT_00c0bfc8 || (puVar3[2] == -1)))) goto LAB_0070b952;
      pcVar2 = (&PTR_DAT_00c0be1c)[puVar3[2]];
      goto LAB_0070b960;
    }
  }
  else {
LAB_0070b952:
    pcVar2 = "no value";
LAB_0070b960:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
    FUN_006f5da0(1);
  }
  iVar4 = *(int *)(param_1 + 0xc);
  puVar3 = (undefined4 *)(iVar4 + 0x10);
  if (puVar3 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar3 != &DAT_00c0bfc8) && (*(int *)(iVar4 + 0x18) == 6)) goto LAB_0070b9d8;
    if ((*(undefined4 **)(param_1 + 8) <= puVar3) ||
       ((puVar3 == &DAT_00c0bfc8 || (*(int *)(iVar4 + 0x18) == -1)))) goto LAB_0070b9ab;
    pcVar2 = (&PTR_DAT_00c0be1c)[*(int *)(iVar4 + 0x18)];
  }
  else {
LAB_0070b9ab:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","function",pcVar2);
  FUN_006f5da0(2);
LAB_0070b9d8:
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  while( true ) {
    puVar3 = *(undefined4 **)(param_1 + 0xc);
    if (*(undefined4 **)(param_1 + 8) <= puVar3) {
      puVar3 = &DAT_00c0bfc8;
    }
    iVar4 = FUN_006f9270(*puVar3);
    if (iVar4 == 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
      return 0;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar3 = *(undefined4 **)(param_1 + 8);
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    if (puVar3 <= puVar5) {
      puVar5 = &DAT_00c0bfc8;
    }
    *puVar3 = *puVar5;
    puVar3[1] = puVar5[1];
    puVar3[2] = puVar5[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar3 = *(undefined4 **)(param_1 + 8);
    *puVar3 = puVar3[-0xc];
    puVar3[1] = puVar3[-0xb];
    puVar3[2] = puVar3[-10];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar3 = *(undefined4 **)(param_1 + 8);
    *puVar3 = puVar3[-0xc];
    puVar3[1] = puVar3[-0xb];
    puVar3[2] = puVar3[-10];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x30,1);
    puVar1 = *(undefined **)(param_1 + 8);
    if ((puVar1 == &DAT_00c0bfd8) || (*(int *)(puVar1 + -8) != 0)) break;
    *(undefined **)(param_1 + 8) = puVar1 + -0x20;
  }
  return 1;
}

