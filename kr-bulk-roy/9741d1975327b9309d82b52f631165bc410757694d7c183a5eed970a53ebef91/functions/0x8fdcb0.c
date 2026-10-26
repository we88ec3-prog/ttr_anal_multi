
void FUN_008fdcb0(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    FUN_00572110();
    FUN_00572100();
    cVar1 = FUN_00572220();
    while (cVar1 != '\0') {
      FUN_00572200();
      FUN_008fdc80();
      FUN_00572210();
      cVar1 = FUN_00572220();
    }
  }
  return;
}

