
void FUN_0049b410(void)

{
  int iVar1;
  float fVar2;
  DWORD DVar3;
  uint uVar4;
  int unaff_ESI;
  
  DVar3 = timeGetTime();
  *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
  iVar1 = *(int *)(unaff_ESI + 0xc);
  uVar4 = DVar3 - *(int *)(unaff_ESI + 0x10);
  *(DWORD *)(unaff_ESI + 0x14) = DVar3;
  if (999 < uVar4) {
    fVar2 = (float)(int)uVar4;
    if ((int)uVar4 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
    *(DWORD *)(unaff_ESI + 0x10) = DVar3;
    *(float *)(unaff_ESI + 0x1c) = (float)(iVar1 * 1000) / fVar2;
    FUN_00440830("%3.1f / %3.1f (%3.1f)",(double)*(float *)(unaff_ESI + 0x18),
                 (double)*(float *)(unaff_ESI + 0x1c),(double)*(float *)(unaff_ESI + 0x6c));
  }
  return;
}

