
void FUN_00550780(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  if (((*(int *)(unaff_ESI + 0x24) != 0) && (local_8 = *(int *)(unaff_ESI + 0x6c), local_8 != 0)) &&
     (*(int *)(unaff_ESI + 0x70) != 0)) {
    iVar1 = FUN_0040f060();
    FUN_0082ef00(&local_8);
    if ((local_c == *(int *)(iVar1 + 0xc)) || (*(int **)(local_c + 0x10) == (int *)0x0))
    goto LAB_00550810;
    puVar2 = (undefined4 *)(**(code **)(**(int **)(local_c + 0x10) + 0x4c))();
    iVar1 = *(int *)(unaff_ESI + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *puVar2;
    *(undefined4 *)(iVar1 + 0x2c) = puVar2[1];
    *(undefined4 *)(iVar1 + 0x30) = puVar2[2];
    *(undefined4 *)(iVar1 + 0x70) = 1;
    if (*(int **)(unaff_ESI + 0x28) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_ESI + 0x28) + 0x14))(puVar2);
    }
  }
  if (*(int *)(unaff_ESI + 0x24) == 0) {
    return;
  }
  if (*(int *)(*(int *)(unaff_ESI + 0x24) + 0x6c) == 0) {
    return;
  }
  if (*(int *)(unaff_ESI + 0x78) != 0) {
    *(int *)(unaff_ESI + 0x78) = *(int *)(unaff_ESI + 0x78) + -1;
    return;
  }
LAB_00550810:
  *(undefined4 *)(unaff_ESI + 0x74) = 1;
  return;
}

