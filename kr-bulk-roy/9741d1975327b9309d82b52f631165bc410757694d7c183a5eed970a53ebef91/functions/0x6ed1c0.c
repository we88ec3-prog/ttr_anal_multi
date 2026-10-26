
undefined4 FUN_006ed1c0(void)

{
  int iVar1;
  int in_EAX;
  void *pvVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  
  if (in_EAX < 0) {
    return 0x80070057;
  }
  if (in_EAX == 0) {
    if ((void *)*unaff_ESI != (void *)0x0) {
      _free((void *)*unaff_ESI);
      *unaff_ESI = 0;
    }
    unaff_ESI[2] = 0;
    unaff_ESI[1] = 0;
    return 0;
  }
  if (((void *)*unaff_ESI == (void *)0x0) || ((int)unaff_ESI[2] < in_EAX)) {
    iVar1 = unaff_ESI[2];
    iVar3 = 0x10;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
    if (in_EAX <= iVar1 + iVar3) {
      in_EAX = iVar1 + iVar3;
    }
    pvVar2 = _realloc((void *)*unaff_ESI,in_EAX * 4);
    if (pvVar2 == (void *)0x0) {
      return 0x8007000e;
    }
    *unaff_ESI = pvVar2;
    unaff_ESI[2] = in_EAX;
  }
  return 0;
}

