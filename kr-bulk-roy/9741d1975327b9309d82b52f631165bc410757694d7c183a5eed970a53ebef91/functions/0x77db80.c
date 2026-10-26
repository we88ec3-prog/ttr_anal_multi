
void FUN_0077db80(void)

{
  int iVar1;
  int unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *(undefined4 *)(unaff_ESI + 0x214) = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 0x210) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 0x210) + 4) = *(int *)(unaff_ESI + 0x210);
    *(int *)(*(int *)(unaff_ESI + 0x210) + 8) = *(int *)(unaff_ESI + 0x210);
    *(undefined1 *)(*(int *)(unaff_ESI + 0x210) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 0x210) + 0x2d) = 1;
    *(undefined4 *)(unaff_ESI + 0x208) = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

