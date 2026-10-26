
void FUN_00867fd0(int param_1,int param_2)

{
  FUN_00867f40();
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  FUN_008673c0();
  switch(*(undefined4 *)(param_1 + 4)) {
  case 1:
    FUN_00867410(*(undefined4 *)(param_2 + 8));
    return;
  case 2:
    FUN_00867670(*(undefined4 *)(param_2 + 8));
    return;
  case 3:
    FUN_00867470(*(undefined4 *)(param_2 + 8));
    return;
  case 4:
    param_2 = (int)**(char **)(param_2 + 8);
    FUN_00867670(&param_2);
    return;
  case 5:
    FUN_008674a0();
    return;
  case 6:
    FUN_008674e0();
    return;
  case 7:
    FUN_00867520();
    return;
  case 8:
    FUN_00867570(*(undefined4 *)(param_2 + 8));
    return;
  case 9:
    FUN_008675d0(*(undefined4 *)(param_2 + 8));
    return;
  case 10:
    FUN_00867440(*(undefined4 *)(param_2 + 8));
    return;
  case 0xb:
    FUN_00867630(*(undefined4 *)(param_2 + 8));
    return;
  case 0xc:
    FUN_00867670(*(undefined4 *)(param_2 + 8));
    return;
  case 0xd:
    FUN_00867670(*(undefined4 *)(param_2 + 8));
  }
  return;
}

