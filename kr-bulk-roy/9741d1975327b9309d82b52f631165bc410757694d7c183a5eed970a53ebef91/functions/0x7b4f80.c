
void FUN_007b4f80(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  if ((in_EAX < DAT_00fbab58) && (DAT_00fbab54 <= in_EAX)) {
    iVar2 = (int)in_EAX - (int)DAT_00fbab54;
    if (DAT_00fbab58 == DAT_00fbab5c) {
      FUN_007b5010();
    }
    puVar1 = (undefined4 *)0x0;
    if (DAT_00fbab58 != (undefined4 *)0x0) {
      *DAT_00fbab58 = DAT_00fbab54[iVar2 >> 2];
      DAT_00fbab58 = DAT_00fbab58 + 1;
      return;
    }
  }
  else {
    if (DAT_00fbab58 == DAT_00fbab5c) {
      FUN_007b5010();
    }
    puVar1 = DAT_00fbab58;
    if (DAT_00fbab58 != (undefined4 *)0x0) {
      *DAT_00fbab58 = *in_EAX;
      puVar1 = DAT_00fbab58;
    }
  }
  DAT_00fbab58 = puVar1 + 1;
  return;
}

