
void FUN_00785470(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (uVar2 = *unaff_EDI, uVar2 <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_007862b0(1);
    }
    in_EAX = ((int)(in_EAX - uVar2) / 0x60) * 0x60 + *unaff_EDI;
  }
  else if (uVar1 == unaff_EDI[2]) {
    FUN_007862b0(1);
  }
  puVar3 = (undefined4 *)unaff_EDI[1];
  if (puVar3 != (undefined4 *)0x0) {
    FUN_007852a0();
    *puVar3 = gbTCBRotKey::vftable;
    puVar3[0x14] = *(undefined4 *)(in_EAX + 0x50);
    puVar3[0x15] = *(undefined4 *)(in_EAX + 0x54);
    puVar3[0x16] = *(undefined4 *)(in_EAX + 0x58);
    puVar3[0x17] = *(undefined4 *)(in_EAX + 0x5c);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x60;
  return;
}

