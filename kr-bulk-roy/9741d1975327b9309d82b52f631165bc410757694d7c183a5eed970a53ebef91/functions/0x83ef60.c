
void FUN_0083ef60(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  if ((in_EAX < DAT_00fbac90) && (DAT_00fbac8c <= in_EAX)) {
    iVar4 = (int)in_EAX - (int)DAT_00fbac8c;
    if (DAT_00fbac90 == DAT_00fbac94) {
      FUN_0083f2c0();
    }
    puVar2 = DAT_00fbac90;
    puVar1 = DAT_00fbac8c + (iVar4 >> 3) * 2;
    puVar3 = (undefined4 *)0x0;
    if (DAT_00fbac90 != (undefined4 *)0x0) {
      *DAT_00fbac90 = *puVar1;
      puVar2[1] = puVar1[1];
      DAT_00fbac90 = DAT_00fbac90 + 2;
      return;
    }
  }
  else {
    if (DAT_00fbac90 == DAT_00fbac94) {
      FUN_0083f2c0();
    }
    puVar3 = DAT_00fbac90;
    if (DAT_00fbac90 != (undefined4 *)0x0) {
      *DAT_00fbac90 = *in_EAX;
      puVar3[1] = in_EAX[1];
      puVar3 = DAT_00fbac90;
    }
  }
  DAT_00fbac90 = puVar3 + 2;
  return;
}

