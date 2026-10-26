
undefined4 * FUN_0080fd80(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = MoonSound::COpenALListener::vftable;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

