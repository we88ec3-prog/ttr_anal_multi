
void FUN_004dc160(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 *unaff_EDI;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0090b471;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = *(undefined4 *)(in_ECX + 4);
    puVar3[1] = *(undefined4 *)(in_ECX + 4);
    puVar3[2] = *(undefined4 *)(in_ECX + 4);
    *(undefined2 *)(puVar3 + 8) = 0;
    if (puVar3 + 3 != (undefined4 *)0x0) {
      *(undefined1 *)(puVar3 + 3) = *unaff_EDI;
      puVar1 = puVar3 + 4;
      puVar2 = (undefined4 *)(unaff_EDI + 4);
      *puVar1 = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      if (puVar1 != puVar2) {
        *puVar1 = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        *puVar1 = *puVar2;
        puVar3[5] = *(undefined4 *)(unaff_EDI + 8);
        puVar3[6] = *(undefined4 *)(unaff_EDI + 0xc);
        *puVar2 = 0;
        *(undefined4 *)(unaff_EDI + 8) = 0;
        *(undefined4 *)(unaff_EDI + 0xc) = 0;
      }
    }
    ExceptionList = local_10;
    return;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

