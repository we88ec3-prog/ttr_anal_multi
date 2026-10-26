
void FUN_004cb230(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 in_ECX;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = CActorState::vftable;
  unaff_ESI[1] = in_EAX;
  unaff_ESI[2] = in_ECX;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[8] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    unaff_ESI[7] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_ESI[7] + 4) = unaff_ESI[7];
    *(undefined4 *)(unaff_ESI[7] + 8) = unaff_ESI[7];
    *(undefined1 *)(unaff_ESI[7] + 0x14) = 1;
    *(undefined1 *)(unaff_ESI[7] + 0x15) = 1;
    unaff_ESI[10] = 0;
    unaff_ESI[0xb] = 0;
    unaff_ESI[0xc] = 0;
    unaff_ESI[0xd] = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

