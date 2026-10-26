
void FUN_00713370(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  FUN_00711f00();
  unaff_ESI[8] = -1;
  if (*(int *)(iVar1 + 0x2c) < unaff_ESI[6] + 1) {
    uVar2 = FUN_00700790(unaff_ESI[4],*(undefined4 *)(iVar1 + 0xc),(int *)(iVar1 + 0x2c),4,
                         "code size overflow");
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  *(undefined4 *)(*(int *)(iVar1 + 0xc) + unaff_ESI[6] * 4) = param_1;
  if (*(int *)(iVar1 + 0x30) < unaff_ESI[6] + 1) {
    uVar2 = FUN_00700790(unaff_ESI[4],*(undefined4 *)(iVar1 + 0x14),(int *)(iVar1 + 0x30),4,
                         "code size overflow");
    *(undefined4 *)(iVar1 + 0x14) = uVar2;
  }
  *(undefined4 *)(*(int *)(iVar1 + 0x14) + unaff_ESI[6] * 4) = param_2;
  unaff_ESI[6] = unaff_ESI[6] + 1;
  return;
}

