
int FUN_008ebfc0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  uint *unaff_EBX;
  uint unaff_ESI;
  undefined4 *unaff_EDI;
  int local_8;
  
  if (*unaff_EBX < unaff_ESI) {
    local_8 = in_ECX;
    uVar1 = FUN_008bc7d0(param_1,1,*unaff_EBX * in_ECX,in_ECX * unaff_ESI,*unaff_EDI,&local_8);
    *unaff_EDI = uVar1;
    if (local_8 != 0) {
      return local_8;
    }
    *unaff_EBX = unaff_ESI;
  }
  return 0;
}

