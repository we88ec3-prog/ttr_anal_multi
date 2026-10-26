
undefined4 * FUN_00867d70(undefined4 *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = gbParam::vftable;
  cVar2 = FUN_00867750();
  if (cVar2 == '\0') {
    param_1[1] = *(undefined4 *)(iVar1 + 4);
    FUN_008673c0();
    switch(param_1[1]) {
    case 1:
      FUN_00867410(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 2:
      FUN_00867670(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 3:
      FUN_00867470(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 4:
      param_2 = (int)**(char **)(param_2 + 8);
      FUN_00867670(&param_2);
      return param_1;
    case 5:
      FUN_008674a0();
      return param_1;
    case 6:
      FUN_008674e0();
      return param_1;
    case 7:
      FUN_00867520();
      return param_1;
    case 8:
      FUN_00867570(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 9:
      FUN_008675d0(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 10:
      FUN_00867440(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 0xb:
      FUN_00867630(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 0xc:
      FUN_00867670(*(undefined4 *)(param_2 + 8));
      return param_1;
    case 0xd:
      FUN_00867670(*(undefined4 *)(param_2 + 8));
    }
  }
  return param_1;
}

