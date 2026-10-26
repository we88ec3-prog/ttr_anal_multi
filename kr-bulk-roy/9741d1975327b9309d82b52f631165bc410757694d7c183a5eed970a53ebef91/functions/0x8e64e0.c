
undefined4 FUN_008e64e0(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_c;
  
  puVar1 = *(uint **)(param_1 + 0x210);
  uVar3 = 6;
  if ((puVar1 != (uint *)0x0) && (puVar1[1] == param_2)) {
    uVar5 = 0;
    if (*puVar1 != 0) {
      do {
        uVar6 = 0;
        iVar4 = 0x10000;
        local_c = 0x10000;
        if (puVar1[1] != 0) {
          do {
            param_1 = *(int *)(param_3 + uVar6 * 4);
            if (param_1 < 0) {
              param_1 = 0;
            }
            else if (0x10000 < param_1) {
              param_1 = 0x10000;
            }
            if ((uVar5 & 1 << ((byte)uVar6 & 0x1f)) == 0) {
              param_1 = 0x10000 - param_1;
            }
            lVar2 = (longlong)local_c * (longlong)param_1 +
                    (ulonglong)((int)((longlong)local_c * (longlong)param_1 >> 0x3f) + 0x8000);
            iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            uVar6 = uVar6 + 1;
            local_c = iVar4;
          } while (uVar6 < puVar1[1]);
        }
        *(int *)(puVar1[0x22] + uVar5 * 4) = iVar4;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

