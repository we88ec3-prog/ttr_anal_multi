
void FUN_00581eb0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091afae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX[6] != 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x28,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
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
    *in_ECX = puVar1;
    if ((uint)in_ECX[7] < 0x10) {
      puVar1 = in_ECX + 2;
    }
    else {
      puVar1 = (undefined4 *)in_ECX[2];
    }
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 0;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = 0xffffffff;
    }
    FUN_007383e0(puVar1);
  }
  ExceptionList = local_10;
  return;
}

