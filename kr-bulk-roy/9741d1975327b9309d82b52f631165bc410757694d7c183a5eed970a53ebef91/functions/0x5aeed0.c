
void FUN_005aeed0(int param_1)

{
  undefined4 in_ECX;
  
  FUN_005ac600(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4299:
    FUN_005aef80(in_ECX);
    return;
  case 0xf429a:
    FUN_005af050();
    return;
  case 0xf429b:
    FUN_005af270();
    break;
  case 0xf42a5:
    FUN_005af180(in_ECX);
    return;
  case 0xf42a6:
    FUN_005af1d0();
    return;
  case 0xf42a7:
    FUN_005af210(in_ECX);
    return;
  }
  return;
}

