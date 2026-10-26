
void FUN_00804c70(void)

{
  bool bVar1;
  DWORD DVar2;
  int unaff_ESI;
  uint uVar3;
  
  DVar2 = timeGetTime();
  *(DWORD *)(unaff_ESI + 0x48) = DVar2;
  if (*(int *)(unaff_ESI + 0xa4) == 0) {
    FUN_00804d20(unaff_ESI);
  }
  DVar2 = timeGetTime();
  bVar1 = 0x21 < *(int *)(unaff_ESI + 0x88) - DVar2;
  if (bVar1) {
    *(DWORD *)(unaff_ESI + 0x88) = DVar2;
  }
  uVar3 = 0;
  if (*(int *)(unaff_ESI + 0x98) - *(int *)(unaff_ESI + 0x94) >> 2 != 0) {
    do {
      *(bool *)(*(int *)(*(int *)(unaff_ESI + 0x94) + uVar3 * 4) + 0x10) = bVar1;
      SetEvent(*(HANDLE *)(*(int *)(*(int *)(unaff_ESI + 0x94) + uVar3 * 4) + 8));
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(unaff_ESI + 0x98) - *(int *)(unaff_ESI + 0x94) >> 2));
  }
  WaitForMultipleObjects(*(DWORD *)(unaff_ESI + 0xa4),*(HANDLE **)(unaff_ESI + 0xa8),1,0xffffffff);
  DVar2 = timeGetTime();
  *(DWORD *)(unaff_ESI + 0x4c) = DVar2;
  return;
}

