
void FUN_008fd2e0(void)

{
  char cVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  FUN_00572110();
  FUN_00572100();
  cVar1 = FUN_00572220();
  while (cVar1 != '\0') {
    thunk_FUN_00572200();
    FUN_008fd1e0();
    FUN_005721f0();
    cVar1 = FUN_00572220();
  }
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x28))(1);
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  return;
}

