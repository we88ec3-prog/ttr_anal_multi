
void FUN_006a51d0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if ((*(int *)(*(int *)(in_EAX + 0xf8) + 0xcc) != 0) &&
     (*(int *)(*(int *)(in_EAX + 0xf8) + 0xd8) != 0)) {
    uVar1 = FUN_005f55a0();
    switch(uVar1) {
    case 0:
      FUN_006a6600(*(undefined4 *)(in_EAX + 0xfc));
      return;
    case 1:
      FUN_00450b80(*(undefined4 *)(in_EAX + 0x108));
      return;
    case 2:
      FUN_006a71a0();
      FUN_006a7660();
      return;
    case 3:
      FUN_006a7ec0(*(undefined4 *)(in_EAX + 0x104));
    }
  }
  return;
}

