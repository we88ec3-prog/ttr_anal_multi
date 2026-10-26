
/* WARNING: Removing unreachable block (ram,0x00444940) */
/* WARNING: Removing unreachable block (ram,0x00444941) */
/* WARNING: Removing unreachable block (ram,0x00444955) */

void FUN_00444910(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if (*(int *)(in_ECX + 0x30) != *(int *)(in_ECX + 0x34)) {
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x30);
  }
  return;
}

