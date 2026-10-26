
/* WARNING: Removing unreachable block (ram,0x0084d9a5) */

void FUN_0084d940(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x40) != 0) {
    FUN_0084d650(*(int *)(unaff_ESI + 0x40));
    *(undefined4 *)(unaff_ESI + 0x40) = 0;
  }
  iVar1 = *(int *)(unaff_ESI + 0x44);
  if (iVar1 != 0) {
    FUN_00857730(iVar1);
    FUN_0089120c(iVar1);
    *(undefined4 *)(unaff_ESI + 0x44) = 0;
  }
  if (*(int *)(unaff_ESI + 0x48) != *(int *)(unaff_ESI + 0x4c)) {
    uVar2 = FUN_008525a0(*(int *)(unaff_ESI + 0x4c));
    FUN_008510f0(*(undefined4 *)(unaff_ESI + 0x4c));
    *(undefined4 *)(unaff_ESI + 0x4c) = uVar2;
  }
  if (*(int *)(unaff_ESI + 0x28) != *(int *)(unaff_ESI + 0x2c)) {
    *(int *)(unaff_ESI + 0x2c) = *(int *)(unaff_ESI + 0x28);
  }
  if (*(int *)(unaff_ESI + 0x58) != *(int *)(unaff_ESI + 0x5c)) {
    uVar2 = FUN_004fa270(*(int *)(unaff_ESI + 0x58));
    *(undefined4 *)(unaff_ESI + 0x5c) = uVar2;
  }
  return;
}

