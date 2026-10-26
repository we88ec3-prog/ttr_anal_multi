
int FUN_008d86b0(undefined4 param_1,undefined4 *param_2)

{
  uint in_EAX;
  uint uVar1;
  void *unaff_EBX;
  void *_Dst;
  int local_8;
  
  uVar1 = 0;
  _Dst = (void *)0x0;
  local_8 = 0;
  if ((in_EAX != 0) && (*(char *)((int)unaff_EBX + (in_EAX - 1)) == '\0')) {
    in_EAX = in_EAX - 1;
  }
  if (in_EAX != 0) {
    do {
      if ((*(byte *)(uVar1 + (int)unaff_EBX) < 0x20) || (0x7f < *(byte *)(uVar1 + (int)unaff_EBX)))
      goto LAB_008d8717;
      uVar1 = uVar1 + 1;
    } while (uVar1 < in_EAX);
  }
  if (in_EAX != 0) {
    _Dst = (void *)FUN_008baee0(param_1,in_EAX + 1,&local_8);
    if (local_8 == 0) {
      FID_conflict__memcpy(_Dst,unaff_EBX,in_EAX);
      *(undefined1 *)((int)_Dst + in_EAX) = 0;
    }
  }
LAB_008d8717:
  *param_2 = _Dst;
  return local_8;
}

