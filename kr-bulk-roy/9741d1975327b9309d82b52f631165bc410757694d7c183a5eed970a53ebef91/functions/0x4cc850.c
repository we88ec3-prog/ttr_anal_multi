
undefined4 FUN_004cc850(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xfc) != 0) {
    if (*(int *)(*(int *)(in_ECX + 0xfc) + 0x24) != 0) {
      FUN_007be5f0();
    }
    if (*(int *)(in_ECX + 0xfc) != 0) {
      FUN_004c7db0();
      *(undefined4 *)(in_ECX + 0xfc) = 0;
    }
  }
  if ((*(int *)(in_ECX + 0xf0) != 0) && (*(int *)(*(int *)(in_ECX + 0xf0) + 0x24) != 0)) {
    FUN_007be5f0();
  }
  return 0;
}

