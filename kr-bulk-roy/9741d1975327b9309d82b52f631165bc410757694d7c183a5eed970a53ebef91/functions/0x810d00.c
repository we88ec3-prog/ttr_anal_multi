
void FUN_00810d00(void)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  uint *unaff_EDI;
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 7));
  *unaff_EDI = in_EAX;
  iVar1 = FUN_0087dc3d(-(uint)((int)((ulonglong)in_EAX * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)in_EAX * 4));
  alGenSources(*unaff_EDI,iVar1);
  FUN_00810c90();
  iVar2 = 0;
  local_8 = iVar1;
  if (0 < (int)*unaff_EDI) {
    do {
      FUN_006de910(local_8);
      iVar2 = iVar2 + 1;
      local_8 = local_8 + 4;
    } while (iVar2 < (int)*unaff_EDI);
  }
  FUN_00891d3d(iVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 7));
  return;
}

