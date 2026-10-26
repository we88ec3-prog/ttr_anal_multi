
void FUN_00712bb0(undefined4 *param_1)

{
  int unaff_ESI;
  
  FUN_007122a0();
  switch(*param_1) {
  case 2:
  case 4:
  case 5:
    break;
  case 3:
    FUN_00711ca0();
    break;
  default:
    FUN_00712aa0(0);
    break;
  case 10:
    FUN_00712a50();
  }
  FUN_00711fe0();
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x18);
  FUN_00711fe0();
  param_1[4] = 0xffffffff;
  return;
}

