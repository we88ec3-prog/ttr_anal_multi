
undefined4 FUN_0080e750(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00891268(0x2002c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = MoonSound::COpenALStreamPlayer::vftable;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[0x8006] = 0x20000;
    puVar1[0x8007] = 0;
    puVar1[0x8009] = 0;
    puVar1[0x800a] = 0;
    *(undefined4 **)(in_ECX + 0x14) = puVar1;
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return 0;
}

