
undefined4 * FUN_0080fd30(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = FUN_00810ec0();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = iVar1;
      puVar2[4] = in_ECX + 0xc;
      *puVar2 = MoonSound::COpenALSource::vftable;
      puVar2[1] = 1;
      puVar2[3] = 0;
      return puVar2;
    }
  }
  return (undefined4 *)0x0;
}

