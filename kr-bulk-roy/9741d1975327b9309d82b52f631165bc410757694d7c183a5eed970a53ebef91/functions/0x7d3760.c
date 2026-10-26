
void FUN_007d3760(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int local_10;
  int local_c;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    local_10 = 0;
    local_c = 0;
    FUN_007c5f40(*(int *)(unaff_ESI + 0x10),&local_10);
    uVar2 = local_c - local_10 >> 0x1f;
    iVar1 = (local_c - local_10 ^ uVar2) - uVar2;
    *(float *)(unaff_ESI + 0x24) = (float)iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(unaff_ESI + 0x20) = 1;
    }
  }
  return;
}

