
/* WARNING: Removing unreachable block (ram,0x0087907e) */
/* WARNING: Removing unreachable block (ram,0x00879080) */
/* WARNING: Removing unreachable block (ram,0x0087909a) */

void FUN_00879050(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x18) != *(int *)(unaff_ESI + 0x1c)) {
    uVar1 = FUN_00789c40(*(int *)(unaff_ESI + 0x1c));
    *(undefined4 *)(unaff_ESI + 0x1c) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x28) != *(int *)(unaff_ESI + 0x2c)) {
    *(int *)(unaff_ESI + 0x2c) = *(int *)(unaff_ESI + 0x28);
  }
  return;
}

