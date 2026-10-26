
undefined4 FUN_008d1370(int param_1)

{
  int in_EAX;
  int iVar1;
  undefined1 local_8 [4];
  
  while (in_EAX != 0) {
    in_EAX = in_EAX + -1;
    iVar1 = FUN_008d1210(1,0);
    if (iVar1 == 0) {
      return 0xa0;
    }
  }
  iVar1 = FUN_008d1210(1,local_8);
  while( true ) {
    if (iVar1 == 0) {
      return 0xa0;
    }
    iVar1 = FUN_008d12a0();
    if ((iVar1 == param_1) || (iVar1 == 0x14)) break;
    iVar1 = FUN_008d1210(1,local_8);
  }
  return 0;
}

