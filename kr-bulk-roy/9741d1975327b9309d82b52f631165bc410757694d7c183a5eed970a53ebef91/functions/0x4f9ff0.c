
void FUN_004f9ff0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  if ((in_EAX < DAT_00fe1a94) && (DAT_00fe1a90 <= in_EAX)) {
    iVar4 = (int)in_EAX - (int)DAT_00fe1a90;
    if (DAT_00fe1a94 == DAT_00fe1a98) {
      FUN_004fa0c0();
    }
    puVar2 = DAT_00fe1a94;
    puVar1 = DAT_00fe1a90 + (iVar4 / 0x14) * 5;
    puVar3 = (undefined4 *)0x0;
    if (DAT_00fe1a94 != (undefined4 *)0x0) {
      *DAT_00fe1a94 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar1[2];
      puVar2[3] = puVar1[3];
      puVar2[4] = puVar1[4];
      DAT_00fe1a94 = DAT_00fe1a94 + 5;
      return;
    }
  }
  else {
    if (DAT_00fe1a94 == DAT_00fe1a98) {
      FUN_004fa0c0();
    }
    puVar3 = DAT_00fe1a94;
    if (DAT_00fe1a94 != (undefined4 *)0x0) {
      *DAT_00fe1a94 = *in_EAX;
      puVar3[1] = in_EAX[1];
      puVar3[2] = in_EAX[2];
      puVar3[3] = in_EAX[3];
      puVar3[4] = in_EAX[4];
      puVar3 = DAT_00fe1a94;
    }
  }
  DAT_00fe1a94 = puVar3 + 5;
  return;
}

