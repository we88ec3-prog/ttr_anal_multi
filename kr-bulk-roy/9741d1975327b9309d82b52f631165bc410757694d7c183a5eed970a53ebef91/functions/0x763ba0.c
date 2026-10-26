
void FUN_00763ba0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined **local_24 [4];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c818;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  in_ECX[1] = DAT_00fba828;
  local_8 = 0;
  *in_ECX = FoxUI::FXUIImageSetGroup::vftable;
  in_ECX[4] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    in_ECX[3] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
    *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
    *(undefined1 *)(in_ECX[3] + 0x14) = 1;
    *(undefined1 *)(in_ECX[3] + 0x15) = 1;
    ExceptionList = local_10;
    return;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

