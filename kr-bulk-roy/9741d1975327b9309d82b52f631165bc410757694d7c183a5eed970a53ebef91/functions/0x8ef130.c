
void FUN_008ef130(int param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte local_5;
  
  if (*(short *)(param_1 + 0x9a) != 0) {
    if ((*(byte *)(param_1 + 0x170) & 1) == 0) {
      local_5 = 0x10;
    }
    else {
      local_5 = 8;
    }
    sVar3 = 0;
    uVar5 = 0;
    do {
      uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0xac) + sVar3 * 2) -
              (uint)*(ushort *)(param_1 + 0xb0);
      if (*(ushort *)(param_1 + 0x98) <= uVar4) {
        uVar4 = *(ushort *)(param_1 + 0x98) - 1;
      }
      uVar7 = uVar5;
      if (uVar5 <= uVar4) {
        uVar6 = uVar5;
        do {
          if ((*(byte *)(*(int *)(param_1 + 0xa8) + uVar6) & local_5) != 0) {
            uVar7 = uVar6;
            uVar1 = uVar6;
            if (uVar6 <= uVar4) {
              while (uVar2 = uVar7, uVar7 = uVar2 + 1, uVar7 <= uVar4) {
                if ((*(byte *)(uVar7 + *(int *)(param_1 + 0xa8)) & local_5) != 0) {
                  FUN_008eeff0(uVar1 + 1,uVar2);
                  uVar1 = uVar7;
                }
              }
              if (uVar1 == uVar6) {
                FUN_008eefb0();
              }
              else {
                FUN_008eeff0(uVar1 + 1 & 0xffff,uVar4);
                if (uVar6 != 0) {
                  FUN_008eeff0(uVar5,uVar6 - 1);
                }
              }
            }
            break;
          }
          uVar7 = uVar6 + 1;
          uVar6 = uVar7;
        } while (uVar7 <= uVar4);
      }
      sVar3 = sVar3 + 1;
      uVar5 = uVar7;
    } while (sVar3 < *(short *)(param_1 + 0x9a));
  }
  return;
}

