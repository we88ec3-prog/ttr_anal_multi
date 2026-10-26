
void FUN_00596630(int param_1)

{
  undefined4 in_ECX;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf43db:
    FUN_005966c0();
    return;
  case 0xf43dc:
    FUN_00596830(in_ECX);
    return;
  case 0xf43fe:
    FUN_005974d0(in_ECX,0);
    return;
  case 0xf43ff:
    FUN_005978d0(in_ECX);
  }
  return;
}

