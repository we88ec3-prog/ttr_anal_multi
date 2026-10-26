
void FUN_0071a810(int param_1)

{
  void *_Src;
  int iVar1;
  int *in_EAX;
  int *unaff_ESI;
  
  _Src = (void *)*unaff_ESI;
  if (_Src != (void *)0x0) {
    FID_conflict__memcpy((void *)((int)_Src - unaff_ESI[1]),_Src,*in_EAX - (int)_Src);
  }
  *in_EAX = *in_EAX + param_1;
  iVar1 = *in_EAX;
  unaff_ESI[1] = unaff_ESI[1] + param_1;
  *unaff_ESI = iVar1;
  return;
}

