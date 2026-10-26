
/* WARNING: Removing unreachable block (ram,0x008790ca) */
/* WARNING: Removing unreachable block (ram,0x008790d0) */
/* WARNING: Removing unreachable block (ram,0x008790ea) */

void FUN_008790b0(void)

{
  int in_EAX;
  int in_ECX;
  
  if (1 < in_EAX) {
    if (*(int *)(in_ECX + 0x28) != *(int *)(in_ECX + 0x2c)) {
      *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x28);
    }
    FUN_008792b0();
  }
  return;
}

