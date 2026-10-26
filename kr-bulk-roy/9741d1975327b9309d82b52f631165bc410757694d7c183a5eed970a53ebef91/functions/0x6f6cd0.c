
void FUN_006f6cd0(void)

{
  int *in_EAX;
  void *_Src;
  int iVar1;
  uint local_8;
  
  iVar1 = in_EAX[2];
  _Src = (void *)FUN_006f53f0(0xffffffff,&local_8);
  if (local_8 <= (uint)((int)in_EAX + (0x20c - *in_EAX))) {
    FID_conflict__memcpy((void *)*in_EAX,_Src,local_8);
    *in_EAX = *in_EAX + local_8;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -0x10;
    return;
  }
  iVar1 = FUN_006f6af0();
  if (iVar1 != 0) {
    FUN_006f52b0();
  }
  in_EAX[1] = in_EAX[1] + 1;
  FUN_006f6b60();
  return;
}

