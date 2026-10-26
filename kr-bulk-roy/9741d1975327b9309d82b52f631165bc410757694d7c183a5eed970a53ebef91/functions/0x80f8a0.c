
void FUN_0080f8a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_EDI = MoonSound::COpenALDriver::vftable;
  unaff_EDI[3] = 0;
  puVar1 = unaff_EDI + 4;
  *puVar1 = 0;
  puVar2 = (undefined4 *)FUN_00891268(8);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar1 = puVar2;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    unaff_EDI[5] = 0;
    unaff_EDI[6] = 0;
    unaff_EDI[7] = 0;
    unaff_EDI[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 10));
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

