
void FUN_008fd220(void)

{
  char cVar1;
  int in_ECX;
  
  FUN_00572110();
  FUN_00572100();
  cVar1 = FUN_00572220();
  while (cVar1 != '\0') {
    thunk_FUN_00572200();
    FUN_008fd1a0();
    FUN_005721f0();
    cVar1 = FUN_00572220();
  }
  *(undefined1 *)(in_ECX + 0x2d) = 0;
  return;
}

