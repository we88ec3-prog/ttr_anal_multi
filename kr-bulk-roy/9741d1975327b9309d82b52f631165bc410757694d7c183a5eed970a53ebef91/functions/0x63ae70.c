
void FUN_0063ae70(void)

{
  undefined4 uVar1;
  int in_EAX;
  int in_EDX;
  
  switch(*(undefined4 *)(in_EAX + 0x10)) {
  case 0xf424b:
    FUN_0063c410(*(undefined4 *)(in_EDX + 0xfc));
    return;
  case 0xf424c:
    FUN_0063cd40(*(undefined4 *)(in_EDX + 0xfc));
    return;
  case 0xf424d:
    FUN_0063df40();
    return;
  case 0xf424e:
    FUN_0063d9c0(*(undefined4 *)(in_EDX + 0x104));
    return;
  case 0xf424f:
    FUN_0063de70(*(undefined4 *)(in_EDX + 0x104));
    return;
  case 0xf4250:
    FUN_0063df40();
    return;
  case 0xf4251:
    FUN_0063fc90(*(undefined4 *)(in_EDX + 0x100));
    return;
  case 0xf4252:
    uVar1 = *(undefined4 *)(in_EDX + 0x100);
    FUN_0063f310();
    FUN_0063f470(uVar1);
    return;
  case 0xf4253:
    FUN_006400c0();
    return;
  case 0xf4254:
    FUN_0063f310();
    break;
  case 0xf4255:
    FUN_00640110();
    return;
  }
  return;
}

