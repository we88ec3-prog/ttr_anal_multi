
void FUN_0056fd00(void)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  in_ECX[8] = in_EAX;
  puVar1 = (undefined4 *)FUN_00891268(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *puVar1 = Graphics::CImageSprite::vftable;
  }
  in_ECX[7] = puVar1;
  if (in_ECX[4] != 0) {
    if (0xf < (uint)in_ECX[5]) {
      FUN_007383e0(*in_ECX);
      return;
    }
    FUN_007383e0(in_ECX);
  }
  return;
}

