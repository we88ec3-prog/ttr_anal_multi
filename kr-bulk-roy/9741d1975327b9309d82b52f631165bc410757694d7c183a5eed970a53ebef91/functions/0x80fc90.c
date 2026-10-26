
void FUN_0080fc90(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 local_8;
  
  local_8 = unaff_ESI[2];
  iVar1 = unaff_ESI[1];
  *unaff_ESI = MoonSound::COpenALBuffer::vftable;
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
  alDeleteBuffers(1,&local_8);
  FUN_00810c90();
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
  FUN_0089120c();
  return;
}

