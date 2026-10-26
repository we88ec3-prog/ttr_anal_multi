
void FUN_0073ce20(void)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  short *in_ECX;
  undefined4 ***pppuVar4;
  undefined4 extraout_EDX;
  undefined4 ***pppuVar5;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar6;
  uint uVar7;
  undefined2 *unaff_EDI;
  undefined4 uVar8;
  undefined4 **local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar8 = 0;
  if (in_ECX == (short *)0x0) {
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    uVar6 = extraout_EDX;
  }
  else {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
    psVar2 = in_ECX;
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    FUN_00402160(in_ECX,(int)psVar2 - (int)(in_ECX + 1) >> 1);
    local_8 = 0;
    uVar3 = 0;
    pppuVar4 = (undefined4 ***)local_30[0];
    uVar7 = local_1c;
    if (local_20 != 0) {
      do {
        pppuVar5 = pppuVar4;
        if (uVar7 < 8) {
          pppuVar5 = local_30;
        }
        if (*(ushort *)((int)pppuVar5 + uVar3 * 2) < 0x100) {
          pppuVar5 = pppuVar4;
          if (uVar7 < 8) {
            pppuVar5 = local_30;
          }
          if (0x7e < *(ushort *)((int)pppuVar5 + uVar3 * 2)) {
            if (uVar7 < 8) {
              pppuVar4 = local_30;
            }
            *(undefined2 *)((int)pppuVar4 + uVar3 * 2) = 0x20;
            pppuVar4 = (undefined4 ***)local_30[0];
            uVar7 = local_1c;
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < local_20);
    }
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    FUN_00402800(local_30);
    uVar6 = extraout_EDX_00;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
      uVar6 = extraout_EDX_01;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar6,uVar8);
  return;
}

