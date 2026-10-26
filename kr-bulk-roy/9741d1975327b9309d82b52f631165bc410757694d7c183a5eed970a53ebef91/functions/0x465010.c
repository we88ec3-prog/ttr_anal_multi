
void FUN_00465010(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined **local_24 [4];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ba66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007659c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *in_ECX = FUI::CLinkTextBox::vftable;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  local_8 = 1;
  in_ECX[0x5e] = 0;
  iVar1 = FUN_00891268(0x50);
  if (iVar1 != 0) {
    in_ECX[0x5d] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(in_ECX[0x5d] + 4) = in_ECX[0x5d];
    *(undefined4 *)(in_ECX[0x5d] + 8) = in_ECX[0x5d];
    *(undefined1 *)(in_ECX[0x5d] + 0x4c) = 1;
    *(undefined1 *)(in_ECX[0x5d] + 0x4d) = 1;
    in_ECX[0x60] = 0;
    ExceptionList = local_10;
    return;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

