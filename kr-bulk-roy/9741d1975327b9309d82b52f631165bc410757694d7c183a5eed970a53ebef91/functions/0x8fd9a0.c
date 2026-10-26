
void FUN_008fd9a0(void)

{
  char cVar1;
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x2d) != '\0') {
    FUN_00572110();
    FUN_00572100();
    cVar1 = FUN_00572220();
    while (cVar1 != '\0') {
      thunk_FUN_00572200();
      FUN_008fd1a0();
      FUN_005721f0();
      cVar1 = FUN_00572220();
    }
  }
  if (*(char *)(in_EAX + 0x2c) != '\0') {
    FUN_00572110();
    FUN_00572100();
    cVar1 = FUN_00572220();
    while (cVar1 != '\0') {
      thunk_FUN_00572200();
      FUN_008fd1e0();
      FUN_005721f0();
      cVar1 = FUN_00572220();
    }
  }
  FUN_00572110();
  FUN_00572100();
  cVar1 = FUN_00572220();
  while (cVar1 != '\0') {
    thunk_FUN_00572200();
    FUN_008fd4d0();
    FUN_005721f0();
    cVar1 = FUN_00572220();
  }
  FUN_005723f0();
  return;
}

