
void FUN_007845e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *(undefined4 *)(unaff_ESI + 4);
    puVar2[1] = *(undefined4 *)(unaff_ESI + 4);
    puVar2[2] = *(undefined4 *)(unaff_ESI + 4);
    *(undefined2 *)(puVar2 + 5) = 0;
    if (puVar2 + 3 != (undefined4 *)0x0) {
      puVar2[3] = *unaff_EDI;
      iVar1 = unaff_EDI[1];
      puVar2[4] = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
      }
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

