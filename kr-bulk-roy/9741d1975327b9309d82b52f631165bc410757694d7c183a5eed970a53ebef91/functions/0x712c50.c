
void FUN_00712c50(undefined4 *param_1)

{
  int unaff_ESI;
  
  FUN_007122a0();
  switch(*param_1) {
  case 1:
  case 3:
    break;
  case 2:
    FUN_00711ca0();
    break;
  default:
    FUN_00712aa0(1);
    break;
  case 10:
  }
  FUN_00711fe0();
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x18);
  FUN_00711fe0();
  param_1[5] = 0xffffffff;
  return;
}

