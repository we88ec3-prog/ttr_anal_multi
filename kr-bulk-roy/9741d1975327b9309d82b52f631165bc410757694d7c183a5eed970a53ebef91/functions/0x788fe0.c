
void FUN_00788fe0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar2 = unaff_EDI[1];
  if ((in_EAX < uVar2) && (uVar3 = *unaff_EDI, uVar3 <= in_EAX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00788100(1);
    }
    iVar1 = *unaff_EDI + ((int)(in_EAX - uVar3) / 0x18) * 0x18;
    puVar4 = (undefined4 *)unaff_EDI[1];
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = gbKey<float>::vftable;
      puVar4[1] = *(undefined4 *)(iVar1 + 4);
      puVar4[2] = *(undefined4 *)(iVar1 + 8);
      puVar4[3] = *(undefined4 *)(iVar1 + 0xc);
      *puVar4 = gbBezKey<float>::vftable;
      puVar4[4] = *(undefined4 *)(iVar1 + 0x10);
      puVar4[5] = *(undefined4 *)(iVar1 + 0x14);
      puVar4[3] = 0;
      unaff_EDI[1] = unaff_EDI[1] + 0x18;
      return;
    }
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00788100(1);
    }
    puVar4 = (undefined4 *)unaff_EDI[1];
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = gbKey<float>::vftable;
      puVar4[1] = *(undefined4 *)(in_EAX + 4);
      puVar4[2] = *(undefined4 *)(in_EAX + 8);
      puVar4[3] = *(undefined4 *)(in_EAX + 0xc);
      *puVar4 = gbBezKey<float>::vftable;
      puVar4[4] = *(undefined4 *)(in_EAX + 0x10);
      puVar4[5] = *(undefined4 *)(in_EAX + 0x14);
      puVar4[3] = 0;
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x18;
  return;
}

