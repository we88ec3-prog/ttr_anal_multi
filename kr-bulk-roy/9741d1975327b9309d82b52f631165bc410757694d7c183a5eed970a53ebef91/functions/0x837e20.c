
void FUN_00837e20(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_PTR_00d639fc;
  for (piVar1 = *(int **)(PTR_PTR_00d639fc + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[3]) {
    if (*piVar1 == param_1) {
      return;
    }
  }
  iVar3 = FUN_00891268(0x38);
  if (iVar3 == 0) {
    uRam0000000c = *(undefined4 *)(puVar2 + 8);
    *(undefined4 *)(puVar2 + 8) = 0;
    return;
  }
  iVar3 = FUN_00837d50(*(int *)(puVar2 + 0x34) + 1);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(puVar2 + 8);
  *(int *)(puVar2 + 8) = iVar3;
  return;
}

