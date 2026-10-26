
void FUN_005b3e70(int param_1)

{
  int in_ECX;
  
  FUN_005b7f80(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf439e:
    FUN_005b4680(in_ECX);
    break;
  case 0xf43fc:
    FUN_005b42b0();
    return;
  case 0xf4404:
    FUN_006b3b80();
    FUN_00427fb0(*(undefined4 *)(in_ECX + 0x30c));
    return;
  case 0xf4405:
    FUN_006b3b80();
    return;
  }
  return;
}

