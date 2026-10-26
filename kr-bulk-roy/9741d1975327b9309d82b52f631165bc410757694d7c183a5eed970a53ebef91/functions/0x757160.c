
void FUN_00757160(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x24) != 0) && (*(char *)(in_ECX + 0xe8) != '\0')) {
    *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x14c0) = 7;
  }
  return;
}

