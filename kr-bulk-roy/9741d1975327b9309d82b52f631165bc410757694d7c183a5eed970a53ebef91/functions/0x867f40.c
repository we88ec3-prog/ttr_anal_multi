
void FUN_00867f40(void)

{
  int unaff_ESI;
  undefined4 uVar1;
  
  switch(*(undefined4 *)(unaff_ESI + 4)) {
  case 1:
  case 6:
  case 9:
  case 10:
  case 0xd:
    uVar1 = *(undefined4 *)(unaff_ESI + 8);
    break;
  case 2:
  case 7:
  case 0xb:
    uVar1 = *(undefined4 *)(unaff_ESI + 8);
    break;
  case 3:
  case 5:
  case 8:
  case 0xc:
    uVar1 = *(undefined4 *)(unaff_ESI + 8);
    break;
  case 4:
    FUN_00891d3d(*(undefined4 *)(unaff_ESI + 8));
  default:
    goto switchD_00867f49_default;
  }
  FUN_0089120c(uVar1);
switchD_00867f49_default:
  *(undefined4 *)(unaff_ESI + 8) = 0;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    FUN_00891d3d(*(int *)(unaff_ESI + 0xc));
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
  }
  return;
}

