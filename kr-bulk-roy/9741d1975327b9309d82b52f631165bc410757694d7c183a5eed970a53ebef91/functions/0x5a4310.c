
void FUN_005a4310(int param_1)

{
  undefined4 in_ECX;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf43db:
    FUN_005966c0();
    break;
  case 0xf43dc:
    FUN_00596830(in_ECX);
    break;
  case 0xf43fe:
    FUN_005974d0(in_ECX,0);
    break;
  case 0xf43ff:
    FUN_005978d0(in_ECX);
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4366:
    FUN_005a3e10();
    return;
  case 0xf4367:
    FUN_005a5240();
    return;
  case 0xf4377:
    FUN_005a40a0(in_ECX);
    return;
  case 0xf4378:
    FUN_005a41a0(in_ECX);
    return;
  case 0xf4379:
    FUN_005a3ef0();
    return;
  case 0xf43e3:
    FUN_005a4940();
    return;
  case 0xf43e4:
    FUN_005a49e0();
    return;
  case 0xf43e5:
    FUN_005a4af0();
    return;
  case 0xf43e6:
    FUN_005a5aa0(in_ECX);
  }
  return;
}

