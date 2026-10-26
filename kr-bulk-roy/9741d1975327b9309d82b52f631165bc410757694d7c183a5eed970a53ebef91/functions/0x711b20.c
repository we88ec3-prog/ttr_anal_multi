
void FUN_00711b20(int param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x34);
  psVar1 = (short *)(iVar2 + 0x34);
  *psVar1 = *psVar1 + 1;
  if (200 < *(ushort *)(iVar2 + 0x34)) {
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,"chunk has too many syntax levels",0);
  }
  do {
    switch(*(undefined4 *)(param_1 + 0x10)) {
    case 0x104:
    case 0x105:
    case 0x106:
    case 0x114:
    case 0x11f:
      goto switchD_00711b68_caseD_104;
    }
    iVar2 = FUN_007119e0();
    if (*(int *)(param_1 + 0x10) == 0x3b) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
      if (*(int *)(param_1 + 0x20) == 0x11f) {
        uVar3 = FUN_006ffec0(param_1 + 0x18);
        *(undefined4 *)(param_1 + 0x10) = uVar3;
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x20) = 0x11f;
      }
    }
    *(uint *)(*(int *)(param_1 + 0x30) + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x30) + 0x32);
  } while (iVar2 == 0);
switchD_00711b68_caseD_104:
  psVar1 = (short *)(*(int *)(param_1 + 0x34) + 0x34);
  *psVar1 = *psVar1 + -1;
  return;
}

