
void FUN_0070f860(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_EDI;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0x7b:
    FUN_0070e950(param_1);
    return;
  default:
    FUN_0070f580(param_1);
    return;
  case 0x107:
    *unaff_EDI = 3;
    unaff_EDI[2] = 0;
    break;
  case 0x109:
    FUN_00700740();
    FUN_0070ef60(param_1);
    return;
  case 0x10d:
    *unaff_EDI = 1;
    unaff_EDI[2] = 0;
    break;
  case 0x113:
    *unaff_EDI = 2;
    unaff_EDI[2] = 0;
    break;
  case 0x117:
    piVar2 = *(int **)(param_1 + 0x30);
    iVar3 = *piVar2;
    if (*(char *)(iVar3 + 0x4a) == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(param_1,"cannot use \'...\' outside a vararg function",
                   *(undefined4 *)(param_1 + 0x10));
    }
    pbVar1 = (byte *)(iVar3 + 0x4a);
    *pbVar1 = *pbVar1 & 0xfb;
    uVar4 = FUN_00713370(0x800025,*(undefined4 *)(piVar2[3] + 8));
    *unaff_EDI = 0xe;
    unaff_EDI[2] = uVar4;
    break;
  case 0x11c:
    unaff_EDI[2] = 0;
    unaff_EDI[4] = 0xffffffff;
    unaff_EDI[5] = 0xffffffff;
    *unaff_EDI = 5;
    *(undefined8 *)(unaff_EDI + 2) = *(undefined8 *)(param_1 + 0x18);
    FUN_00700740();
    return;
  case 0x11e:
    FUN_0070d9d0();
    FUN_00700740();
    return;
  }
  unaff_EDI[5] = 0xffffffff;
  unaff_EDI[4] = 0xffffffff;
  FUN_00700740();
  return;
}

