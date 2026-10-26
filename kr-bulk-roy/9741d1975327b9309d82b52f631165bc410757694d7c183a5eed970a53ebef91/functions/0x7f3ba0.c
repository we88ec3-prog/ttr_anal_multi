
void FUN_007f3ba0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  uVar1 = *(undefined4 *)(param_1 + 8);
  uVar3 = FUN_007f3e80();
  FUN_007f40b0(uVar3,uVar1);
  unaff_EDI[2] = uVar3;
  puVar4 = (undefined4 *)FUN_00891268(0x10);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0xc);
    *puVar4 = *puVar2;
    puVar4[1] = puVar2[1];
    puVar4[2] = puVar2[2];
    puVar4[3] = puVar2[3];
  }
  unaff_EDI[3] = puVar4;
  unaff_EDI[4] = 0;
  unaff_EDI[10] = 0xf;
  unaff_EDI[9] = 0;
  *(undefined1 *)(unaff_EDI + 5) = 0;
  return;
}

