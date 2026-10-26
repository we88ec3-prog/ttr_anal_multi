
undefined4 * FUN_0080fc20(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x28));
  local_8 = 0;
  alGenBuffers(1,&local_8);
  FUN_00810c90();
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x28));
  iVar1 = local_8;
  if (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_00891268(0x10);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = in_EAX + 0xc;
      puVar2[2] = iVar1;
      *puVar2 = MoonSound::COpenALBuffer::vftable;
      puVar2[3] = 1;
      return puVar2;
    }
  }
  return (undefined4 *)0x0;
}

