
void FUN_007a9d90(void)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined **local_14 [3];
  undefined4 local_8;
  
  uVar1 = *in_EAX;
  iVar2 = in_EAX[1];
  local_8 = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  if (iVar2 != 0) {
    cVar3 = FUN_0047c250();
    if (cVar3 != '\0') {
      FUN_007a31c0(uVar1,iVar2);
      return;
    }
  }
  FUN_00891010();
  local_14[0] = std::tr1::bad_weak_ptr::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c858ac);
}

