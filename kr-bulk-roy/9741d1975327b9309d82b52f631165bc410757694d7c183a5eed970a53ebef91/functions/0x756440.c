
void FUN_00756440(void)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x44) != 0) && (*(int *)(in_ECX + 0x24) != 0)) &&
     (*(char *)(*(int *)(in_ECX + 0x44) + 0xea) != '\0')) {
    *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14c0) = 8;
  }
  return;
}

