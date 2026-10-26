
int FUN_008d3840(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_8 [4];
  
  iVar1 = FUN_008d1210(1,local_8);
  while (iVar1 != 0) {
    uVar2 = FUN_008d12a0();
    switch(uVar2) {
    case 0x14:
    case 0x15:
      return 0;
    default:
      goto LAB_008d38a9;
    case 0x32:
    case 0x33:
      iVar1 = FUN_008d3670();
      break;
    case 0x35:
      iVar1 = FUN_008d34d0();
      break;
    case 0x4b:
      goto switchD_008d3879_caseD_4b;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
switchD_008d3879_caseD_4b:
    iVar1 = FUN_008d1210(1,local_8);
  }
LAB_008d38a9:
  return 0xa0;
}

