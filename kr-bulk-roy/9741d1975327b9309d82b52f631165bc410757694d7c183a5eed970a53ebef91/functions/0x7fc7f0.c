
/* WARNING: Removing unreachable block (ram,0x007fc808) */
/* WARNING: Removing unreachable block (ram,0x007fc810) */
/* WARNING: Removing unreachable block (ram,0x007fc824) */

void FUN_007fc7f0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x78) != *(int *)(iVar1 + 0x7c))) {
    *(int *)(iVar1 + 0x7c) = *(int *)(iVar1 + 0x78);
  }
  return;
}

