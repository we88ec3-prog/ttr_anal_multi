
undefined4 FUN_0053c820(uint param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  short *psVar5;
  bool bVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009366b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < param_2) {
    iVar2 = FUN_0053ce30();
    if (iVar2 == 0) {
      ExceptionList = local_10;
      return 0x80004005;
    }
    uVar3 = param_2 - 8 >> 2;
    if (uVar3 != 0) {
      psVar5 = (short *)(param_1 + 8);
      param_1 = uVar3;
      do {
        iVar2 = FUN_0040f060();
        bVar6 = *(short *)(iVar2 + 0xf0) == *psVar5;
        uVar1 = psVar5[1];
        if ((uVar1 & 1) == 0) {
          if ((uVar1 & 2) == 0) {
            if ((uVar1 & 4) == 0) goto LAB_0053c96c;
            FUN_0053c230();
            if (bVar6) {
              FUN_0044e720();
              *(undefined4 *)(in_ECX + 0x5ebc) = 0;
              FUN_004054c0();
              FUN_00402250();
              local_8 = 0;
              FUN_005854b0();
              uVar4 = FUN_00585330();
              FUN_00402250(uVar4);
              local_8 = 0xffffffff;
              FUN_0058b270(0xca);
            }
          }
          else {
            FUN_0053c230();
            if (bVar6) {
              FUN_0044e720();
              *(undefined4 *)(in_ECX + 0x5ebc) = 0;
            }
          }
        }
        else {
LAB_0053c96c:
          FUN_0053c1a0();
        }
        psVar5 = psVar5 + 2;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
  }
  ExceptionList = local_10;
  return 0;
}

