
void FUN_007134a0(void)

{
  int iVar1;
  undefined4 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_EDI = Package::CPackageMgr::vftable;
  unaff_EDI[0x41] = 0;
  unaff_EDI[0x43] = 0;
  iVar1 = FUN_00891268(0x118);
  if (iVar1 != 0) {
    unaff_EDI[0x42] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_EDI[0x42] + 4) = unaff_EDI[0x42];
    _memset(unaff_EDI + 1,0,0x100);
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

