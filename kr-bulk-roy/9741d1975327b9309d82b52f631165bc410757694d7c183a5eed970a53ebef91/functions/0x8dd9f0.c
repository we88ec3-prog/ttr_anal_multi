
int FUN_008dd9f0(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int *unaff_ESI;
  int unaff_EDI;
  int local_8;
  
  uVar1 = *(undefined4 *)(unaff_EDI + 0x1c);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  *unaff_ESI = unaff_EDI;
  iVar4 = FUN_008b9850();
  unaff_ESI[1] = iVar4;
  uVar3 = FUN_008b9ab0();
  if (local_8 != 0) goto LAB_008ddae2;
  if (uVar3 == 0) {
    return 0;
  }
  bVar2 = FUN_008b9a40();
  if ((byte)(bVar2 - 1) < 4) {
    *(byte *)(unaff_ESI + 3) = bVar2;
    unaff_ESI[2] = (uint)uVar3;
    unaff_ESI[4] = (uVar3 + 1) * (uint)bVar2 + 3 + unaff_ESI[1];
    local_8 = FUN_008b9820();
    if (local_8 != 0) goto LAB_008ddae2;
    iVar4 = FUN_008dd9a0();
    if (iVar4 != 0) {
      unaff_ESI[5] = iVar4 + -1;
      if (param_1 == '\0') {
        local_8 = FUN_008b9820();
        if (local_8 == 0) {
          return 0;
        }
      }
      else {
        local_8 = FUN_008bc7a0();
        if (local_8 == 0) {
          return 0;
        }
      }
      goto LAB_008ddae2;
    }
  }
  local_8 = 8;
LAB_008ddae2:
  FUN_008b9f80(uVar1,unaff_ESI[6]);
  unaff_ESI[6] = 0;
  return local_8;
}

