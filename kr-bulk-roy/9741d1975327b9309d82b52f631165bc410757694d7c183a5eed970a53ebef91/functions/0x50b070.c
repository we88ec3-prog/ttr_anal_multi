
void FUN_0050b070(char *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  int unaff_ESI;
  uint uVar4;
  undefined **local_10 [3];
  
  pcVar2 = param_1;
  if (*(uint *)(unaff_ESI + 8) <= *(int *)(unaff_ESI + 0x10) + 1U) {
    FUN_0050b360(unaff_ESI);
  }
  uVar4 = *(int *)(unaff_ESI + 0xc) + *(int *)(unaff_ESI + 0x10);
  if (*(uint *)(unaff_ESI + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(unaff_ESI + 8);
  }
  if (*(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) == 0) {
    iVar3 = FUN_00891268(0x13);
    if (iVar3 == 0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_10,&param_1);
      local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10,&DAT_00c857a8);
    }
    *(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) = iVar3;
  }
  puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 4) + uVar4 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)pcVar2;
    puVar1[1] = *(undefined4 *)(pcVar2 + 4);
    puVar1[2] = *(undefined4 *)(pcVar2 + 8);
    puVar1[3] = *(undefined4 *)(pcVar2 + 0xc);
    *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(pcVar2 + 0x10);
    *(char *)((int)puVar1 + 0x12) = pcVar2[0x12];
  }
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 1;
  return;
}

