
undefined4 FUN_007119e0(void)

{
  int in_EAX;
  int iVar1;
  
  switch(*(undefined4 *)(in_EAX + 0x10)) {
  case 0x102:
    FUN_00700740();
    FUN_00710010();
    return 1;
  case 0x103:
    FUN_00700740();
    FUN_0070fe00();
    FUN_0070d8b0();
    return 0;
  default:
    FUN_00711820();
    return 0;
  case 0x108:
    FUN_00710ea0(*(undefined4 *)(in_EAX + 4));
    return 0;
  case 0x109:
    FUN_00711780(*(undefined4 *)(in_EAX + 4));
    return 0;
  case 0x10a:
    FUN_00711150();
    return 0;
  case 0x10c:
    break;
  case 0x110:
    FUN_00710320();
    return 0;
  case 0x111:
    FUN_007118a0();
    return 1;
  case 0x115:
    FUN_007100b0();
    return 0;
  }
  FUN_00700740();
  if ((*(int *)(in_EAX + 0x10) == 0x109) && (iVar1 = FUN_0070d800(), iVar1 != 0)) {
    FUN_007114d0();
    return 0;
  }
  FUN_007115c0();
  return 0;
}

