
/* WARNING: Removing unreachable block (ram,0x00545240) */
/* WARNING: Removing unreachable block (ram,0x00545241) */
/* WARNING: Removing unreachable block (ram,0x00545255) */

void FUN_00545210(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x34)) {
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x30);
  }
  return;
}

