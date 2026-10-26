
undefined4 FUN_00782b60(void)

{
  char cVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x8c) == '\0') &&
     (*(int *)(*(int *)(**(int **)(in_ECX + 0x84) + 4) + 0xc + (int)*(int **)(in_ECX + 0x84)) == 0))
  {
    cVar1 = FUN_00782110(in_ECX);
    if (cVar1 != '\0') {
      FUN_007821b0(in_ECX,*(undefined4 *)(in_ECX + 0x84));
      FUN_00782370(in_ECX,*(undefined4 *)(in_ECX + 0x84));
      *(undefined1 *)(in_ECX + 0x8c) = 1;
      return 1;
    }
  }
  return 0;
}

